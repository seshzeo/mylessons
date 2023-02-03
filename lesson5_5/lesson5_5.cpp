#include <stdio.h>

int main()
{
    int arr[100][100];
    int x,y;

    printf("Введите количество строк: ");
    scanf("%i",&x);
    printf("Введите количество столбцов: ");
    scanf("%i",&y);

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            printf("Значение элемента [%i][%i]: ",i,j);
            scanf("%i", &arr[i][j]);
        }
    }
    printf("\n");

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            printf("%5i ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    int n = 1;
    for (int i = 0; i < x*y; i++)
    {
        for (int j = n; j < y; j++)
        {
            if(arr[i][j]!=arr[j][i])
            {
            int q = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = q;
            }
        }
        n++;
    }

    printf("\n");
    
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            printf("%5i ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\nОбщее количество итераций: %i", n );

    return 0;
}