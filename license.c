#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 30
#define MAX_ITEMS 10

#define BYTE 1
#define LICENSE_PLATE_LENGTH 7

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf ("Usage: <program> <plates.txt>\n");
        return EXIT_FAILURE;
    }

    char file_in[MAX_CHARS];

    strcpy_s (file_in, MAX_CHARS, argv[1]);

    FILE *fp = fopen (file_in, "r");

    if (fp == NULL)
    {
        printf ("Failed to open the file!\n");
        return EXIT_FAILURE;
    }

    char licensePlates1[MAX_ITEMS][MAX_CHARS] = { '\0' };
    char licensePlates2[MAX_ITEMS][MAX_CHARS] = { '\0' };

    // First way to read the file is to read it row by row 
    // then replace the '\n' with nul
    printf ("First way\n");

    __int32 itemCount = 0;
    
    while (fread (licensePlates1[itemCount], BYTE, LICENSE_PLATE_LENGTH, fp) == LICENSE_PLATE_LENGTH)
    {
        licensePlates1[itemCount++][6] = '\0';
    } 

    for (int i = 0; i < itemCount; i++)
    {
        printf ("%s\n", licensePlates1[i]);
    }


    // Second way to read the file is to read charachter by character
    fp = freopen (file_in, "r", fp);

    printf ("\n");
    printf ("Second way\n");

    itemCount = 0;
    __int32 charCount = 0;

    char readChar = '\0';

    while ((readChar = getc (fp)) != EOF)
    {
        if (readChar != '\n' && charCount < MAX_CHARS)
        {
            licensePlates2[itemCount][charCount++] = readChar;
        }
        else
        {
            itemCount++;
            charCount = 0;
        }
    }

    for (int i = 0; i < itemCount; i++)
    {
        printf ("%s\n", licensePlates2[i]);
    }


    fclose(fp);
    fp = NULL;

    return EXIT_SUCCESS;
}