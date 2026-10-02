#include <stdio.h>
#include <string.h>

#define MAX 100

/* Parallel arrays: position i in every array is the same supplier */
static int  supplierIds[MAX];
static char supplierNames[MAX][50];
static char supplierEmails[MAX][50];
static char supplierPhones[MAX][20];
static char supplierTowns[MAX][50];
static int  supplierCount = 0;

/* Read a whole number. Keeps asking until the user types a valid number */
static int readInt(void)
{
    int number;
    while (scanf("%d", &number) != 1) {
        printf("Invalid number. Try again: ");
        while (getchar() != '\n');      /* throw away the bad input */
    }
    while (getchar() != '\n');          /* throw away the rest of the line */
    return number;
}

/* Read a line of text (spaces allowed) */
static void readText(char text[], int size)
{
    int len;
    fgets(text, size, stdin);
    len = strlen(text);
    if (len > 0 && text[len - 1] == '\n')
        text[len - 1] = '\0';          /* replace the Enter key with end of string */
}

/* Return the position of the supplier with this ID, or -1 if not found */
static int findSupplier(int id)
{
    int i;
    for (i = 0; i < supplierCount; i++) {
        if (supplierIds[i] == id)
            return i;
    }
    return -1;
}

void addSupplier(void)
{
    int id;
    char name[50], email[50], phone[20], town[50];

    if (supplierCount >= MAX) {
        printf("Supplier list is full.\n");
        return;
    }

    printf("Supplier ID: ");
    id = readInt();
    if (id <= 0) {
        printf("ID must be a positive number.\n");
        return;
    }
    if (findSupplier(id) != -1) {
        printf("That ID already exists.\n");
        return;
    }

    printf("Supplier name: ");
    readText(name, 50);
    if (strlen(name) == 0) {
        printf("Name cannot be empty.\n");
        return;
    }

    printf("Email: ");
    readText(email, 50);
    if (strchr(email, '@') == NULL) {
        printf("Invalid email. It must contain @.\n");
        return;
    }

    printf("Telephone: ");
    readText(phone, 20);
    if (strlen(phone) < 7) {
        printf("Invalid telephone. At least 7 characters.\n");
        return;
    }

    printf("Town/Location: ");
    readText(town, 50);
    if (strlen(town) == 0) {
        printf("Town cannot be empty.\n");
        return;
    }

    /* All checks passed, so save the supplier */
    supplierIds[supplierCount] = id;
    strcpy(supplierNames[supplierCount], name);
    strcpy(supplierEmails[supplierCount], email);
    strcpy(supplierPhones[supplierCount], phone);
    strcpy(supplierTowns[supplierCount], town);
    supplierCount++;

    printf("Supplier added successfully.\n");
}

void displaySuppliers(void)
{
    int i;

    if (supplierCount == 0) {
        printf("No suppliers registered.\n");
        return;
    }

    printf("\n%-5s %-20s %-25s %-12s %-15s\n",
           "ID", "Name", "Email", "Telephone", "Town");
    for (i = 0; i < supplierCount; i++) {
        printf("%-5d %-20s %-25s %-12s %-15s\n",
               supplierIds[i], supplierNames[i], supplierEmails[i],
               supplierPhones[i], supplierTowns[i]);
    }
    printf("Total suppliers: %d\n", supplierCount);
}

void searchSupplier(void)
{
    char name[50];
    int i, found = 0;

    printf("Enter the supplier name to search: ");
    readText(name, 50);

    for (i = 0; i < supplierCount; i++) {
        if (strcmp(supplierNames[i], name) == 0) {   /* 0 means the names match */
            printf("Found: ID %d, %s, %s, %s, %s\n",
                   supplierIds[i], supplierNames[i], supplierEmails[i],
                   supplierPhones[i], supplierTowns[i]);
            found = 1;
        }
    }

    if (found == 0)
        printf("No supplier found with that name.\n");
}

void compareSuppliers(void)
{
    int idA, idB, a, b;

    if (supplierCount < 2) {
        printf("You need at least 2 suppliers to compare.\n");
        return;
    }

    printf("First supplier ID: ");
    idA = readInt();
    printf("Second supplier ID: ");
    idB = readInt();

    a = findSupplier(idA);
    b = findSupplier(idB);
    if (a == -1 || b == -1) {
        printf("One or both IDs were not found.\n");
        return;
    }

    printf("\n%s is in %s\n", supplierNames[a], supplierTowns[a]);
    printf("%s is in %s\n", supplierNames[b], supplierTowns[b]);

    if (strcmp(supplierTowns[a], supplierTowns[b]) == 0)
        printf("Both suppliers are in the same town.\n");
    else
        printf("The suppliers are in different towns.\n");
}

void supplierMenu(void)
{
    int choice;

    do {
        printf("\n========================================\n");
        printf("         SUPPLIER MANAGEMENT\n");
        printf("========================================\n");
        printf("1. Add supplier\n");
        printf("2. Display suppliers\n");
        printf("3. Search supplier\n");
        printf("4. Compare suppliers\n");
        printf("5. Back to main menu\n");
        printf("Enter your choice: ");
        choice = readInt();

        switch (choice) {
            case 1: addSupplier();      break;
            case 2: displaySuppliers(); break;
            case 3: searchSupplier();   break;
            case 4: compareSuppliers(); break;
            case 5: printf("Returning to main menu...\n"); break;
            default: printf("Invalid choice. Enter 1 to 5.\n");
        }
    } while (choice != 5);
}
