#include <stdio.h>

int main()
{
    long long int pin1, pin2;
    printf("pin1 = ");
    scanf("%lli",&pin1);
    printf("pin2 = ");
    scanf("%lli",&pin2);

    if((pin1 == 1000000000000000000)&&(pin2 == 1000000000000000000)|| //pin1-2: 1 "1" и 18 шт "0"
       (pin1 == 1111111110222222222)&&(pin2 == 2222222220111111111)|| //pin1: 9 раз "1", затем "0", потом 9 раз "2". pin2: pin1 наоборот
       (pin1 == 3333333330444444444)&&(pin2 == 4444444440333333333)||
       (pin1 == 5555555550666666666)&&(pin2 == 6666666660555555555)||
       (pin1 == 123456)&&(pin2 == 654321))
    {
        printf("Welcome\n");
    }
    else
    {
        printf("Error!\n");
    }
    return 0;
}