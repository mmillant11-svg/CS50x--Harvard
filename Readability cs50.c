#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string text = get_string("Text: ");

    // Contador de datos
    float letter = 0;
    float word = 0;
    float sentence = 0;
    int n = strlen(text);

    for (int i = 0; i < n; i++)
    {
        int x = isalpha(text[i]);
        int y = isspace(text[i]);
       
        if (x != 0)
        {
            letter++;
        }

        if (y != 0)
        {
            word++;
        }

        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentence++;
        }
    }

    float L = (letter / (word + 1)) * 100;
    float S = (sentence / (word + 1)) * 100;

    float index = 0.0588 * L - 0.296 * S - 15.8;

    // Condicionales
    double grade = round(index);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }

    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %.0f\n", grade);
    }
}
