#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int arr[100][100];
    int x,y;
    
    srand(time(NULL));
    printf("Введите количество строк массива: ");
    scanf("%i", &x);
    printf("Введите количество столбцов массива: ");
    scanf("%i", &y);
    if (x<1||y<1)
    {
        printf("Количество строк и столбцов должно быть больше нуля!\n");
    }
    else
    {
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                arr[i][j] = rand()%10+(-2);
            }
        }
        printf("\n");
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                printf("%3i ",arr[i][j]);
            }
            printf("\n\n");
        }
        printf("\n");
    }
    return 0;
}