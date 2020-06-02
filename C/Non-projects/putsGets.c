#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main()
{
    char catsName[50];
    char catsFood[25];
    char sentence[75] = "";

    puts("Whats the cats dumd name?");
    gets(catsName);

    puts("What do they eat?");
    gets(catsFood);

    strcat(sentence,catsName);
    strcat(sentence, " loves to eat ");
    strcat(sentence, catsFood);

    puts(sentence);
    return 0;
}