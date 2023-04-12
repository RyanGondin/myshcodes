// Estruturação de dados ()

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para representar o <<Hipermercado>>
typedef struct {
    char nome_hipermercado[50];
    int numero_caixas;
    int numero_funcionarios;
    int numero_produtos;
    int numero_clientes;
} hipermercado;

// Estrutura para representar um <<Produto>>
typedef struct node {
    int codigo_produto;
    char nome_produto[50];
    float preco;
    int tcompra;
    int tcaixa;

    struct node* proximo;

} produto;

//estrutura para representar um funcionario
typedef struct node {
    int numero_funcionario;
    char nome_funcionario[50];

    struct node* proximo;

} funcionario;

// Estrutura para representar um produto comprado por um <<cliente>>
typedef struct node {
    int numero_cliente;
    char nome_cliente[50];
    produto *produtos_comprados; // lista de produtos comprados
    int tempo_total; // tempo total gasto pelo cliente

    struct node* proximo;

} cliente;

// Estrutura para representar uma caixa
typedef struct {
    int numero_caixa;
    char descricao[50];
    int tempo_atendimento;
    fila_cliente fila; // fila de clientes na caixa
} caixa;

//------------------------------------------------------------------------------------------->

//fila de clientes
typedef struct {
    cliente* inicio;
    cliente* fim;
    int tamanho;
} fila_cliente;

//fila de caixas
typedef struct {
    caixa* caixas;
    int tamanho;
} fila_caixa;

//fila funcionarios
typedef struct {
    funcionario* inicio;
    funcionario* fim;
    int tamanho;
} fila_funcionario;

//fila de produtos
typedef struct {
    produto* inicio;
    produto* fim;
    int tamanho;
} fila_produto;

//------------------------------------------------------------------------------------------->

//
int Ler_ProdutosF()