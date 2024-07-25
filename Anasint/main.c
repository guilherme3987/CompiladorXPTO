#include <stdio.h>
#include <stdlib.h>
#include "analex.h"
#include "anasint.h"

FILE *fd;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <caminho_do_arquivo>\n", argv[0]);
        return 1;
    }

    // Abre o arquivo de entrada
    fd = fopen(argv[1], "r");
    if (fd == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    // Executa a análise sintática
    analise_sintatica();

    // Fecha o arquivo
    fclose(fd);

    return 0;
}
