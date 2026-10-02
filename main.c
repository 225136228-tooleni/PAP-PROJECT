
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

/* Header inclusions for module routing */
#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"
#include "reports.h"

/* Dummy implementations until teammates supply their .c files */
void employeeMenu(void) { printf("\n--- Employee Management Module ---\n"); }
void budgetMenu(void)   { printf("\n--- Budget Management Module ---\n"); }
void supplierMenu(void) { printf("\n--- Supplier Management Module ---\n"); }
void assetMenu(void)    { printf("\n--- Asset Management Module ---\n"); }
void reportsMenu(void)  { printf("\n--- System Reports Module ---\n"); }

/* Function prototypes for Member 6 */
void displayMainMenu(void);
void navigateSystem(void);
void clearInputBuffer(void);

int main(void) {
    navigateSystem();
    return 0;
}

void displayMainMenu(void) {
    printf("\n========================================\n");
    printf("MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("========================================\n");
    printf("1. Employee Management\n");
    printf("2. Budget Management\n");
    printf("3. Supplier Management\n");
    printf("4. Asset Management\n");
    printf("5. Reports\n");
    printf("6. Exit\n");
    printf("========================================\n");
    printf("Enter your choice (1-6): ");
}

void navigateSystem(void) {
    int choice = 0;
    int running = 1;

    while (running) {
        displayMainMenu();

        /* Input validation to check for non-numeric input */
        if (scanf("%d", &choice) != 1) {
            printf("\n[ERROR] Invalid input! Please enter a valid number.\n");
            clearInputBuffer();
            continue;
        }

        switch (choice) {
            case 1: employeeMenu(); break;
            case 2: budgetMenu(); break;
            case 3: supplierMenu(); break;
            case 4: assetMenu(); break;
            case 5: reportsMenu(); break;
            case 6:
                printf("\nExiting system. Goodbye!\n");
                running = 0;
                break;
            default:
                printf("\n[ERROR] Choice out of range! Select between 1 and 6.\n");
                break;
        }
    }
}

void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}