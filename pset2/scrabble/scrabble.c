#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    int points_p1, points_p2;
    // Solicitar ao usuário duas palavras
    string word_1 = get_string("Player 1: ");

    string word_2 = get_string("Player 2: ");
    // Calcular os pontos de cada palavra
    points_p1 = compute_score(word_1);

    points_p2 = compute_score(word_2);
    // Imprimir o vencedor
    if(points_p1 > points_p2){
        printf("Player 1 wins! \n");
    }else if(points_p1 < points_p2){
        printf("Player 2 wins! \n");
    }else{
        printf("Tie! \n");
    }
}

int compute_score(string word)
{
    int c, i, n, sum = 0;
    // Computa e devolve os pontos de cada palavra
     for ( i = 0, n = strlen(word); i < n; i++)
     {
        c = (int)(toupper(word[i])) - 65;
        sum += POINTS[c];
     }

    return sum;
}
