#include "helpers.h"
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float rgb_avg = 0.0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            rgb_avg = image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen;
            rgb_avg = rgb_avg / 3.0;
            int int_rgb_avg = round(rgb_avg);
            image[i][j].rgbtRed = int_rgb_avg;
            image[i][j].rgbtBlue = int_rgb_avg;
            image[i][j].rgbtGreen = int_rgb_avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiaRed, sepiaGreen, sepiaBlue;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            sepiaRed = round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue);
            sepiaGreen = round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue);
            sepiaBlue = round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue);

            image[i][j].rgbtRed = fmin(255, sepiaRed);
            image[i][j].rgbtGreen = fmin(255, sepiaGreen);
            image[i][j].rgbtBlue = fmin(255, sepiaBlue);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++)
    {
        int max_index = width - 1;
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE temp;
            if (width % 2 == 0)
            {
                if (j > max_index)
                {
                    break;
                }
                else
                {
                    temp = image[i][j];
                    image[i][j] = image[i][max_index];
                    image[i][max_index] = temp;
                    max_index--;
                }
            }
            else
            {
                if (j == max_index)
                {
                    break;
                }
                else
                {
                    temp = image[i][j];
                    image[i][j] = image[i][max_index];
                    image[i][max_index] = temp;
                    max_index--;
                }
            }
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    // We need a copy array to keep original values
    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
            copy[row][column] = image[row][column];
        }
    }

    int count = 0;
    float total_red = 0.0;
    float total_green = 0.0;
    float total_blue = 0.0;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            for (int m = i - 1; m <= i + 1; m++)
            {
                for (int k = j - 1; k <= j + 1; k++)
                {
                    if (m >= 0 && k >= 0 && k < width && m < height)
                    {
                        total_red += copy[m][k].rgbtRed;
                        total_blue += copy[m][k].rgbtBlue;
                        total_green += copy[m][k].rgbtGreen;
                        count++;
                    }
                }
            }

            image[i][j].rgbtRed = round(total_red / count);
            image[i][j].rgbtGreen = round(total_green / count);
            image[i][j].rgbtBlue = round(total_blue / count);
            count = 0;
            total_red = total_green = total_blue = 0;
        }
    }
    return;
}
