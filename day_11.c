/*
structures
*/
#include<stdio.h>
#include<string.h>

struct Employee

{
	char Name[20];
	char surname[20];
	char Gender;
	char Address[20];
	int id;
	char designation[50];
	long float Salary;
	int experience;
	
};
void dispDetails(emp [],int);

void scanEmployee(Employee *emp)
{
    printf("Enter id: ");
    scanf("%d", &emp->);
	printf("Name ");
	scanf("%c", emp->Name);
    printf("Enter surname:  ");
    scanf("%s", emp->surname);
    printf("Enter Gender:  ");
    scanf("%s", emp->Gender);
    printf("Enter Address:  ");
    scanf("%f", &emp->Address); 
    printf("Enter designation: ");
	scanf("%s", emp->designation);
	printf("Enter salary: ");
	scanf("%lf",&emp->salary);
	printf("Enter Experience (years): ");
    scanf("%d", &emp->experience);

}
void displayEmployee(const Employee *emp)
{
    printf("id: %d, Name: %s %s, Salary: %.2f\n", emp->id, emp->Name, emp->surnameName, emp->salary, emp->experience);
}
void searchById(const Employee employees[], int count, int id)
{
    for (int i = 0; i < count; i++)
	{
        if (employees[i].id == id)
		{
            displayEmployee(&employees[i]);
            return;
        }
    }
printf("Employee with id %d not found.\n", id);
}

void searchBysurname(const Employee employees[], int count, const char *surname)
{
    for (int i = 0; i < count; i++)
	{
        if (strcmp(employees[i].Name, lastName) == 0)
		{
            displayEmployee(&employees[i]);

            return;
        }
    }
	    printf("Employee with surname %s not found.\n", surname);
}

void searchBySalaryRange(const Employee employees[], int count, float minSalary, float maxSalary)
{
    for (int i = 0; i < count; i++)
	{
        if (employees[i].salary >= minSalary && employees[i].salary <= maxSalary)
		{
            displayEmployee(&employees[i]);
        }
    }
}

void updatesurname(Employee employees[], int count, int id, const char *newLastName)
{
    for (int i = 0; i < count; i++)
	{
        if (employees[i].id == id)
		{
            strcpy(employees[i].Name, newLastName);
            printf("Last name updated successfully.\n");
            return;
        }
    }
    printf("Employee with ID %d not found.\n", id);
}

void
