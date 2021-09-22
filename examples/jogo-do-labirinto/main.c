typedef int bool;

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "definitions.h"

int getRandom(int min, int max);
int *setMapValue(int columnsNumber, int rowsNumber, int lastBoard[]);
void drawMap(int rowsNumber, int columnsNumber, int map[rowsNumber][columnsNumber], int playerCurrentPosition[]);
bool checkMove(int rowsNumber, int columnsNumber, int playerCurrentPosition[2], int map[playerCurrentPosition[X]][playerCurrentPosition[Y]]);
int main()
{
    srand(time(0));

    int hiNumberSize = 10,
        lowNumberSize = 5;

    int columnsNumber = getRandom(lowNumberSize, hiNumberSize),
        rowsNumber = getRandom(lowNumberSize, hiNumberSize);

    if (DEBUG_MODE)
    {
        printf("Número de linhas: %i \nNúmero de colunas: %i\n\n\n", rowsNumber, columnsNumber);
    }

    int map[rowsNumber][columnsNumber];
    for (size_t row = 0; row < rowsNumber; row++)
    {
        for (size_t column = 0; column < columnsNumber; column++)
        {
            map[row][column] = getRandom(0, 1);
        }
    }

    int firstColumn = getRandom(0, columnsNumber);

    int curentRow = 0;
    int *lastBoard;
    int *currentBoard;

    lastBoard = (int[]){0, firstColumn};

    while (curentRow < rowsNumber)
    {
        currentBoard = setMapValue(columnsNumber, rowsNumber, lastBoard);

        if (!(currentBoard[X] == rowsNumber))
        {

            printf("X: %i, Y: %i\n", currentBoard[X], currentBoard[Y]);
            map[currentBoard[X]][currentBoard[Y]] = DEBUG_MODE ? DEBUG : LIVRE;
        }

        curentRow = currentBoard[X];
        lastBoard = currentBoard;
    }
    map[0][firstColumn] = PLAYER; // Primeira casa

    int playerCurrentPosition[2] = {0, firstColumn};

    char movimento;

    while ((movimento != 'x') && (movimento != 'X'))
    {
        system(LIMPARTELA);
        drawMap(rowsNumber, columnsNumber, map, playerCurrentPosition);

        map[playerCurrentPosition[X]][playerCurrentPosition[Y]] = LIVRE;

        // Mostrar direções
        printf("\n\n  (W)\n(A)+(D)\n  (S)\n\n");

        if ((scanf("%c", &movimento)) == 0)
        {
            printf("mensagem de erro..\n");
            getchar();
            getchar();
            return ERRO;
        }
        if ((movimento == 'w') || (movimento == 'W'))
        {
            playerCurrentPosition[X] = (playerCurrentPosition[X] - 1);

            if (checkMove(rowsNumber, columnsNumber, playerCurrentPosition, map))
            {
                playerCurrentPosition[X] = playerCurrentPosition[X] + 1;
                printf("\n\nups.. ali não =)\n");
                getchar();
                getchar();
            }
        }
        if ((movimento == 's') || (movimento == 'S'))
        {
            playerCurrentPosition[X] = playerCurrentPosition[X] + 1;

            if (checkMove(rowsNumber, columnsNumber, playerCurrentPosition, map))
            {
                playerCurrentPosition[X] = playerCurrentPosition[X] - 1;
                printf("\n\nups.. ali não =)\n");
                getchar();
                getchar();
            }
        }
        if ((movimento == 'd') || (movimento == 'D'))
        {
            playerCurrentPosition[Y] = playerCurrentPosition[Y] + 1;

            if (checkMove(rowsNumber, columnsNumber, playerCurrentPosition, map))
            {
                playerCurrentPosition[Y] = playerCurrentPosition[Y] - 1;
                printf("\n\nups.. ali não =)\n");
                getchar();
                getchar();
            }
        }
        if ((movimento == 'a') || (movimento == 'A'))
        {
            playerCurrentPosition[Y] = playerCurrentPosition[Y] - 1;

            if (checkMove(rowsNumber, columnsNumber, playerCurrentPosition, map))
            {
                playerCurrentPosition[Y] = playerCurrentPosition[Y] + 1;
                printf("\n\nups.. ali não =)\n");
                getchar();
                getchar();
            }
        }

        map[playerCurrentPosition[X]][playerCurrentPosition[Y]] = PLAYER;
    }

    return 0;
}

int getRandom(int min, int max)
{
    int num = (min + rand() % (max + 1 - min));
    return num;
}

int *setMapValue(int columnsNumber, int rowsNumber, int lastBoard[])
{

    int *p;

    if (lastBoard[X] == 0)
    {

        if (lastBoard[Y] == 0)
        {
            p = (int[]){/*length:*/ 2, /*values:*/ LESTE, SUL};
        }
        else if (lastBoard[Y] == columnsNumber)
        {
            p = (int[]){/*length:*/ 2, /*values:*/ OESTE, SUL};
        }
        else
        {
            p = (int[]){/*length:*/ 3, /*values:*/ LESTE, OESTE, SUL};
        }
    }
    else if (lastBoard[X] == rowsNumber)
    {
        // Ultima linha
    }
    else if (lastBoard[Y] == 0)
    {
        p = (int[]){/*length:*/ 2, /*values:*/ LESTE, SUL};
    }
    else if (lastBoard[Y] == (columnsNumber - 1))
    {
        p = (int[]){/*length:*/ 2, /*values:*/ OESTE, SUL};
    }
    else
    {
        p = (int[]){/*length:*/ 3, /*values:*/ LESTE, OESTE, SUL};
    }

    int *nextBoard;

    if (DEBUG_MODE)
    {
        printf("ESCOLHA: %i\n", getRandom(1, p[0]));
    }
    switch (p[getRandom(1, p[0])])
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

void drawMap(int rowsNumber,
             int columnsNumber,
             int map[rowsNumber][columnsNumber],
             int playerCurrentPosition[])
{
    for (size_t row = 0; row < rowsNumber; row++)
    {
        printf("|");
        for (size_t column = 0; column < columnsNumber; column++)
        {

            printf(GREEN " | %zux%zu (%i) " RESET, row, column, map[row][column]);

            switch (map[row][column])
            {
            case PLAYER:
                printf(YELLOW "@" RESET);
                break;
            case LIVRE:
                printf(" ");
                break;
            case BLOCO:
                printf("*");
                break;

            case DEBUG:
                printf(RED "#" RESET);
                break;
            default:
                printf(RED "ERRO!" RESET);
                break;
            }
        }
        printf("|\n");
    }
}

bool checkMove(int rowsNumber, int columnsNumber, int playerCurrentPosition[2], int map[playerCurrentPosition[X]][playerCurrentPosition[Y]])
{

    if (map[playerCurrentPosition[X]][playerCurrentPosition[Y]] == BLOCO)
    {
        // Movimento é inválido
        printf("(%i, %i) É UM BLOCO! \n"
               "Valor map: % i ",
               playerCurrentPosition[X],
               playerCurrentPosition[Y],
               map[playerCurrentPosition[X]][playerCurrentPosition[Y]]);
        return true;
    }
    else
    {
        return false;
    }
}
