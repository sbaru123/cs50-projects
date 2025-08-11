#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    double average = 0.0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (image[i][j].rgbtRed == image[i][j].rgbtGreen && image[i][j].rgbtRed == image[i][j].rgbtBlue) {
                j++;
                j--;
            }
            else {
                average = image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue;
                average /= 3;
                average = (int) round(average);
                image[i][j].rgbtRed = average;
                image[i][j].rgbtGreen = average;
                 image[i][j].rgbtBlue = average;
            }
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            

        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
