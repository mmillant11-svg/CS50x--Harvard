#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int datos(string word, int value[]);
int main(void)
{
    // pedir las palabras//
    string p1 = get_string("Player 1: ");
    string p2 = get_string("Player 2: ");

    // El valor de cada letra//
    int value[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    int first = datos(p1, value);
    int second = datos(p2, value);

    // Establecer el ganador
    if (first > second)
    {
        printf("Player 1 wins!\n");
    }
    else if (first == second)
    {
        printf("Tie!\n");
    }
    else
    {
        printf("Player 2 wins!\n");
    }
}

// Funcion para establecer el puntaje de cada jugador
int datos(string word, int value[])
{
    int length;
    int sum = 0;
    length = strlen(word);

    for (int i = 0; i < length; i++)
    {
        int x = isalpha(word[i]);

        if (x != 0)
        {
            char mayus = toupper(word[i]);
            int place = mayus - 'A';
            sum = sum + value[place];
        }
    }
    return sum;
}
