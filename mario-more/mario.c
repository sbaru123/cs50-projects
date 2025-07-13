#include <cs50.h>
#include <stdio.h>

void pyramid(int height);

int main(void)
{
    int input = get_int("Height: ");
    pyramid(input);
}

void pyramid(int height) {

    for (int i = 0; i < height; i++) {

        for (int j = 0; j < 5; j++ ) {

            printf("#");

    }
printf("\n");
}
}
