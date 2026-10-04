#include <stdio.h>
#include <string.h>
#include "employees.h"

// Array to store employee ID
int employeeIDs[50];

// Array to store employee names
char employeeNames[50][30];

// Array to store departments
char departments[50][30];

// Array to store basic salaries
float basicSalary[50];

// Array to store housing allowances
float housingAllowances[50];

// Array to store transport allowances
float transportAllowance[50];

// Array to store other relevant information
char otherInformation[50][100];

// Array to store total salaries
float totalSalaries[50];

// Variable to count employees
int employeeCount = 0;

// Function to calculate salary
float calculateSalary(float basic, float housing, float transport)
{
    return basic + housing + transport;
}

// Function to add an employee
void addEmployee()
{

int i;

// Check if maximum employees reached
if(employeeCount >= 50)
{
    printf("Maximum employee limit reached!\n");
    return;
}

// Ask the user for employee details
printf("Enter Employee ID: ");
scanf("%d", &employeeIDs[employeeCount]);

// Check for duplicate ID
for(i = 0; i < employeeCount; i++)
{
    if(employeeIDs[i] == employeeIDs[employeeCount])
    {
        printf("Employee with ID %d already exists!\n", employeeIDs[employeeCount]);
        return;
    }
}
while(getchar() != '\n'); 

    printf("Enter Employee Name: ");
    fgets(employeeNames[employeeCount], 30, stdin);

    if (strlen(employeeNames[employeeCount]) <= 1) 
    {
        printf("Employee name cannot be empty!\n");
        return;
    }

    printf("Enter Department: ");
    fgets(departments[employeeCount], 30, stdin);

    if (strlen(departments[employeeCount]) <= 1) 
    {
        printf("Department cannot be empty!\n");
        return;
    }

    printf("Enter Basic Salary: ");
    scanf("%f", &basicSalary[employeeCount]);

    if(basicSalary[employeeCount] < 0)
    {
        printf("Basic Salary cannot be negative!\n");
        return;
    }
    printf("Enter Housing Allowance: ");
    scanf("%f", &housingAllowances[employeeCount]);

    if(housingAllowances[employeeCount] < 0)
    {
        printf("Allowance cannot be negative!\n");
        return;
    }

    printf("Enter Transport Allowance: ");
    scanf("%f", &transportAllowance[employeeCount]);

    if(transportAllowance[employeeCount] < 0)
    {
        printf("Transport Allowance cannot be negative!\n");
        return;
    }

    printf("Enter Other Relevant Information: ");
    scanf("%s", otherInformation[employeeCount]);

    // Calculate total salary
    totalSalaries[employeeCount] =
    calculateSalary(
        basicSalary[employeeCount],
        housingAllowances[employeeCount],
        transportAllowance[employeeCount]
    );

    // Increase employee count by 1
    employeeCount++;

    // Display success message
    printf("\nEmployee Added Successfully!\n");

}

// Function to display employees
void displayEmployees()
{
    int i;

    if(employeeCount == 0)
    {
        printf("\nNo Employees to Display!\n");
        return;
    }

    printf("\n--- EMPLOYEE LIST ---\n");

    for(i = 0; i < employeeCount; i++)
    {
        printf("\nEmployee %d\n", i + 1);

        printf("ID: %d\n", employeeIDs[i]);

        printf("Name: %s\n", employeeNames[i]);

        printf("Department: %s\n", departments[i]);

        printf("Basic Salary: %.2f\n", basicSalary[i]);

        printf("Housing Allowance: %.2f\n", housingAllowances[i]);

        printf("Transport Allowance: %.2f\n", transportAllowance[i]);

        printf("Total salaries: %.2f\n", totalSalaries[i]);

        printf("Other Relevant Information: %s\n", otherInformation[i]);
    }
}

// Function to search employee
void searchEmployee()
{
    int searchID;
    int i;
    int found = 0;

    // Ask user for employee ID
    printf("\nEnter Employee ID to search: ");
    scanf("%d", &searchID);

    // Search through employee records
    for(i = 0; i < employeeCount; i++)
    {
        if(employeeIDs[i] == searchID)
        {
            printf("\nEmployee found!\n");

            printf("ID: %d\n", employeeIDs[i]);

            printf("Name: %s\n", employeeNames[i]);

            printf("Department: %s\n", departments[i]);

            printf("Basic Salary: %.2f\n", basicSalary[i]);

            printf("Housing Allowance: %.2f\n", housingAllowances[i]);

            printf("Transport Allowance: %.2f\n", transportAllowance[i]);

            printf("Total Salary: %.2f\n", totalSalaries[i]);

            printf("Other Relevant Information: %s\n", otherInformation[i]);

    // Employee found
            found = 1;

            break;
        }
    }

    // Display message if employee is not found
    if(found == 0)
    {
        printf("\nEmployee Not Found!\n");
    }
}

// Employee management menu
void employeeMenu()
{
    int choice;

    do
    {
        printf("\n--- EMPLOYEE MANAGEMENT MENU ---\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addEmployee();
                break;

            case 2:
                displayEmployees();
                break;

            case 3:
                searchEmployee();
                break;

            case 4:
                printf("Exiting Employee Management Menu...\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }
    }
    while(choice != 4);
}