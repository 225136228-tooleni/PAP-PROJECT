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

int searchEmployee(int id, int ids[], int size)
{
    for(int i = 0; i < size; i++)
    {
        if(ids[i] == id)
        {
            return i; // Return index if found
        }
    }
    return -1; // Return -1 if not found
}

// Check if maximum employees reached
void addEmployee()
{

int position;
if(employeeCount >= 50)
{
    printf("Maximum employee limit reached!\n");
    return;
}

// Ask the user for employee details
printf("Enter Employee ID: ");
scanf("%d", &employeeIDs[employeeCount]);

position = searchEmployee(employeeIDs[employeeCount], employeeIDs, employeeCount);

// Check for duplicate ID
if(position != -1)
{
    printf("Employee with ID %d already exists!\n", employeeIDs[employeeCount]);
    return;
}

    printf("Enter Employee Name: ");
    scanf("%s", employeeNames[employeeCount]);

    if(strlen(employeeNames[employeeCount]) == 0) 
    {
        printf("Employee name cannot be empty!\n");
        return;
    }

    printf("Enter Department: ");
    scanf("%s", departments[employeeCount]);

    if(strlen(departments[employeeCount]) == 0) 
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
void searchEmployeeByID()
{
    int id;
    printf("\nEnter Employee ID to search: ");
    scanf("%d", &id);

    int index = searchEmployee(id, employeeIDs, employeeCount);
    if(index == -1)
    {
        printf("Employee not found!\n");
    }
    else
    {
        printf("ID: %d\n", employeeIDs[index]);
        printf("Name: %s\n", employeeNames[index]);
        printf("Department: %s\n", departments[index]);
        printf("Basic Salary: %.2f\n", basicSalary[index]);
        printf("Housing Allowance: %.2f\n", housingAllowances[index]);
        printf("Transport Allowance: %.2f\n", transportAllowance[index]);
        printf("Total Salary: %.2f\n", totalSalaries[index]);
        printf("Other Relevant Information: %s\n", otherInformation[index]);
    }
}

// Search employee by name
void searchEmployeeByName()
{
    char searchName[30];
    int found = 0;

    printf("\nEnter Employee Name to search: ");
    scanf("%s", searchName);

    for(int i = 0; i < employeeCount; i++)
    {
        if(strcmp(employeeNames[i], searchName) == 0)
        {
            printf("\nEmployee found at position %d!\n", i);

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

        }
    }

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
        printf("3. Search Employee by ID\n");
        printf("4. Search Employee by Name\n");
        printf("5. Exit\n");
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
                searchEmployeeByID();
                break;

            case 4:
                searchEmployeeByName();
                break;

            case 5:
                printf("Exiting Employee Management Menu...\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }
    }
    while(choice != 5);
}