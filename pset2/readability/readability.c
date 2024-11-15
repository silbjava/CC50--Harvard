#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
    int i, n, spc = 0, words = 0, sentences = 0, letters = 0;
    float L, S;
    string text = get_string("Text: ");
    for ( i = 0, n = strlen(text); i < n; i++)
    {
        if(text[i] == '.' || text[i] == '!' || text[i] == '?'){
            sentences += 1;
        }else if( text[i] == 32){
            spc++;
            words = spc+1;
        }if (('a' <= text[i] && text[i] <= 'z') || ('A' <= text[i] && text[i] <= 'Z')){
            letters += 1;
        }
    }
    L = round(pow(10,4) * letters/words)/100;
    S = round(pow(10,4) * sentences/words)/100;
    if((int)(round(0.0588 * L - 0.296 * S - 15.8)) < 2){
        printf("Before Grade 1 \n");
    }else if((int)(round(0.0588 * L - 0.296 * S - 15.8)) >= 16){
        printf("Grade 16+ \n");
    }else{
        printf("Grade:  %d\n",(int)(round(0.0588 * L - 0.296 * S - 15.8)));
    }
}
