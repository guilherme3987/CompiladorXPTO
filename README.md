### Módulo do Analisador Léxico da Linguagem XPTO
Linguagem XPTO é uma linguagem criada por mim para facilitar estudos de algoritmos

#### 1) Palavras Reservadas

- **inicio:** para marcar o início do programa
- **fim:** para marcar o fim do programa
- **se:** para condicional
- **entao:** para indicar o bloco de código dentro do condicional
- **senao:** para o bloco de código alternativo
- **enquanto:** para loops
- **faça:** para o bloco de código dentro do loop
- **imprima:** para saída de texto
- **inteiro:** para declarar variáveis inteiras
- **string:** para declarar variáveis de string

#### 2) Símbolos

- **=:** para atribuição
- **+, -, *, >, >=, <, <=:*,\* para operações matemáticas
- **!=:** para comparação de diferença
- **{ } ():,;** para delimitação de blocos
- **" ":** para delimitar strings

#### 3) Strings

Strings são delimitadas por aspas duplas `" "`. São utilizadas para representar sequências de caracteres dentro do programa.

---


---

## Especificações da Linguagem

Esta linguagem é uma linguagem de programação simplificada, projetada para ser fácil de entender e usar. Abaixo estão as especificações detalhadas da linguagem, incluindo palavras reservadas, símbolos, e regras para strings e expressões.

### 1. Regras da Linguagem

- Um programa deve começar com a palavra-chave `inicio` e terminar com `fim`.
- As variáveis podem ser declaradas usando `inteiro` para variáveis do tipo inteiro e `string` para variáveis do tipo string.
- As operações de expressões incluem adição, subtração e multiplicação. Divisão não é suportada pela linguagem.
- As estruturas condicionais são definidas com `se`, `entao`, e `senao`.
- Os loops são definidos com `enquanto` e `faça`.

### Exemplos

Aqui estão alguns exemplos de código na linguagem:

#### Exemplo 1: Programa Simples

```plaintext
inicio
    inteiro x
    x = 5
    imprime "O valor de x é: "
    imprime x
fim
```

#### Exemplo 2: Estrutura Condicional

```plaintext
inicio
    inteiro x
    x = 10
    se x > 5 entao
        imprime "x é maior que 5"
    senao
        imprime "x é 5 ou menor"
    fimse
fim
```

#### Exemplo 3: Loop

```plaintext
inicio
    inteiro i
    i = 0
    enquanto i < 10 faça
        imprime i
        i = i + 1
    fimenquanto
fim
```



#  Módulo do Analisador Sintático da Linguagem XPTO 

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
