#include <stdio.h>
#include <stdlib.h>
    struct lista{
        int v;
        struct lista *prox;
    };
    struct lista *insere(struct lista *ini,int v){ /// aloca os blocos depois da funcao hash
        struct lista *aux = (struct lista *)malloc(sizeof(struct lista));
        aux->v = v;
        aux->prox = NULL;
        if(ini==NULL){
            ini = aux;
        }else{
            struct lista *ultimo = ini;
            while(ultimo->prox!=NULL){
                ultimo = ultimo->prox;
            }
            ultimo->prox = aux; /// lista simples mesmo , mas poderia ser
                                /// duplamente encadeada
            aux->prox = NULL;
        }
        return ini;
    }
    void aloca(int vet[],int tamanho,int valorRecebido){ /// pra aloca no hash
        int i;
        int vet2[tamanho];
 
         for(i=0;i<tamanho;i++){
 
            vet2[i] = vet[i] % valorRecebido; /// calcula a entrada do hash
        }
        struct lista *list[valorRecebido]; /// Array hash pai
        for(i=0;i<valorRecebido;i++){
             list[i] = NULL; /// anula todo mundo por seguranca no Array hash pai
        }
        struct lista *ini = NULL;
        int t=0,j,v=0;
        /// aloca nas posicoes certas
        for(i=0;i<tamanho;i++){
            v = vet2[i];
            for(j=0;j<tamanho;j++){
                if(vet2[j]==v && t <= tamanho){
                    ini = insere(ini,vet[j]);
                    list[vet2[j]] = ini;
                    t++;
                }
            }
            ini = NULL;
            t = 0;
        } 
        struct lista *aux = NULL;
        int cont=0;
        for(i=0;i<valorRecebido;i++){
            cont++;
            aux = list[i];
            printf("%d -> ",i);
            /// esse laco e pra mostrar todos os valores da lista
            while(aux!=NULL){
                if(aux->prox!=NULL)
                printf("%d -> ",aux->v);/// oks
                else{
                    printf("%d -> \\",aux->v); /// oks
                }
                aux = aux->prox;
            }
            if(list[i]==NULL){
                printf("\\"); /// oks
            }
            if(cont <= valorRecebido-1){
                printf("\n"); /// precisa disto pra formatar corretamente como as saidas exemplo
            }
        }
    }
 
    int main()
    {
        int a,b,i,teste;
 
        scanf("%d",&teste);
 
        while(teste--){
 
            scanf("%d %d",&a,&b);
 
            int vet[b];
 
            for(i=0;i<b;i++){
 
                scanf("%d",&vet[i]);
            }
            aloca(vet,b,a);
            if(teste > 0){
                printf("\n\n");
            }else{
                printf("\n");
            }
        }
        return 0;
    }