#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    FILE *memoryCard = fopen(argv[1], "r");
    if (memoryCard == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    uint8_t buffer[512];
    int count = 0;
    int found_jpg = 1;
    FILE *img = NULL;
    char filename[8];

    while (fread(buffer, 1, 512, memoryCard) == 512)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            found_jpg = 0;
        }

        if (found_jpg == 0)
        {
            if (count != 0)
            {
                fclose(img);
            }

            sprintf(filename, "%03i.jpg", count);
            count++;

            img = fopen(filename, "w");
            fwrite(buffer, 1, 512, img);
            found_jpg = 1;
        }
        else if (count != 0)
        {
            fwrite(buffer, 1, 512, img);
        }
    }
    fclose(img);
    fclose(memoryCard);
}
