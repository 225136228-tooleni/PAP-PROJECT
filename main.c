#include <stdio.h>
#include "employees.h"

int main()
{
    // Variable to store menu choice
    int choice;

    // Repeat menu until user chooses Exit
    do 
    {
        // Display menu
        printf("\n--- EMPLOYEE MANAGEMENT SYSTEM ---\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Exit\n");

        // Ask user to enter choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform action based on user's choice
        switch(choice)
        {
            // Add employee
            case 1:
            addEmployee();
            break;

            // Display all employees
            case 2:
            displayEmployees();
            break;

            // Search for an employee
            case 3:
            searchEmployee();
            break;

            //Exit the program
            case 4:
            printf("Exiting Program...\n");
            break;

            // Handle Invalid menu choices
            default:
            printf("Invalid Choice!\n");
        }
    }
    while(choice != 4);

    //End of program
    return 0;
}