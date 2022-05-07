#include "Tipo_Dados.h"


PALAVRA *Criar_Palavra(char *txt)
{
    PALAVRA *P = (PALAVRA *)malloc(sizeof(PALAVRA));
    strcpy(P->TEXTO, txt);
    return P;
}
void Mostrar_Palavra(PALAVRA *Pal)
{
    if (Pal == NULL) return;
    printf("[%s]\n", Pal->TEXTO);
}
