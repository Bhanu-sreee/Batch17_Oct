                    Function Pointer assignments

Mandatory

1. WAP to invoke functions below based on user input character using function pointer. Character mapping and respective functions to be invoked are given below.

Character input Function

+ int add(int x, int y)

- int sub(int x, int y)

* int multiply(int x, int y)

/ int divide(int x, int y)


#include <stdio.h>

// Function declarations
int add(int x, int y) { return x + y; }
int sub(int x, int y) { return x - y; }
int multiply(int x, int y) { return x * y; }
int divide(int x, int y) { return y != 0 ? x / y : 0; } // Avoid divide by zero

// Main function
int main() {
    char input;
    int x, y, result = 0;

    printf("Enter operation (+, -, *, /): ");
    scanf(" %c", &input);
    printf("Enter two integers: ");
    scanf("%d %d", &x, &y);

    // Define function pointer
    int (*operation)(int, int) = NULL;

    // Map input to corresponding function
    switch (input) {
        case '+': operation = add; break;
        case '-': operation = sub; break;
        case '*': operation = multiply; break;
        case '/': operation = divide; break;
        default:
            printf("Invalid operation!\n");
            return 1;
    }

    // Invoke function using the pointer
    result = operation(x, y);
    printf("Result: %d\n", result);

    return 0;
}







-----------------------------------------------------------------------------------------------------------------------


2. Extend Q1 to include a function below which will return the address of a function based on input character.

<address of function> getaddr(char mychar);

#include <stdio.h> // Required for printf and scanf
#include <stdlib.h> // Required for NULL

// Function definitions
int add(int x, int y) { return x + y; }
int sub(int x, int y) { return x - y; }
int multiply(int x, int y) { return x * y; }
int divide(int x, int y) { return y != 0 ? x / y : 0; } // Avoid divide by zero

// Function to return function pointer based on input character
int (*getaddr(char mychar))(int, int) {
    switch (mychar) {
        case '+': return add;
        case '-': return sub;
        case '*': return multiply;
        case '/': return divide;
        default: return NULL;
    }
}

// Main function
int main() {
    char input;
    int x, y, result = 0;
    int (*operation)(int, int) = NULL;

    printf("Enter operation (+, -, *, /): ");
    scanf(" %c", &input);
    printf("Enter two integers: ");
    scanf("%d %d", &x, &y);

    // Get function pointer
    operation = getaddr(input);
    if (operation == NULL) {
        printf("Invalid operation!\n");
        return 1;
    }

    // Invoke function using the pointer
    result = operation(x, y);
    printf("Result: %d\n", result);

    return 0;
}


-------------------------------------------------------------------------------------------------


3. Extend Q1 to include a function below which takes a function pointer to a calculator function and one integer (value = 10) as arguments and shall invoke the given function with required arguments. For the second argument read input from user. Return the result.

int invokefunc(<function pointer as argument1>, int val1);



#include <stdio.h>

// Function definitions
int add(int x, int y) { return x + y; }
int sub(int x, int y) { return x - y; }
int multiply(int x, int y) { return x * y; }
int divide(int x, int y) { return y != 0 ? x / y : 0; } // Avoid divide by zero

// Function to invoke any function pointer
int invokefunc(int (*func)(int, int), int val1) {
    int val2;
    printf("Enter the second integer: ");
    scanf("%d", &val2);
    return func(val1, val2);
}

// Main function
int main() {
    char operation;
    int val1 = 10, result = 0;
    int (*func_ptr)(int, int) = NULL;

    printf("Enter operation (+, -, *, /): ");
    scanf(" %c", &operation);

    // Assign the appropriate function pointer
    switch (operation) {
        case '+': func_ptr = add; break;
        case '-': func_ptr = sub; break;
        case '*': func_ptr = multiply; break;
        case '/': func_ptr = divide; break;
        default:
            printf("Invalid operation!\n");
            return 1;
    }

    // Invoke the function and display the result
    result = invokefunc(func_ptr, val1);
    printf("Result: %d\n", result);

    return 0;
}


---------------------------------------------------------------------------------------------------------


4. Extend Q1 to define an array of function pointers and invoke them based user input character.


#include <stdio.h>

// Function definitions
int add(int x, int y) { return x + y; }
int sub(int x, int y) { return x - y; }
int multiply(int x, int y) { return x * y; }
int divide(int x, int y) { return y != 0 ? x / y : 0; } // Avoid divide by zero

// Main function
int main() {
    char operation;
    int x, y, result = 0;
    
    // Array of function pointers
    int (*func_ptrs[4])(int, int) = {add, sub, multiply, divide};

    printf("Enter operation (+, -, *, /): ");
    scanf(" %c", &operation);
    printf("Enter two integers: ");
    scanf("%d %d", &x, &y);

    // Select function based on operation
    switch (operation) {
        case '+': result = func_ptrs[0](x, y); break;
        case '-': result = func_ptrs[1](x, y); break;
        case '*': result = func_ptrs[2](x, y); break;
        case '/': result = func_ptrs[3](x, y); break;
        default:
            printf("Invalid operation!\n");
            return 1;
    }

    // Display the result
    printf("Result: %d\n", result);

    return 0;
}
