/*
    Name : Vinayak Santosh Koshti
    Date : 11/07/2021

1.a) Write a C program to take ‘N’ no of integers from the user and arrange
 in ascending and descending order.
 (Note: create separate files (.c files) for both functions)
*/

#include<stdio.h>
#include"sort.h"

int main()
{
    int num,i;
    int arr[100];
 
    printf("Enter how many elements want to enter ? ");
    scanf("%d",&num);
    printf("Enter %d elements to sort ",num);
    for(i=0;i<num;i++)
    {
        scanf("%d",&arr[i]);
    }
    ascending(arr,num);
    printf("\nAscending oreder : ");
    for(i=0;i<num;i++)
    {
        printf("%d ",arr[i]);
    }

    descending(arr,num);
    printf("\nDescending order : ");
    for(i=0;i<num;i++)
    {
        printf("%d ",arr[i]);
    }

    printf("\n");
    return  0;
    
}