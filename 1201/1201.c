#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maior;
int flag=0;

struct arvore{
    int chave;
    struct arvore *dir;
    struct arvore *esq;
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
        if(raiz->chave==maior){
            mostraArvoreEmOrdem(raiz->esq);
            printf("%d",raiz->chave);
            mostraArvoreEmOrdem(raiz->dir);

        }else{
            mostraArvoreEmOrdem(raiz->esq);
            printf("%d ",raiz->chave);
            mostraArvoreEmOrdem(raiz->dir);
        }
    }
}

void posFixa(Arvore *raiz,Arvore *guardaRaiz){

    if(raiz!=NULL){
        if(raiz->chave==guardaRaiz->chave){
            posFixa(raiz->esq,guardaRaiz);
            posFixa(raiz->dir,guardaRaiz);
            printf("%d",raiz->chave);
        }else{
            posFixa(raiz->esq,guardaRaiz);
            posFixa(raiz->dir,guardaRaiz);
            printf("%d ",raiz->chave);
        }
    }
}

void preOrdem(Arvore *prox){
   if(!prox) return;

   if(flag==0){
        printf("%d", prox->chave);
        flag=1;
   }else{
        printf(" %d", prox->chave);
    }
    preOrdem(prox->esq);
    preOrdem(prox->dir);
}

struct arvore *treeSearch(Arvore *raiz,int chaveQueBusco){

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

    if(raiz==NULL)return NULL;
    else{
        while(raiz->dir != NULL){

            raiz = raiz->dir;
        }

        return raiz->chave;
    }
}

struct arvore *treeDelete(Arvore *raiz,int chavePraDeletar){

    if(raiz==NULL){ /// arvore vazia beleza retorna NULL

        return NULL;

    }else{ /// essa parte serve para encontrar na árvore onde está a chave que quero

        if(raiz->chave > chavePraDeletar){

            raiz->esq = treeDelete(raiz->esq,chavePraDeletar);
        }else{

            if(raiz->chave < chavePraDeletar){

                raiz->dir = treeDelete(raiz->dir,chavePraDeletar);

            }else{/// aqui achou a chave que deve ser deletada

                /// nó sem filhos( nós folhas )

                if(raiz->esq == NULL && raiz->dir==NULL){

                    free(raiz);
                    raiz = NULL;
                }else{

                    /// só tem um filho a direita

                    if(raiz->esq==NULL){

                        Arvore *t = raiz;
                        raiz = raiz->dir;
                        free(t);
                    }else{
                        /// só tem um filho à esquerda

                        if(raiz->dir==NULL){

                            Arvore *t = raiz;
                            raiz = raiz->esq;
                            free(t);
                        }else{

                            /// aqui são para blocos que possuem 2 filhos

                            Arvore *f = raiz->esq;
                            while(f->dir != NULL){

                                f = f->dir;
                            }

                            raiz->chave = f->chave; /// troca as informações aqui
                            f->chave = chavePraDeletar;
                            raiz->esq = treeDelete(raiz->esq,chavePraDeletar);
                        }
                    }
                }
            }
        }
    }

    return raiz;
}

int main()
{
    Arvore *raiz = NULL;
    Arvore *buscasNaArvore = NULL;
    char opcao[20];
    char t;
    int valor;

    while(scanf("%s",opcao) != EOF){

            t = opcao[0];

            if(t == 'I' && strcmp(opcao,"INFIXA")!=0){
                 scanf("%d",&valor);
                 raiz = treeInsert(raiz,valor);
            }

            if(t == 'R'){
                 scanf("%d",&valor);
                 raiz = treeDelete(raiz,valor);
            }

            if(t == 'P' && strcmp(opcao,"POSFIXA")!=0 && strcmp(opcao,"PREFIXA")!=0){

                scanf("%d",&valor);
                buscasNaArvore = treeSearch(raiz,valor);

                if(buscasNaArvore!=NULL){

                    printf("%d existe\n",valor);
                }else{
                    printf("%d nao existe\n",valor);
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
