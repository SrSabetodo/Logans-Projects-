#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>

void display(char **array);
void deallocateStuff(char **array);
char **allocateArray();
bool **allocateBoolArray();
void sleep_seconds(const unsigned int sleepMSs);
void processInput(char **array, int value, int *xCoord, int *yCoord, int *old_XCoord, int *old_YCoord);
void findOpenSpaceWorS(char **array, int *xCoord, int *yCoord);
void findOpenSpaceAorD(char **array, int *xCoord, int *yCoord);
void moveSelectionAfterPlacement(char **array, int *xCoord, int *yCoord);
void setSpaceToX(char **array, int *xCoord, int *yCoord, int *old_XCoord, int *old_YCoord);
void numberEntered(char **array, int *xCoord, int *yCoord, char key, int *numSpaces);
char **readFromFile(char **array);
void backSpacePressed(char **array, int *xCoord, int *yCoord);
void backSlashPressed(char **array, int *xCoord, int *yCoord);
int findNumEmptySpaces(char **array);
bool isValidUpAndAcross(char **array, int *xCoord, int *yCoord, char key);
bool isValidInSquare(char **array, int *xCoord, int *yCoord, char key);
void setInitialPosition(char **array, int *xCoord, int *yCoord);
void welcomeScreen(char **array);
void helpKeyPressed(char **array);
char **populateControlArray(char **controlArray, char **array);
void deleteMode(char **array, int *xCoord, int *yCoord, char **controlArray);
void deleteMove(char **array, int *xCoord, int *yCoord, int value, char **controlArray);
void deleteModeFindOpenSpaceAorD(char **controlArray, int *xCoord, int *yCoord);
void deleteModeFindOpenSpaceWorS(char **controlArray, int *xCoord, int *yCoord);
void cleanUpDisplayArray(char **array);
void locateSelection(char **array);
void deleteBackSpacePressed(char **controlArray, char **array, int *xCoord, int *yCoord, char previousKey);
void deleteBackSlashPressed(char **controlArray, char **array, int *xCoord, int *yCoord, char previousKey);

int main(void)
{
    /* ===== Seeding time and setting up theme of console ===== */
    srand(time(0));
    puts("");
    system("color 70");

    /* ===== Allocating and populating bool array and char array ===== */
    char **array = allocateArray();
    array = readFromFile(array);

    char **controlArray = allocateArray();
    controlArray = populateControlArray(controlArray, array);

    /* ===== Setting X and Y coords to a random place in the puzzle ===== */
    int xCoord, yCoord;
    setInitialPosition(array, &xCoord, &yCoord);
    int old_Xcoord = xCoord;
    int old_YCoord = yCoord;

    /* ===== Declaring val for future input and getting the number of empty spaces in the puzzle ===== */
    int val, numberEmptySpaces = findNumEmptySpaces(array);

    /* ===== Welcome screen displays first, then the puzzle loop starts ===== */
    welcomeScreen(array);

    while (1)
    {
        system("cls");
        display(array);

        if (numberEmptySpaces < 0)
        {
            puts("Congradulations! \nYou have solved the puzzle!");
            break;
        }

        char key = getch();
        int val = key;

        if (val == 27)
        {
            break;
        }

        if (numberEmptySpaces > 0)
        {
            if (val == 97 || val == 119 || val == 100 || val == 115) // player is moving around
            {
                processInput(array, val, &xCoord, &yCoord, &old_Xcoord, &old_YCoord);
                setSpaceToX(array, &xCoord, &yCoord, &old_Xcoord, &old_YCoord);
            }
            else if (val == 8)
            {
                backSpacePressed(array, &xCoord, &yCoord);
            }
            else if (val == 92)
            {
                backSlashPressed(array, &xCoord, &yCoord);
            }
            else if (val >= 49 && val <= 57) // player is attempting to sovle
            {
                numberEntered(array, &xCoord, &yCoord, key, &numberEmptySpaces);
            }
            else if (val == 104)
            {
                helpKeyPressed(array);
            }
            else if (val == 83)
            {
                deleteMode(array, &xCoord, &yCoord, controlArray);
            }
            else if (val == 108)
            {
                locateSelection(array);
            }
        }
        else
        {
            if (val >= 49 && val <= 57) // player is guessing the last number
            {
                numberEntered(array, &xCoord, &yCoord, key, &numberEmptySpaces);
            }
            else if (val == 104)
            {
                helpKeyPressed(array);
            }
            else if (val == 108)
            {
                locateSelection(array);
            }
        }
    }

    deallocateStuff(array);
    deallocateStuff(controlArray);

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
    char **array = (char **)malloc(sizeof(char *[9]));
    for (int i = 0; i < 9; i++)
    {
        array[i] = (char *)malloc(sizeof(char[9]));
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
                findOpenSpaceAorD(array, *&xCoord, *&yCoord);
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
                findOpenSpaceWorS(array, *&xCoord, *&yCoord);
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
                findOpenSpaceAorD(array, *&xCoord, *&yCoord);
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
                findOpenSpaceWorS(array, *&xCoord, *&yCoord);
            }

        } while (array[*yCoord][*xCoord] != ' ');

        break;
    }
}

