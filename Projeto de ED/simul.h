//Libs
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "fila.h"
#include "fila.c"
#include "hashing.h"
#include "hashing.c"
// Adicionar cliente no fim da fila
void adicionarCliente(struct Fila_cliente* fila, int numero_cliente,char nome_cliente[50], float tempoTotal)

// Remover o cliente do início da fila
void removerCliente(struct Fila_cliente* fila)