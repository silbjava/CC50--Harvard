#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;

    do
    {
        height = get_int("Digite a altura da pirâmide:\n");

        if (height < 1 || height > 8)
        {
            printf("Tamanho inválido! Por favor, insira um número entre 1 e 8.\n");
        }
    }
    while (height < 1 || height > 8);

    for (int i = 1; i <= height; i++)
    {
        for (int j = 1; j <= height - i; j++)
        {
            printf(" ");
        }
        for (int j = 1; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }

    return 0;
}
