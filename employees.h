#ifndef EMPLOYEES_H
#define EMPLOYEES_H

float calculateSalary(float basic, float housing, float transport);

void addEmployee(void);
void displayEmployees(void);
int searchEmployee(int id, int ids[], int size);
void searchEmployeeByName(void); 
void employeeMenu(void);

#endif