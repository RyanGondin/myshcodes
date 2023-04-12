
#include "hashing.h"

// Função para criar uma nova tabela hash
tabela_hash *criarTabelaHash(int tamanho)
{
    tabela_hash *tabela = (tabela_hash *)malloc(sizeof(tabela_hash));
    tabela->tamanho = tamanho;
    tabela->itens = (cliente **)malloc(tamanho * sizeof(cliente *));
    for (int i = 0; i < tamanho; i++)
    {
        tabela->itens[i] = NULL;
    }
    return tabela;
}

// Função para destruir uma tabela hash e liberar a memória alocada
void destruirTabelaHash(tabela_hash *tabela)
{
    for (int i = 0; i < tabela->tamanho; i++)
    {
        cliente *atual = tabela->itens[i];
        while (atual != NULL)
        {
            cliente *proximo = atual->proximo;
            free(atual);
            atual = proximo;
        }
    }
    free(tabela->itens);
    free(tabela);
}

// Função para calcular o hash de um número de cliente
int calcularIndiceHash(int numero_cliente, int tamanho)
{
    return numero_cliente % tamanho;
}

// Função para obter um cliente a partir do seu número de cliente usando tabela de hash
cliente *hashing_obter_cliente(tabela_hash *tabela, int numero_cliente)
{
    // Calcula o índice na tabela de hash usando a função de hash
    int indice = tabela->funcao_hash(numero_cliente, tabela->tamanho);

    // Percorre a lista encadeada no índice correspondente na tabela de hash
    for (cliente *ptr_cliente = tabela->elementos[indice]; ptr_cliente != NULL; ptr_cliente = ptr_cliente->proximo)
    {
        if (ptr_cliente->numero_cliente == numero_cliente)
        {
            return ptr_cliente; // Retorna o cliente encontrado
        }
    }

    return NULL; // Retorna NULL se o cliente não for encontrado
}

// Função para calcular o hash de um número de cliente
cliente* buscarClienteTabelaHash(tabela_hash *tabela, int num_cartao) {
    int indice = calcularIndiceHash(num_cartao);
    if (tabela->itens[indice] == NULL) {
        return NULL;
    } else {
        if (tabela->itens[indice]->num_cartao == num_cartao) {
            return tabela->itens[indice];
        } else {
            printf("Colisao na tabela de hash. Buscando por cliente...\n");
            int i = indice + 1;
            while (i != indice) {
                if (i >= tabela->tamanho) {
                    i = 0;
                }
                if (tabela->itens[i] == NULL) {
                    return NULL;
                }
                if (tabela->itens[i]->num_cartao == num_cartao) {
                    return tabela->itens[i];
                }
                i++;
            }
            printf("Cliente nao encontrado na tabela de hash.\n");
            return NULL;
        }
    }
}

// Função para inserir um novo cliente na tabela hash de clientes
void hashing_inserir_cliente(tabela_hash *tabela, cliente *novo_cliente)
{
    // Calcula o índice na tabela de hash usando a função de hash
    int indice = tabela->funcao_hash(novo_cliente->numero_cliente, tabela->tamanho);

    // Insere o cliente no início da lista encadeada no índice correspondente na tabela de hash
    novo_cliente->proximo = tabela->elementos[indice];
    tabela->elementos[indice] = novo_cliente;
}

// Função para remover um cliente da tabela hash de clientes
void hashing_remover_cliente(tabela_hash *tabela, int numero_cliente)
{
    // Calcula o índice na tabela de hash usando a função de hash
    int indice = tabela->funcao_hash(numero_cliente, tabela->tamanho);

    // Percorre a lista encadeada no índice correspondente na tabela de hash
    cliente *anterior = NULL;
    for (cliente *ptr_cliente = tabela->elementos[indice]; ptr_cliente != NULL; ptr_cliente = ptr_cliente->proximo)
    {
        if (ptr_cliente->numero_cliente == numero_cliente)
        {
            // Remove o cliente da lista encadeada
            if (anterior == NULL)
            {
                tabela->elementos[indice] = ptr_cliente->proximo;
            }
            else
            {
                anterior->proximo = ptr_cliente->proximo;
            }

            // Libera a memória alocada para o cliente
            free(ptr_cliente);

            return;
        }

        anterior = ptr_cliente;
    }
}
