#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    // valor inicial ao usuário
    int pop_inicial, pop_final, populacao, anos = 0;

    pop_inicial = get_int("Tamanho inicial: ");
    do
    {
        if (pop_inicial < 9)
        {
            pop_inicial = get_int("Tamanho inicial: ");
        }
    }
    while (pop_inicial < 9);

    pop_final = get_int("Tamanho final: ");
    do
    {
        if (pop_final < pop_inicial)
        {
            pop_final = get_int("Tamanho final: ");
        }
    }
    while (pop_final < pop_inicial);

    // Calculo do número de anos até o limite
    populacao = pop_inicial;
    do
    {
        anos++;
        populacao = populacao + (int) populacao / 3 - (int) populacao / 4;
    }
    while (populacao < pop_final);
    // Imprime o número de anos
    printf("Anos: %i\n", anos);
    return 0;
}
