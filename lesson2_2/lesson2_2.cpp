#include <stdio.h>

int main()
{
    int a, b;

    printf("Программа для сравнения двух чисел \nВведите число, которое нужно сравнить:");
    scanf("%i", &a);
    printf("С каким числом нужно сравнить:");
    scanf("%i", &b);

    if (a>b)
    {
        printf("Больше\n");
    }
    else
    {
        if (a<b)
        {
            printf("Меньше\n");
        }
        else
        {
            if (a==b)
            {
                printf("Равно\n");
            }
            else
            {
                printf("Ошибка\n");
            }
        }
    }
    return 0;
   
}
/* делаю все как в видеоуроке. но поизучав синтаксис думаю, что лучше было бы использовать
оператор switch. Также не хватает проверки ввода корректной информации пользователем.*/