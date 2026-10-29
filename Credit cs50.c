#include <cs50.h>
#include <stdio.h>

long get_number(void);
int main(void)
{
    long digit = 0;
    long count = 0;
    long number = get_number();
    long n = number;
    long credit = number;
    int by;
    int mul;
    int plus;
    int sum;
    int total;
    int proof;
    int i;

    while (number > 0)
    {
        number = number / 10;
        digit++;
    }

    // Luhn's algorithm
    while (n > 0)
    {
        by = n % 10;
        n = n / 10;
        count++;

        if (count % 2 == 0)
        {
            mul = by * 2;
            plus = plus + (mul % 10) + (mul / 10);
        }

        else
        {
            sum = sum + by;
        }
    }

    total = plus + sum;

    proof = total % 10;

    // First two numbers
    while (credit > 99)
    {
        credit = credit / 10;
    }

    // First number
    i = credit / 10;

    if (digit < 13 || digit > 16 || proof != 0)
    {
        printf("INVALID\n");
    }

    else if ((credit == 34 || credit == 37) && digit == 15)
    {
        printf("AMEX\n");
    }

    else if ((credit >= 51 && credit <= 55) && digit == 16)
    {
        printf("MASTERCARD\n");
    }

    else if (i == 4 && (digit == 13 || digit == 16))
    {
        printf("VISA\n");
    }

    else
    {
        printf("INVALID\n");
    }
}

// variable
long get_number(void)
{
    long number;
    do
    {
        number = get_long("Number:");
    }
    while (number < 0);
    return number;
}
