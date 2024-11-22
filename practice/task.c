#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char lName[50];
    float salary;
} Employee;

void scanEmployee(Employee* emp, int n)
{
    for (int i = 0; i < n; i++)
	{
        printf("Enter details for employee %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &emp[i].id);
        printf("Last Name: ");
        scanf("%s", emp[i].lName);
        printf("Salary: ");
        scanf("%f", &emp[i].salary);
    }
}

void displayEmployees(Employee* emp, int n)
{
    for (int i = 0; i < n; i++)
	{
        printf("Employee %d:\n", i + 1);
        printf("ID: %d\n", emp[i].id);
        printf("Last Name: %s\n", emp[i].lName);
        printf("Salary: %.2f\n", emp[i].salary);
    }
}

void searchById(Employee* emp, int n, int id)
{
    for (int i = 0; i < n; i++)
	{
        if (emp[i].id == id) 
		{
            printf("Employee found:\n");
            printf("ID: %d\n", emp[i].id);
            printf("Last Name: %s\n", emp[i].lName);
            printf("Salary: %.2f\n", emp[i].salary);
            return;
        }
    }
    printf("Employee with ID %d not found.\n", id);
}

void searchByLastName(Employee* emp, int n, const char* lName)
{
    for (int i = 0; i < n; i++)
	{
        if (strcmp(emp[i].lName, lName) == 0)
		{
            printf("Employee found:\n");
            printf("ID: %d\n", emp[i].id);
            printf("Last Name: %s\n", emp[i].lName);
            printf("Salary: %.2f\n", emp[i].salary);
            return;
        }
    }
    printf("Employee with last name %s not found.\n", lName);
}

void searchBySalaryRange(Employee* emp, int n, float minSalary, float maxSalary)
{
    int found = 0;
    for (int i = 0; i < n; i++)
	{
        if (emp[i].salary >= minSalary && emp[i].salary <= maxSalary) {
            if (!found)
			{
                printf("Employees with salary between %.2f and %.2f:\n", minSalary, maxSalary);
                found = 1;
            }
            printf("ID: %d\n", emp[i].id);
            printf("Last Name: %s\n", emp[i].lName);
            printf("Salary: %.2f\n", emp[i].salary);
        }
    }
    if (!found)
	{
        printf("No employees found with salary between %.2f and %.2f.\n", minSalary, maxSalary);
    }
}

void updateLastName(Employee* emp, int n, int id, const char* newLastName)
{
    for (int i = 0; i < n; i++)
	{
        if (emp[i].id == id)
		{
            strcpy(emp[i].lName, newLastName);
            printf("Employee's last name updated successfully.\n");
            return;
        }
    }
    printf("Employee with ID %d not found.\n", id);
}

int main()
{
    int n;
    printf("Enter the number of employees: ");
    scanf("%d", &n);

    Employee* employees = (Employee*)malloc(n * sizeof(Employee));

    scanEmployee(employees, n);
    displayEmployees(employees, n);

    int searchId;
    printf("Enter ID to search: ");
    scanf("%d", &searchId);
    searchById(employees, n, searchId);

    char searchLName[50];
    printf("Enter last name to search: ");
    scanf("%s", searchLName);
    searchByLastName(employees, n, searchLName);

    float minSalary = 6000, maxSalary = 10000;
    searchBySalaryRange(employees, n, minSalary, maxSalary);

    int updateId;
    char newLastName[50];
    printf("Enter ID to update last name: ");
    scanf("%d", &updateId);
    printf("Enter new last name: ");
    scanf("%s", newLastName);
    updateLastName(employees, n, updateId, newLastName);
	printf("\nUpdated Employee Records:\n");

    free(employees);
    return 0;
}

