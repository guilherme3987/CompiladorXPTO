#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "analex.h"
#include "analex.c"

int main()
{
    FILE *fd = fopen("C:/Users/guilh/OneDrive/Documentos/CompiladorXPTO/Analex/CompiladorXPTO/xpto.dbk", "r");
    if (fd == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    TOKEN token;

    while ((token = AnaLex(fd)).cat != FIM_PROG)
    {
        printToken(token);
    }
    fclose(fd);
    return 0;
}
