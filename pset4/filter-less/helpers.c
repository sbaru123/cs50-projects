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
    double sepiaRed = 0;
    double sepiaGreen = 0;
    double sepiaBlue = 0;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            sepiaRed = (int) round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue);
            sepiaGreen = (int) round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue);
            sepiaBlue = (int) round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue);
            if (sepiaRed > 255) {
                sepiaRed = 255;
            }
             if (sepiaBlue > 255) {
                sepiaBlue = 255;
            }
             if (sepiaGreen > 255) {
                sepiaGreen = 255;
            }
             image[i][j].rgbtRed = sepiaRed;
             image[i][j].rgbtGreen = sepiaBlue;
             image[i][j].rgbtBlue = sepiaGreen;

        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE temp;
    int newWidth = width - 1;
      for (int i = 0; i < height; i++) {
        for (int j = 0; j < width / 2; j++) {
            temp = image[i][newWidth - j];
            image[i][newWidth - j] = image[i][j];
            image[i][j] = temp;

        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int avgRed = 0;
    int avgBlue = 0;
    int avgGreen = 0;
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
            if ((i + 1) < height && (i + 1) > 0) {
                avgRed += copy[i + 1][j].rgbtRed;
                avgBlue += copy[i + 1][j].rgbtBlue;
                avgGreen += copy[i + 1][j].rgbtGreen;
            }

             if ((i - 1) >= 0 && (i - 1) < height) {
                 avgRed += copy[i - 1][j].rgbtRed;
                avgBlue += copy[i - 1][j].rgbtBlue;
                avgGreen += copy[i - 1][j].rgbtGreen;
             }

             if ((j + 1) < width && (i + 1) > 0) {
                avgRed += copy[i][j + 1].rgbtRed;
                avgBlue += copy[i][j + 1].rgbtBlue;
                avgGreen += copy[i + 1][j].rgbtGreen;
            }

             if ((i - 1) >= 0 && (i - 1) < width) {
                 avgRed += copy[i - 1][j].rgbtRed;
                avgBlue += copy[i - 1][j].rgbtBlue;
                avgGreen += copy[i - 1][j].rgbtGreen;
             }
        }
    }
      return;
}


