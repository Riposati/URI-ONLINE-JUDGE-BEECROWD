#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char maior;
int flag=0;

struct arvore{
    char chave;
    struct arvore *dir;
    struct arvore *esq;
}typedef Arvore;

struct Arvore *treeInsert(Arvore *raiz,char chave){

    Arvore *raizAux = (Arvore *)malloc(sizeof(Arvore));

    raizAux->chave = chave;
    raizAux->dir = NULL;
    raizAux->esq = NULL;

    Arvore *y = NULL;
    Arvore *x = raiz;

    while(x!=NULL){

        y = x;

        if(raizAux->chave < x->chave){

          x = x->esq;
        }else{

            x = x->dir;
        }
    }

    if(y==NULL){ /// a arvore tava vazia caso entre neste if

        raiz = raizAux;
    }else{

        if(raizAux->chave < y->chave){

            y->esq = raizAux;
        }else{

            y->dir = raizAux;
        }
    }

    return raiz;
}

void mostraArvoreEmOrdem(Arvore *raiz){

    if(raiz!=NULL){
        if(raiz->chave==maior){
            mostraArvoreEmOrdem(raiz->esq);
            printf("%c",raiz->chave);
            mostraArvoreEmOrdem(raiz->dir);

        }else{
            mostraArvoreEmOrdem(raiz->esq);
            printf("%c ",raiz->chave);
            mostraArvoreEmOrdem(raiz->dir);
        }
    }
}

void posFixa(Arvore *raiz,Arvore *guardaRaiz){

    if(raiz!=NULL){
        if(raiz->chave==guardaRaiz->chave){
            posFixa(raiz->esq,guardaRaiz);
            posFixa(raiz->dir,guardaRaiz);
            printf("%c",raiz->chave);
        }else{
            posFixa(raiz->esq,guardaRaiz);
            posFixa(raiz->dir,guardaRaiz);
            printf("%c ",raiz->chave);
        }
    }
}

void preOrdem(Arvore *prox){
   if(!prox) return;

   if(flag==0){
        printf("%c", prox->chave);
        flag=1;
   }else{
        printf(" %c", prox->chave);
    }
    preOrdem(prox->esq);
    preOrdem(prox->dir);
}

struct arvore *treeSearch(Arvore *raiz,char chaveQueBusco){

    while(raiz!=NULL && chaveQueBusco!=raiz->chave){

        if(chaveQueBusco < raiz->chave){

            raiz = raiz->esq;
        }else{

            raiz = raiz->dir;
        }
    }

    return raiz;
}

char *treeMaximum(Arvore *raiz){

    while(raiz->dir != NULL){

        raiz = raiz->dir;
    }

    return raiz->chave;
}

int main()
{
    Arvore *raiz = NULL;
    Arvore *buscasNaArvore = NULL;
    char opcao[20];
    char t;
    char ultimo;

    while(gets(opcao)!=NULL){

            t = opcao[0];

            if(t == 'I' && strcmp(opcao,"INFIXA")!=0){
                 raiz = treeInsert(raiz,opcao[2]);
            }

            if(t == 'P' && strcmp(opcao,"POSFIXA")!=0 && strcmp(opcao,"PREFIXA")!=0){

                buscasNaArvore = treeSearch(raiz,opcao[2]);

                if(buscasNaArvore!=NULL){

                    printf("%c existe\n",opcao[2]);
                }else{
                    printf("%c nao existe\n",opcao[2]);
                }
            }

            if(strcmp(opcao,"INFIXA")==0){
                maior = treeMaximum(raiz);
                mostraArvoreEmOrdem(raiz);
                printf("\n");
            }

            if(strcmp(opcao,"PREFIXA")==0){
                preOrdem(raiz);
                flag=0;
                printf("\n");
            }

            if(strcmp(opcao,"POSFIXA")==0){
                posFixa(raiz,raiz);
                printf("\n");
            }

            strcpy(opcao, "");
            buscasNaArvore = NULL;
        }

    return 0;
}
