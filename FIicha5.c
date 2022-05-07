/* Programa base disponibilizado para permitir o teste das funcionalidades solicitadas na ficha 5- Listas Duplamente Ligadas */

//library
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_PALAVRA 50 // Tamanho maximo para o nome
#define MAX_LINGUA 3
#define LINGUA "PT"
#define NOME_FICHEIRO "PT.txt"

typedef struct Palav {
    char texto[MAX_PALAVRA];  // aqui fica guardada a palavra
} *ptPALAVRA, Palavra;

typedef struct Elem {
    ptPALAVRA inf;
    struct Elem *seg;
    struct Elem *ant;
} *ptELEMENTO, Elemento;

typedef struct Lista {
    char lingua[MAX_LINGUA];
    int nElementos;
    ptELEMENTO inicio;
} *ptLISTA, LISTA;

ptLISTA criar_lista(){
    ptLISTA L;
    L = (ptLISTA)malloc(sizeof(struct Lista));
    L->inicio = NULL;
    L->nElementos = 0;
    return L;
}

ptELEMENTO criar_elemento(){
    ptELEMENTO E = (ptELEMENTO) malloc(sizeof(Elemento));
    E->inf=(ptPALAVRA) malloc(sizeof (Palavra));
    E->seg=NULL;
    E->ant=NULL;
    return E;
}

int validar_elemento(ptELEMENTO E) {
	int i=0;
    if ( !E )  // elemento não existe
        return 0;

    char *palavra = E->inf->texto;

    for (i=0;i<strlen(palavra);i++)
        if (palavra[i]<0 || palavra[i]>127 || !isalpha(palavra[i]))
            return 0;
    return 1;
}

void ler_elemento(ptELEMENTO E) {
    int elemento_valido;
    if ( !E ) { // elemento não existe
        printf("\n\nFuncao [%s] : elemento nao definido...\n\n",__FUNCTION__);
        return;
    }

    do {
        printf("Palavra: ");
        scanf("%s", E->inf->texto);
        if (!(elemento_valido = validar_elemento(E)))
            printf("Introduza apenas letras [a-zA-z] sem caracteres acentuados.\n");
    } while (!elemento_valido);
}

int comparar_elementos(ptELEMENTO A, ptELEMENTO B) {
    // ptPALAVRA PA = (ptPALAVRA) A->inf, PB = (ptPALAVRA) B->inf;
    //return strcmp(PA->texto, PB->texto); // Verificar se A=B atrav�s do texto
    return strcmp(A->inf->texto, B->inf->texto); // Verificar se A=B atrav�s do texto
}

int elementos_iguais(ptELEMENTO A, ptELEMENTO B) {
    return comparar_elementos(A,B)==0;
}

void mostrar_elemento(ptELEMENTO ele_mostrar) {
    printf("%s\n",ele_mostrar->inf->texto);
}

void libertar_elemento(ptELEMENTO X)
{
    if (!X) return;
    if (X->inf) free(X->inf);
    free(X);
}

void inserir_elemento_ordenado(ptLISTA L, ptELEMENTO ele_novo)
{
    // C�digo
    if(!L) return;

    Elemento *NO_novo = ele_novo;
    NO_novo->inf = ele_novo->inf;
    NO_novo->ant = NO_novo->seg = NULL;

	if(!L->inicio)
		L->inicio = NO_novo;

	else
	{
        ptELEMENTO aux = L->inicio;
        int STOP = 1;

        while(aux && STOP)
        {
            if(comparar_elementos(aux, ele_novo)==0)
                aux = aux->seg;
            else
                STOP = 0;
        }

        if (aux)
        {
            if (L->inicio == aux)
            {
                NO_novo->seg = aux;
                aux->ant = NO_novo;
                L->inicio = NO_novo;
            }
            else
            {
                aux->ant->seg = NO_novo;
                NO_novo->ant = aux->ant;
                NO_novo->seg = aux;
                aux->ant = NO_novo;
            }
        }

        else
        {
            aux->seg = NO_novo;
            NO_novo->ant = aux;
            NO_novo->seg = NULL;
        }
	}
    L->nElementos++;
    return;
}

