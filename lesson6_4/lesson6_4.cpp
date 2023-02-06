#include <stdio.h>
#include <string.h>

void task1();
void task2();
void task3();

int main()
{
    //task1();
    task2();

    return 0;
}

void task1()
{
    char str[100];
    int id_removed_ch = 0;

    printf("Введите строку: ");
    scanf("%s",&str); //нужно ли ставить амперсанl после str?

    for (int i = id_removed_ch; i < strlen(str); i++)
    {
        str[i] = str[i+1];
    }
    printf("Результат удаления: ");
    puts(str);
}

void task2()
{
    char str[100];
    char str_buf[100];

    printf("Введите строку: ");
    scanf("%s",&str);

    int j = 0;
    for (int i = strlen(str)-1; i >= 0; i--)
    {
        str_buf[j] = str[i];
        j++;
    }
    puts(str_buf);
}