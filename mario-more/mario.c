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

        for (int spaces = 0; spaces < height - 1; spaces++ ) {

            printf(" ");
        }

         for (int bricks = height; bricks > 0; spaces++ ) {

            printf("#");
        }

    }
printf("\n");
}
}
