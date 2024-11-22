#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold designation and experience details
typedef struct {
    char designation[50];
    int experience;  // in years
} Designation;

// Structure to hold employee data, including designation and experience
typedef struct {
    char emp_id[10];
    char first_name[30];
    char last_name[30];
    float salary;
    Designation designation_info;  // Embedded Designation structure
} Employee;

// Declare a pointer to Employee, which will be dynamically allocated
Employee *employees = NULL;
int total_employees = 0;

// Function to scan employee records
void scan_employees(int num_employees) {
    // Reallocate memory to accommodate new employees
    employees = realloc(employees, (total_employees + num_employees) * sizeof(Employee));

    if (employees == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    for (int i = total_employees; i < total_employees + num_employees; i++) {
        printf("Enter details for Employee %d:\n", i + 1);
        printf("Employee ID: ");
        scanf("%s", employees[i].emp_id);
        printf("First Name: ");
        scanf("%s", employees[i].first_name);
        printf("Last Name: ");
        scanf("%s", employees[i].last_name);
        printf("Salary: ");
        scanf("%f", &employees[i].salary);
        
        // Get designation and experience
        printf("Designation: ");
        scanf(" %[^\n]", employees[i].designation_info.designation);  // To allow spaces in designation
        printf("Experience (in years): ");
        scanf("%d", &employees[i].designation_info.experience);
    }

    // Update the total number of employees
    total_employees += num_employees;
}

// Function to display all employee records
void display_employees() {
    if (total_employees == 0) {
        printf("No employee records available.\n");
        return;
    }

    printf("\nEmployee Records:\n");
    for (int i = 0; i < total_employees; i++) {
        printf("ID: %s", employees[i].emp_id);
		printf("Name: %s %s", employees[i].first_name);
		printf("Salary: %.2f",employees[i].salary);
		printf("Designation: %s",  employees[i].designation_info.designation);
		printf("Experience:%d",employee[i].designation_info.experience);
		: %d years\n",
               employees[i].emp_id, employees[i].first_name, employees[i].last_name, 
               employees[i].salary, employees[i].designation_info.designation, 
               employees[i].designation_info.experience);
    }
}

// Function to search employee by ID
void search_by_id(const char* emp_id) {
    for (int i = 0; i < total_employees; i++) {
        if (strcmp(employees[i].emp_id, emp_id) == 0) {
            printf("Found Employee - ID: %s, Name: %s %s, Salary: %.2f, Designation: %s, Experience: %d years\n", 
                   employees[i].emp_id, employees[i].first_name, employees[i].last_name, 
                   employees[i].salary, employees[i].designation_info.designation, 
                   employees[i].designation_info.experience);
            return;
        }
    }
    printf("No employee found with ID: %s\n", emp_id);
}

// Function to search employee by last name
void search_by_last_name(const char* last_name) {
    int found = 0;
    for (int i = 0; i < total_employees; i++) {
        if (strcasecmp(employees[i].last_name, last_name) == 0) {
            printf("Found Employee - ID: %s, Name: %s %s, Salary: %.2f, Designation: %s, Experience: %d years\n", 
                   employees[i].emp_id, employees[i].first_name, employees[i].last_name, 
                   employees[i].salary, employees[i].designation_info.designation, 
                   employees[i].designation_info.experience);
            found = 1;
        }
    }
    if (!found) {
        printf("No employee found with last name: %s\n", last_name);
    }
}

// Function to search employees within salary range 6K to 10K
void search_salary_range() {
    int found = 0;
    for (int i = 0; i < total_employees; i++) {
        if (employees[i].salary >= 6000 && employees[i].salary <= 10000) {
            printf("Employee within salary range - ID: %s, Name: %s %s, Salary: %.2f, Designation: %s, Experience: %d years\n", 
                   employees[i].emp_id, employees[i].first_name, employees[i].last_name, 
                   employees[i].salary, employees[i].designation_info.designation, 
                   employees[i].designation_info.experience);
            found = 1;
        }
    }
    if (!found) {
        printf("No employees found with salary between 6000 and 10000\n");
    }
}

// Function to update an employee's last name
void update_last_name(const char* emp_id, const char* new_last_name) {
    for (int i = 0; i < total_employees; i++) {
        if (strcmp(employees[i].emp_id, emp_id) == 0) {
            strcpy(employees[i].last_name, new_last_name);
            printf("Employee ID: %s's last name updated to %s\n", employees[i].emp_id, new_last_name);
            return;
        }
    }
    printf("No employee found with ID: %s\n", emp_id);
}

// Main function to interact with the user
int main() {
    int choice;
    char emp_id[10], last_name[30], new_last_name[30];
    
    while (1) {
        printf("\nEmployee Management System\n");
        printf("1. Scan Employee Records\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee by ID\n");
        printf("4. Search Employee by Last Name\n");
        printf("5. Search Employees with Salary between 6K and 10K\n");
        printf("6. Update Employee's Last Name\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                {
                    int num_employees;
                    printf("How many employees do you want to enter? ");
                    scanf("%d", &num_employees);
                    scan_employees(num_employees);
                }
                break;
            case 2:
                display_employees();
                break;
            case 3:
                printf("Enter Employee ID to search: ");
                scanf("%s", emp_id);
                search_by_id(emp_id);
                break;
            case 4:
                printf("Enter Employee Last Name to search: ");
                scanf("%s", last_name);
                search_by_last_name(last_name);
                break;
            case 5:
                search_salary_range();
                break;
            case 6:
                printf("Enter Employee ID to update: ");
                scanf("%s", emp_id);
                printf("Enter new Last Name: ");
                scanf("%s", new_last_name);
                update_last_name(emp_id, new_last_name);
                break;
            case 7:
                printf("Exiting Employee Management System.\n");
                free(employees);  // Free dynamically allocated memory
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

