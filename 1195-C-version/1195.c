#include <stdio.h>
#include <stdlib.h>

struct arvore{
       int chave;
       struct arvore *esq;
       struct arvore *dir;
}typedef Arvore;

struct Arvore *treeInsert(Arvore *raiz,int chave){

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
        mostraArvoreEmOrdem(raiz->esq);
        printf(" %d",raiz->chave);
        mostraArvoreEmOrdem(raiz->dir);
    }
}


void preordem(Arvore *pNo){
    if (pNo != NULL){
       printf(" %d", pNo->chave);
       preordem(pNo->esq);
       preordem(pNo->dir);
    }
}

void posordem(Arvore *pNo){
    if (pNo != NULL){
       posordem(pNo->esq);
       posordem(pNo->dir);
       printf(" %d", pNo->chave);
    }
}

int main (){
    int op,testes,cont=0,testeSupremo;
    struct arvore *raiz=NULL;

    scanf("%d",&testeSupremo);

    while(testeSupremo > 0){

    scanf("%d",&testes);

    while(testes > 0){
        int valor;
        scanf("%d", &valor);

        while(valor < 0){
            scanf("%d",&valor);
        }
        raiz = treeInsert(raiz,valor);

     testes--;
    }
        cont++;

        printf("Case %d:\n",cont);

        printf("Pre.:");
        preordem(raiz);
        printf("\n");

        printf("In..:");
        mostraArvoreEmOrdem(raiz);
        printf("\n");

        printf("Post:");
        posordem(raiz);
        printf("\n");

        raiz = NULL;

        printf("\n");

        testeSupremo--;

    }

   return 0;
}
