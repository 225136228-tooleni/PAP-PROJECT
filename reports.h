#ifndef REPORTS_H
#define REPORTS_H

#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"

// Function prototypes for reports
void generateEmployeeReport(const Employee employees[], int count);
void generateBudgetReport(const DepartmenntBudget budgets[], int count);
void generateSupplierReport(const Supplier suppliers[], int count);
void generateAssetReport(const Asset assets[], int count);
void reportsMenu(const Employee employees[], int emp_count, const DepartmeentBudget budget[], int budget_count, const Supplier Suppliers[], int supp_count, const Asset assets[], int asset_count);

#endif
