# Analisador Sintático

## Estrutura da Linguagem

A linguagem suporta as seguintes construções:

- **Bloco de programa**: O programa deve começar com `inicio` e terminar com `fim`.
- **Declaração de variáveis**: Suporta declaração de variáveis do tipo `inteiro`.
- **Atribuição**: Atribuição de valores a variáveis utilizando `=`.
- **Impressão**: Impressão de valores com o comando `imprime`.
- **Estruturas de controle**:
  - Condicionais: `se ... entao ... senao ... fimse`
  - Loops: `enquanto ... faca ... fimenquanto`

## Funções do Analisador Sintático

- `analise_sintatica()`: Função principal que inicia a análise do programa.
- `programa()`: Verifica a estrutura principal do programa.
- `bloco()`: Analisa blocos de código.
- `comando()`: Analisa comandos dentro de blocos.
- `condicao()`: Analisa estruturas condicionais.
- `repeticao()`: Analisa loops.

## Erros Comuns

- **Erro: Esperado 'inicio'**: O programa deve começar com a palavra reservada `inicio`.
- **Erro: Esperado 'fim'**: O programa deve terminar com a palavra reservada `fim`.
- **Erro: Comando não reconhecido**: Comando inválido dentro de um bloco.
- **Erro: Esperado constante string ou identificador após 'imprima'**: O comando `imprima` deve ser seguido por uma string ou identificador.
- **Erro: Esperado '=' após identificador**: Declaração de variável deve ser seguida por uma atribuição.
