#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int getKeyboardInput();
void display(char **array);
char **allocateArray();
void deallocateStuff(char **array);
void processInput(char **array, int value, int *xCoord, int *yCoord, int *old_XCoord, int *old_YCoord);
void findOpenSpace(char **array, int *xCoord, int *yCoord);
void setSpaceToX(char **array, int *xCoord, int *yCoord, int *old_XCoord, int *old_YCoord);
void numberEntered(char **array, int *xCoord, int *yCoord, char key);
void moveSelectionAfterPlacement(char **array, int *xCoord, int *yCoord);

int main(void)
{
    puts("");

    system("color 70");

    char **array = allocateArray();

    int xCoord = 0;
    int yCoord = 0;

    int old_Xcoord = 0;
    int old_YCoord = 0;
    printf("%d", xCoord);
    int val;

    while (1)
    {
        system("clear");
        display(array);
        char key = getch();
        int val = key;

        if (val == 27)
        {
            break;
        }

        if (val == 97 || val == 119 || val == 100 || val == 115)
        {
            processInput(array, val, &xCoord, &yCoord, &old_Xcoord, &old_YCoord);
            setSpaceToX(array, &xCoord, &yCoord, &old_Xcoord, &old_YCoord);
        }
        else if (val >= 49 && val <= 57)
        {
            numberEntered(array, &xCoord, &yCoord, key);
        }
    }

    deallocateStuff(array);

    return 0;
}

void display(char **array)
{
    printf("      %c | %c | %c || %c | %c | %c || %c | %c | %c  \n", array[0][0], array[0][1], array[0][2], array[0][3], array[0][4], array[0][5], array[0][6], array[0][7], array[0][8]);
    printf("     _____________________________________\n");
    printf("      %c | %c | %c || %c | %c | %c || %c | %c | %c  \n", array[1][0], array[1][1], array[1][2], array[1][3], array[1][4], array[1][5], array[1][6], array[1][7], array[1][8]);
    printf("     _____________________________________\n");
    printf("      %c | %c | %c || %c | %c | %c || %c | %c | %c  \n", array[2][0], array[2][1], array[2][2], array[2][3], array[2][4], array[2][5], array[2][6], array[2][7], array[2][8]);
    printf("     =====================================\n");
    printf("      %c | %c | %c || %c | %c | %c || %c | %c | %c  \n", array[3][0], array[3][1], array[3][2], array[3][3], array[3][4], array[3][5], array[3][6], array[3][7], array[3][8]);
    printf("     _____________________________________\n");
    printf("      %c | %c | %c || %c | %c | %c || %c | %c | %c  \n", array[4][0], array[4][1], array[4][2], array[4][3], array[4][4], array[4][5], array[4][6], array[4][7], array[4][8]);
    printf("     _____________________________________\n");
    printf("      %c | %c | %c || %c | %c | %c || %c | %c | %c  \n", array[5][0], array[5][1], array[5][2], array[5][3], array[5][4], array[5][5], array[5][6], array[5][7], array[5][8]);
    printf("     =====================================\n");
    printf("      %c | %c | %c || %c | %c | %c || %c | %c | %c  \n", array[6][0], array[6][1], array[6][2], array[6][3], array[6][4], array[6][5], array[6][6], array[6][7], array[6][8]);
    printf("     _____________________________________\n");
    printf("      %c | %c | %c || %c | %c | %c || %c | %c | %c  \n", array[7][0], array[7][1], array[7][2], array[7][3], array[7][4], array[7][5], array[7][6], array[7][7], array[7][8]);
    printf("     _____________________________________\n");
    printf("      %c | %c | %c || %c | %c | %c || %c | %c | %c  \n", array[8][0], array[8][1], array[8][2], array[8][3], array[8][4], array[8][5], array[8][6], array[8][7], array[8][8]);
}

void deallocateStuff(char **array)
{
    for (int i = 0; i < 9; i++)
    {
        free(array[i]);
    }
    free(array);
}

char **allocateArray()
{
    char **array = malloc(sizeof(char *[9]));
    for (int i = 0; i < 9; i++)
    {
        array[i] = malloc(sizeof(char[9]));
    }

    for (int i = 0; i < 9; i++)
    {
        for (int n = 0; n < 9; n++)
        {
            array[i][n] = ' ';
        }
    }

    return array;
}

void sleep_seconds(const unsigned int sleepMSs)
{
    Sleep(sleepMSs);
}

