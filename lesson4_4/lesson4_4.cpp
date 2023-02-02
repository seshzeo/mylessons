#include <stdio.h>

int main()
{
    int mas[100];
    int n;

    printf("Введите необходимое для вас количество элементов в создаваемом массиве (не более 100): ");
    scanf("%i", &n);

    for(int i = 0; i < n; ++i)
    {
        printf("Значение массива %i: ", i);
        scanf("%i", &mas[i]);
    }

    int min, max;
    min=max=mas[0];
    int sum = 0;

    for(int i=0;i<n;++i)
    {
        if(mas[i]>max)
        {
            max=mas[i];
        }
        if(mas[i]<min)
        {
            min=mas[i];
        }
        sum+=mas[i];
    }
    float avrg=(float)sum/(float)n;

    printf("\nМинимальное значение: %i\nМаксимально значение: %i\nСумма значений массива: %i\nСреднее арифметическое всех значений: %f\n",min,max,sum,avrg);
    return 0;
}