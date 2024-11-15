#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100

typedef struct {
    int id;
    char firstName[50];
    char lastName[50];
    float salary;
    char designation[50];
    int experience; // in years
    int workingDays; // number of working days
    char address[100];
} Employee;

void scanEmployee(Employee *emp) {
    printf("Enter ID: ");
    scanf("%d", &emp->id);
    printf("Enter First Name: ");
    scanf("%s", emp->firstName);
    printf("Enter Last Name: ");
    scanf("%s", emp->lastName);
    printf("Enter Salary: ");
    scanf("%f", &emp->salary);
    printf("Enter Designation: ");
    scanf("%s", emp->designation);
    printf("Enter Experience (years): ");
    scanf("%d", &emp->experience);
    printf("Enter Working Days: ");
    scanf("%d", &emp->workingDays);
    printf("Enter Address: ");
    scanf(" %[^\n]", emp->address); // to read the full address including spaces
}

void displayEmployee(const Employee *emp) {
    printf("ID: %d, Name: %s %s, Salary: %.2f, Designation: %s, Experience: %d years, Working Days: %d, Address: %s\n",
           emp->id, emp->firstName, emp->lastName, emp->salary, emp->designation, emp->experience, emp->workingDays, emp->address);
}

void searchById(const Employee employees[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (employees[i].id == id) {
            displayEmployee(&employees[i]);
            return;
        }
    }
    printf("Employee with ID %d not found.\n", id);
}

void searchByLastName(const Employee employees[], int count, const char *lastName) {
    for (int i = 0; i < count; i++) {
        if (strcmp(employees[i].lastName, lastName) == 0) {
            displayEmployee(&employees[i]);
            return;
        }
    }
    printf("Employee with last name %s not found.\n", lastName);
}

void searchBySalaryRange(const Employee employees[], int count, float minSalary, float maxSalary) {
    for (int i = 0; i < count; i++) {
        if (employees[i].salary >= minSalary && employees[i].salary <= maxSalary) {
            displayEmployee(&employees[i]);
        }
    }
}

void updateLastName(Employee employees[], int count, int id, const char *newLastName) {
    for (int i = 0; i < count; i++) {
        if (employees[i].id == id) {
            strcpy(employees[i].lastName, newLastName);
            printf("Last name updated successfully.\n");
            return;
        }
    }
    printf("Employee with ID %d not found.\n", id);
}

int main() {
    Employee employees[MAX_EMPLOYEES];
    int count = 0;
    int choice, id;
    char lastName[50];
    float minSalary, maxSalary;

    while (1) {
        printf("\n1. Scan Employee Records\n2. Display All Employees\n3. Search by ID\n4. Search by Last Name\n5. Search by Salary Range\n6. Update Last Name\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (count < MAX_EMPLOYEES) {
                    scanEmployee(&employees[count]);
                    count++;
                } else {
                    printf("Employee list is full.\n");
                }
                break;
            case 2:
                for (int i = 0; i < count; i++) {
                    displayEmployee(&employees[i]);
                }
                break;
            case 3:
                printf("Enter ID to search: ");
                scanf("%d", &id);
                searchById(employees, count, id);
                break;
            case 4:
                printf("Enter last name to search: ");
                scanf("%s", lastName);
                searchByLastName(employees, count, lastName);
                break;
            case 5:
                printf("Enter minimum salary: ");
                scanf("%f", &minSalary);
                printf("Enter maximum salary: ");
                scanf("%f", &maxSalary);
                searchBySalaryRange(employees, count, minSalary, maxSalary);
                break;
            case 6:
                printf("Enter ID to update: ");
                scanf("%d", &id);
                printf("Enter new last name: ");
                scanf("%s", lastName);
                updateLastName(employees, count, id, lastName);
                break;
            case 7:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

