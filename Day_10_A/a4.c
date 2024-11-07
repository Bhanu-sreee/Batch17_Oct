/* DESCRIPTION : program to rotate array every kth element
Date : 7-11-2024
Name : NELLORE BHANU SREE
*/

#include <stdio.h>


void reverse(int arr[], int start, int end)
{
    while (start < end) 
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}


void rotate_k(int arr[], int n, int k) 
{
    for (int i = 0; i < n; i += k) 
    {
        int end = (i + k - 1 < n) ? i + k - 1 : n - 1;
        reverse(arr, i, end);
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    rotate_k(arr, n, k);

    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
