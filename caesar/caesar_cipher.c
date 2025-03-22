#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Funcție care aplică cifrarea Caesar pe un text dat
void caesar_cipher(char *text, int shift)
{
    for (int i = 0; text[i] != '\0'; i++)
    {
        char c = text[i];
        if (isalpha(c))
        {
            char base = isupper(c) ? 'A' : 'a';
            text[i] = (c - base + shift + 26) % 26 + base;
        }
    }
}

// Funcție care procesează fișierele pentru criptare sau decriptare
void process_file(const char *input_file, const char *output_file, int shift)
{
    FILE *fin = fopen(input_file, "r");
    if (!fin)
    {
        perror("Eroare la deschiderea fișierului de intrare");
        exit(EXIT_FAILURE);
    }

    FILE *fout = fopen(output_file, "w");
    if (!fout)
    {
        perror("Eroare la deschiderea fișierului de ieșire");
        fclose(fin);
        exit(EXIT_FAILURE);
    }

    char line[1024];
    while (fgets(line, sizeof(line), fin))
    {
        caesar_cipher(line, shift);
        fputs(line, fout);
    }

    fclose(fin);
    fclose(fout);
}

int main(int argc, char *argv[])
{
    char *input_file = NULL;
    char *output_file = NULL;
    int shift = 0;
    int mode = 0; // 1 pentru criptare, -1 pentru decriptare

    // Parcurgem argumentele din linia de comandă
    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-e") == 0 && i + 1 < argc)
        {
            input_file = argv[++i];
            mode = 1;
        }
        else if (strcmp(argv[i], "-d") == 0 && i + 1 < argc)
        {
            input_file = argv[++i];
            mode = -1;
        }
        else if (strcmp(argv[i], "-k") == 0 && i + 1 < argc)
        {
            shift = atoi(argv[++i]);
        }
        else if (strcmp(argv[i], "-o") == 0 && i + 1 < argc)
        {
            output_file = argv[++i];
        }
    }

    // Verificăm dacă toate argumentele necesare sunt prezente
    if (!input_file || !output_file || mode == 0 || shift == 0)
    {
        fprintf(stderr, "Utilizare: %s -e|-d input_file -k key -o output_file\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Ajustăm shift-ul pentru decriptare
    if (mode == -1)
    {
        shift = -shift;
    }

    shift = shift % 26;
    if (shift < 0)
    {
        shift += 26;
    }

    process_file(input_file, output_file, shift);
    return EXIT_SUCCESS;
}
