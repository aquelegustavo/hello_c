/**
 * Calculadora de número fatoriais (!)
 * 
 * @file /examples/calculadora-fatorial/main.c
 * @author Gustavo Simões
 * @date 06 setembro 2021
 * 
 * 
 * Fontes bibliográficas:
 * https://www.ime.usp.br/~pf/algoritmos/aulas/int.html
*/

// Importação da biblioteca padrão
#include <stdio.h>

// Declaração da função responsável pelo cálculo fatorial
int fatorial(int num);

// Declaração da função main
int main()
{
    // Título do programa
    printf("\033[0;33m"); // Definindo texto para a cor amarela
    printf("************************");
    printf("\n--> Calculadora de número fatorial <--\n");
    printf("************************");
    printf("\033[0;0m"); // Resetando texto para cor padrão
    printf("\n\n");

    // Declaração da variável inteira não negativa
    unsigned int num;

    // Inserção do número positivo não negativo (inteiros sem sinal)
    printf("Insira um número inteiro não negativo:");
    scanf("%i", &num);

    // Exibição do resultado via chamada da função fatorial()
    printf("\n\nO resultado de %i! é %i\n", num, fatorial(num));

    // Retorno da função main()
    return 0;
}

// Declaração da função fatorial()
int fatorial(int num)
{
    /**
     * Para o entendimento da função fatorial(),
     * note e adote as seguintes considerações:
     * 
     * 1) Para 5!, temos: 5 x 4 x 3 x 2 x 1
     * 
     * 1.2) Como ao multiplicar um número por 1 recebemos o mesmo 
     * número, é possível escrever 5! da seguinte forma:
     * 5 x 4 x 3 x 2
     * 
     * 1.3) Ou seja, para 5! multiplicamos todos os números dentro
     * do intervalo de 2 até 5.
     * 
     * 2) Como por definição 0! = 1, o valor mínimo de n!, 
     * sendo n um número inteiro não negativo, sempre será 1, pois 
     * 0 sempre será o menor número possível de n.
     * 
     * 
     * Portanto, com base nas considerações, e generalizando 
     * para qualquer número inteiro não negativo, temos, 
     * transcrito em código:
     */

    // Atribuição do valor 1 à variável v
    // 0! = 1
    unsigned int v = 1;

    // Para cada número dentro do intervalo [2, num],
    // sendo 'num' um parâmetro genérico inteiro não negativo
    for (size_t i = 2; i <= num; i++)
    {
        // Multiplica o elemento do intervalo à variável v
        v = v * i;
    }

    // Retorna o valor de v
    return v;
}