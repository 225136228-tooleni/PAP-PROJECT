#include <stdio.h>
#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"
#include "reports.h"

/* Read a whole number. Keeps asking until the user types a valid number */
static int readChoice(void)
{
    int number;

    while (scanf("%d", &number) != 1) {
        printf("Invalid number. Try again: ");
        while (getchar() != '\n');      /* throw away the bad input */
    }
    while (getchar() != '\n');          /* throw away the rest of the line */
    return number;
}

/* Show the main menu */
static void displayMenu(void)
{
    printf("\n========================================\n");
    printf("MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("========================================\n");
    printf("1. Employee Management\n");
    printf("2. Budget Management\n");
    printf("3. Supplier Management\n");
    printf("4. Asset Management\n");
    printf("5. Reports\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

int main(void)
{
    int choice;

    do {
        displayMenu();
        choice = readChoice();

        switch (choice) {
            case 1: employeeMenu(); break;
            case 2: budgetMenu();   break;
            case 3: supplierMenu(); break;
            case 4: assetMenu();    break;
            case 5: reportsMenu();  break;
            case 6: printf("Exiting system. Goodbye!\n"); break;
            default: printf("Invalid choice. Enter 1 to 6.\n");
        }
    } while (choice != 6);

    return 0;
}
