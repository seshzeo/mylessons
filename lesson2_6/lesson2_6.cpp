#include <stdio.h>

int main()
{
    int day, month, year;

    printf("Введите день вашего рождения:");
    scanf("%i", &day);
    printf("Введите месяц вашего рождения:");
    scanf("%i", &month);   
    printf("Введите год вашего рождения:");
    scanf("%i", &year);

//поскорее бы уже изучить цикл for и массивы(
    if ((day<1)||(day > 31)||(month<1)||(month>12)||(year<1))
    {
        printf("Некорректная дата\n");
    }
    else
    {
        printf("Год вашего рождения ");
        if (year%4 == 0)
        {
            printf("високосный\n");
        }
        else
        {
            printf("невисокосный\n");
        }

        printf("Вы родились в год ");
        switch (year%12)
        {        
            case 0:
            printf("обезьяна\n");
            break;

            case 1:
            printf("петуха\n");
            break;

            case 2:
            printf("собаки\n");
            break;

            case 3:
            printf("свиньи\n");
            break;

            case 4:
            printf("крысы\n");
            break;

            case 5:
            printf("быка\n");
            break;

            case 6:
            printf("тигра\n");
            break;

            case 7:
            printf("кролика\n");
            break;

            case 8:
            printf("дракона\n");
            break;

            case 9:
            printf("змеи\n");
            break;

            case 10:
            printf("лошади\n");
            break;

            case 11:
            printf("козы\n");
            break;

            default:
            printf("... эммм... непонятно\n");
        }

        printf("Ваш знак зодиака ");
        if(((month == 3) && (day >= 21))||((month == 4) && (day <= 19)))
        {
            printf("Овен\n");
        }
        else
        {
            if(((month == 4) && (day >= 20))||((month == 5) && (day <= 20)))
            {
                printf("Телец\n");
            }
            else
            {
                if(((month == 5) && (day >= 21))||((month == 6) && (day <= 20)))
                {
                    printf("Близнецы\n");
                }
                else
                {
                    if(((month == 6) && (day >= 21))||((month == 7) && (day <= 22)))
                    {
                        printf("Рак\n");
                    }
                    else
                    {
                        if(((month == 7) && (day >= 23))||((month == 8) && (day <= 22)))
                        {
                            printf("Лев\n");
                        }
                        else
                        {
                            if(((month == 8) && (day >= 23))||((month == 9) && (day <= 22)))
                            {
                                printf("Дева\n");
                            }
                            else
                            {
                                if(((month == 9) && (day >= 23))||((month == 10) && (day <= 22)))
                                {
                                    printf("Весы\n");
                                }
                                else
                                {
                                    if(((month == 10) && (day >= 23))||((month == 11) && (day <= 21)))
                                    {
                                        printf("Скорпион\n");
                                    }
                                    else
                                    {
                                        if(((month == 11) && (day >= 22))||((month == 12) && (day <= 21)))
                                        {
                                            printf("Стрелец\n");
                                        }
                                        else
                                        {
                                            if(((month == 12) && (day >= 22))||((month == 1) && (day <= 19)))
                                            {
                                                printf("Козерог\n");
                                            }
                                            else
                                            {
                                                if(((month == 1) && (day >= 20))||((month == 2) && (day <= 18)))
                                                {
                                                    printf("Водолей\n");
                                                }
                                                else
                                                {
                                                    if(((month == 2) && (day >= 19))||((month == 3) && (day <= 20)))
                                                    {
                                                        printf("Рыба\n");
                                                    }
                                                    else
                                                    {
                                                        printf("... эммм... непонятно\n");
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }


    return 0;
}