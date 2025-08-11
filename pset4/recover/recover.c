#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
   if (argc != 2)
    {
        printf("Usage: ./recover card.raw\n");
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

   while (fread(&buffer, sizeof(uint8_t), 1, memoryCard) == 512) {
    count = 0;
    if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] && 0xf0) == 0xe0) {
        if (count == 0) {
        sprintf(argv[1] , "%03i.jpg" , count);
        count++;
        }
        else {
        FILE *img = fopen(argv[1] , "w");
        fwrite(&buffer, sizeof(uint8_t), 1, img)
        }
    }
   }


}
