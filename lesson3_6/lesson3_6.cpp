#include <stdio.h>

void five_multiplication_table();
void guessin_game();

int main()
{
    //five_multiplication_table(); //выводит таблицу умножения на 5
    guessin_game(); //игра "угадай число"
    return 0;
}

void five_multiplication_table()
{
    for(int i=1;i<= 10;i++)
    {
        printf("5 * %i = %i\n", i, 5*i);
    }
}

void guessin_game()
{
    printf("Угадай число, которое я загадал: \n");
    int a = 0;
    while(true)
    {
        scanf("%i", &a);
        if (a == 5)
        {
            printf("угадал!\n");
            break;
        }
        else
        {
            if (a>5)
            {
                printf("твое число больше загаданного числа\n");
            }
            else
            {
                if (a<5)
                {
                    printf("твое число меньше загаданного числа\n");
                }
                
            }

            for (int i = 7; i <= 10; i+=3)
            {
                if (a>i)
                {
                    printf("твое число больше %i\n", i);
                }
                else
                {
                    if (a<i)
                    {
                        printf("твое число меньше %i\n", i);
                    }
                    else
                    {
                        if (a==i)
                        {
                            printf("твое число равно %i\n", i);
                        }
                    }
                }
            }
        }
    }
}