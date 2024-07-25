#include <stdio.h>
#include <stdlib.h>
#include "anasint.h"

// Funções auxiliares para análise
void programa();
void bloco();
void comando();
void condicao();
void repeticao();
void erro(const char *msg);

// Função para verificar o próximo token e avançar
TOKEN proximoToken() {
    TOKEN token = AnaLex(fd);
    printToken(token);
    return token;
}

// Função para verificar o próximo token sem avançar
TOKEN lookahead() {
    TOKEN token = AnaLex(fd);
    ungetc(token.lexema[0], fd);
    return token;
}

void erro(const char *msg) {
    printf("Erro: %s\n", msg);
    exit(EXIT_FAILURE);
}

void programa() {
    TOKEN token = proximoToken();
    if (token.cat != PAL_RESERV || token.codigo != 1) { // 'inicio'
        erro("Esperado 'inicio'");
    }
    
    bloco();
    
    token = proximoToken();
    if (token.cat != PAL_RESERV || token.codigo != 2) { // 'fim'
        erro("Esperado 'fim'");
    }
}

void bloco() {
    TOKEN token = proximoToken();
    
    while (token.cat != PAL_RESERV || token.codigo != 2) { // 'fim'
        ungetc(token.lexema[0], fd); // Retorna o token para análise posterior
        comando();
        token = proximoToken();
    }
    ungetc(token.lexema[0], fd); // Retorna o token para análise posterior
}

void comando() {
    TOKEN token = proximoToken();
    
    switch (token.cat) {
        case PAL_RESERV:
            switch (token.codigo) {
                case 7: // 'faca'
                    repeticao();
                    break;
                case 8: // 'imprima'
                    token = proximoToken();
                    if (token.cat != CONST_STRING && token.cat != ID) {
                        erro("Esperado constante string ou identificador após 'imprima'");
                    }
                    break;
                case 3: // 'se'
                    condicao();
                    break;
                default:
                    erro("Comando não reconhecido");
                    break;
            }
            break;
        case ID:
            token = proximoToken();
            if (token.cat != OP_ARIT || token.codigo != '=') {
                erro("Esperado '=' após identificador");
            }
            token = proximoToken();
            if (token.cat != CONST_INT) {
                erro("Esperado constante inteira após '='");
            }
            break;
        default:
            erro("Comando não reconhecido");
            break;
    }
}

void condicao() {
    TOKEN token = proximoToken();
    if (token.cat != OP_RELAC) {
        erro("Esperado operador relacional");
    }
    
    token = proximoToken();
    if (token.cat != PAL_RESERV || token.codigo != 4) { // 'entao'
        erro("Esperado 'entao'");
    }
    
    bloco();
    
    token = proximoToken();
    if (token.cat == PAL_RESERV && token.codigo == 5) { // 'senao'
        bloco();
    } else {
        ungetc(token.lexema[0], fd); // Retorna o token para análise posterior
    }
}

void repeticao() {
    TOKEN token = proximoToken();
    if (token.cat != OP_RELAC) {
        erro("Esperado operador relacional");
    }
    
    token = proximoToken();
    if (token.cat != PAL_RESERV || token.codigo != 6) { // 'enquanto'
        erro("Esperado 'enquanto'");
    }
    
    bloco();
    
    token = proximoToken();
    if (token.cat != PAL_RESERV || token.codigo != 7) { // 'faca'
        erro("Esperado 'faca'");
    }
    
    bloco();
    
    token = proximoToken();
    if (token.cat != PAL_RESERV || token.codigo != 6) { // 'fimenquanto'
        erro("Esperado 'fimenquanto'");
    }
}

void analise_sintatica() {
    programa();
    printf("Análise sintática concluída com sucesso.\n");
}
