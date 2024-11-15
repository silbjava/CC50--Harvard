#include<stdio.h>
#include<cs50.h>


int main (void){
    string resposta = get_string("Qual o seu nome ?");
    printf("Hello, %s \n", resposta);
}
