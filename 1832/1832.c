#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define a 1
#define b 8
#define c 64

int retornaCharEspecial(int v){

    if(v==106){
        return 221;
    }

    if(v==96){
        return 240;
    }
}

char retornaValor(int v){

    if(v==64){

        return ' ';
    }

    if(v==74){

        return '¢';
    }

    if(v==75){

        return '.';
    }

    if(v==76){

        return '<';
    }

    if(v==77){

        return '(';
    }

    if(v==78){

        return '+';
    }

    if(v==79){

        return '|';
    }

    if(v==90){

        return '!';
    }

    if(v==91){

        return '$';
    }

    if(v==92){

        return '*';
    }

    if(v==93){

        return ')';
    }


    if(v==94){

        return ';';
    }

    if(v==95){

        return '¬';
    }

    if(v==96){

        retornaCharEspecial(96);
    }

    if(v==97){

        return '/';
    }

    if(v==106){

        retornaCharEspecial(106);
    }

    if(v==107){

        return ',';
    }

    if(v==108){

        return '%';
    }


    /////////////////////



    if(v==109){

        return '-';
    }

    if(v==110){

        return '>';
    }

    if(v==111){

        return '?';
    }

    ////////////////////


    if(v==121){

        return '\`';
    }

    if(v==122){

        return ':';
    }

    if(v==123){

        return '#';
    }

    if(v==124){

        return '@';
    }

    if(v==125){

        return '\'';
    }

    if(v==126){

        return '=';
    }

    if(v==127){

        return '"';
    }

    //////////////////////////////


    if(v==129){

        return 'a';
    }

    if(v==130){

        return 'b';
    }

    if(v==131){

        return 'c';
    }

    if(v==132){

        return 'd';
    }

    if(v==133){

        return 'e';
    }


    if(v==134){

        return 'f';
    }

    if(v==135){

        return 'g';
    }

    if(v==136){

        return 'h';
    }

    if(v==137){

        return 'i';
    }


    //////////////////////////////


    if(v==145){

        return 'j';
    }

    if(v==146){

        return 'k';
    }

    if(v==147){

        return 'l';
    }

    if(v==148){

        return 'm';
    }

    if(v==149){

        return 'n';
    }


    if(v==150){

        return 'o';
    }

    if(v==151){

        return 'p';
    }

    if(v==152){

        return 'q';
    }

    if(v==153){

        return 'r';
    }


    //////////////////////////////


    if(v==162){

        return 's';
    }

    if(v==163){

        return 't';
    }

    if(v==164){

        return 'u';
    }

    if(v==165){

        return 'v';
    }

    if(v==166){

        return 'w';
    }


    if(v==167){

        return 'x';
    }

    if(v==168){

        return 'y';
    }

    if(v==169){

        return 'z';
    }



    //////////////////////////////


    if(v==192){

        return '{';
    }

    if(v==193){

        return 'A';
    }

    if(v==194){

        return 'B';
    }

    if(v==195){

        return 'C';
    }

    if(v==196){

        return 'D';
    }


    if(v==197){

        return 'E';
    }

    if(v==198){

        return 'F';
    }

    if(v==199){

        return 'G';
    }

    if(v==200){

        return 'H';
    }


    //////////////////////////////


    if(v==201){

        return 'I';
    }

    if(v==208){

        return '}';
    }

    if(v==209){

        return 'J';
    }

    if(v==210){

        return 'K';
    }

    if(v==211){

        return 'L';
    }


    if(v==212){

        return 'M';
    }

    if(v==213){

        return 'N';
    }

    if(v==214){

        return 'O';
    }

    ////////////////////******


    if(v==215){

        return 'P';
    }

    if(v==216){

        return 'Q';
    }


    if(v==217){

        return 'R';
    }

    if(v==226){

        return 'S';
    }

    if(v==227){

        return 'T';
    }



    ////////////////////******


    if(v==228){

        return 'U';
    }

    if(v==229){

        return 'V';
    }


    if(v==230){

        return 'W';
    }

    if(v==231){

        return 'X';
    }

    if(v==232){

        return 'Y';
    }



    ////////////////////******


    if(v==233){

        return 'Z';
    }

    if(v==240){

        return '0';
    }


    if(v==241){

        return '1';
    }

    if(v==242){

        return '2';
    }

    if(v==243){

        return '3';
    }



    ////////////////////******


    if(v==244){

        return '4';
    }

    if(v==245){

        return '5';
    }


    if(v==246){

        return '6';
    }

    if(v==247){

        return '7';
    }

    if(v==248){

        return '8';
    }

    if(v==249){

        return '9';
    }
}

int main()
{
    char vet[10000];
    int vetAux[10000],i,j=0;
    int t,u,v,sum;

    while(gets(vet)!=NULL){

        for(i=0;i<1000;i++){

            vetAux[i]=0;
        }

        int x=0,flag=0;

        for(i=0;i<strlen(vet)-2;i++){

                if(flag==0){
                    t = vet[i+2] - '0';
                    u = vet[i+1] - '0';
                    v = vet[i] - '0';

                    /*printf("vet[i+2] = %c\n",vet[i+2]);
                    printf("vet[i+1] = %c\n",vet[i+1]);
                    printf("vet[i] = %c\n",vet[i]);


                    printf("t = %d\n",t);
                    printf("u = %d\n",u);
                    printf("v = %d\n",v);*/

                    t *= a;
                    u *= b;
                    v *= c;

                    sum = (t+u+v);
                    vetAux[x] = sum;
                    x++;
                    flag=1;
                }else{

                    if(vet[i]==' '){
                    //    printf("i = espaco na posicao = %d\n",i);
                        j = i+1;
                        x++;
                      /*  printf("vet[j+2] = %c\n",vet[j+2]);
                        printf("vet[j+1] = %c\n",vet[j+1]);
                        printf("vet[j] = %c\n",vet[j]);*/

                        t = vet[j+2] - '0';
                        u = vet[j+1] - '0';
                        v = vet[j] - '0';

                        t *= a;
                        u *= b;
                        v *= c;

                        sum = (t+u+v);
                        vetAux[x] = sum;
                        j++;
                    }
            }
        }

        for(i=0;i<1000;i++){

            if(vetAux[i]!=0){
                printf("%c",retornaValor(vetAux[i]));
            }
        }

        printf("\n");
        j=0;

    }

    return 0;
}
