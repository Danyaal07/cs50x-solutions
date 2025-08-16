#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("ERROR | Enter exactly one command line argument\n");
        return 1;
    }
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("File was not opened\n");
        return 1;
    }
    uint8_t buffer[512];
    FILE *img = NULL;
    int file_count = 0;
    char filename[8];
    while (fread(buffer, 1, 512, card) == 512)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3]  & 0xf0) == 0xe0)
        {
            if (img != NULL)
            {
                fclose(img);
            }
            sprintf(filename, "%03i.jpg", file_count);
            img = fopen(filename, "w");
            if (img == NULL)
            {
                printf("Could not create file %s\n", filename);
                fclose(card);
                return 1;
            }
            file_count++;
        }
        if (img != NULL)
        {
            fwrite(buffer, 1, 512, img);
        }
    }

    if (img != NULL)
    {
        fclose(img);
    }

    fclose(card);
    return 0;
}
