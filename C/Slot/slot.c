#include <stdlib.h>
#include <stdio.h>

void shuffleRotor(int *rotor);

int main()
{
    int rotorOne[7] = {1, 2, 3, 4, 5, 6, 7};
    int rotorTwo[7] = {1, 2, 3, 4, 5, 6, 7};
    int rotorThr[7] = {1, 2, 3, 4, 5, 6, 7};
    int rotorFou[7] = {1, 2, 3, 4, 5, 6, 7};
    int rotorFiv[7] = {1, 2, 3, 4, 5, 6, 7};
    int rotorSix[7] = {1, 2, 3, 4, 5, 6, 7};
    int rotorSev[7] = {1, 2, 3, 4, 5, 6, 7};

    for (int i = 0; i < 7; i++)
    {
        shuffleRotor(rotorOne);

        for (int i = 0; i < 7; i++)
        {
            printf("%d", rotorOne[i]);
        }

        puts("");
    }

    return 0;
}

void shuffleRotor(int *rotor)
{
    int returnedRotor[7] = {};
    int index = 0;

    for (int i = 0; i < 7; i++)
    {
        index++;

        if (index > 6)
        {
            index = 0;
        }
        returnedRotor[index] = rotor[i];
    }

    for (int i = 0; i < 7; i++)
    {
        rotor[i] = returnedRotor[i];
    }
}

void display(int *rotorOne, int *rotorTwo, int *rotorThr, int *rotorFou, int *rotorFiv, int *rotorSix, int *rotorSev)
{
}