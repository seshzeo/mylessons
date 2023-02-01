#include <stdio.h>

void task_1_1();
void task_1_2();
void task_2();

int main()
{
    ///task_1_1(); //Выводит "Hello" 9 раз
    //task_1_2(); //Выводит i начиная с нуля 15 итераций цикла
    task_2(); //Выводит сумму чисел от 5 до 15 включительно
    
    return 0;
}

void task_1_1()
{
    for (int i = 0; i < 9; i++)
    {
        printf("Hello\n");
    }
}

void task_1_2()
{
    for (int i = 0; i < 15; i++)
    {
        printf("%i ", i);
    }
    printf("\n");
    for (int i = 1; i < 15; i+=2)
    {
        printf("%i ", i);
    }
    printf("\n");
}

void task_2()
{
    int sum;
    for (int i = 5; i <= 15; i++)
    {
        sum = sum + i;
    }
    printf("Cумма чисел от 5 до 15 равна %i\n", sum);

}