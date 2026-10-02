#include <stdio.h>
#include "employees.h"

// Array to store employee IDs
int employeeIDs[50];

// Array to store employee names
char employeeNames[50][30];

// Array to store departments
char departments[50][30];

// Array to store basic salaries
float basicSalary[50];

// Array to store allowances
float allowance[50];

// Array to store total salaries
float totalSalaries[50];

// Variable to count employees
int employeeCount = 0;

// Function to calculate salary
float calculateSalary(float basic, float extraAllowance)
{
    return basic + extraAllowance;
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

    printf("Enter Employee Name: ");
    scanf("%s", employeeNames[employeeCount]);

    printf("Enter Department: ");
    scanf("%s", departments[employeeCount]);

    printf("Enter Basic Salary: ");
    scanf("%f", &basicSalary[employeeCount]);

    if(basicSalary[employeeCount] < 0)
    {
        printf("Basic Salary cannot be negative!\n");
        return;
    }
    printf("Enter Allowance: ");
    scanf("%f", &allowance[employeeCount]);

    if(allowance[employeeCount] < 0)
    {
        printf("Allowance cannot be negative!\n");
        return;
    }

    // Calculate total salary
    totalSalaries[employeeCount] =
    calculateSalary(
        basicSalary[employeeCount],
        allowance[employeeCount]
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

        printf("Allowance: %.2f\n", allowance[i]);

        printf("Total salaries: %.2f\n", totalSalaries[i]);
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

            printf("Allowance: %.2f\n", allowance[i]);

            printf("Total Salary: %.2f\n",
totalSalaries[i]);

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