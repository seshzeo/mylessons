#include <stdio.h>

void task_1();
void task_2();

int main()
{
    //task_1(); //ручное заполнение массива из 7 значений
    task_2(); //ручное заполнение массива из любого количества значений(до 100)
    return 0;
}

void task_1()
{
    int mas[7];
    printf("Заполните в массиве элементами по порядку: \n");

    for (int i = 0; i < 7; ++i)
    {
        printf("Значение массива %i: ", i);
        scanf("%2i", &mas[i]);
    }
    printf("Массив: ");
    for (int i = 0; i < 7; ++i)
    {
        printf("%2i", mas[i]);
    }
    printf("\n");
}

void task_2()
{
    int n;
    int mas[100];
    printf("Введите количество элементов в массиве (max 100): ");
    scanf("%i", &n);

    for (int i = 0; i < n; ++i)
    {
        printf("Значение массива %i: ", i);
        scanf("%2i", &mas[i]);
    }
    printf("\n");
    for (int i = 0; i < n; ++i)
    {
        printf("%2i", mas[i]);
    }
    printf("\n");
}