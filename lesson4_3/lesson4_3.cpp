#include <stdio.h>

void buble_sort();

int main()
{
    buble_sort();
    return 0;
}

void buble_sort()
{
    int mas[100];
    int n;
    printf("Введите необходимое количество элементов в массиве (не более 100): ");
    scanf("%i", &n);

    if (n<1)
    {
        printf("Количество элементов должно быть больше 0!\n");
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            printf("Значение массива %i: ", i);
            scanf("%i", &mas[i]);
        }
        for (int i = 0; i < n; i++)
        {
            printf("%4i", mas[i]);
        }
        printf("\n");

        bool fl = true;
        int ch = 0;
        while(fl)
        {
            fl = false;
            for (int i = 0; i < n-1; i++)
            {
                
                if(mas[i]>mas[i+1])
                {
                    int z = mas[i];
                    mas[i]= mas[i+1];
                    mas[i+1] = z;
                    fl = true;
                }
            }
            ch++;
        }
        
        for (int i = 0; i < n; i++)
        {
            printf("%4i", mas[i]);
        }
        printf("\nКоличество итераций: %i\n", ch);
    }
}