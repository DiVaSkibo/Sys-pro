#include "header.h"

void invert_case(FILE *fin, FILE *fout)
{
    char c;
    while ((c = fgetc(fin)) != EOF)
    {
        if (isupper(c))
        {
            fputc(tolower(c), fout);
        }
        else
        {
            fputc(toupper(c), fout);
        }
    }
}
void a_into_Ao(FILE* fin, FILE* fout)
{
    char c;
    while ((c = fgetc(fin)) != EOF)
    {
        if (c == 'a')
        {
            fprintf(fout, "Ao");
        }
        else
        {
            fputc(c, fout);
        }
    }
}
void o_into_Oa(FILE* fin, FILE* fout)
{
    char c;
    while ((c = fgetc(fin)) != EOF)
    {
        if (c == 'o')
        {
            fprintf(fout, "Oa");
        }
        else
        {
            fputc(c, fout);
        }
    }
}
void number_into_text(FILE* fin, FILE* fout)
{
    char c;
    while ((c = fgetc(fin)) != EOF)
    {
        switch (c)
        {
        case '0':
            fprintf(fout, "zero");
            break;
        case '1':
            fprintf(fout, "one");
            break;
        case '2':
            fprintf(fout, "two");
            break;
        case '3':
            fprintf(fout, "three");
            break;
        case '4':
            fprintf(fout, "four");
            break;
        case '5':
            fprintf(fout, "five");
            break;
        case '6':
            fprintf(fout, "six");
            break;
        case '7':
            fprintf(fout, "seven");
            break;
        case '8':
            fprintf(fout, "eight");
            break;
        case '9':
            fprintf(fout, "nine");
            break;
        default:
            fputc(c, fout);
        }
    }
}
void cyrillic_into_latin(FILE* fin, FILE* fout)
{
    wchar_t c;
    while ((c = fgetwc(fin)) != WEOF)
    {
        switch (c)
        {
            case L'А': fputws(L"A", fout); break;
            case L'а': fputws(L"a", fout); break;
            case L'Б': fputws(L"B", fout); break;
            case L'б': fputws(L"b", fout); break;
            case L'В': fputws(L"V", fout); break;
            case L'в': fputws(L"v", fout); break;
            case L'Г': fputws(L"G", fout); break;
            case L'г': fputws(L"g", fout); break;
            case L'Д': fputws(L"D", fout); break;
            case L'д': fputws(L"d", fout); break;
            case L'Е': fputws(L"E", fout); break;
            case L'е': fputws(L"e", fout); break;
            case L'Ё': fputws(L"Yo", fout); break;
            case L'ё': fputws(L"yo", fout); break;
            case L'Ж': fputws(L"Zh", fout); break;
            case L'ж': fputws(L"zh", fout); break;
            case L'З': fputws(L"Z", fout); break;
            case L'з': fputws(L"z", fout); break;
            case L'И': fputws(L"I", fout); break;
            case L'и': fputws(L"i", fout); break;
            case L'Й': fputws(L"Y", fout); break;
            case L'й': fputws(L"y", fout); break;
            case L'К': fputws(L"K", fout); break;
            case L'к': fputws(L"k", fout); break;
            case L'Л': fputws(L"L", fout); break;
            case L'л': fputws(L"l", fout); break;
            case L'М': fputws(L"M", fout); break;
            case L'м': fputws(L"m", fout); break;
            case L'Н': fputws(L"N", fout); break;
            case L'н': fputws(L"n", fout); break;
            case L'О': fputws(L"O", fout); break;
            case L'о': fputws(L"o", fout); break;
            case L'П': fputws(L"P", fout); break;
            case L'п': fputws(L"p", fout); break;
            case L'Р': fputws(L"R", fout); break;
            case L'р': fputws(L"r", fout); break;
            case L'С': fputws(L"S", fout); break;
            case L'с': fputws(L"s", fout); break;
            case L'Т': fputws(L"T", fout); break;
            case L'т': fputws(L"t", fout); break;
            case L'У': fputws(L"U", fout); break;
            case L'у': fputws(L"u", fout); break;
            case L'Ф': fputws(L"F", fout); break;
            case L'ф': fputws(L"f", fout); break;
            case L'Х': fputws(L"Kh", fout); break;
            case L'х': fputws(L"kh", fout); break;
            case L'Ц': fputws(L"Ts", fout); break;
            case L'ц': fputws(L"ts", fout); break;
            case L'Ч': fputws(L"Ch", fout); break;
            case L'ч': fputws(L"ch", fout); break;
            case L'Ш': fputws(L"Sh", fout); break;
            case L'ш': fputws(L"sh", fout); break;
            case L'Щ': fputws(L"Sch", fout); break;
            case L'щ': fputws(L"sch", fout); break;
            case L'Ъ': fputws(L"Y", fout); break;
            case L'ъ': fputws(L"y", fout); break;
            case L'Ы': fputws(L"Y", fout); break;
            case L'ы': fputws(L"y", fout); break;
            case L'Ь': fputws(L"`", fout); break;
            case L'ь': fputws(L"`", fout); break;
            case L'Э': fputws(L"E", fout); break;
            case L'э': fputws(L"e", fout); break;
            case L'Ю': fputws(L"Yu", fout); break;
            case L'ю': fputws(L"yu", fout); break;
            case L'Я': fputws(L"Ya", fout); break;
            case L'я': fputws(L"ya", fout); break;
        default:
            fputwc(c, fout);
        }
    }
}