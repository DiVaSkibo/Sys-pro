#include "header.h"

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        fprintf(stderr, "{ Not enough arguments... }\n");
        printf("[ Waited for: %s <task> <input file> <output file> ]\n", argv[0]);
        return 1;
    }

    FILE
        *fin = fopen(argv[2], "r"),
        *fout = fopen(argv[3], "w");

    if (!fin)
    {
        fprintf(stderr, "{ File %s wasn`t found... }\n", argv[2]);
    }
    if (!fout)
    {
        fprintf(stderr, "{ File %s wasn`t found... }\n", argv[3]);
    }
    if (!fin || !fout)
    {
        fclose(fin);
        fclose(fout);
        return 1;
    }
    
    setlocale(LC_ALL, "");

    switch (atoi(argv[1]))
    {
    case 1:
        invert_case(fin, fout);
        fseek(fin, 0, SEEK_END);
        fseek(fout, ftell(fin) / 2, SEEK_SET);
        break;
    case 2:
        a_into_Ao(fin, fout);
        fseek(fout, 20, SEEK_SET);
        break;
    case 3:
        o_into_Oa(fin, fout);
        fseek(fout, -20, SEEK_END);
        break;
    case 4:
        number_into_text(fin, fout);
        fseek(fout, -5, SEEK_END);
        break;
    case 5:
        cyrillic_into_latin(fin, fout);
        fseek(fout, -10, SEEK_END);
        break;
    default:
        fprintf(stderr, "{ No task #%s... }\n", argv[1]);
    }
    fprintf(fout, "{ Skibo Dmytro Viacheslavovich 335a }");

    fclose(fin);
    fclose(fout);
    return 0;
}