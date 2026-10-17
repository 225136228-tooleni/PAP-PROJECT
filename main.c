#include <stdio.h>
#include <string.h>

#define MAX 50

// Structures for the Municipal Financial Management System
struct Employee {
    int id;
    char name[50];
    char department[50];
    float basicSalary;
    float housingAllowance;
    float transportAllowance;
};

struct Budget {
    char department[50];
    float allocatedBudget;
    float expenditure;
};

struct Supplier {
    int id;
    char name[50];
    char telephone[20];
    char town[50];
};

struct Asset {
    int id;
    char name[50];
    float purchaseValue;
};

// Global arrays and counters
struct Employee employees[MAX];
int empCount = 0;

struct Budget budgets[MAX];
int budgetCount = 0;

struct Supplier suppliers[MAX];
int supCount = 0;

struct Asset assets[MAX];
int assetCount = 0;

// Function Prototypes based on project design
void displayMenu(void);
void addEmployee(void);
void displayEmployees(void);
void searchEmployee(void);
void budgetManagement(void);
void supplierManagement(void);
void assetManagement(void);
void displayReports(void);

int main(void) {
    int choice;
    
    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                {
                    int empChoice;
                    do {
                        printf("\n--- EMPLOYEE MANAGEMENT ---\n");
                        printf("1. Add Employee\n");
                        printf("2. Display Employees\n");
                        printf("3. Search Employee\n");
                        printf("4. Back to Main Menu\n");
                        printf("Enter choice: ");
                        scanf("%d", &empChoice);

                        if (empChoice == 1) {
                            addEmployee();
                        } else if (empChoice == 2) {
                            displayEmployees();
                        } else if (empChoice == 3) {
                            searchEmployee();
                        }
                    } while (empChoice != 4);
                }
                break;
            case 2:
                budgetManagement();
                break;
            case 3:
                supplierManagement();
                break;
            case 4:
                assetManagement();
                break;
            case 5:
                displayReports();
                break;
            case 6:
                printf("\nExiting system. Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice! Please enter a number between 1 and 6.\n");
        }
    } while (choice != 6);

    return 0;
}

// Display Main Menu[cite: 5]
void displayMenu(void) {
    printf("\n=========================================\n");
    printf("   MUNICIPAL FINANCIAL MANAGEMENT SYSTEM   \n");
    printf("=========================================\n");
    printf("1. Employee Management\n");
    printf("2. Budget Management\n");
    printf("3. Supplier Management\n");
    printf("4. Asset Management\n");
    printf("5. Reports\n");
    printf("6. Exit\n");
    printf("-----------------------------------------\n");
    printf("Enter your choice: ");
}

// Employee Management: Add with Validation
void addEmployee(void) {
    if (empCount >= MAX) {
        printf("Employee database is full.\n");
        return;
    }

    int id, duplicate = 0;
    printf("Enter Employee ID: ");
    scanf("%d", &id);

    // Validation: Check if ID already exists
    for (int i = 0; i < empCount; i++) {
        if (employees[i].id == id) {
            duplicate = 1;
            break;
        }
    }

    if (duplicate || id <= 0) {
        printf("Error: Invalid ID or Employee ID already exists! Addition failed.\n");
        return;
    }

    employees[empCount].id = id;

    printf("Enter Employee Name: ");
    scanf("%s", employees[empCount].name); // Simple string input

    printf("Enter Department: ");
    scanf("%s", employees[empCount].department);

    printf("Enter Basic Salary: ");
    scanf("%f", &employees[empCount].basicSalary);

    if (employees[empCount].basicSalary < 0) {
        printf("Error: Salary cannot be negative. Addition failed.\n");
        return;
    }

    printf("Enter Housing Allowance: ");
    scanf("%f", &employees[empCount].housingAllowance);

    printf("Enter Transport Allowance: ");
    scanf("%f", &employees[empCount].transportAllowance);

    empCount++;
    printf("Employee added successfully!\n");
}

