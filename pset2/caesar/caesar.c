#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #define typeof(var) _Generic( (var),\
// char: "Char",\
// int: "Integer",\
// float: "Float",\
// char *: "String",\
// void *: "Pointer",\
// default: "Undefined")

int main(int argc, string argv[])
{
    int n, i = 0, key;
    // Verify key is numeric value
    if (argc != 2 || !isdigit(argv[1][0]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Caesar Key
    key = atoi(argv[1]);
    string Pi = get_string("plaintext: ");
    string Ci = Pi;

    // a = 65 and A = 97 ascii table
    n = strlen(Pi);
    while (i <= n)
    {
        if (isalpha(Pi[i]) && Pi[i] > 64 && Pi[i] < 91)
        {
            Ci[i] = 65 + (Pi[i] - 65 + key) % 26;
        }
        else if (isalpha(Pi[i]) && Pi[i] > 96 && Pi[i] < 123)
        {
            Ci[i] = 97 + (Pi[i] - 97 + key) % 26;
        }
        i++;
    }
    printf("ciphertext: %s\n", Ci);
    return 0;
}
