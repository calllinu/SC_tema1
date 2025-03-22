#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Funcție pentru compararea cheii de transpunere
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void encrypt_columns_transposition(const char *text, int key, const char *output_file)
{
    int len = strlen(text);
    int cols = key;
    int rows = (len + cols - 1) / cols;
    char matrix[rows][cols];
    int index = 0;

    // Umple matricea cu textul, completând cu 'X' dacă este necesar
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (index < len)
                matrix[i][j] = text[index++];
            else
                matrix[i][j] = 'X'; // Caracter de umplere a randului
        }
    }

    // Scrie coloanele în fișierul de ieșire
    FILE *fout = fopen(output_file, "w");
    if (!fout)
    {
        perror("Eroare la deschiderea fișierului de ieșire");
        exit(EXIT_FAILURE);
    }

    for (int j = 0; j < cols; j++)
    {
        for (int i = 0; i < rows; i++)
        {
            fputc(matrix[i][j], fout);
        }
    }

    fclose(fout);
}

void decrypt_columns_transposition(const char *text, int key, const char *output_file)
{
    int len = strlen(text);
    int cols = key;
    int rows = (len + cols - 1) / cols;
    char matrix[rows][cols];
    int index = 0;

    // Umple matricea pe coloane (în funcție de textul criptat)
    for (int j = 0; j < cols; j++)
    {
        for (int i = 0; i < rows; i++)
        {
            if (index < len)
                matrix[i][j] = text[index++];
        }
    }

    // Citește matricea pe rânduri
    FILE *fout = fopen(output_file, "w");
    if (!fout)
    {
        perror("Eroare la deschiderea fișierului de ieșire");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            fputc(matrix[i][j], fout);
        }
    }

    fclose(fout);
}

void process_file(const char *input_file, const char *output_file, int key, int decrypt)
{
    FILE *fin = fopen(input_file, "r");
    if (!fin)
    {
        perror("Eroare la deschiderea fișierului de intrare");
        exit(EXIT_FAILURE);
    }

    char text[1024];
    fgets(text, sizeof(text), fin);
    fclose(fin);

    if (decrypt)
        decrypt_columns_transposition(text, key, output_file);
    else
        encrypt_columns_transposition(text, key, output_file);
}

int main(int argc, char *argv[])
{
    char *input_file = NULL;
    char *output_file = NULL;
    int key = 0;
    int decrypt = 0;

    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-e") == 0 && i + 1 < argc)
        {
            input_file = argv[++i];
        }
        else if (strcmp(argv[i], "-d") == 0 && i + 1 < argc)
        {
            input_file = argv[++i];
            decrypt = 1;
        }
        else if (strcmp(argv[i], "-k") == 0 && i + 1 < argc)
        {
            key = atoi(argv[++i]);
        }
        else if (strcmp(argv[i], "-o") == 0 && i + 1 < argc)
        {
            output_file = argv[++i];
        }
    }

    if (!input_file || !output_file || key <= 0)
    {
        fprintf(stderr, "Utilizare: %s -e|-d input_file -k key -o output_file\n", argv[0]);
        return EXIT_FAILURE;
    }

    process_file(input_file, output_file, key, decrypt);
    return EXIT_SUCCESS;
}
