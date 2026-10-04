#include <stdio.h>
#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"
#include "reports.h"

int main()
{
    // Variable to store menu choice
    int choice;

    // Repeat menu until user chooses Exit
    do 
    {
        // Display menu
        printf("\n--- MUNICIPAL FINANCIAL MANAGEMENT SYSTEM ---\n");
        printf("1. Employee Management\n");
        printf("2. Budget Management\n");
        printf("3. Supplier Management\n");
        printf("4. Asset Management\n");
        printf("5. Reports Management\n");
        printf("6. Exit\n");

        // Ask user to enter choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform action based on user's choice
        switch(choice)
        {
            // Display employee menu
            case 1:
            employeeMenu();
            break;

            // Display budget menu
            case 2:
            budgetMenu();
            break;

            //Display supplier menu
            case 3:
            supplierMenu();
            break;

            // Display asset menu
            case 4:
            assetMenu();
            break;

            // Display reports menu
            case 5:
            reportsMenu();
            break;

            //Exit the program
            case 6:
            printf("Exiting Program...\n");
            break;

            // Handle Invalid menu choices
            default:
            printf("Invalid Choice!\n");
        }
    }
    while(choice != 6);

    //End of program
    return 0;
}