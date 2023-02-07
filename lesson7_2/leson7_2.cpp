#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void array_filling(int[],int n);

int main()
{
    srand(time(NULL));
    int arr1[100];
    int arr2[100];
    int arr1size = rand()%10+1;
    int arr2size = rand()%10+1;

    array_filling(arr1,arr1size);
    array_filling(arr2,arr2size);

    return 0;
}

void array_filling(int arr[],int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i]= rand()%20;
    }
    
    for (int i = 0; i < n; i++)
    {
        printf("%2i ",arr[i]);
    }
    printf("\n");
}