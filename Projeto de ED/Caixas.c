#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct caixa {
   int numero_caixa;
   int numero_clientes;
   int numero_funcionarios;
   int *clientes; // vetor dinâmico com os números dos clientes alocados nesta caixa
   int *funcionarios; // vetor dinâmico com os números dos funcionários alocados nesta caixa
};

struct caixa* criar_caixa(int numero_caixa) {
    struct caixa* caixa = malloc(sizeof(struct caixa));
    if (caixa == NULL) {
        printf("Erro na alocação de memoria para na nova caixa!\n");
        return NULL;
    }

    // Info pra a nova caixa
    caixa->numero_caixa = numero_caixa;
    caixa->numero_clientes = 0;
    caixa->numero_funcionarios = 0;
    caixa->clientes = NULL;
    caixa->funcionarios = NULL;

    printf("Caixa criada com sucesso! ID: %d\n", numero_caixa);
    return caixa;
}

typedef struct {
    int numero_funcionario;
    char nome_funcionario[50];
    int horas_trabalhadas;
    struct funcionario* proximo;
} funcionario;

typedef struct {
    int codigo_produto;
    char nome_produto[50];
    float preco;
    int tcompra;
    int tcaixa;
} produto;

typedef struct cliente {
    int numero_cliente;
    char nome_cliente[50];
    produto *produtos_comprados; // lista de produtos comprados pelo cliente
    int tempo_total; // tempo total gasto pelo cliente na loja

    struct cliente* proximo;

} cliente;

struct Fila_cliente {
    struct cliente* inicio;
    struct cliente* fim;
    int tamanho;
};

// Adicionar cliente no fim da fila
void adicionarCliente(struct Fila_cliente* fila, int numero_cliente, float tempoTotal) {

    // Cria um novo nó para o cliente
    cliente* N_Cliente = (cliente*) malloc(sizeof(cliente));
    N_Cliente->numero_cliente = numero_cliente;
    N_Cliente->tempo_total = tempoTotal;
    N_Cliente->proximo = NULL;
    N_Cliente->produtos_comprados = NULL;

// (if) Se a fila estiver vazia, o novo cliente será o primeiro da fila
// (else) Caso contrário, adiciona o novo cliente no fim da fila
    if (fila->inicio == NULL) {
        fila->inicio = N_Cliente;
        fila->fim = N_Cliente;
    } else {
        fila->fim->proximo = N_Cliente;
        fila->fim = N_Cliente;
    }
    fila->tamanho++;
}

// Remover o cliente do início da fila
void removerCliente(struct Fila_cliente* fila) {

    if (fila->inicio != NULL) {
        struct cliente* primeiroCliente = fila->inicio;
        fila->inicio = fila->inicio->proximo;
        free(primeiroCliente);
        fila->tamanho--;
    }
}

funcionario* adicionarFuncionario(funcionario* lista, int numero_funcionario, char* nome_funcionario) {

// Cria um novo nó para o funcionário
    funcionario* N_funcionario = (funcionario*) malloc(sizeof(funcionario));
    N_funcionario->numero_funcionario = numero_funcionario;
    strcpy(N_funcionario->nome_funcionario, nome_funcionario);
    N_funcionario->proximo = NULL;

// Se a lista estiver vazia, o novo funcionário será o primeiro da lista
// Caso contrário, adiciona o novo funcionário no final da lista
    if (lista == NULL) {
        lista = N_funcionario;
    } else { 
        funcionario* atual = lista;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = N_funcionario;
    }
    return lista;
}

int Ler_FuncionariosF() {
    FILE* ListaFunc = fopen("funcionarios.txt", "r");
    if (ListaFunc == NULL) {
        printf("Erro a abrir o file dos 'funcionarios.txt'\n");
        return 1;
    }

    funcionario* lista = NULL;
    char linha[500];
    while (fgets(linha, 500, ListaFunc) != NULL) {
        int numero_funcionario;
        char nome_funcionario[50];
        sscanf(linha, "%d %[^\n]", &numero_funcionario, nome_funcionario);
        lista = adicionarFuncionario(lista, numero_funcionario, nome_funcionario);
    }

    fclose(ListaFunc);

    //lista de clientes e fazer o que precisa
    funcionario* atual = lista;
    while (atual != NULL) {
         printf("Número do Funcionário: %d, Nome: %s\n", atual->numero_funcionario, atual->nome_funcionario);
        atual = atual->proximo;
    }

    return 0;
}

int Ler_ClientesF() {
    FILE* ListaClien = fopen("clientes.txt", "r");
    if (ListaClien == NULL) {
        printf("Erro a abrir o file dos 'clientes.txt'\n");
        return 1;
    }

    cliente* lista = NULL;
    char linha[15000];
    while (fgets(linha, 15000, ListaClien) != NULL) {
        int numero_cliente;
        char nome_cliente[50];
        sscanf(linha, "%d %[^\n]", &numero_cliente, nome_cliente);
        lista = adicionarClinete(lista, numero_cliente, nome_cliente);
    }

    fclose(ListaClien);

    //lista de clientes e fazer o que precisa
    cliente* atual = lista;
    while (atual != NULL) {
        printf("Número do Clinete: %d, Nome: %s\n", atual->numero_cliente, atual->nome_cliente);
        atual = atual->proximo;
    }

    return 0;
}

int Ler_ProdutosF() {
    FILE* ListaProd = fopen("produtos.txt", "r");
    if (ListaProd == NULL) {
        printf("Erro a abrir o file dos 'produtos.txt'\n");
        return 1;
    }

    produto* lista = NULL;
    char linha[500];
    while (fgets(linha, 500, ListaProd) != NULL) {
        int codigo_produto;
        char nome_produto[50];
        float preco;
        int tcompra;
        int tcaixa;
        sscanf(linha, "%d %f %d %d %[^\n]", &codigo_produto, &preco, &tcompra, &tcaixa, nome_produto);
        lista = adicionarProduto(lista, codigo_produto, nome_produto, preco, tcompra, tcaixa);
    }

    fclose(ListaProd);

    //lista de clientes e fazer o que precisa
    produto* atual = lista;
    while (atual != NULL) {
        printf("Código do Produto: %d, Nome: %s, Preço: %f, Tempo de Compra: %d, Tempo de Caixa: %d\n", atual->codigo_produto, atual->nome_produto, atual->preco, atual->tcompra, atual->tcaixa);
        atual = atual->proximo;
    }

    return 0;
}