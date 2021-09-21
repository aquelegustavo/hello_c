#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define NORTE 0
#define SUL 2
#define LESTE 1
#define OESTE 3

#define X 0
#define Y 1

int getRandom(int min, int max);
int *setMapValue(int columnsNumber, int rowsNumber, int lastBoard[]);

int main()
{

    int hiNumberSize = 30,
        lowNumberSize = 5;

    int columnsNumber = getRandom(lowNumberSize, hiNumberSize),
        rowsNumber = getRandom(lowNumberSize, hiNumberSize);

    int map[columnsNumber][rowsNumber];

    for (size_t column = 0; column < columnsNumber; column++)
    {
        for (size_t row = 0; row < rowsNumber; row++)
        {
            map[column][row] = getRandom(0, 1);
        }
    }

    int firstColumn = getRandom(0, columnsNumber);

    map[0][firstColumn] = 4; // Primeira casa

    int curentRow = 0;
    int *lastBoard;
    int *currentBoard;

    lastBoard = (int[]){0, firstColumn};

    while (curentRow < rowsNumber)
    {
        currentBoard = setMapValue(columnsNumber, rowsNumber, lastBoard);

        printf("X: %i, Y: %i\n", *(currentBoard), *(currentBoard + 1));

        map[*(currentBoard)][*(currentBoard + 1)] = 3;

        curentRow = *(currentBoard + 1);
        lastBoard = currentBoard;
    }

    for (size_t column = 0; column < columnsNumber; column++)
    {
        for (size_t row = 0; row < rowsNumber; row++)
        {
            printf("%i", map[column][row]);
        }
        printf("\n");
    }

    return 0;
}

int getRandom(int min, int max)
{
    int num = (min + rand() % (max + 1 - min));
    printf("\nNúmero aletório: %i", num);
    return num;
}

int *setMapValue(int columnsNumber, int rowsNumber, int lastBoard[])
{

    printf("lastBoard => x: %i, y: %i\n", lastBoard[X], lastBoard[Y]);

    int *p;

    if (lastBoard[X] == 0)
    {

        if (lastBoard[Y] == 0)
        {
            p = (int[]){LESTE, SUL};
        }
        else if (lastBoard[Y] == columnsNumber)
        {
            p = (int[]){OESTE, SUL};
        }
        else
        {
            p = (int[]){LESTE, OESTE, SUL};
        }
    }
    else if (lastBoard[X] == rowsNumber)
    {
        // Ultima linha
    }
    else if (lastBoard[Y] == 0)
    {
        p = (int[]){LESTE, SUL};
    }
    else if (lastBoard[Y] == columnsNumber)
    {
        p = (int[]){OESTE, SUL};
    }
    else
    {
        p = (int[]){LESTE, OESTE, SUL};
    }

    int a[] = {LESTE, OESTE, SUL, 4, 3, 2, 1};

    p = &a;

    int *nextBoard;

    //printf("\nTamanho do array: %lu\n", sizeof s / sizeof p[0]);

    switch (1)
    {

    case LESTE:
        nextBoard = (int[]){lastBoard[X], (lastBoard[Y] + 1)};
        break;
    case SUL:
        nextBoard = (int[]){(lastBoard[X] + 1), lastBoard[Y]};
        break;
    case OESTE:
        nextBoard = (int[]){lastBoard[X], (lastBoard[Y] - 1)};
        break;
    }

    return nextBoard;
}