#include <stdio.h>
#include <string.h>
 
void task1();
void task2();
void task3();

int main()
{
    //task1();
    //task2();
    task3();

    return 0;
}

void task1()
{
    char str[100];

    printf("Введите слово:");
    scanf("%s",&str);
    if(strlen(str)<2)
    {
       printf("Нужно больше 1 символа\n"); 
    }
    else
    {
    printf("%c",str[1]);
    }
}

void task2()
{
    char str[100];

    printf("Введите строку: ");
    scanf("%s",&str);

    if(strlen(str)<2)
    {
        printf("В строке должно быть больше 2 символов");
    }
    else
    {
    printf("Последний символ строки: \"%c\"\n",str[strlen(str)-1]);

    char buf = str[1];
    str[1]= str[strlen(str)-1];
    str[strlen(str)-1] = buf;

    printf("Слово после замены символов: ");
    puts(str);
    }
}

void task3()
{
    char str[100];
    int id_removed_ch;
    
    printf("Введите строку: ");
    scanf("%s",&str);

    printf("Введите какой по порядку символ нужно удалить: ");
    scanf("%i",&id_removed_ch);
    if(id_removed_ch<1 || id_removed_ch>strlen(str))
    {
        printf("Номер символа должен быть больше нуля и меньше длины строки\n");
    }
    else
    {
        for (int i = id_removed_ch-1; i < strlen(str); i++)
        {
            str[i]=str[i+1];
        }
        printf("Строка без символа: ");
        puts(str);
    }
}