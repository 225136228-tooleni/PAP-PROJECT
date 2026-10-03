#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "budget.h"

#define MAX_DEPTS   30
#define DEPT_LEN    40
#define LINE_LEN    100

typedef struct {
    char   department[DEPT_LEN];
    double allocated;
    double expenditure;
} Budget;

static Budget budgets[MAX_DEPTS];
static int    budgetCount = 0;

/* ---------- Input helpers ---------- */

static void readLine(const char *prompt, char *buf, int size)
{
    int len, c;

    printf("%s", prompt);
    if (fgets(buf, size, stdin) == NULL) {
        buf[0] = '\0';
        return;
    }
    len = (int)strlen(buf);
    if (len > 0 && buf[len - 1] == '\n') {
        buf[len - 1] = '\0';
    } else {
        while ((c = getchar()) != '\n' && c != EOF)
            ;
    }
}

static void readNonEmpty(const char *prompt, char *buf, int size)
{
    do {
        readLine(prompt, buf, size);
        if (strlen(buf) == 0)
            printf("  Error: this field cannot be empty.\n");
    } while (strlen(buf) == 0);
}

/* Reads a number greater than zero (negative / invalid rejected) */
static double readPositiveDouble(const char *prompt)
{
    char line[LINE_LEN];
    char *end;
    double value;

    while (1) {
        readLine(prompt, line, sizeof(line));
        value = strtod(line, &end);
        if (end == line || *end != '\0')
            printf("  Error: please enter a valid number.\n");
        else if (value <= 0)
            printf("  Error: the amount must be greater than zero.\n");
        else
            return value;
    }
}

static int readIntInRange(const char *prompt, int min, int max)
{
    char line[LINE_LEN];
    char *end;
    long value;

    while (1) {
        readLine(prompt, line, sizeof(line));
        value = strtol(line, &end, 10);
        if (end == line || *end != '\0')
            printf("  Error: please enter a whole number.\n");
        else if (value < min || value > max)
            printf("  Error: choose a number from %d to %d.\n", min, max);
        else
            return (int)value;
    }
}

/* Case-insensitive comparison; returns 1 if equal, 0 otherwise */
static int sameText(const char *a, const char *b)
{
    while (*a != '\0' && *b != '\0') {
        if (tolower((unsigned char)*a) != tolower((unsigned char)*b))
            return 0;
        a++;
        b++;
    }
    return (*a == '\0' && *b == '\0');
}

/* Returns index of department, or -1 if not found */
static int findDepartment(const char *name)
{
    int i;
    for (i = 0; i < budgetCount; i++) {
        if (sameText(budgets[i].department, name))
            return i;
    }
    return -1;
}

static const char *getStatus(double allocated, double expenditure)
{
    if (expenditure > allocated)
        return "OVER BUDGET";
    return "WITHIN BUDGET";
}

static void printBudgetDetails(const Budget *b)
{
    printf("\nDepartment       : %s\n", b->department);
    printf("Allocated Budget : N$%.2f\n", b->allocated);
    printf("Expenditure      : N$%.2f\n", b->expenditure);
    printf("Remaining Budget : N$%.2f\n",
           calculateRemaining(b->allocated, b->expenditure));
    printf("Status           : %s\n", getStatus(b->allocated, b->expenditure));
}

/* ---------- Public functions ---------- */

double calculateRemaining(double allocated, double expenditure)
{
    return allocated - expenditure;
}

void enterBudget(void)
{
    Budget b;

    printf("\n--- ENTER DEPARTMENTAL BUDGET ---\n");

    if (budgetCount >= MAX_DEPTS) {
        printf("Maximum number of departments (%d) reached.\n", MAX_DEPTS);
        return;
    }

    while (1) {
        readNonEmpty("Department name: ", b.department, sizeof(b.department));
        if (findDepartment(b.department) != -1)
            printf("  Error: this department already has a budget.\n");
        else
            break;
    }

    b.allocated = readPositiveDouble("Allocated budget (N$): ");
    b.expenditure = 0.0;

    budgets[budgetCount] = b;
    budgetCount++;
    printf("\nBudget for '%s' saved.\n", b.department);
}

void enterExpenditure(void)
{
    char name[DEPT_LEN];
    int index;
    double amount;

    printf("\n--- ENTER EXPENDITURE ---\n");
    if (budgetCount == 0) {
        printf("No departmental budgets entered yet.\n");
        return;
    }

    readNonEmpty("Department name: ", name, sizeof(name));
    index = findDepartment(name);
    if (index == -1) {
        printf("Department not found.\n");
        return;
    }

    amount = readPositiveDouble("Expenditure amount (N$): ");
    budgets[index].expenditure += amount;

    printBudgetDetails(&budgets[index]);
    if (budgets[index].expenditure > budgets[index].allocated)
        printf("\nWARNING: this department has exceeded its budget!\n");
}

void displayBudgets(void)
{
    int i;

    printf("\n--- BUDGET INFORMATION ---\n");
    if (budgetCount == 0) {
        printf("No departmental budgets entered yet.\n");
        return;
    }

    printf("\n%-18s %-14s %-14s %-14s %-14s\n",
           "Department", "Allocated", "Expenditure", "Remaining", "Status");
    printf("-------------------------------------------------------------"
           "------------------\n");
    for (i = 0; i < budgetCount; i++) {
        printf("%-18s %-14.2f %-14.2f %-14.2f %-14s\n",
               budgets[i].department,
               budgets[i].allocated,
               budgets[i].expenditure,
               calculateRemaining(budgets[i].allocated, budgets[i].expenditure),
               getStatus(budgets[i].allocated, budgets[i].expenditure));
    }
}

void displayExceededDepartments(void)
{
    int i, found = 0;

    printf("\n--- DEPARTMENTS OVER BUDGET ---\n");
    for (i = 0; i < budgetCount; i++) {
        if (budgets[i].expenditure > budgets[i].allocated) {
            printf("%-18s over by N$%.2f\n", budgets[i].department,
                   budgets[i].expenditure - budgets[i].allocated);
            found++;
        }
    }
    if (found == 0)
        printf("No department has exceeded its budget.\n");
}

void budgetMenu(void)
{
    int choice;

    do {
        printf("\n========================================\n");
        printf("           BUDGET MANAGEMENT\n");
        printf("========================================\n");
        printf("1. Enter departmental budget\n");
        printf("2. Enter expenditure\n");
        printf("3. Display budget information\n");
        printf("4. Show departments over budget\n");
        printf("5. Back to main menu\n");
        choice = readIntInRange("Enter your choice: ", 1, 5);

        switch (choice) {
            case 1: enterBudget();                break;
            case 2: enterExpenditure();           break;
            case 3: displayBudgets();             break;
            case 4: displayExceededDepartments(); break;
            case 5: printf("Returning to main menu...\n"); break;
        }
    } while (choice != 5);
}

int getBudgetCount(void)
{
    return budgetCount;
}

double getTotalAllocated(void)
{
    double total = 0.0;
    int i;
    for (i = 0; i < budgetCount; i++)
        total += budgets[i].allocated;
    return total;
}

double getTotalExpenditure(void)
{
    double total = 0.0;
    int i;
    for (i = 0; i < budgetCount; i++)
        total += budgets[i].expenditure;
    return total;
}
