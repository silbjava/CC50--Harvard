#include<stdio.h>
#include<cs50.h>

int main (void){
    char c = get_char("Você concorda? \n");

    if( c == 's'){
        printf("Eu concordo!! \n");
    }else if(c == 'n'){
        printf("Eu discordo!! \n");
    }
}