Elemento *pesquisar_iterativo(ptLISTA L, ptELEMENTO ele_pesquisa)
{
    if (!L) return NULL;
    if (!ele_pesquisa) return NULL;
    Elemento *P = L->inicio;

    while(P)
    {
        if(comparar_elementos(P, ele_pesquisa) == 0)
            return P;
        else
            P = P->seg;
    }
    return NULL;
}

ptELEMENTO remover_elemento(ptLISTA L, ptELEMENTO ele_remover) {
    // Código
    if(!L) return NULL;
    if(!ele_remover) return NULL;

    ptELEMENTO aux = L->inicio;
    int STOP = 1;

    while(aux && STOP)
    {
    	if(comparar_elementos(aux, ele_remover) == 0)
    		STOP = 0;
    	else
    		aux = aux->seg;
	}
		aux->ant->seg = aux->seg;
		aux->seg->ant = aux->ant;
		libertar_elemento(aux);
		L->nElementos--;

    return L->inicio;
}

ptELEMENTO remover_primeiro(ptLISTA L) {
    // Código
    if(!L) return NULL;

    ptELEMENTO aux = L->inicio;

    L->inicio = aux->seg;
    L->inicio->ant = NULL;
    libertar_elemento(aux);
    L->nElementos--;

    return L->inicio;
}

void mostrar_n_anteriores(ptLISTA L, ptELEMENTO ele_pesquisar, int n)
{
    if (!L) return;
    if (!ele_pesquisar) return;
    //X = X->ant;

    Elemento *X = pesquisar_iterativo(L, ele_pesquisar);

    if(!X)
        return;

    while(X && (n >= 0))
    {
        mostrar_elemento(X);
        X = X->ant;
        n--;
    }
}

void mostrar_ordenado(ptLISTA L)
{
    if(!L) return;
    printf("Palavras na lista:\n");
    ptELEMENTO p = L->inicio;
    while(p)
    {
        mostrar_elemento(p);
        p = p->seg;
    }
    /*
    for (p = L->inicio; p != NULL; p = p->seg)
        mostrar_elemento(p);
    */
    //for (; p != NULL; mostrar_elemento(p), p = p->seg);
}

void mostrar_inversa(ptLISTA L)
{
    if (!L) return;
    Elemento *P = L->inicio;
    if (!P) return;
    while (P->seg)
        P = P->seg;

    //P est� no �ltimo v�lido!
    while (P)
    {
        mostrar_elemento(P);
        P = P->ant;
    }
}

void Add_palavra(ptLISTA L, char *plv)
{
    if (!L) return;
    if (!plv) return;
    Elemento *X = criar_elemento();
    strcpy(X->inf->texto, plv);
    inserir_elemento_ordenado(L, X);
}


void Ler_Ficheiro_Palavras(LISTA *L, char *nome_ficheiro)
{
    printf("Inicio de <%s>\n", __FUNCTION__);
    if (!L) return;
    FILE *F = fopen(nome_ficheiro, "r");
    if (!F)
    {
        printf("Atencao erro na abertura do ficheiro\n");
        return;
    }
    char TEMP[MAX_PALAVRA];
    while (!feof(F))
    {
        fscanf(F,"%s", TEMP);
        printf("[%s]\n", TEMP);
        Add_palavra(L, TEMP);
    }
    fclose(F);
    printf("Fim de <%s>\n", __FUNCTION__);
}


