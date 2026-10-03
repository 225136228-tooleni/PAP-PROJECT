#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "assets.h"

#define MAX_ASSETS   100
#define ID_LEN       15
#define NAME_LEN     50
#define TYPE_LEN     30
#define DEPT_LEN     40
#define COND_LEN     10
#define LINE_LEN     100

typedef struct {
    char   id[ID_LEN];
    char   name[NAME_LEN];
    char   type[TYPE_LEN];
    double value;
    char   department[DEPT_LEN];
    char   condition[COND_LEN];
} Asset;

static Asset assets[MAX_ASSETS];
static int   assetCount = 0;

/* ---------- Input helpers ---------- */

static void readLine(const char *prompt, char *buf, int size)
{
    int len, c;

    printf("%s", prompt);
    if (fgets(buf, size, stdin) == NULL) {
        buf[0] = '\0';
        return;
    }
    len = (int)strlen(buf);
    if (len > 0 && buf[len - 1] == '\n') {
        buf[len - 1] = '\0';
    } else {
        while ((c = getchar()) != '\n' && c != EOF)
            ;   /* discard the rest of an over-long line */
    }
}

/* Reads a non-empty string (re-prompts until valid) */
static void readNonEmpty(const char *prompt, char *buf, int size)
{
    do {
        readLine(prompt, buf, size);
        if (strlen(buf) == 0)
            printf("  Error: this field cannot be empty.\n");
    } while (strlen(buf) == 0);
}

/* Reads a positive number (re-prompts until valid) */
static double readPositiveDouble(const char *prompt)
{
    char line[LINE_LEN];
    char *end;
    double value;

    while (1) {
        readLine(prompt, line, sizeof(line));
        value = strtod(line, &end);
        if (end == line || *end != '\0')
            printf("  Error: please enter a valid number.\n");
        else if (value <= 0)
            printf("  Error: the value must be greater than zero.\n");
        else
            return value;
    }
}

/* Reads an integer between min and max (inclusive) */
static int readIntInRange(const char *prompt, int min, int max)
{
    char line[LINE_LEN];
    char *end;
    long value;

    while (1) {
        readLine(prompt, line, sizeof(line));
        value = strtol(line, &end, 10);
        if (end == line || *end != '\0')
            printf("  Error: please enter a whole number.\n");
        else if (value < min || value > max)
            printf("  Error: choose a number from %d to %d.\n", min, max);
        else
            return (int)value;
    }
}

static void toLowerCopy(const char *src, char *dest, int size)
{
    int i;
    for (i = 0; i < size - 1 && src[i] != '\0'; i++)
        dest[i] = (char)tolower((unsigned char)src[i]);
    dest[i] = '\0';
}

/* Returns index of asset with this ID, or -1 if not found */
static int findAssetById(const char *id)
{
    int i;
    for (i = 0; i < assetCount; i++) {
        if (strcmp(assets[i].id, id) == 0)
            return i;
    }
    return -1;
}

static void printAssetHeader(void)
{
    printf("\n%-12s %-22s %-14s %-14s %-16s %-10s\n",
           "ID", "Name", "Type", "Value (N$)", "Department", "Condition");
    printf("-------------------------------------------------------------"
           "-------------------\n");
}

static void printAssetRow(const Asset *a)
{
    printf("%-12s %-22s %-14s %-14.2f %-16s %-10s\n",
           a->id, a->name, a->type, a->value, a->department, a->condition);
}

/* ---------- Public functions ---------- */

