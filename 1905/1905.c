#include <stdio.h>
#include <stdlib.h>

struct estruturaMatriz{

    int valor;
    int flag_marca_visitado;

}typedef EstruturaMatriz;

void resposta(EstruturaMatriz m[5][5],int linha,int coluna){

    int valorLinha,valorColuna;
    int f1=0,f2=0,f3=0,f4=0;
    /// olharei nas 4 direções possíveis

    if(m[linha][coluna].valor==0){

        m[linha][coluna].flag_marca_visitado = 1; /// marca como visitado o vértice que chegar
        valorLinha = linha;
        valorColuna = coluna;

        if(valorColuna > 0 && m[valorLinha][valorColuna-1].valor==0 &&
           m[valorLinha][valorColuna-1].flag_marca_visitado==0){

            f1 = 1;
            resposta(m,valorLinha,valorColuna-1);
        }

        if(valorColuna < 4 && m[valorLinha][valorColuna+1].valor==0 &&
           m[valorLinha][valorColuna+1].flag_marca_visitado==0){

            f2 = 1;
            resposta(m,valorLinha,valorColuna+1);
        }

        if(valorLinha > 0 && m[valorLinha-1][valorColuna].valor==0 &&
           m[valorLinha-1][valorColuna].flag_marca_visitado==0){

            f3 = 1;
            resposta(m,valorLinha-1,valorColuna);
        }

       if(valorLinha < 4 && m[valorLinha+1][valorColuna].valor==0 &&
           m[valorLinha+1][valorColuna].flag_marca_visitado==0){

            f4 = 1;
            resposta(m,valorLinha+1,valorColuna);
        }

    }/// fim do if que verifica se é 0
}

int main()
{
    struct estruturaMatriz m[5][5];
    int i,j,t;

    scanf("%d",&t);

    while(t--){

        for(i=0;i<5;i++){

            for(j=0;j<5;j++){
                scanf("%d",&m[i][j].valor);
                m[i][j].flag_marca_visitado = 0;
            }
        }

        resposta(m,0,0);

        if(m[4][4].flag_marca_visitado==1){

            printf("COPS\n");
        }else{

            printf("ROBBERS\n");
        }

    }
    return 0;
}
