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
    // Inicialização srand() com uma semente baseada no tempo
    // Geração de números aleatórios
    srand(time(0));

    // Declaração as proporções máximas do mapa
    int hiNumberSize = 10,
        lowNumberSize = 5;

    // Declaração do número de linhas e colunas do mapa
    int rowsNumber = getRandom(lowNumberSize, hiNumberSize),
        columnsNumber = getRandom(lowNumberSize, hiNumberSize);

    if (DEBUG_MODE)
    {
        printf("Número de linhas: %i \nNúmero de colunas: %i\n\n\n", rowsNumber, columnsNumber);
    }

    // Declaração do mapa
    int map[rowsNumber][columnsNumber];

    // Para cada linha no mapa
    for (size_t row = 0; row < rowsNumber; row++)
    {
        // Para cada coluna no mapa
        for (size_t column = 0; column < columnsNumber; column++)
        {
            // A casa atual (linha, coluna) recebe um valor entre 0 e 1
            // 0 ---> livre
            // 1 ---> parede
            map[row][column] = getRandom(0, 1);
        }
    }

    int firstColumn = getRandom(0, (columnsNumber - 1));

    int *lastBoard;
    int *currentBoard;

    lastBoard = (int[]){0, firstColumn};
    currentBoard = (int[]){0, firstColumn};

    while (currentBoard[X] < rowsNumber)
    {
        currentBoard = setMapValue(columnsNumber, rowsNumber, lastBoard);

        if (!(currentBoard[X] == rowsNumber))
        {

            if (DEBUG_MODE)
            {
                printf("X: %i, Y: %i\n", currentBoard[X], currentBoard[Y]);
            }

            map[currentBoard[X]][currentBoard[Y]] = DEBUG_MODE ? DEBUG : LIVRE;
        }

        lastBoard = currentBoard;
    }
    // Posição de início do player
    map[0][firstColumn] = PLAYER;

    int playerCurrentPosition[2] = {0, firstColumn};

    char move;

    while ((move != 'x') && (move != 'X'))
    {
        system(LIMPARTELA);
        drawMap(rowsNumber, columnsNumber, map, playerCurrentPosition);

        map[playerCurrentPosition[X]][playerCurrentPosition[Y]] = LIVRE;

        // Mostrar direções
        printf("\n\n  (W)\n(A)+(D)\n  (S)\n\n");

        if (DEBUG_MODE)
        {
            printf(GREEN "Posição do player: (%i, %i)\n\n" RESET, playerCurrentPosition[X], playerCurrentPosition[Y]);
        }

        if ((scanf("%c", &move)) == 0)
        {
            printf("mensagem de erro..\n");
            getchar();
            getchar();
            return ERRO;
        }
        if ((move == 'w') || (move == 'W'))
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
        if ((move == 's') || (move == 'S'))
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
        if ((move == 'd') || (move == 'D'))
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
        if ((move == 'a') || (move == 'A'))
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

int *setMapValue(int columnsNumber,
                 int rowsNumber,
                 int lastBoard[])
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
            if (DEBUG_MODE)
            {
                printf(GREEN " | %zux%zu (%i) " RESET, row, column, map[row][column]);
            }

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

bool checkMove(int rowsNumber,
               int columnsNumber,
               int playerCurrentPosition[2],
               int map[playerCurrentPosition[X]][playerCurrentPosition[Y]])
{

    if (map[playerCurrentPosition[X]][playerCurrentPosition[Y]] == BLOCO)
    {
        // move é inválido

        if (DEBUG_MODE)
        {
            printf("(%i, %i) É UM BLOCO! \n"
                   "Valor map: % i ",
                   playerCurrentPosition[X],
                   playerCurrentPosition[Y],
                   map[playerCurrentPosition[X]][playerCurrentPosition[Y]]);
        }

        return true;
    }
    else
    {
        return false;
    }
}
