#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    float troco;
    // Instanciando variaveis inteiras as moedas de 25, 10, 5 e 1 centavos
    int m25 = 0, m10 = 0, m5 = 0, m1 = 0, moedas, centavos;
    do
    {
        troco = get_float("Digite o valor de troco:\n");

        if (troco < 0)
        {
            printf("Valor inválido! Por favor, insira uma quantia valida.\n");
        }
    }
    while (troco < 0);

    //Valor inteiro em centavos
    int centavos = round(troco * 100);

    while (centavos> 0)
    {
        if (centavos>= 25)
        {
            m25 = valor_troca/025;
            centavos-= 0.25 * m25;
        }
        else if (centavos>= 0.10)
        {
            m10 = valor_troca/0.1;
            centavos-= 0.1 * m10;
        }
        else if (centavos>= 0.05)
        {
            m5 = valor_troca/0.05;
            centavos-= 0.05 * m5;
        }
        else
        {
            m1++;
            centavos-= 0.01;

        }
    }

    moedas = m25 + m10 + m5 + m1;
    if (troco >= 0.00)
    {
        printf("Troca devida: %.2f\n", troco);
        // Imprime o total de moedas pra serem destinadas ao valor de troco
        printf("%i\n", moedas);
        printf("%i, %i, %i, %i \n", m25,m10,m5,m1);
    }

    return 0;
}