// Display Employees[cite: 5]
void displayEmployees(void) {
    if (empCount == 0) {
        printf("No employees found.\n");
        return;
    }

    printf("\n--- EMPLOYEE LIST ---\n");
    for (int i = 0; i < empCount; i++) {
        float total = employees[i].basicSalary + employees[i].housingAllowance + employees[i].transportAllowance;
        printf("ID: %d | Name: %s | Dept: %s | Total Salary: %.2f\n",
               employees[i].id, employees[i].name, employees[i].department, total);
    }
}

// Search Employee[cite: 5]
void searchEmployee(void) {
    if (empCount == 0) {
        printf("No employees to search.\n");
        return;
    }

    int searchId, found = 0;
    printf("Enter Employee ID to search: ");
    scanf("%d", &searchId);

    for (int i = 0; i < empCount; i++) {
        if (employees[i].id == searchId) {
            float total = employees[i].basicSalary + employees[i].housingAllowance + employees[i].transportAllowance;
            printf("Found! Name: %s, Department: %s, Total Salary: %.2f\n",
                   employees[i].name, employees[i].department, total);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Employee with ID %d not found.\n", searchId);
    }
}

// Budget Management[cite: 5]
void budgetManagement(void) {
    int choice;
    printf("\n--- BUDGET MANAGEMENT ---\n");
    printf("1. Add Budget\n2. Display Budgets\nChoice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        if (budgetCount >= MAX) return;
        printf("Enter Department: ");
        scanf("%s", budgets[budgetCount].department);
        printf("Allocated Budget: ");
        scanf("%f", &budgets[budgetCount].allocatedBudget);
        printf("Expenditure: ");
        scanf("%f", &budgets[budgetCount].expenditure);

        if (budgets[budgetCount].allocatedBudget < 0 || budgets[budgetCount].expenditure < 0) {
            printf("Error: Budget or expenditure cannot be negative.\n");
            return;
        }
        budgetCount++;
        printf("Budget added.\n");
    } else if (choice == 2) {
        for (int i = 0; i < budgetCount; i++) {
            float rem = budgets[i].allocatedBudget - budgets[i].expenditure;
            printf("Dept: %s | Remaining: %.2f | Status: %s\n",
                   budgets[i].department, rem, (rem >= 0 ? "WITHIN BUDGET" : "EXCEEDED"));
        }
    }
}

// Supplier Management[cite: 5]
void supplierManagement(void) {
    int choice;
    printf("\n--- SUPPLIER MANAGEMENT ---\n");
    printf("1. Add Supplier\n2. Display Suppliers\nChoice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        if (supCount >= MAX) return;
        printf("Supplier ID: ");
        scanf("%d", &suppliers[supCount].id);
        printf("Supplier Name: ");
        scanf("%s", suppliers[supCount].name);
        supCount++;
        printf("Supplier added.\n");
    } else if (choice == 2) {
        for (int i = 0; i < supCount; i++) {
            printf("ID: %d | Name: %s\n", suppliers[i].id, suppliers[i].name);
        }
    }
}

// Asset Management
void assetManagement(void) {
    int choice;
    printf("\n--- ASSET MANAGEMENT ---\n");
    printf("1. Add Asset\n2. Display Assets\nChoice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        if (assetCount >= MAX) return;
        printf("Asset ID: ");
        scanf("%d", &assets[assetCount].id);
        printf("Asset Name: ");
        scanf("%s", assets[assetCount].name);
        assetCount++;
        printf("Asset added.\n");
    } else if (choice == 2) {
        for (int i = 0; i < assetCount; i++) {
            printf("ID: %d | Name: %s\n", assets[i].id, assets[i].name);
        }
    }
}

// Reports
void displayReports(void) {
    printf("\n--- SYSTEM REPORTS ---\n");
    printf("Total Employees: %d\n", empCount);
    printf("Total Budgets: %d\n", budgetCount);
    printf("Total Suppliers: %d\n", supCount);
    printf("Total Assets: %d\n", assetCount);
}
