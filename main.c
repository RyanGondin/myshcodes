#include <stdio.h>
#include <stdlib.h>

#include "Tipo_Dados.h"
#include "Lista.h"

int main()
{
    printf("Ficha 2: Listas TP2!\n");
    Lista *LP = Criar_Lista("PT");

   // Ler_Ficheiro(LP, "dados.txt");
   //Exportar_Ficheiro(LP, "copia.txt");

   int i;

   // testes, remover
    for( i = 0 ; i < 5 ; i++ )
    {
    NO * n1;
    n1 = Criar_No();
    lerElemento(n1);
    inserir_elemento_fim(LP, n1);
    }
    Mostrar_Lista(LP);
    Destruir_Lista(LP);


    return 0;
}
