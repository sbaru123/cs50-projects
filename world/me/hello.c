#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // prints hello world and moves cursor to next line
    string answer = get_string("What's your name? ");
    printf("hello, %s\n", answer);
}
