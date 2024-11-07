#include <stdio.h>
// Function to check  prime number
int is_prime(int n)
{
    if (n<=1); 
       
    for (int i=2; i*i<=n; i++)
    {
        if (n%i==0)
        return 0;
    }
    return 1;
}

// Function for prime numbers sum
int pairs(int num)
{
    int sum=0;
    for (int i=2; i<=num/2; i++) 
    {
        if (is_prime(i) && is_prime(num-i)) 
        {
            printf("%d=%d+%d\n",num,i,num-i);
            sum++;
        }
    }
    if (sum>0) 
    {
        printf("No of Ways = %d\n",sum);
    } 
    else 
    {
        printf("No of Ways = -1\n");
    }
}

int main() 
{
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    pairs(num);
    return 0;
}