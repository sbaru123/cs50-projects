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

   while (fread(&buffer, sizeof(uint8_t), 1, memoryCard) == 512) {

   }


}
