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

/* ---------- INPUT HELPERS ---------- */

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
    int len, c;

    fgets(text, size, stdin);
    len = strlen(text);

    if (len > 0 && text[len - 1] == '\n') {
        text[len - 1] = '\0';           /* replace the Enter key with end of string */
    } else {
        /* The user typed more than fits, so throw away the extra characters */
        while ((c = getchar()) != '\n' && c != EOF);
    }
}

/* ---------- VALIDATION HELPERS ---------- */

/* Returns 1 if the text is empty or contains only spaces, otherwise 0 */
static int isBlank(char text[])
{
    int i;

    for (i = 0; text[i] != '\0'; i++) {
        if (text[i] != ' ')
            return 0;                   /* found a real character */
    }
    return 1;                           /* only spaces (or nothing) */
}

/* Returns 1 if the email looks valid, otherwise 0.
   Rules: exactly one @, something before the @, no spaces,
   a dot after the @, and the email does not end with a dot */
static int isValidEmail(char email[])
{
    int i;
    int len = strlen(email);
    int atCount = 0;
    int atPosition = -1;
    int dotAfterAt = 0;

    /* Step 1: look for spaces and find the @ */
    for (i = 0; i < len; i++) {
        if (email[i] == ' ')
            return 0;                   /* spaces are not allowed */
        if (email[i] == '@') {
            atCount++;
            atPosition = i;
        }
    }

    /* Step 2: check the @ */
    if (atCount != 1)
        return 0;                       /* must have exactly one @ */
    if (atPosition == 0)
        return 0;                       /* must have text before the @ */

    /* Step 3: look for a dot after the @ */
    for (i = atPosition + 1; i < len; i++) {
        if (email[i] == '.')
            dotAfterAt = 1;
    }
    if (dotAfterAt == 0)
        return 0;

    /* Step 4: must not end with a dot */
    if (email[len - 1] == '.')
        return 0;

    return 1;                           /* all checks passed */
}

/* Returns 1 if the phone number looks valid, otherwise 0.
   Allowed: digits, spaces, dashes, and a + at the start.
   Must contain at least 7 digits */
static int isValidPhone(char phone[])
{
    int i;
    int digitCount = 0;

    for (i = 0; phone[i] != '\0'; i++) {
        if (phone[i] >= '0' && phone[i] <= '9') {
            digitCount++;               /* a digit, count it */
        } else if (phone[i] == ' ' || phone[i] == '-') {
            /* spaces and dashes are allowed, do nothing */
        } else if (phone[i] == '+' && i == 0) {
            /* a + is only allowed as the first character */
        } else {
            return 0;                   /* any other character is invalid */
        }
    }

    if (digitCount < 7)
        return 0;                       /* too few digits */

    return 1;
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

/* ---------- SUPPLIER FUNCTIONS ---------- */

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
    if (isBlank(name)) {
        printf("Name cannot be empty.\n");
        return;
    }

    printf("Email: ");
    readText(email, 50);
    if (!isValidEmail(email)) {
        printf("Invalid email. Example: name@company.com\n");
        return;
    }

    printf("Telephone: ");
    readText(phone, 20);
    if (!isValidPhone(phone)) {
        printf("Invalid telephone. Use digits only, at least 7.\n");
        return;
    }

    printf("Town/Location: ");
    readText(town, 50);
    if (isBlank(town)) {
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
