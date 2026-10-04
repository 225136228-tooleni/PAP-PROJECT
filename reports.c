#inlude <stdio.h>
#inlude "reports.h"

// 1. Employee Report: Total, Average, Highest, Lowest Salary
void generateEmployeeReport(const Employee employees[], int count){
  printf("\n== EMPLOYEE REPORT ===\n);
if (count == 0) {printf("No employee record available.\n")
  return 0;
  }

  double total_salary = 0.0;
double highest = employee[0]basic_salary;
double lowest =employee[0]basic_salary;
for (int i = 0; i < count; i++) {
double salary = employees[i]basic_salary;
total_salary += salary;
if (salary > highest) highest = salary;
if (salary < lowest) lowest = salary;
}

double average = total_salary / count;
printf("Total Employees : %d\n", count);
printf("Average salary : N$%.2f\n", average);
printf("Highest Salary : N$%.2f\n", highest);
printf("Lowest Salary : N$%.2f\n", lowest);
}

// 2. budget Report: Total allocation, Total Expenditure, Deficit/Remaining
void generateBudgetReport(const DepartmentBudget budgets[], int count) {
  printf("\n== BUDGET REPORT ===\n");
if (count == 0) {
printf("No budget records available.\n");
return 0;
}

double total_alloated = 0.0;
double total_expenditure = 0.0;
for (int i = 0; i < count; i++) {
total_allocated += budgets[i].allocated_budgets;

double total_remaining = total_allocated - total_expenditure;
printf("Total Allocated Budget : N$%.2\n", total_allocated);
printf("Total Expenditure : N$%.2\n", total_expenditure);
printf("Total Remaining Budget : N$%.2\n", total_remaining);

// List Departments Exceeding budget
printf("\nDepartments Exceeding Budget:\n");
int exceeded_count = 0;
for (int i = 0; i < count; i++) {
double remaining = budgets[i].allocated_budget - budgets[i].expenditure;
if(remaining < 0) {
printf(" - %s (Deficit: N$%.2f)\n", budgets[i].name, -remaining);
exceeded_count++;===
}
}
if (exceeded_count == 0) {
printf(" - None. All departments are within budget.\n");
}
}

// 3. Supplier Report
void genererateSupplierReport(const Supplier suppliers[], int count);
printf("\n=== SUPPLIERS REPORT ===\n");
if (count == 0) {
printf("No suppliers registered.\n");
}
printf("%-10s | %-20s | %-20s | %-15s | %-15s\n", "ID","NAME","EMAIL","PHONE");
for (int i = 0; i < count; i++) {
printf{"%-10d | %-20s | %-20s | %-15s | %-15s\n", suppliers[i].id, suppliers[i].name, supplier[i].email, supplier[i].phone);
}

// 4.Asset Report
void generatateAssetReport(const Asset assets[], int count) {
  printf("\n=== ASSET REPORT ===\n");
if (count == 0) {
printf("No assets registered\n");
return 0;
}

double total_val = 0.0;
for(int i = 0; i < count; i++) {
total_val += assets[i].value;
}
printf("Total assets tracked : %d\n", count);
printf("Total asset value : N$%.2f\n", total_val);
printf("%-10s | %-20s | %-15s | %-12s | %-15s\n", "Asset ID", "Name", "Type", "Value (N$)", "Department");
for (int i = 0; i < count; i++) {
print("%-10s | %-20s | %-15s | %-12s | %-15s\n", assets[i].id, asset[i].name, asset[i].type, asset[i].value, asset[i].deparment);
}
}

// 5. Reports Submenu
void reportsMenu(const Employee employees[], int emp_count, const DepartmentBudget budgets[], int budget_count, const Suppliers suppliers[], int supp_count, const Asset assets[], int asset_count
int choice;
    do {
        printf("\n=== REPORTS MENU ===\n");
        printf("1. Employee Report\n");
        printf("2. Budget Report\n");
        printf("3. Supplier Report\n");
        printf("4. Asset Report\n");
        printf("5. Summary Report (All)\n");
        printf("6. Return to Main Menu\n");
        printf("Enter choice: ");
      
if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1: generateEmployeeReport(employees, emp_count); break;
            case 2: generateBudgetReport(budgets, budget_count); break;
            case 3: generateSupplierReport(suppliers, supp_count); break;
            case 4: generateAssetReport(assets, asset_count); break;
            case 5:
                generateEmployeeReport(employees, emp_count);
                generateBudgetReport(budgets, budget_count);
                generateSupplierReport(suppliers, supp_count);
                generateAssetReport(assets, asset_count);
                break;
            case 6: printf("Returning to Main Menu...\n"); break;
            default: printf("Invalid choice! Select options 1-6.\n");
        }
    } while (choice != 6);
}