void processInput(char **array, int value, int *xCoord, int *yCoord, int *old_XCoord, int *old_YCoord)
{
    int counter;
    switch (value)
    {
    case 97: // a
        counter = 0;
        *old_XCoord = *xCoord;
        *old_YCoord = *yCoord;
        do
        {
            if (*xCoord == 0)
            {
                *xCoord = 8;
            }
            else
            {
                *xCoord -= 1;
            }
            counter += 1;

            if (counter > 10)
            {
                int xPlaceholder = *xCoord;
                int yPlaceholder = *yCoord;

                findOpenSpace(array, &xPlaceholder, &yPlaceholder);

                *xCoord = xPlaceholder;
                *yCoord = yPlaceholder;
            }

        } while (array[*yCoord][*xCoord] != ' ');
        break;
    case 119: // w
        counter = 0;
        *old_YCoord = *yCoord;
        *old_XCoord = *xCoord;
        do
        {
            if (*yCoord == 0)
            {
                *yCoord = 8;
            }
            else
            {
                *yCoord -= 1;
            }
            counter += 1;

            if (counter > 10)
            {
                int xPlaceholder = *xCoord;
                int yPlaceholder = *yCoord;

                findOpenSpace(array, &xPlaceholder, &yPlaceholder);

                *xCoord = xPlaceholder;
                *yCoord = yPlaceholder;
            }

        } while (array[*yCoord][*xCoord] != ' ');
        break;
    case 100: // d
        counter = 0;
        *old_XCoord = *xCoord;
        *old_YCoord = *yCoord;
        do
        {
            if (*xCoord == 8)
            {
                *xCoord = 0;
            }
            else
            {
                *xCoord += 1;
            }
            counter += 1;

            if (counter > 10)
            {
                int xPlaceholder = *xCoord;
                int yPlaceholder = *yCoord;

                findOpenSpace(array, &xPlaceholder, &yPlaceholder);

                *xCoord = xPlaceholder;
                *yCoord = yPlaceholder;
            }

        } while (array[*yCoord][*xCoord] != ' ');
        break;
    case 115: // s
        counter = 0;
        *old_YCoord = *yCoord;
        *old_XCoord = *xCoord;
        do
        {
            if (*yCoord == 8)
            {
                *yCoord = 0;
            }
            else
            {
                *yCoord += 1;
            }
            counter += 1;

            if (counter > 10)
            {
                int xPlaceholder = *xCoord;
                int yPlaceholder = *yCoord;

                findOpenSpace(array, &xPlaceholder, &yPlaceholder);

                *xCoord = xPlaceholder;
                *yCoord = yPlaceholder;
            }

        } while (array[*yCoord][*xCoord] != ' ');

        break;
    }
}

void findOpenSpace(char **array, int *xCoord, int *yCoord)
{
    for (int y = *yCoord + 1; y < 9; y++)
    {
        for (int x = 0; x < 9; x++)
        {
            if (array[y][x] == ' ')
            {
                *yCoord = y;
                *xCoord = x;
                return;
            }
        }
    }

    int counter = 0;

    for (int y = 0; y < 9; y++)
    {
        for (int x = 0; x < 9; x++)
        {
            counter += 1;
            if (array[y][x] == ' ')
            {
                *yCoord = y;
                *xCoord = x;
                return;
            }
            if (counter > 81)
            {
                break;
            }
        }
    }
}

void moveSelectionAfterPlacement(char **array, int *xCoord, int *yCoord)
{
    int x = *xCoord + 1;
    int y = *yCoord;
    while (1)
    {
        if (array[y][x] == ' ')
        {
            array[y][x] = 'X';
            *yCoord = y;
            *xCoord = x;
            return;
        }
        x += 1;
        if (x > 8)
        {
            x = 0;
            y += 1;
        }
        if (y > 8)
        {
            y = 0;
            x = 0;
        }
    }
}
void setSpaceToX(char **array, int *xCoord, int *yCoord, int *old_XCoord, int *old_YCoord)
{
    array[*yCoord][*xCoord] = 'X';
    array[*old_YCoord][*old_XCoord] = ' ';
}

void numberEntered(char **array, int *xCoord, int *yCoord, char key)
{
    array[*yCoord][*xCoord] = key;
    puts("");

    int xPlaceholder = *xCoord;
    int yPlaceholder = *yCoord;

    moveSelectionAfterPlacement(array, &xPlaceholder, &yPlaceholder);

    *xCoord = xPlaceholder;
    *yCoord = yPlaceholder;
}