void findOpenSpaceWorS(char **array, int *xCoord, int *yCoord)
{
    for (int x = *xCoord + 1; x < 9; x++)
    {
        for (int y = 0; y < 9; y++)
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

    for (int x = 0; x < 9; x++)
    {
        for (int y = 0; y < 9; y++)
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

void findOpenSpaceAorD(char **array, int *xCoord, int *yCoord)
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

    int counter = 0;

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
        counter += 1;
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

        if (counter > 81)
        {
            break;
        }
    }
}

void setSpaceToX(char **array, int *xCoord, int *yCoord, int *old_XCoord, int *old_YCoord)
{
    array[*yCoord][*xCoord] = 'X';
    array[*old_YCoord][*old_XCoord] = ' ';
}

void numberEntered(char **array, int *xCoord, int *yCoord, char key, int *numSpaces)
{
    if (isValidInSquare(array, *&xCoord, *&yCoord, key) && isValidUpAndAcross(array, *&xCoord, *&yCoord, key))
    {
        array[*yCoord][*xCoord] = key;
        *numSpaces -= 1;
        moveSelectionAfterPlacement(array, *&xCoord, *&yCoord);
    }
}

char **readFromFile(char **array)
{
    char tempStorage[81];
    char c;

    FILE *file;
    file = fopen("numbers.txt", "r");

    int counter = 0;

    if (file)
    {
        while ((c = getc(file)) != EOF)
        {
            if (isdigit(c))
            {
                if (c == '0')
                {
                    c = ' ';
                }
                tempStorage[counter] = c;
                counter += 1;
            }
        }
        fclose(file);
    }

    counter = 0;

    for (int y = 0; y < 9; y++)
    {
        for (int x = 0; x < 9; x++)
        {
            array[y][x] = tempStorage[counter];
            counter += 1;
        }
    }

    return array;
}

void backSpacePressed(char **array, int *xCoord, int *yCoord)
{
    int old_xCoord = *xCoord;
    int old_yCoord = *yCoord;

    int x = *xCoord;
    int y = *yCoord;

    int counter = 0;

    while (1)
    {
        if (array[y][x] == ' ')
        {
            *xCoord = x;
            *yCoord = y;
            setSpaceToX(array, *&xCoord, *&yCoord, &old_xCoord, &old_yCoord);
            return;
        }
        else
        {
            counter += 1;

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

            if (counter > 81)
            {
                *xCoord = old_xCoord;
                *yCoord = old_yCoord;

                array[*yCoord][*xCoord] = 'X';

                return;
            }
        }
    }
}

void backSlashPressed(char **array, int *xCoord, int *yCoord)
{
    int old_xCoord = *xCoord;
    int old_yCoord = *yCoord;

    int x = *xCoord;
    int y = *yCoord;

    int counter = 0;

    while (1)
    {
        if (array[y][x] == ' ')
        {
            *xCoord = x;
            *yCoord = y;
            setSpaceToX(array, *&xCoord, *&yCoord, &old_xCoord, &old_yCoord);
            return;
        }
        else
        {
            counter += 1;

            x -= 1;

            if (x < 0)
            {
                x = 8;
                y -= 1;
            }

            if (y < 0)
            {
                y = 8;
                x = 8;
            }

            if (counter > 81)
            {
                *xCoord = old_xCoord;
                *yCoord = old_yCoord;

                array[*yCoord][*xCoord] = 'X';

                return;
            }
        }
    }
}

int findNumEmptySpaces(char **array)
{
    int numSpaces = 0;

    for (int y = 0; y < 9; y++)
    {
        for (int x = 0; x < 9; x++)
        {
            if (array[y][x] == ' ')
            {
                numSpaces += 1;
            }
        }
    }

    return numSpaces;
}

bool isValidUpAndAcross(char **array, int *xCoord, int *yCoord, char key)
{
    bool verticalCheckFail = false;
    bool horizontCheckFail = false;

    for (int y = 0; y < 9; y++)
    {
        if (array[y][*xCoord] == key)
        {
            verticalCheckFail = true;
            printf("Error: there is already a %c in column %d!\n", key, *xCoord + 1);
        }
    }

    for (int x = 0; x < 9; x++)
    {
        if (array[*yCoord][x] == key)
        {
            horizontCheckFail = true;
            printf("Error: there is already a %c in row %d!\n", key, *yCoord + 1);
        }
    }

    if (verticalCheckFail || horizontCheckFail)
    {

        char c;
        puts("Press enter to continue");
        scanf("%c", &c);
        return false;
    }

    return true;
}

bool isValidInSquare(char **array, int *xCoord, int *yCoord, char key)
{
    int square;

    /* ===== top row of squares 1,2,3 ===== */
    if (*xCoord < 3 && *yCoord < 3)
    {
        square = 1;
    }
    if ((*xCoord > 2 && *xCoord < 6) && (*yCoord < 3))
    {
        square = 2;
    }
    if ((*xCoord > 5) && (*yCoord < 3))
    {
        square = 3;
    }

    /* ===== middle row of squares 4,5,6 ===== */
    if ((*xCoord < 3) && (*yCoord > 2 && *yCoord < 6))
    {
        square = 4;
    }
    if ((*xCoord > 2 && *xCoord < 6) && (*yCoord > 2 && *yCoord < 6))
    {
        square = 5;
    }
    if ((*xCoord > 5) && (*yCoord > 2 && *yCoord < 6))
    {
        square = 6;
    }

    /* ===== last row of square 7,8,9 ===== */
    if ((*xCoord < 3) && (*yCoord > 5))
    {
        square = 7;
    }
    if ((*xCoord > 2 && *xCoord < 6) && (*yCoord > 5))
    {
        square = 8;
    }
    if ((*xCoord > 5) && (*yCoord > 5))
    {
        square = 9;
    }

    switch (square)
    {
    case 1:
        for (int y = 0; y < 3; y++)
        {
            for (int x = 0; x < 3; x++)
            {
                if (array[y][x] == key)
                {
                    printf("Error: there is already a %c in square 1\n", key);
                    char c;
                    puts("Press enter to continue");
                    scanf("%c", &c);
                    return false;
                }
            }
        }
        break;
    case 2:
        for (int y = 0; y < 3; y++)
        {
            for (int x = 3; x < 6; x++)
            {
                if (array[y][x] == key)
                {
                    printf("Error: there is already a %c in square 2\n", key);
                    char c;
                    puts("Press enter to continue");
                    scanf("%c", &c);
                    return false;
                }
            }
        }
        break;
    case 3:
        for (int y = 0; y < 3; y++)
        {
            for (int x = 6; x < 9; x++)
            {
                if (array[y][x] == key)
                {
                    printf("Error: there is already a %c in square 3\n", key);
                    char c;
                    puts("Press enter to continue");
                    scanf("%c", &c);
                    return false;
                }
            }
        }
        break;
    case 4:
        for (int y = 3; y < 6; y++)
        {
            for (int x = 0; x < 3; x++)
            {
                if (array[y][x] == key)
                {
                    printf("Error: there is already a %c in square 4\n", key);
                    char c;
                    puts("Press enter to continue");
                    scanf("%c", &c);
                    return false;
                }
            }
        }
        break;
    case 5:
        for (int y = 3; y < 6; y++)
        {
            for (int x = 3; x < 6; x++)
            {
                if (array[y][x] == key)
                {
                    printf("Error: there is already a %c in square 5\n", key);
                    char c;
                    puts("Press enter to continue");
                    scanf("%c", &c);
                    return false;
                }
            }
        }
        break;
    case 6:
        for (int y = 3; y < 6; y++)
        {
            for (int x = 6; x < 9; x++)
            {
                if (array[y][x] == key)
                {
                    printf("Error: there is already a %c in square 6\n", key);
                    char c;
                    puts("Press enter to continue");
                    scanf("%c", &c);
                    return false;
                }
            }
        }
        break;
    case 7:
        for (int y = 6; y < 9; y++)
        {
            for (int x = 0; x < 3; x++)
            {
                if (array[y][x] == key)
                {
                    printf("Error: there is already a %c in square 7\n", key);
                    char c;
                    puts("Press enter to continue");
                    scanf("%c", &c);
                    return false;
                }
            }
        }
        break;
    case 8:
        for (int y = 6; y < 9; y++)
        {
            for (int x = 3; x < 6; x++)
            {
                if (array[y][x] == key)
                {
                    printf("Error: there is already a %c in square 8\n", key);
                    char c;
                    puts("Press enter to continue");
                    scanf("%c", &c);
                    return false;
                }
            }
        }
        break;
    case 9:
        for (int y = 6; y < 9; y++)
        {
            for (int x = 6; x < 9; x++)
            {
                if (array[y][x] == key)
                {
                    printf("Error: there is already a %c in square 9\n", key);
                    char c;
                    puts("Press enter to continue");
                    scanf("%c", &c);
                    return false;
                }
            }
        }
        break;
    }
    return true;
}

void setInitialPosition(char **array, int *xCoord, int *yCoord)
{
    while (1)
    {
        int y = rand() % 9;
        int x = rand() % 9;

        if (array[y][x] == ' ')
        {
            *xCoord = x;
            *yCoord = y;
            array[y][x] = 'X';
            return;
        }
    }
}

void welcomeScreen(char **array)
{
    system("cls");
    display(array);
    puts("Welcome to the adventure Sudoku!");
    puts("X marks what your current selection is.");
    puts("Press 'W' to move the selection up, 'S' to move down, 'A' to move to the left, and 'D' to move to the right.");
    puts("When attempting to solve the puzzle, simply press the number you'd like to put in the space.\n");
    puts("Pressing BACKSPACE will allow you to cycle through all blank spaces.\nPressing ESC will leave the game.");
    puts("Pressing DELETE will activate Erase Mode, which will allow you to erase previous guesses.");
    puts("Press DELETE, and navigate to the desired key, and press ENTER to erase it.");
    puts("Pressing L will locate your current selection for you");
    puts("");
    puts("You can always press 'H' to bring up the commands.");
    puts("");
    char c;
    puts("Press enter to continue...");
    scanf("%c", &c);
}

void helpKeyPressed(char **array)
{
    system("cls");
    display(array);
    puts("X marks what your current selection is.");
    puts("Press 'W' to move the selection up, 'S' to move down, 'A' to move to the left, and 'D' to move to the right.");
    puts("When attempting to solve the puzzle, simply press the number you'd like to put in the space.\n");
    puts("Pressing BACKSPACE will allow you to cycle through all blank spaces.\nPressing ESC will leave the game.");
    puts("Pressing DELETE will activate Erase Mode, which will allow you to erase previous guesses.");
    puts("Press DELETE, and navigate to the desired key, and press ENTER to erase it.");
    puts("Pressing L will locate your current selection for you");
    puts("");
    puts("You can always press 'H' to bring up the commands.");
    puts("");
    char c;
    puts("Press enter to continue");
    scanf("%c", &c);
}

char **populateControlArray(char **controlArray, char **array)

{
    for (int x = 0; x < 9; x++)
    {
        for (int y = 0; y < 9; y++)
        {
            if (array[y][x] != ' ')
            {
                controlArray[y][x] = '0'; // '0' denotes a space that cannot be modified by user
            }
            else
            {
                controlArray[y][x] = '1'; // '1' denotes a space that can be modified by user
            }
        }
    }

    return controlArray;
}

void deleteMode(char **array, int *xCoord, int *yCoord, char **controlArray)
{
    int old_XCoord = *xCoord;
    int old_YCoord = *yCoord;

    char previousKey;

    array[*yCoord][*xCoord] = 'X';

    int counter = 0;

    while (1)
    {
        system("cls");
        display(array);
        puts("Erase mode is activated");
        puts("Press ENTER to erase the selected number");
        int val = getch();

        if (val == 83)
        {
            system("cls");
            display(array);

            int x = *xCoord;
            int y = *yCoord;

            while (1)
            {
                if (array[y][x] == ' ')
                {
                    *xCoord = x;
                    *yCoord = y;
                    break;
                }

                x += 1;

                if (x > 8)
                {
                    x = 0;
                    y += 1;
                }

                if (y > 8)
                {
                    x = 0;
                    y = 0;
                }
            }

            array[*yCoord][*xCoord] = 'X';
            array[old_YCoord][old_XCoord] = previousKey;

            cleanUpDisplayArray(array);
            puts("Erase mode deactivated");

            sleep_seconds(500);
            break;
        }
        if (val == 97 || val == 119 || val == 100 || val == 115)
        {
            array[old_YCoord][old_XCoord] = previousKey;

            deleteMove(array, *&xCoord, *&yCoord, val, controlArray);

            old_XCoord = *xCoord;
            old_YCoord = *yCoord;

            previousKey = array[*yCoord][*xCoord];

            array[*yCoord][*xCoord] = 'X';
        }
        else if (val == 13)
        {
            previousKey = ' ';
        }
        else if (val == 8)
        {
            deleteBackSpacePressed(controlArray, array, *&xCoord, *&yCoord, previousKey);

            old_XCoord = *xCoord;
            old_YCoord = *yCoord;
        }
        else if (val == 92)
        {
            deleteBackSlashPressed(controlArray, array, *&xCoord, *&yCoord, previousKey);

            old_XCoord = *xCoord;
            old_YCoord = *yCoord;
        }
    }
}

void deleteMove(char **array, int *xCoord, int *yCoord, int value, char **controlArray)
{
    int old_XCoord, old_YCoord;
    {
        int counter;
        switch (value)
        {
        case 97: // a
            counter = 0;
            old_XCoord = *xCoord;
            old_YCoord = *yCoord;
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
                    deleteModeFindOpenSpaceAorD(controlArray, *&xCoord, *&yCoord);
                }

            } while (controlArray[*yCoord][*xCoord] != '1');
            break;
        case 119: // w
            counter = 0;
            old_YCoord = *yCoord;
            old_XCoord = *xCoord;
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
                    deleteModeFindOpenSpaceWorS(controlArray, *&xCoord, *&yCoord);
                }

            } while (controlArray[*yCoord][*xCoord] != '1');
            break;
        case 100: // d
            counter = 0;
            old_XCoord = *xCoord;
            old_YCoord = *yCoord;
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
                    deleteModeFindOpenSpaceAorD(controlArray, *&xCoord, *&yCoord);
                }

            } while (controlArray[*yCoord][*xCoord] != '1');
            break;
        case 115: // s
            counter = 0;
            old_YCoord = *yCoord;
            old_XCoord = *xCoord;
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
                    deleteModeFindOpenSpaceWorS(controlArray, *&xCoord, *&yCoord);
                }

            } while (controlArray[*yCoord][*xCoord] != '1');

            break;
        }
    }
}