void addAsset(void)
{
    Asset a;
    int choice;

    printf("\n--- ADD ASSET ---\n");

    if (assetCount >= MAX_ASSETS) {
        printf("Asset register is full (%d assets).\n", MAX_ASSETS);
        return;
    }

    /* Unique, non-empty ID */
    while (1) {
        readNonEmpty("Asset ID: ", a.id, sizeof(a.id));
        if (findAssetById(a.id) != -1)
            printf("  Error: an asset with this ID already exists.\n");
        else
            break;
    }

    readNonEmpty("Asset name: ", a.name, sizeof(a.name));

    printf("Asset type:\n");
    printf("  1. Vehicle\n  2. Computer\n  3. Building\n");
    printf("  4. Equipment\n  5. Furniture\n  6. Other\n");
    choice = readIntInRange("Select type (1-6): ", 1, 6);
    switch (choice) {
        case 1: strcpy(a.type, "Vehicle");   break;
        case 2: strcpy(a.type, "Computer");  break;
        case 3: strcpy(a.type, "Building");  break;
        case 4: strcpy(a.type, "Equipment"); break;
        case 5: strcpy(a.type, "Furniture"); break;
        default:
            readNonEmpty("Enter type name: ", a.type, sizeof(a.type));
            break;
    }

    a.value = readPositiveDouble("Purchase value (N$): ");
    readNonEmpty("Department: ", a.department, sizeof(a.department));

    printf("Condition:\n  1. Good\n  2. Fair\n  3. Poor\n");
    choice = readIntInRange("Select condition (1-3): ", 1, 3);
    if (choice == 1)
        strcpy(a.condition, "Good");
    else if (choice == 2)
        strcpy(a.condition, "Fair");
    else
        strcpy(a.condition, "Poor");

    assets[assetCount] = a;
    assetCount++;
    printf("\nAsset '%s' added successfully.\n", a.name);
}

void displayAssets(void)
{
    int i;

    printf("\n--- ASSET REGISTER ---\n");
    if (assetCount == 0) {
        printf("No assets registered yet.\n");
        return;
    }

    printAssetHeader();
    for (i = 0; i < assetCount; i++)
        printAssetRow(&assets[i]);

    printf("\nTotal assets: %d\n", assetCount);
    printf("Total value : N$%.2f\n", getTotalAssetValue());
}

void searchAsset(void)
{
    char term[NAME_LEN], termLower[NAME_LEN], nameLower[NAME_LEN];
    int choice, i, found = 0;

    printf("\n--- SEARCH ASSET ---\n");
    if (assetCount == 0) {
        printf("No assets registered yet.\n");
        return;
    }

    printf("  1. Search by ID\n  2. Search by name\n  3. Search by department\n");
    choice = readIntInRange("Select option (1-3): ", 1, 3);
    readNonEmpty("Enter search term: ", term, sizeof(term));
    toLowerCopy(term, termLower, sizeof(termLower));

    for (i = 0; i < assetCount; i++) {
        int match = 0;

        if (choice == 1) {
            match = (strcmp(assets[i].id, term) == 0);
        } else if (choice == 2) {
            toLowerCopy(assets[i].name, nameLower, sizeof(nameLower));
            match = (strstr(nameLower, termLower) != NULL);
        } else {
            toLowerCopy(assets[i].department, nameLower, sizeof(nameLower));
            match = (strstr(nameLower, termLower) != NULL);
        }

        if (match) {
            if (!found)
                printAssetHeader();
            printAssetRow(&assets[i]);
            found++;
        }
    }

    if (found == 0)
        printf("No matching assets found.\n");
    else
        printf("\n%d asset(s) found.\n", found);
}

void assetMenu(void)
{
    int choice;

    do {
        printf("\n========================================\n");
        printf("           ASSET MANAGEMENT\n");
        printf("========================================\n");
        printf("1. Add asset\n");
        printf("2. Display assets\n");
        printf("3. Search asset\n");
        printf("4. Back to main menu\n");
        choice = readIntInRange("Enter your choice: ", 1, 4);

        switch (choice) {
            case 1: addAsset();      break;
            case 2: displayAssets(); break;
            case 3: searchAsset();   break;
            case 4: printf("Returning to main menu...\n"); break;
        }
    } while (choice != 4);
}

int getAssetCount(void)
{
    return assetCount;
}

double getTotalAssetValue(void)
{
    double total = 0.0;
    int i;
    for (i = 0; i < assetCount; i++)
        total += assets[i].value;
    return total;
}
