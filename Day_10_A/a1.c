/* DESCRIPTION : Program to find the number can be expressed as the sum of two prime number
Date : 7-11-2024
Name : Nellore Bhanusree
*/

#include <stdio.h>
int is_prime(int n);
int primePairs(int n);

int main() 
{
    int n;
    printf("Enter a positive integer: ");
    scanf("%d",&n);
    primePairs(n);
    return 0;
}

  int is_prime(int n)
{
  {
    if (n<=1) 
        return 0;
  }
    for (int i=2; i*i<=n; i++)
  {
        if (n%i==0)
            return 0;
  }
    return 1;
}


int primePairs(int n)
{
    int sum=0;
    for (int i=2; i<=n/2; i++)
    {
        if (is_prime(i) && is_prime(n-i)) 
        {
            printf("%d=%d+%d\n",n,i,n-i);
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
