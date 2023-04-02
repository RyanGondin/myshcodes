#include <stdio.h>

int main() {
    int opcao;

    do {
        printf("|====================================|\n");
        printf("|          Página Principal          |\n");
        printf("|====================================|\n");
        printf("|                                    |\n");
        printf("| 1. Carregar dados do arquivo       |\n");
        printf("| 2. Gravar dados em arquivo         |\n");
        printf("| 3. Ver histórico de ações          |\n");
        printf("| 4. Mudar cliente de caixa          |\n");
        printf("| 5. Abrir nova caixa                |\n");
        printf("| 6. Fechar caixa menos ocupada      |\n");
        printf("| 7. Fechar caixa                    |\n");
        printf("| 8. Pesquisar pessoa na fila        |\n");
        printf("| 9. Mostrar desempenho do sistema   |\n");
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
            case 9:
                // código para mostrar desempenho do sistema
                break;
            case 0:
                printf("\nObrigado Volte sempre!\n");
                break;
            default:
                printf("\nOpção inválida\n");
                printf("\nNota: Opções aceites:\n");
                printf("-> 0. Sair\n");
                printf("-> 1. Carregar dados do arquivo\n");
                printf("-> 2. Gravar dados em arquivo\n");
                printf("-> 3. Ver histórico de ações\n");
                printf("-> 4. Mudar cliente de caixa\n");
                printf("-> 5. Abrir nova caixa\n");
                printf("-> 6. Fechar caixa menos ocupada\n");
                printf("-> 7. Fechar caixa\n");
                printf("-> 8. Pesquisar pessoa na fila\n");
                printf("-> 9. Mostrar desempenho do sistema\n");
        }

        printf("\n");

    } while(opcao != 0);

    return 0;
}