void deleteModeFindOpenSpaceAorD(char **controlArray, int *xCoord, int *yCoord)
{
    for (int y = *yCoord + 1; y < 9; y++)
    {
        for (int x = 0; x < 9; x++)
        {
            if (controlArray[y][x] == '1')
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
            if (controlArray[y][x] == '1')
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

void deleteModeFindOpenSpaceWorS(char **controlArray, int *xCoord, int *yCoord)
{
    for (int x = *xCoord + 1; x < 9; x++)
    {
        for (int y = 0; y < 9; y++)
        {
            if (controlArray[y][x] == '1')
            {
                *yCoord = y;
                *xCoord = x;
                return;
            }
        }
    }

    int counter = 0;

    for (int x = 0; x < 9; x++)
    {
        for (int y = 0; y < 9; y++)
        {
            counter += 1;
            if (controlArray[y][x] == '1')
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

void cleanUpDisplayArray(char **array)
{
    for (int y = 0; y < 9; y++)
    {
        for (int x = 0; x < 9; x++)
        {
            if(!isdigit(array[y][x]))
            {
                array[y][x] = ' ';
            }
        }
    }
}

void locateSelection(char **array)
{
    char copyArray[9][9];

    for (int y = 0; y < 9; y++)
    {
        for (int x = 0; x < 9; x++)
        {
            if (array[y][x] == 'X')
            {
                copyArray[y][x] = array[y][x];
            }
            else
            {
                copyArray[y][x] = ' ';
            }
        }
    }
    system("cls");
    printf("      %c | %c | %c || %c | %c | %c || %c | %c | %c  \n", copyArray[0][0], copyArray[0][1], copyArray[0][2], copyArray[0][3], copyArray[0][4], copyArray[0][5], copyArray[0][6], copyArray[0][7], copyArray[0][8]);
    printf("     _____________________________________\n");
    printf("      %c | %c | %c || %c | %c | %c || %c | %c | %c  \n", copyArray[1][0], copyArray[1][1], copyArray[1][2], copyArray[1][3], copyArray[1][4], copyArray[1][5], copyArray[1][6], copyArray[1][7], copyArray[1][8]);
    printf("     _____________________________________\n");
    printf("      %c | %c | %c || %c | %c | %c || %c | %c | %c  \n", copyArray[2][0], copyArray[2][1], copyArray[2][2], copyArray[2][3], copyArray[2][4], copyArray[2][5], copyArray[2][6], copyArray[2][7], copyArray[2][8]);
    printf("     =====================================\n");
    printf("      %c | %c | %c || %c | %c | %c || %c | %c | %c  \n", copyArray[3][0], copyArray[3][1], copyArray[3][2], copyArray[3][3], copyArray[3][4], copyArray[3][5], copyArray[3][6], copyArray[3][7], copyArray[3][8]);
    printf("     _____________________________________\n");
    printf("      %c | %c | %c || %c | %c | %c || %c | %c | %c  \n", copyArray[4][0], copyArray[4][1], copyArray[4][2], copyArray[4][3], copyArray[4][4], copyArray[4][5], copyArray[4][6], copyArray[4][7], copyArray[4][8]);
    printf("     _____________________________________\n");
    printf("      %c | %c | %c || %c | %c | %c || %c | %c | %c  \n", copyArray[5][0], copyArray[5][1], copyArray[5][2], copyArray[5][3], copyArray[5][4], copyArray[5][5], copyArray[5][6], copyArray[5][7], copyArray[5][8]);
    printf("     =====================================\n");
    printf("      %c | %c | %c || %c | %c | %c || %c | %c | %c  \n", copyArray[6][0], copyArray[6][1], copyArray[6][2], copyArray[6][3], copyArray[6][4], copyArray[6][5], copyArray[6][6], copyArray[6][7], copyArray[6][8]);
    printf("     _____________________________________\n");
    printf("      %c | %c | %c || %c | %c | %c || %c | %c | %c  \n", copyArray[7][0], copyArray[7][1], copyArray[7][2], copyArray[7][3], copyArray[7][4], copyArray[7][5], copyArray[7][6], copyArray[7][7], copyArray[7][8]);
    printf("     _____________________________________\n");
    printf("      %c | %c | %c || %c | %c | %c || %c | %c | %c  \n", copyArray[8][0], copyArray[8][1], copyArray[8][2], copyArray[8][3], copyArray[8][4], copyArray[8][5], copyArray[8][6], copyArray[8][7], copyArray[8][8]);

    sleep_seconds(500);
}

void deleteBackSpacePressed(char **controlArray, char **array, int *xCoord, int *yCoord, char previousKey)
{
    int old_xCoord = *xCoord;
    int old_yCoord = *yCoord;

    int x = *xCoord;
    int y = *yCoord;

    int counter = 0;

    while (1)
    {
        if (controlArray[y][x] == '1' && array[y][x] != 'X')
        {
            *xCoord = x;
            *yCoord = y;

            array[*yCoord][*xCoord] = 'X';
            array[old_yCoord][old_xCoord] = previousKey;

            return;
        }
        else
        {
            counter += 1;

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

            if (counter > 81)
            {
                return;
            }
        }
    }
}

void deleteBackSlashPressed(char **controlArray, char **array, int *xCoord, int *yCoord, char previousKey)
{
    int old_xCoord = *xCoord;
    int old_yCoord = *yCoord;

    int x = *xCoord;
    int y = *yCoord;

    int counter = 0;

    while (1)
    {
        if (controlArray[y][x] == '1' && array[y][x] != 'X')
        {
            *xCoord = x;
            *yCoord = y;

            array[*yCoord][*xCoord] = 'X';
            array[old_yCoord][old_xCoord] = previousKey;

            return;
        }
        else
        {
            counter -= 1;

            x -= 1;

            if (x < 0)
            {
                x = 8;
                y -= 1;
            }

            if (y < 0)
            {
                y = 8;
                x = 8;
            }

            if (counter > 81)
            {
                return;
            }
        }
    }
}