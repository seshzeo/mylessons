#include <stdio.h>

int main()
{
    int sum, count = 100;

    for (int i = 0; i <= count; ++i)
    {
        sum = sum + i;
    }
    printf("%i\n", sum);

    return 0;
}