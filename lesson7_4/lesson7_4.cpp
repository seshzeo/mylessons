#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

void task1();
void task2();
void change_str(char[],char);
void delete_spaces(char[]);

int main()
{
    //task1(); //Первое задание
    task2(); //Второе задание

    return 0;
}


void task1()
{
    char str[100];
    char by;
    printf("Введдите строку в которой будем менять первую и последнюю букву: ");
    scanf("%s",str);
    printf("Введите символ на который будем менять: ");
    scanf("%c",&by);
    scanf("%c",&by);
    change_str(str,by);
    puts(str);
}

void task2()
{
    char str[100] = "    Hello    ";
    /*При вводе слова в консоль с пробелами, даже без использование каких либо сторонних функций типа моей, все пробелы (в начале и конце) удаляются автоматически
    поэтому массив задал вручную*/
    delete_spaces(str);
    puts(str);
}

void change_str(char str[],char by)
{
    str[0] = str[strlen(str)-1] = by;
}

void delete_spaces(char str[])
{
    while(str[strlen(str)-1] == ' ')
    {
        str[strlen(str)-1]=str[strlen(str)];
    }
    while(str[0] == ' ')
    {
        for (int i = 0;i<strlen(str);i++)
        {
            str[i]=str[i+1];
        }
    }
}
