#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <wchar.h>
#include <locale.h>

void invert_case(FILE*, FILE*);
void a_into_Ao(FILE*, FILE*);
void o_into_Oa(FILE*, FILE*);
void number_into_text(FILE*, FILE*);
void cyrillic_into_latin(FILE*, FILE*);
