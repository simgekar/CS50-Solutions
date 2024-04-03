#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage ./recover filename.jpg\n");
        return 1;
    }
    FILE *f = fopen(argv[1], "r");
    if (f == NULL)
    {
        printf("Can not open the file\n");
        return 1;
    }
    int BLOCK_SIZE = 512;
    typedef uint8_t BYTE;
    BYTE buffer[BLOCK_SIZE];
    int jpeg_counter = 0;
    int bytes_read = 0;
    char filename[8];

    FILE *img = NULL;

    while (1)
    {
        bytes_read = fread(buffer, sizeof(BYTE), 512, f);

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && ((buffer[3] & 0xf0) == 0xe0))
        {
            if (jpeg_counter == 0)
            {
                sprintf(filename, "%03i.jpg", jpeg_counter);
                img = fopen(filename, "w");
                fwrite(buffer, sizeof(BYTE), bytes_read, img);
                jpeg_counter++;
            }
            else
            {
                fclose(img);
                sprintf(filename, "%03i.jpg", jpeg_counter);
                img = fopen(filename, "w");
                fwrite(buffer, sizeof(BYTE), bytes_read, img);
                jpeg_counter++;
            }
        }
        else if (jpeg_counter != 0)
        {
            fwrite(buffer, sizeof(BYTE), bytes_read, img);
            if (bytes_read == 0)
            {
                fclose(img);
                fclose(f);
                return 0;
            }
        }
    }
    fclose(img);
    fclose(f);
}
