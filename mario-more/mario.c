#include <cs50.h>
#include <stdio.h>

void pyramid(int height);

int main(void)
{
    int input = get_int("Height: ");
    pyramid(input);
}

void pyramid(int height) {

    for (int row = 1; row <= height; row++) {

        for (int spaces = 0; spaces < height - row; spaces++ ) {

            printf(" ");
        }

         for (int bricks = 0; bricks < row; bricks++ ) {

            printf("#");
        }

        printf("  ");

         for (int bricks = 0; bricks < row; bricks++ ) {

            printf("#");
        }
        printf("\n");
    }

}

