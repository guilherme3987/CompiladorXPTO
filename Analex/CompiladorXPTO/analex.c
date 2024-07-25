#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "analex.h"
#include <stdlib.h>

// Definindo o token global
TOKEN tk;

TOKEN AnaLex(FILE *fd) {
    int estado = 0;
    int tamL = 0;
    char lexema[TAM_MAX_LEXEMA] = "";
    TOKEN token;

    while (1) {
        char c = fgetc(fd);

        switch (estado) {
            case 0:
                if (c == ' ' || c == '\t' || c == '\n') {
                    // Ignora espaços em branco e nova linha
                    estado = 0;
                }
                else if (isalpha(c)) { // Identificadores e palavras reservadas
                    estado = 1;
                    lexema[tamL++] = c;
                }
                else if (isdigit(c)) { // Números inteiros
                    estado = 2;
                    lexema[tamL++] = c;
                }
                else if (c == '"') { // Strings
                    estado = 3;
                    lexema[tamL++] = c;
                }
                else if (c == '(' || c == ')' || c == '{' || c == '}' || c == ';' || c == ',') {
                    // Sinais de pontuação
                    lexema[tamL++] = c;
                    lexema[tamL] = '\0';

                    token.cat = SINAL;
                    token.codigo = lexema[0]; // Usando o próprio caractere como código
                    strcpy(token.lexema, lexema);
                    return token;
                }
                else if (c == '=') {
                    estado = 4;
                    lexema[tamL++] = c;
                }
                else if (c == '+') {
                    lexema[tamL++] = c;
                    lexema[tamL] = '\0';

                    token.cat = OP_ARIT;
                    token.codigo = lexema[0]; // Usando o próprio caractere como código
                    strcpy(token.lexema, lexema);
                    return token;
                }
                else if (c == '-') {
                    lexema[tamL++] = c;
                    lexema[tamL] = '\0';

                    token.cat = OP_ARIT;
                    token.codigo = lexema[0]; // Usando o próprio caractere como código
                    strcpy(token.lexema, lexema);
                    return token;
                }
                else if (c == '*') {
                    lexema[tamL++] = c;
                    lexema[tamL] = '\0';

                    token.cat = OP_ARIT;
                    token.codigo = lexema[0]; // Usando o próprio caractere como código
                    strcpy(token.lexema, lexema);
                    return token;
                }
                else if (c == '>') {
                    estado = 5;
                    lexema[tamL++] = c;
                }
                else if (c == '<') {
                    estado = 6;
                    lexema[tamL++] = c;
                }
                else if (c == EOF) {
                    // Fim de arquivo
                    token.cat = FIM_PROG;
                    return token;
                }
                break;
            case 1:
                if (isalnum(c) || c == '_') {
                    lexema[tamL++] = c;
                }
                else {
                    ungetc(c, fd);
                    estado = 0;

                    // Verifica se é palavra reservada ou identificador
                    if (strcmp(lexema, "inicio") == 0) {
                        token.cat = PAL_RESERV;
                        token.codigo = 1; // Código específico para "inicio"
                    }
                    else if (strcmp(lexema, "fim") == 0) {
                        token.cat = PAL_RESERV;
                        token.codigo = 2; // Código específico para "fim"
                    }
                    else if (strcmp(lexema, "se") == 0) {
                        token.cat = PAL_RESERV;
                        token.codigo = 3; // Código específico para "se"
                    }
                    else if (strcmp(lexema, "entao") == 0) {
                        token.cat = PAL_RESERV;
                        token.codigo = 4; // Código específico para "entao"
                    }
                    else if (strcmp(lexema, "senao") == 0) {
                        token.cat = PAL_RESERV;
                        token.codigo = 5; // Código específico para "senao"
                    }
                    else if (strcmp(lexema, "enquanto") == 0) {
                        token.cat = PAL_RESERV;
                        token.codigo = 6; // Código específico para "enquanto"
                    }
                    else if (strcmp(lexema, "faca") == 0) {
                        token.cat = PAL_RESERV;
                        token.codigo = 7; // Código específico para "faca"
                    }
                    else if (strcmp(lexema, "imprima") == 0) {
                        token.cat = PAL_RESERV;
                        token.codigo = 8; // Código específico para "imprima"
                    }
                    else if (strcmp(lexema, "inteiro") == 0) {
                        token.cat = PAL_RESERV;
                        token.codigo = 9; // Código específico para "inteiro"
                    }
                    else if (strcmp(lexema, "string") == 0) {
                        token.cat = PAL_RESERV;
                        token.codigo = 10; // Código específico para "string"
                    }
                    else {
                        token.cat = ID;
                    }
                    
                    strcpy(token.lexema, lexema);
                    return token;
                }
                break;
            case 2:
                if (isdigit(c)) {
                    lexema[tamL++] = c;
                }
                else {
                    ungetc(c, fd);
                    estado = 0;

                    // Número inteiro
                    token.cat = CONST_INT;
                    token.valInt = atoi(lexema);
                    strcpy(token.lexema, lexema);
                    return token;
                }
                break;
            case 3:
                if (c == '"') {
                    lexema[tamL++] = c;
                    estado = 0;

                    // String literal
                    token.cat = CONST_STRING;
                    strcpy(token.lexema, lexema);
                    return token;
                }
                else if (isprint(c)) {
                    lexema[tamL++] = c;
                }
                break;
            case 4:
                if (c == '=') {
                    lexema[tamL++] = c;
                    lexema[tamL] = '\0';

                    token.cat = OP_RELAC;
                    token.codigo = IGUAL; // =
                    strcpy(token.lexema, lexema);
                    return token;
                }
                else {
                    ungetc(c, fd);
                    estado = 0;

                    // Atribuição
                    token.cat = OP_ARIT;
                    token.codigo = '='; // =
                    strcpy(token.lexema, lexema);
                    return token;
                }
                break;
            case 5:
                if (c == '=') {
                    lexema[tamL++] = c;
                    lexema[tamL] = '\0';

                    token.cat = OP_RELAC;
                    token.codigo = MAIOR_IGUAL; // >=
                    strcpy(token.lexema, lexema);
                    return token;
                }
                else {
                    ungetc(c, fd);
                    estado = 0;

                    // Operador relacional >
                    token.cat = OP_RELAC;
                    token.codigo = '>'; // >
                    strcpy(token.lexema, lexema);
                    return token;
                }
                break;
            case 6:
                if (c == '=') {
                    lexema[tamL++] = c;
                    lexema[tamL] = '\0';

                    token.cat = OP_RELAC;
                    token.codigo = MENOR_IGUAL; // <=
                    strcpy(token.lexema, lexema);
                    return token;
                }
                else {
                    ungetc(c, fd);
                    estado = 0;

                    // Operador relacional <
                    token.cat = OP_RELAC;
                    token.codigo = '<'; // <
                    strcpy(token.lexema, lexema);
                    return token;
                }
                break;
        }
    }
}


void printToken(TOKEN token) {
    switch (token.cat) {
        case ID:
            printf("<ID> <%s>\n", token.lexema);
            break;
        case CONST_INT:
            printf("<CONST_INT> <%d>\n", token.valInt);
            break;
        case CONST_STRING:
            printf("<CONST_STRING> <%s>\n", token.lexema);
            break;
        case SINAL:
            printf("<SINAL> <   %c   >\n", token.codigo);
            break;
        case OP_ARIT:
            printf("<OP_ARIT> <   %c  >\n", token.codigo);
            break;
        case OP_RELAC:
            printf("<OP_RELAC> <   %c  > \n", token.codigo);
            break;
        case PAL_RESERV:
            printf("<PAL_RESERV> <%s>\n", token.lexema);
            break;
        case FIM_PROG:
            printf("<FIM_PROG> \n");
            break;
        default:
            printf("<DESCONHECIDO> \n");
            break;
    }
}