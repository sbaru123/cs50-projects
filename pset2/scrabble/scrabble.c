#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int getScore(string word);

    string p1Answer = get_string("Player 1: ");
    string p2Answer = get_string("Player 2: ");
    int p1Score = getScore(p1Answer);
    int p2Score = getScore(p2Answer);
    if (p1Score > p2Score)
    {
        printf("Player 1 wins!\n");
    }
    else if (p1Score < p2Score)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int getScore(string word)
{
    int score = 0;
    int sum = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        word[i] = tolower(word[i]);
        if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'l' ||
            word[i] == 'n' || word[i] == 'o' || word[i] == 'r' || word[i] == 's' ||
            word[i] == 't' || word[i] == 'u')
        {
            score = 1;
        }
        else if (word[i] == 'd' || word[i] == 'g')
        {
            score = 2;
        }
        else if (word[i] == 'b' || word[i] == 'c' || word[i] == 'm' || word[i] == 'p')
        {
            score = 3;
        }
        else if (word[i] == 'f' || word[i] == 'h' || word[i] == 'v' || word[i] == 'w' ||
                 word[i] == 'y')
        {
            score = 4;
        }
        else if (word[i] == 'k')
        {
            score = 6;
        }
        else if (word[i] == 'j' || word[i] == 'x')
        {
            score = 8;
        }
        else if (word[i] == 'q' || word[i] == 'z')
        {
            score = 10;
        }
        else
        {
            score = 0;
        }
        sum += score;
    }

    return sum;
}
