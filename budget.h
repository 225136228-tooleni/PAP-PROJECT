#ifndef BUDGET_H
#define BUDGET_H

// Budget Management module

void enterBudget(void);
void enterExpenditure(void);
void displayBudgets(void);
void displayExceededDepartments(void);
void budgetMenu(void);

double calculateRemaining(double allocated, double expenditure);

// Helpers for the Reports module 
int    getBudgetCount(void);
double getTotalAllocated(void);
double getTotalExpenditure(void);

#endif
