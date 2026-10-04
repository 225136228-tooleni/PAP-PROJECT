#include <stdio.h>
#include "reports.h"

void generateEmployeeReport(void)

{
    printf("\n--- EMPLOYEE REPORT ---\n");
    printf("Employee report will be displayed here.\n");
}

void generateBudgetReport(void)
{
    printf("\n--- BUDGET REPORT ---\n");
    printf("Budget report will be displayed here.\n");
}

void generateSupplierReport(void)
{
    printf("\n--- SUPPLIER REPORT ---\n");
    printf("Supplier report will be displayed here.\n");
}

void generateAssetReport(void)
{
    printf("\n--- ASSET REPORT ---\n");
    printf("Asset report will be displayed here.\n");
}

void reportsMenu(void)
{
    int choice;

    do {
        printf("\n--- REPORTS MANAGEMENT ---\n");
        printf("1. Employee Report\n");
        printf("2. Budget Report\n");
        printf("3. Supplier Report\n");
        printf("4. Asset Report\n");
        printf("5. Back to Main Menu\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                generateEmployeeReport();
                break;

            case 2:
                generateBudgetReport();
                break;

            case 3:
                generateSupplierReport();
                break;

            case 4:
                generateAssetReport();
                break;

            case 5:
                generateEmployeeReport();
                generateBudgetReport();
                generateSupplierReport();
                generateAssetReport();
                break;

                case 6:
                printf("Returning to Main Menu...\n");

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);
}