int menu_principal() {
    int x;
    printf("\n\n# MENU PRINCIPAL ------------------------------------------#");
    printf("\n| (1) Inserir um novo elemento na lista                    |");
    printf("\n| (2) Retirar um elemento (especificado pelo utilizador)   |");
    printf("\n| (3) Retirar o primeiro elemento da lista                 |");
    printf("\n| (4) Mostrar os elementos pela ordem actual               |");
    printf("\n| (5) Mostrar os elementos pela ordem inversa              |");
    printf("\n| (6) Listar n elementos anteriores a um elemento          |");
    printf("\n|   (7) Mostrar elemento actual                            |");
    printf("\n|   (8) Mostrar proximo elemento                           |");
    printf("\n|   (9) Mostrar elemento anterior                          |");
    printf("\n| (10) Inserir algumas palavras para teste...              |");
    printf("\n| -------------------------------------------------------- |");
    printf("\n|       (0) SAIR                                           |");
    printf("\n#----------------------------------------------------------#\n");
    fflush(stdin);
    do {
        printf("\n  Qual a sua opcao ? ");
        fflush(stdin);
        scanf("%d",&x);
    } while (x<0 || x>10);
    return x;
}


int main() {
    ptELEMENTO act, ele_remover, ele_removido, ele_proc, ele_novo;
    //ptELEMENTO ele_pesquisar;
    int n;

    ptLISTA lista = criar_lista();    // Criar a lista
    strcpy(lista->lingua, LINGUA);  // Associar a lingua a lista

    Ler_Ficheiro_Palavras(lista, "ficheiro.txt");

    act = lista->inicio;

    for(;;) // while (1)
    {
        //system("cls");
        if (lista->nElementos == 0) act = NULL;
        if ((act == NULL) && (lista->nElementos > 0))
            act = lista->inicio;
        switch (menu_principal()) {
            case 1:
                ele_novo = criar_elemento();
                ler_elemento(ele_novo);
                inserir_elemento_ordenado(lista, ele_novo);
                break;
            case 2:
                ele_remover = criar_elemento();
                ler_elemento(ele_remover);
                ele_removido = remover_elemento(lista, ele_remover);
                if (ele_removido) {
                    printf("O elemento foi removido!\n");
                    mostrar_elemento(ele_removido);
                    libertar_elemento(ele_removido);
                }
                else
                    printf("Nao foi encontrado nenhum elemento!\n");
                break;
            case 3:
                ele_removido = remover_primeiro(lista);
                if (ele_removido) {
                    printf("Foi removido o primeiro elemento: \n");
                    fseek(stdin, 2, 0);
                    mostrar_elemento(ele_removido);
                    libertar_elemento(ele_removido);
                }
                else
                    printf("Nao foi encontrado nenhum elemento!\n");
                break;
            case 4:
                if (lista->nElementos == 0)
                    printf("Nao existem elementos na lista!\n");
                else
                    mostrar_ordenado(lista);
                break;
            case 5:
                if (lista->nElementos == 0)
                    printf("Nao existem elementos na lista!\n");
                else
                    mostrar_inversa(lista);
                break;
            case 6:
                ele_proc = criar_elemento();
                ler_elemento(ele_proc);
                printf("\n  Quantos elementos antes desse quer mostrar ? ");
                fseek(stdin, 2, 0);
                scanf("%d",&n);
                mostrar_n_anteriores(lista, ele_proc, n);
                break;
            case 7:
                if (!act)
                    printf("\n  A lista nao tem elementos ");
                else {
                     // codigo
                }
                break;
            case 8:
                if (!act)
                    printf("\n  A lista nao tem elementos ");
                else
                {
                     // codigo
                }
                break;
            case 9:
                if (!act)
                    printf("\n  A lista nao tem elementos ");
                else
                {
                    // codigo
                }
                break;
            case 10:  // para facilitar os testes
                Add_palavra(lista,"Rome");
                Add_palavra(lista,"Ludwig");
                Add_palavra(lista,"Duarte");
                Add_palavra(lista,"Ramos"); 
                Add_palavra(lista,"Alexander");
                Add_palavra(lista,"Luka");
                Add_palavra(lista,"Xi");
                Add_palavra(lista,"Yamamoto");
                break;
            case 0:
                exit(0);    // Fim do Programa
                break;
        } //END switch (menu_principal())
        //system("pause");
    }
    return 0;
}