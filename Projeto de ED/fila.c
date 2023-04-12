#include "fila.h"

int Ler_ProdutosF() {
    FILE* ListaProd = fopen("produtos.txt", "r");
    if (ListaProd == NULL) {
        printf("Erro a abrir o file dos 'produtos.txt'\n");
        return 1;
    }

    produto* lista = NULL;
    char linha[10000];
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

int Ler_ClientesF() {
    FILE* ListaClientes = fopen("clientes.txt", "r");
    if (ListaClientes == NULL) {
        printf("Erro a abrir o file dos 'clientes.txt'\n");
        return 1;
    }

    cliente* lista = NULL;
    char linha[10000];
    while (fgets(linha, 500, ListaClientes) != NULL) {
        int num_cartao;
        char nome_cliente[50];
        int num_produtos;
        sscanf(linha, "%d %d %[^\n]", &num_cartao, &num_produtos, nome_cliente);
        lista = adicionarCliente(lista, num_cartao, nome_cliente, num_produtos);
    }

    fclose(ListaClientes);

    //lista de clientes e fazer o que precisa
    cliente* atual = lista;
    while (atual != NULL) {
        printf("Número do Cartão: %d, Nome: %s, Número de Produtos: %d\n", atual->num_cartao, atual->nome_cliente, atual->num_produtos);
        atual = atual->proximo;
    }

    return 0;
}

int Ler_FilaF() {
    FILE* ListaFila = fopen("fila.txt", "r");
    if (ListaFila == NULL) {
        printf("Erro a abrir o file dos 'fila.txt'\n");
        return 1;
    }

    fila* lista = NULL;
    char linha[10000];
    while (fgets(linha, 500, ListaFila) != NULL) {
        int num_cartao;
        int num_produtos;
        sscanf(linha, "%d %d", &num_cartao, &num_produtos);
        lista = adicionarFila(lista, num_cartao, num_produtos);
    }

    fclose(ListaFila);

    //lista de clientes e fazer o que precisa
    fila* atual = lista;
    while (atual != NULL) {
        printf("Número do Cartão: %d, Número de Produtos: %d\n", atual->num_cartao, atual->num_produtos);
        atual = atual->proximo;
    }

    return 0;
}