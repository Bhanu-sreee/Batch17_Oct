1D, 2D, Multidimensional Array Assignments


1D Array :

1. Refer the code snippet and answer the queries:

int main()

{

int array[100];

int *ptr;

// do something

}

1: Can pointer be used in Array-style syntax?
 A: Yes, pointers can be used in array-style syntax, e.g., ptr[10] and ptr[0] are valid.

2: Can Array be used in Pointer-style syntax? 
a: Yes, arrays can be used in pointer-style syntax, e.g., *array, *(array + 0), and *(array + 10) are valid.

3: Is ptr++ valid? 
a: Yes, ptr++ is valid as long as ptr is not pointing to read-only memory.

4: Is array++ valid? 
a: No, array++ is not valid because the name of the array is a constant pointer and cannot be incremented.

5: What is sizeof(array)?
a: sizeof(array) is 400 bytes (size of 100 integers, assuming sizeof(int) = 4).

6: What is sizeof(ptr)?
a: sizeof(ptr) is the size of a pointer, typically 8 bytes on a 64-bit system.


2. Refer the code snippet below. Comment on the other elements (other than those that are explicitly initialized) of all array variables in code snippet below.

#define MAX 100

int main()

{

int arr[MAX] = {11,22,33};

int arr1[MAX]={0};

static int arr2[MAX];

}

· arr: Elements other than explicitly initialized ones are set to 0.

· arr1: All elements are explicitly initialized to 0.

· arr2: Being a static array, all elements are initialized to 0 by default.
#include <stdio.h>

#define MAX 100

int main() {
    int arr[MAX] = {11, 22, 33}; // Elements arr[3] to arr[MAX-1] are set to 0
    int arr1[MAX] = {0};         // All elements arr1[0] to arr1[MAX-1] are set to 0
    static int arr2[MAX];        // All elements arr2[0] to arr2[MAX-1] are set to 0 by default

    return 0;
}
-----------------------------------------------------------------------------------------------------------


3. Refer the program “array_pointer.c”. Add a function getmax() to find the maximum in the array and call in main() and display the result.
#include <stdio.h>

// Function to find the maximum value in an array
int getmax(int *arr, int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int array[] = {10, 20, 30, 40, 50};
    int size = sizeof(array) / sizeof(array[0]);

    // Call the getmax function and store the result
    int max_value = getmax(array, size);

    // Display the result
    printf("The maximum value in the array is: %d\n", max_value);

    return 0;
}

---------------------------------------------------------------------------------------------------------------------------------------------------------
4. Extend the code given below to read N and a start value from the user to perform the given operations.

#define MAX 100

int main()

{

int arr[MAX] = {11,22,33};

}

Add the following functions choosing proper input, output and return.

a. init() - Use the inputs to initialize the first N elements of the array with N consequetive values starting with given start value .

b. update() – increment value of every element in the array

c. display() – display the contents of array

#include <stdio.h>

#define MAX 100

void init(int arr[], int N, int start)
{
    for (int i = 0; i < N; i++)
        arr[i] = start + i;
}

void update(int arr[], int N)
{
    for (int i = 0; i < N; i++)
        arr[i]++;
}

void display(int arr[], int N)
{
    for (int i = 0; i < N; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[MAX] = {0};
    int N, start;

    printf("Enter number of elements (N): ");
    scanf("%d", &N);
    printf("Enter start value: ");
    scanf("%d", &start);

    init(arr, N, start);
    printf("Array after init: ");
    display(arr, N);

    update(arr, N);
    printf("Array after update: ");
    display(arr, N);

    return 0;
}
----------------------------------------------------------------------------------------







4. Extend the code given below to read N and a start value from the user to perform the given operations.

#define MAX 100

int main()

{

int arr[MAX] = {11,22,33};

}

Add the following functions choosing proper input, output and return.

a. init() - Use the inputs to initialize the first N elements of the array with N consequetive values starting with given start value .

b. update() – increment value of every element in the array

c. display() – display the contents of array.

#include <stdio.h>
#include <string.h>

void sort(char arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                char temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    char arr[] = "xaybz";
    int size = strlen(arr);

    sort(arr, size);

    printf("Sorted array: %s\n", arr);

    return 0;
}


--------------------------------------------------------------------------------------



2. Refer the code snippet below.

int main()

{

char arr[][3] = {

sort(arr, sizeof(arr)/sizeof(arr[0]);

return 0;

}

Allow user to perform the following operations.

a. init() - initialize the array and return 0

b. search_update() – search for a given element in array and
if found update it to given value and return 0 else return 1

c. display() – traverse and display array contents

For the functions, pass array and other required arguments to 
functions and return as per requirement


	#include <stdio.h>

#define ROWS 3
#define COLS 3

void init(char arr[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            arr[i][j] = 'A' + i * COLS + j; // Example initialization
}

int search_update(char arr[ROWS][COLS], char search, char update)
{
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
        {
            if (arr[i][j] == search)
            {
                arr[i][j] = update;
                return 0; // Success
            }
        }
    return 1; // Failure
}

void display(char arr[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
            printf("%c ", arr[i][j]);
        printf("\n");
    }
}

int main()
{
    char arr[ROWS][COLS];
    init(arr);

    printf("Array after initialization:\n");
    display(arr);

    char search = 'C', update = 'Z';
    if (search_update(arr, search, update) == 0)
        printf("\nArray after updating '%c' to '%c':\n", search, update);
    else
        printf("\nCharacter '%c' not found.\n", search);

    display(arr);

    return 0;
}



































