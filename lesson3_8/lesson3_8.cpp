#include <stdio.h>

int main()
{
    float n = 0, min=3.402823466E+38, max = 0, sum = 0, avrg = 0, val = 0;
    printf("Введите количество элементов, которые будете воодить по очереди: ");
    scanf("%f", &n);

    if(n < 1)
    {
        printf("Элементов должно быть больше одного\n");
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            printf("Введите значение: ");
            scanf("%f", &val);
            sum = sum + val;
            if(val < min)
                min = val;
            if(val > max)
                max = val;
        }
    avrg = sum/n;
    printf("Минимальное значение перечня элементов: %f\nМаксимальное значение: %f\nСумма значений: %f\nСреднее арифметическое: %f\n", min,max,sum,avrg); 
    }
    
    return 0;
}
