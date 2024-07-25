#include <stdio.h>
#include <ctype.h>
#include <string.h>

#ifndef ANALEX_H
#define ANALEX_H
#define TAM_MAX_LEXEMA 100

// Definição dos tokens
typedef enum {
    ID,             // Identificador
    PAL_RESERV,     // Palavra reservada
    OP_ARIT,        // Operador aritmético
    OP_RELAC,       // Operador relacional
    SINAL,          // Sinal de pontuação
    CONST_INT,      // Constante inteira
    CONST_STRING,   // Constante string
    FIM_PROG        // Fim do programa
} CategoriaToken;

// Códigos para operadores relacionais
typedef enum {
    MAIOR_IGUAL,    // >=
    MENOR_IGUAL,    // <=
    IGUAL,    // ==
    DIFERENTE       // !=
} CodigoToken;

// Estrutura para armazenar tokens
typedef struct {
    CategoriaToken cat;     // Categoria do token
    int codigo;             // Código específico para certos tokens (como operadores)
    char lexema[TAM_MAX_LEXEMA];  // Lexema do token
    union {
        int valInt;         // Valor inteiro para constantes inteiras
    };
} TOKEN;

extern TOKEN token;
extern FILE *fd;
extern TOKEN AnaLex(FILE *);

#endif
