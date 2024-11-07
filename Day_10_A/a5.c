/* DESCRIPTION :  program to print alphabet triangle.
Date : 7-11-2024
Name : Bhanu sree
*/

#include <stdio.h>


void printAlphabetTriangle(int n)
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            printf(" ");
        }
       
        for (int j = 0; j <= i; j++) 
        {
            printf("%c", 'A' + j);
        }
        
        for (int j = i - 1; j >= 0; j--) 
        {
            printf("%c", 'A' + j);
        }
        printf("\n");
    }
}


void numTriangle(int n) 
{
    for (int i = 1; i <= n; i++) 
    {
        printf("%*c", n - i + 1, ' '); 
        for (int j = 1; j <= i; j++) 
        {
            printf("%d", j);
        }
        for (int j = i - 1; j >= 1; j--) {
            printf("%d", j);
        }

        printf("\n");  
    }
}

int main()
{
    int n;
    printf("Enter the number of rows: ");
    scanf("%d", &n);

    printf("\nAlphabet Triangle:");
    printAlphabetTriangle(n);

    printf("\nNumber Triangle:");
    numTriangle(n);
   

    return 0;
}