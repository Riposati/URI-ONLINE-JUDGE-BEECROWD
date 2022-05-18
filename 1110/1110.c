#include <stdio.h>
#include <stdlib.h>
  
struct lista{
    int v;
    struct lista *prox;
};
  
struct lista *insere(struct lista *ini,int v){
  
    struct lista *aux = ini;
    aux = (struct lista *)malloc(sizeof(struct lista));
  
    aux->v = v;
    aux->prox = NULL;
  
    if(ini==NULL){
  
        ini = aux;
  
    }else{
  
        struct lista *ultimo = ini;
  
        while(ultimo->prox!=NULL){
  
            ultimo = ultimo->prox;
        }
        ultimo->prox = aux;
  
        aux->prox = NULL;
    }
  
    return ini;
}
  
void mostrar(struct lista *ini){
  
    struct lista *aux = ini;
  
        while(aux!=NULL){
            printf("%d",aux->v);
            aux=aux->prox;
        }
}
  
struct lista *removeNo(struct lista *ini){
    if(ini->prox!=NULL){ /// se o proximo do inicio nao for nulo
  
    struct lista *aux = ini; /// um aux = ini
  
    struct lista *aux2 = ini->prox; /// aux2 = o da frente do inicio
    ini = ini->prox;
    struct lista *aux4 = ini; /// o aux4 recebe o que deve ir para o fim da lista
  
    if(ini->prox==NULL)
    printf("%d",aux->v);else{
        printf("%d, ",aux->v); /// pra mostra os que foram desalocados
    }
    free(aux);
  
    while(aux2->prox!=NULL){
  
  
        aux2 = aux2->prox;
  
    } /// esse while e pra achar o ultimo
  
    /// aqui movimento os dados ///
    if(ini->prox!=NULL){
        ini = ini->prox;
        aux4->prox=NULL;
        aux2->prox = aux4;
        return ini;
    }
  
    }
    return ini;
}
  
int main()
{
    struct lista *ini = NULL;
  
    int i,v;
  
    scanf("%d",&v);
  
    while(v!=0){
  
    for(i=1;i<=v;i++){
  
        ini = insere(ini,i);
    }
  
    printf("Discarded cards: ");
    for(i=0;i<v;i++){
        ini = removeNo(ini);
    }
  
    printf("\n");
    printf("Remaining card: ");
    mostrar(ini);
  
    printf("\n");
    scanf("%d",&v);
    ini = NULL;
    }
  
    return 0;
}
