#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 30
#define MAX_ITEMS 10

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

    char licensePlates[MAX_ITEMS][MAX_CHARS] = { '\0' };

    // Read the file row by row but insetrts the '\n' at the end of strings
    // int itemCount = 0;
    // do
    // {
    //     fgets (licensePlates[itemCount], MAX_CHARS, fp);
    //     printf ("%s\n", licensePlates[itemCount]);

    //     itemCount++;

    // } while (feof(fp) == 0);

    __int32 itemCount = 0;
    __int32 charCount = 0;

    char readChar = '\0';

    while ((readChar = getc (fp)) != EOF)
    {
        if (readChar != '\n' && charCount < MAX_CHARS)
        {
            licensePlates[itemCount][charCount++] = readChar;
        }
        else
        {
            itemCount++;
            charCount = 0;
        }
    }

    for (int i = 0; i < itemCount; i++)
    {
        printf ("%s\n", licensePlates[i]);
    }


    fclose(fp);
    fp = NULL;

    return EXIT_SUCCESS;
}