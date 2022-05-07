#include "Lista.h"
#include "utils.h"



Lista *Criar_Lista(char *ling)
{
    //printf("[%s] Ainda nao implementada\n", __FUNCTION__);
    Lista *L = (Lista *)malloc(sizeof(Lista));
    L->Inicio = NULL;
    L->NEL = 0;
    if (strlen(ling) == 2)
        strcpy(L->Lingua, ling);
    else
        strcpy(L->Lingua, "??");
    return L;
}
NO *Criar_No()
{
   // printf("[%s] Ainda nao implementada\n", __FUNCTION__);
     ELEMENTO *P = (ELEMENTO *)malloc(sizeof(ELEMENTO));
    //PtrNO P = (PtrNO)malloc(sizeof(NO));
    P->Info = (PtrNO) malloc(sizeof(PALAVRA));
    P->Prox = NULL;
    return P;
}
void Add_Inicio(Lista *L, NO *X)
{
    //printf("[%s] Ainda nao implementada\n", __FUNCTION__);
    if (!L) return;
    if (!X) return;
    X->Prox = L->Inicio;
    L->Inicio = X;
    L->NEL++;
}
void Add_Fim(Lista *L, NO *X)
{
    printf("[%s] Ainda nao implementada\n", __FUNCTION__);
}
void Add_Ord(Lista *L, NO *X)
{
    printf("[%s] Ainda nao implementada\n", __FUNCTION__);
}
void Mostrar_Lista(Lista *L)
{
    if (!L) return;
    printf("LINGUA = [%s]\n", L->Lingua);
    printf("NEL = %d\n", L->NEL);
    NO *P = L->Inicio;
    while (P != NULL)
    {
        Mostrar_Palavra(P->Info);
        P = P->Prox;
    }
}
void Mostrar_Contrario_Lista(Lista *L)
{
    printf("[%s] Ainda nao implementada\n", __FUNCTION__);
}
PALAVRA *Pesquisar_Palavra(Lista *L, char *txt)
{
    printf("[%s] Ainda nao implementada\n", __FUNCTION__);
    return NULL;
}
void Destruir_Lista(Lista *L)
{
    if(!L) return;
    PtrNO no = L->Inicio;
    PtrNO aux;

    while(no != NULL)
    {
        aux = no->Prox;
        libertarElemento(no);
        no = aux;
    }
    free(L);
}


int Ler_Ficheiro(Lista *L, char *ficheiro)
{
    //printf("[%s] Ainda nao implementada\n", __FUNCTION__);
    if (!L) return 0;
    if (!ficheiro) return 0;
    FILE *F = fopen(ficheiro, "r");
    if (!F) return 0;
    char BUFFER[MAX_PALAVRA];
    while (!feof(F))
    {
        fscanf(F, "%s", BUFFER);
        PALAVRA *PAL = Criar_Palavra(BUFFER);
        NO *X = Criar_No();
        X->Info = PAL;
        Add_Inicio(L, X);
    }
    fclose(F);
    return 1;
}
int Exportar_Ficheiro(Lista *L, char *ficheiro)
{
    //printf("[%s] Ainda nao implementada\n", __FUNCTION__);
    if (!L) return 0;
    if (!ficheiro) return 0;
    FILE *F = fopen(ficheiro, "w");
    if (!F) return 0;
    NO *P = L->Inicio;
    while (P)
    {
        fprintf(F, "%s\n", P->Info->TEXTO);
        P = P->Prox;
    }
    fclose(F);
    return 0;
}
int Remover_Palavra(Lista *L, char *txt)
{
    printf("[%s] Ainda nao implementada\n", __FUNCTION__);
    return 0;
}

void inserir_elemento_fim(Lista* L, PtrNO E)
{
    if(!L) return;

    PtrNO P = L->Inicio;
    E->Prox = NULL;

    if( L->Inicio == NULL )
    {
        L->Inicio = E;
    }
    else
    {
        while (P->Prox != NULL)
            P = P->Prox;
        P->Prox = E;
    }
    L->NEL++;
}


void lerElemento(PtrNO E)
{
    int valido;
    if(!E) return;
    do
    {
        char * string[50];

        printf("Qual a palavra? \n");
        scanf("%s", string);
        strcpy(E->Info->TEXTO, string);
        valido = validar_Elemento(E);
        if(!valido)
        {
            printf("Introduza apenas letras [a-z, A-Z] sem caracteres acentuados");
        }

    } while(!valido);
}


int validar_Elemento(PtrNO E)
{
    if(!E) return;
    char * PALAVRA = E->Info->TEXTO;
    int i;
    for ( i = 0 ; i < strlen(E->Info->TEXTO) ; i++)
    {
        if(PALAVRA[i] < 0 || PALAVRA[i] > 128 || !isalpha(PALAVRA[i])) return 0;
    }
    return 1;
}

void libertarElemento(PtrNO E)
{
    free(E->Info);
    free(E);
}
