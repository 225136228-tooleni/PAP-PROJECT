# Municipal Financial Management System (MFMS) 

## Group Number


## Group Members
| Name | Student Number | Responsibility |
|------|---------------|----------------|
|1.Sarty Ndjendjela|226040453| Employee Management |
|2.Tweufiilwa J Vataleni     | 226157121 | Budget Management |
|3.Tooleni Simon|225136228| Supplier Management |
|4.Max K Gebhard | 226085783 | Asset Management |
|5.... | ... | Reports |
|6.Kambinda Posani|226080749| Functions & Integration |
|7.Ndasilwohenda N Nandiinotya | 224080881 | Input Validation & Documentation |

## Project Description
A menu-driven C application that manages municipal employees, budgets, suppliers, and assets, with reporting and input validation.

## System Features
- Employee Management (add, display, search, salary calculation)
- Budget Management (allocation, expenditure, remaining budget, over-budget detection)
- Supplier Management (add, display, search)
- Asset Management (add, display, search)
- Reports (employee, budget, supplier, asset)
- Input Validation (salary, budget, menu, general)

## Compilation Instructions

Requires **GCC** (MinGW-w64 on Windows, `gcc` on Linux/macOS).

```bash
gcc -std=c99 -Wall -Wextra -pedantic -o mfms main.c employees.c budget.c suppliers.c assets.c reports.c validation.c -lm
```

To build and run the validation tests:

```bash
gcc -std=c99 -Wall -Wextra -pedantic -o test_validation test_validation.c validation.c -lm
./test_validation
```

## How to Run

```bash
./mfms          # Linux / macOS
mfms.exe        # Windows
```

Type the number of a menu option and press **Enter**. Entering text, a number out of range, or an empty value shows an `[ERROR]` message and asks again.

## Individual Responsibilities

| Member | Responsibility | Files |
|--------|----------------|-------|
|1.Sarty Ndjendjela| Employee Management | `employees.c`, `employees.h` |
|2.Tweufiilwa J Vataleni| Budget Management | `budget.c`, `budget.h` |
|3.Tooleni Simon| Supplier Management | `suppliers.c`, `suppliers.h` |
|4.Max K Gebhard| Asset Management | `assets.c`, `assets.h` |
|5. | Reports | `reports.c`, `reports.h` |
|6.Kambinda Posani| Functions & integration | `main.c` |
|7.Ndasilwohenda Nandiinotya| Input validation (salary, budget, menu), error handling, README, technical report, GitHub repository management | `validation.c`, `validation.h`,  `README.md`, `GIT_WORKFLOW.md`,  |

