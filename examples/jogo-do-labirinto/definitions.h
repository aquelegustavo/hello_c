#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#define true (1 == 1)
#define false (!true)

#define DEBUG_MODE true
#define DEBUG 7

#define OK 1
#define ERRO 2

#define NORTE 0
#define SUL 2
#define LESTE 1
#define OESTE 3

#define LIVRE 0
#define BLOCO 1
#define PAREDE 2
#define PLAYER 3

#define X 0
#define Y 1

#define RESET "\033[0m"
#define BLACK "\033[30m"   /* Black */
#define RED "\033[31m"     /* Red */
#define GREEN "\033[32m"   /* Green */
#define YELLOW "\033[33m"  /* Yellow */
#define BLUE "\033[34m"    /* Blue */
#define MAGENTA "\033[35m" /* Magenta */
#define CYAN "\033[36m"    /* Cyan */
#define WHITE "\033[37m"   /* White */

/* Usuarios de Windows, troquem "clear" por "cls" */
#define LIMPARTELA "clear"

#endif