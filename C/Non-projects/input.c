#include <stdio.h>
#include <stdlib.h>

int main()
{
    char firstname[20];
    char lastname[20];
    int age;

    printf("Enter first name? \n");
    scanf("%s",firstname);

    printf("Enter last name? \n");
    scanf("%s",lastname);

    printf("How old are you? \n");
    scanf("%d", &age);


    printf("%s %s is %d years old \n",firstname, lastname, age);
    
    return 0;
}