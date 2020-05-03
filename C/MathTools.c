#include <stdio.h>
#include <stdbool.h>

void lowest_common_multiple(long int x, long int y);

int main()
{
    long int x, y;

    printf("Enter the first number to find the Lowest Common Multiple (LCM) of: ");
    scanf("%d",&x);
    printf("Enter the second number: ");
    scanf("%d",&y);

    lowest_common_multiple(x,y);
}

void lowest_common_multiple(long int x, long int y)
{
    bool control = false;
    long int number = 0;

    while(!control)
    {
        number += 1;
        if(number % x == 0 && number % y == 0)
        {
            printf("Lowest common multiple of %d", x);
            printf(" and %d", y);
            printf(" is %d", number);
            control = true;
        }
    }

}