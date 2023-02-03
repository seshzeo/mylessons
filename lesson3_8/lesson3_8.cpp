#include <stdio.h>

int main()
{
    float n = 0, min = 0, max = 0, sum = 0, avrg = 0, val = 0;
    printf("Введите количество элементов, которые будете воодить по очереди: ");
    scanf("%f", &n);


    if(n < 1)
    {
        printf("Элементов должно быть больше одного\n");
    }
    else
    {
        printf("Введите значение: ");
        scanf("%f", &val);
        min = max = val;
        sum += val;
        for (int i = 1; i < n; i++)
        {
            
            printf("Введите значение: ");
            scanf("%f", &val);
            if(val < min)
                min = val;
            if(val > max)
                max = val;
            sum += val;
        }
    avrg = sum/n;
    printf("Минимальное значение перечня элементов: %f\nМаксимальное значение: %f\nСумма значений: %f\nСреднее арифметическое: %f\n", min,max,sum,avrg); 
    }
    
    return 0;
}
