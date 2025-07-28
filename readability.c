#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int getLevel(string text);

int main(void)
{
    string input = get_string("Text: ");
    int gradeLevel = getLevel(input);
    string answer = "";
    if (gradeLevel < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (gradeLevel >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", gradeLevel);
    }
}

int getLevel(string text)
{
    float index = 0.0;
    double totalL = 0;
    double totalS = 0;
    double totalW = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == ' ')
        {
            totalW++;
        }
        else if ((text[i] == '.' || text[i] == '!' || text[i] == '?') && (i != n - 1))
        {
            totalS++;
        }
        else if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            totalL++;
        }
        else if (i == n - 1 && text[n - 1] != '"')
        {
            totalW++;
            totalS++;
        }
    }

    float L = (totalL / totalW) * 100;
    float S = (totalS / totalW) * 100;

    index = (0.0588 * L - 0.296 * S - 15.8);
    index = (int) round(index);
    return index;
}
