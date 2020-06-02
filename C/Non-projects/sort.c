#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main()
{
    int i, temp, swapped;
    int howMany = 10;
    int goals[howMany];

    // populate array 
    for(i = 0; i < howMany; i++)
    {
        goals[i] = (rand()%25)+1;
    }

    printf("Original list \n");
     for(i = 0; i < howMany; i++)
    {
        printf("%d \n", goals[i]);
    }

    while(1)
    {
        swapped = 0;

        for(i = 0; i < howMany -1; i++)
        {
            if(goals[i] > goals[i + 1])
            {
                temp = goals[i];
                goals[i] = goals[i + 1];
                goals[i + 1] = temp;
                swapped = 1;
            }
        }

        if(swapped == 0)
            {
                break;
            }
    }

    puts("Sorted list: ");
    for(int k = 0; k < howMany; k++)
    {
        printf("%d \n", goals[k]);
    }

    return 0;
}