/* 
DESCRIPTION : Program to perform type casting and conversions
Date : 19-11-2024
Name : Nellore Bhanu sree
*/

#include <stdio.h>
#include <stdbool.h>

int main()
{
    int i = 123;
    short s = 98;
    bool b = true;
    char c = 'Y';
    float d = 235.789;

    // Perform the operations and display the results
    printf("b + c = %d\n", b + c);         // 'b' is converted to int, result is int
    printf("s * i = %d\n", s * i);         // 's' is converted to int, result is int
    printf("c * d = %.2f\n", c * d);       // 'c' is converted to float, result is float
    c = c + b;                             // Adding 'bool' to 'char'
    printf("New value of c = %c\n", c);    // Display updated 'c' as char
    d = d + c;                             // Adding 'char' to 'float'
    printf("New value of d = %.2f\n", d);  // Display updated 'd' as float
    b = -d;                                // Assigning negative float to bool
    printf("New value of b = %d\n", b);    // Display 'b' as int (0 or 1)

    return 0;
}

