#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "fila.h"
#include "fila.c"
#include "hashing.h"
#include "hashing.c"

int main() {
    int opcao;

    printf("Hipermercado Iniciado!\n");

    printf("Para continuar o sistema terá de saber quantas caixas iniciais & ativas tem o estabelecimento.\n");
    printf("Número de caixas é: ");
    scanf("%d", &numero_caixas);

    printf("Continuando...\n");

    do {
        printf("|====================================|\n");
        printf("|          Página Principal          |\n");
        printf("|====================================|\n");
        printf("|                                    |\n");
        printf("| 1. Abrir caixa                     |\n");
        printf("| 2. Fechar Caixa                    |\n");
        printf("| 3. Mostrar clientes das Caixas     |\n");
        printf("| 4. Mostrar Compras por Caixas      |\n");
        printf("| 4. Mudar cliente de caixa          |\n");
        printf("| 0. Sair                            |\n");
        printf("|                                    |\n");
        printf("|====================================|\n");

        printf("\nO que pretende do Sistema ? ");
        printf("\nOpção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                // código para carregar dados do arquivo
                break;
            case 2:
                // código para gravar dados em arquivo
                break;
            case 3:
                // código para ver histórico de ações
                break;
            case 4:
                // código para mudar cliente de caixa
                break;
            case 5:
                // código para abrir nova caixa
                break;
            case 6:
                // código para fechar caixa menos ocupada
                break;
            case 7:
                // código para fechar caixa
                break;
            case 8:
                // código para pesquisar pessoa na fila
                break;
            case 0:
                printf("\nObrigado Volte sempre!\n");
                break;
            default:
                printf("\nOpção inválida\n");
                printf("\nNota: Opções aceites:\n");
                printf("-> 0. Sair\n");

        }

        printf("\n");

    } while(opcao != 0);

    return 0;
}