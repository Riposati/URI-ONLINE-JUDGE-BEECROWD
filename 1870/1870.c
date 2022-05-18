#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
   int linhas,colunas,posicaoBalao,i,j,x=0,t=0;
   int flag = 0,ventilador1=0,ventilador2=0;
   int diferenca_ventiladores;

   scanf("%d %d %d",&linhas,&colunas,&posicaoBalao);

   while(linhas!=0&&colunas!=0&&posicaoBalao!=0){

   int matriz[linhas][colunas];

   /// recebe a matriz
   for(i=0;i<linhas;i++){
        for(j=0;j<colunas;j++){
            scanf("%d",&matriz[i][j]);
        }
   }
   int vet[9];

   int posicaoBalao_menos1 = (posicaoBalao - 1);

   memset(vet, 0, sizeof(vet)); /// inicializa o array
   /// o vetor recebe os ventiladores para saber onde tem ou não ventiladores
   for(i=0;i<linhas;i++){

        for(j=0;j<colunas;j++){

            if(matriz[i][j]!=0){
                x = j;
                vet[x] = matriz[i][j]; /// esse array recebe os ventiladores dessa linha
            }
        }
            t = posicaoBalao_menos1;
            while(t > 0 && vet[t]==0){
                t--;
            }
            ventilador1 = vet[t];

            t = posicaoBalao_menos1;
            while(t < 9 && vet[t]==0){
                t++;
            }
            ventilador2 = vet[t];
            /// até esta perfeito pegando corretamente onde o balão está entre os ventiladores certos
            diferenca_ventiladores = abs(ventilador1-ventilador2);

            if(ventilador1 > ventilador2){ /// vai pra esquerda o balão

                posicaoBalao_menos1 += diferenca_ventiladores;
            }else{

                if(ventilador2 > ventilador1){ /// vai pra direita o balão
                    posicaoBalao_menos1 -= diferenca_ventiladores;
                }
            }

            if(posicaoBalao_menos1 < 0)posicaoBalao_menos1 = 0;
            if(posicaoBalao_menos1 > 9)posicaoBalao_menos1 = 9;

            if(vet[posicaoBalao_menos1]!=0){
                printf("BOOM %d %d\n",i+1,posicaoBalao_menos1+1);
                flag=1;
                break;
            }
        memset(vet, 0, sizeof(vet)); /// inicializa o array
        flag=ventilador1=ventilador2=x=t=0;
    }
    if(flag==0)
    printf("OUT %d\n",posicaoBalao_menos1+1);
    scanf("%d %d %d",&linhas,&colunas,&posicaoBalao);
   }
    return 0;
}