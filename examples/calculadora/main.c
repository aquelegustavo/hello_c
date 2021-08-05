// ARQUIVO: RELATÓRIO DE TRABALHO DE LABORATÓRIO 1
//TÍTULO: Relatório de trabalho de laboratório parte prática
//ENVIADO POR: Gustavo Simões Mendonça; Izabelle Custodia Teixeira Sebastiao.
//Todo o código tem como autores Gustavo Simões Mendonça e Izabelle C. T. Sebastião.
//PARA O CURSO: Enhenharia de Computação
//DATA:04/08/21 

//propósito
/**Este programa, tem como objetivo central oferecer ao usuário a realização de cálculos
matemáticos básicos. Essas operações básicas estão registradas no programa sendo elas a soma, 
a subtração, a multiplicação e a divisão. Assim, para realizar uma das operações desejadas é necessário
que o usuário escolha 2 números racionais./

//METÓDO GERAL:
/**A lista de tarefas gerais é:
1. Escolha uma das opções disponíveis (+, -, /, *).
2. inserir o primeiro número à n1.
3. inserir o segundo número à n2.
4. imprime o resultado do cálculo escolhido./

//ARQUIVOS INCLUÍDOS:
//stdio.h

//ARQUIVO DE DADOS:
//Nenhum 

//PARAMETROS:
// nome            tipo          valor/referencia             descrição   
//--------------------------------------------------------------------------------------------------------
// menuIndex       int                valor             apresenta opções que podem ser escolhidas pelo usuário
// n1, n2         float               valor               numeros racionais
// result         float            referencia            apresenta os resultados

/**
 * Escreva o programa “calculadora” que recebe 2 números reais e dependendo da
 * escolha do usuário realiza operações básicas (+, -, /, *) com esses números.
 * 
 * @file examples/calculadora/main.c
 * @author Gustavo Simões e Izabelle Sebastião
 * @date 03 agosto 2021
 * 
 */

// Biblioteca padrão do C (standard input-output header)
#include <stdio.h>

// Função main (início do programa)
int main()
{
    /**
     * 
     * Sessão 1: título do programa
     * 
     * */

    printf("\033[0;33m"); // Definindo texto para a cor amarela
    printf("\n************************");
    printf("\n--> Calculadora <--\n");
    printf("************************");
    printf("\033[0;0m"); // Resetando texto para cor padrão

    /**
     * 
     * Sessão 2: Menu de opções
     * 
     * */

    printf("\033[0;34m"); // Definindo texto para a cor azul
    printf("\n\nOpções:\n\n");
    printf("\033[0;0m"); // Resetando texto para cor padrão

    // Opções disponíveis (+, -, /, *)
    printf("Digite 1 para adição de dois números\n");
    printf("Digite 2 para subtração de dois números\n");
    printf("Digite 3 para divisão de dois números\n");
    printf("Digite 4 para multiplicação de dois números\n");

    int menuIndex; // Opção escolhida pelo usuário

    printf("\n\nOpção? ");
    scanf("%i", &menuIndex); // Atribuição da escolha do usuário à variável menuIndex

    // Caso a escolha do usuário seja diferente dos index disponíveis,
    // o programa deve entrar em loop até a entrada ser uma opção válida;
    while (
        menuIndex != 1 &&
        menuIndex != 2 &&
        menuIndex != 3 &&
        menuIndex != 4)
    {
        printf("\033[0;31m"); // Definindo texto para a cor vermelho
        printf("! Escolha uma opção entre 1, 2, 3 ou 4:");
        printf("\033[0;0m"); // Resetando texto para cor padrão

        scanf("%i", &menuIndex); // Atribuição da escolha do usuário à variável menuIndex
    }

    /**
     * 
     * Sessão 3: Atribuiução dos membros da expressão
     * 
     * */

    float n1, n2; // Mebros da expressão matemática
    float result; // Resultado da expressão

    // Primeira atribuição
    printf("\nInsira o primeiro número ");
    scanf("%f", &n1); // Atribuir o primeiro número à n1

    // Segunda atribuição
    printf("\nInsira o segundo número ");
    scanf("%f", &n2); // Atribuir o segundo número à n2

    /**
     * 
     * Sessão 4: Cálculo do resultado de acordo com index escolhido
     * 
     * */

    switch (menuIndex)
    {
    case 1:
        result = n1 + n2;
        break;
    case 2:
        result = n1 - n2;
        break;

    case 3:
        // Bloquear divisão por 0
        if (n2 == 0)
        {
            printf("\033[0;31m"); // Definindo texto para a cor vermelho
            printf("! Não é possível dividir por 0\n");
            printf("\033[0;0m"); // Resetando texto para cor padrão

            return 0; // Encerrar programa
        }
        result = n1 / n2;
        break;
    case 4:
        result = n1 * n2;
        break;
    }

    /**
     * 
     * Sessão 5: Exibindo o resultado
     * 
     * */

    printf("\033[0;34m"); // Definindo texto para a cor azul
    printf("\n\nO resultado da operação é: %g\n\n", result);
    printf("\033[0;0m"); // Resetando texto para cor padrão

    return 0; // Retorno da função main()
}
