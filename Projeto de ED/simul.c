#include "simul.h"

// Caixas ->

// Função para adicionar uma nova caixa à fila de caixas
void adicionarCaixa(fila_caixa *fila, int numero_caixa, char descricao[], int tempo_atendimento)
{
    if (fila->quantidade < fila->tamanho)
    {
        caixa nova_caixa;
        N_caixa.numero_caixa = numero_caixa;
        N_caixa.tempo_atendimento = tempo_atendimento;
        N_caixa.disponivel = true;
        fila->caixas[fila->quantidade] = N_caixa;
        fila->quantidade++;
    }
}

// Função para remover uma caixa da fila de caixas
void removerCaixa(fila_caixa *fila, int numero_caixa)
{
    for (int i = 0; i < fila->quantidade; i++)
    {
        if (fila->caixas[i].numero_caixa == numero_caixa)
        {
            for (int j = i; j < fila->quantidade - 1; j++)
            {
                fila->caixas[j] = fila->caixas[j + 1];
            }
            fila->quantidade--;
            break;
        }
    }
}

// Função para encontrar uma caixa na fila de caixas com base no seu número de caixa
caixa *encontrarCaixa(fila_caixa *fila, int numero_caixa)
{
    for (int i = 0; i < fila->quantidade; i++)
    {
        if (fila->caixas[i].numero_caixa == numero_caixa)
        {

            printf("Caixa %d: %s (tempo de atendimento: %d segundos)\n", fila->caixas[i].numero_caixa, fila->caixas[i].descricao, fila->caixas[i].tempo_atendimento);
            return &fila->caixas[i];
        }
    }
    return NULL;
}

// Função para imprimir as informações de todas as caixas na fila de caixas
void imprimirInformacoesCaixas(fila_caixa *fila)
{
    printf("Informacoes das caixas:\n");
    for (int i = 0; i < fila->quantidade; i++)
    {
        printf("Caixa %d: %s (tempo de atendimento: %d segundos)\n", fila->caixas[i].numero_caixa, fila->caixas[i].descricao, fila->caixas[i].tempo_atendimento);
    }
}

// funcao pra fechar caixas menos utilizadas
void fecharCaixas(fila_caixa *fila, int numero_caixa)
{
    for (int i = 0; i < fila->quantidade; i++)
    {
        if (fila->caixas[i].numero_caixa == numero_caixa)
        {
            for (int j = i; j < fila->quantidade - 1; j++)
            {
                fila->caixas[j] = fila->caixas[j + 1];
            }
            fila->quantidade--;
            break;
        }
    }
}

// Cliente ->

// Adicionar cliente no fim da fila
void adicionarCliente(struct Fila_cliente *fila, int numero_cliente, char nome_cliente[50], float tempoTotal)
{

    // Cria um novo nó para o cliente
    cliente *N_Cliente = (cliente *)malloc(sizeof(cliente));
    N_Cliente->numero_cliente = numero_cliente;
    N_Cliente->nome_cliente = nome_cliente;
    N_Cliente->tempo_total = tempoTotal;
    N_Cliente->proximo = NULL;
    N_Cliente->produtos_comprados = NULL;

    // (if) Se a fila estiver vazia, o novo cliente será o primeiro da fila
    // (else) Caso contrário, adiciona o novo cliente no fim da fila
    if (fila->inicio == NULL)
    {
        fila->inicio = N_Cliente;
        fila->fim = N_Cliente;
    }
    else
    {
        fila->fim->proximo = N_Cliente;
        fila->fim = N_Cliente;
    }
    fila->tamanho++;
}

// Remover o cliente do início da fila
void removerCliente(struct Fila_cliente *fila)
{

    if (fila->inicio != NULL)
    {
        struct cliente *primeiroCliente = fila->inicio;
        fila->inicio = fila->inicio->proximo;
        free(primeiroCliente);
        fila->tamanho--;
    }
}

// Funcinarios ->

// Adicionar funcionário no fim da lista
funcionario *adicionarFuncionario(funcionario *lista, int numero_funcionario, char *nome_funcionario)
{
    // Cria um novo nó para o funcionário
    funcionario *N_funcionario = (funcionario *)malloc(sizeof(funcionario));
    N_funcionario->numero_funcionario = numero_funcionario;
    strcpy(N_funcionario->nome_funcionario, nome_funcionario);
    N_funcionario->proximo = NULL;

    // Se a lista estiver vazia, o novo funcionário será o primeiro da lista
    // Caso contrário, adiciona o novo funcionário no final da lista
    if (lista == NULL)
    {
        lista = N_funcionario;
    }
    else
    {
        funcionario *atual = lista;
        while (atual->proximo != NULL)
        {
            atual = atual->proximo;
        }
        atual->proximo = N_funcionario;
    }
    return lista;
}

// Produtos ->

// Adicionar produto no fim da lista
produto *adicionarProduto(produto *lista, int codigo_produto, char nome_produto[50], float preco, int tcompra, int tcaixa)
{
    produto *novo = (produto *)malloc(sizeof(produto));
    novo->codigo_produto = codigo_produto;
    novo->preco = preco;
    novo->tcompra = tcompra;
    novo->tcaixa = tcaixa;
    strcpy(novo->nome_produto, nome_produto);
    novo->proximo = lista;
    return novo;
}