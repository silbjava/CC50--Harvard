#include <cs50.h>
#include <math.h>
#include <stdio.h>

int find_length(long long n);
int valid_card(long long n_card, int l);

int main(void)
{

    // Get the card number from the user
    long long card_number = get_long("Card number: ");

    // Determine the card type based on the first few digits
    int length = find_length(card_number);
    // Call valid card number function
    int digit = valid_card(card_number, length);

    if (length == 15 && digit % 10 == 0)
    {
        printf("AMEX\n");
    }
    else if (length == 16 && digit % 10 == 0 && card_number / (long long) pow(10, 15) != 4)
    {
        printf("MASTERCARD\n");
    }
    else if ((length == 13 || length == 16) && digit % 10 == 0)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
    return 0;
}

// Finds the number of digits in a long long number
int find_length(long long n)
{
    int count = 0;
    while (n != 0)
    {
        n /= 10;
        ++count;
    }
    return count;
}

// Verify if number card is valid or not
int valid_card(long long n_card, int l)
{
    int n_cardx2 = 0, sum_dig_alt = 0, sum_dig_rem = 0, i;
    if (l % 2 == 0)
    {
        for (i = 1; i <= l; i++)
        {
            if (i == 1)
            {
                n_cardx2 = 2 * (int) (n_card / pow(10, l - 1));
                // verify if double card digit is greater than 9
                if (n_cardx2 >= 10)
                {
                    n_cardx2 = 1 + n_cardx2 % 10;
                    sum_dig_alt += n_cardx2;
                }
                else
                {
                    sum_dig_alt += n_cardx2;
                }
            }
            else if (i % 2 != 0)
            { // verify odd positions
                n_cardx2 = 2 * (int) (n_card % (long long) pow(10, l - i + 1) / pow(10, l - i));

                if (n_cardx2 >= 10)
                {
                    n_cardx2 = 1 + n_cardx2 % 10;
                    sum_dig_alt += n_cardx2;
                }
                else
                {
                    sum_dig_alt += n_cardx2;
                }
            }
            else
            {
                if (i != l)
                {
                    sum_dig_rem += (int) (n_card % (long long) pow(10, l - i + 1) / pow(10, l - i));
                }
                else
                {
                    sum_dig_rem += (int) (n_card % (long long) pow(10, l - i + 1));
                }
            }
        }
    }
    else
    {
        for (i = 1; i <= l; i++)
        {
            if (i == 1)
            {
                sum_dig_rem += (int) (n_card / pow(10, l - 1));
            }
            else if (i % 2 == 0)
            {
                n_cardx2 = 2 * (int) (n_card % (long long) pow(10, l - i + 1) / pow(10, l - i));

                // verify if double card digit is greater than 9
                if (n_cardx2 >= 10)
                {
                    n_cardx2 = 1 + n_cardx2 % 10;
                    sum_dig_alt += n_cardx2;
                }
                else
                {
                    sum_dig_alt += n_cardx2;
                }
            }
            else
            {
                sum_dig_rem += (int) (n_card % (long long) pow(10, l - i + 1) / pow(10, l - i));
            }
        }
    }
    return sum_dig_alt + sum_dig_rem;
}
