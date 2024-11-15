#include<stdio.h>
#include<cs50.h>

int main (void){
    long x = get_long("x: ");

    long y = get_long("y: ");

    printf("A soma de x e y é igual a: %li \n", x+y);

    //Compara x com y
    if( x < y){
        printf("x é meno do que y\n");
    }else if(x > y){
        printf("x é maior do que y\n");
    }else{
        printf("x é igual a y");
    }

}
