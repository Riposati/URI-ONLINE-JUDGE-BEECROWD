#include <bits/stdc++.h>

using namespace std;

struct grafo{
    int rotuloVertice;
    vector<int>listaArestas;
    bool verticeFechado;
}typedef Grafo;

Grafo grafo[30];
vector<int>cc;

void DFS(int tamanhoGrafo,int verticeInicial){

    cc.push_back(grafo[verticeInicial].rotuloVertice);
    grafo[verticeInicial].verticeFechado = true;
    int u;

    for(int y=0;y<grafo[verticeInicial].listaArestas.size();y++){

        int r = grafo[verticeInicial].listaArestas[y];

        for(u=0;u<tamanhoGrafo;u++){

            if(r==grafo[u].rotuloVertice)
            break;
        }
        if(!grafo[u].verticeFechado){
            DFS(tamanhoGrafo,grafo[verticeInicial].listaArestas[y]);
        }
    }
}

int main()
{
    int qtdVertices,qtdArestas;
    int tes,cont,j,casoTeste=1;
    char vertice1,vertice2;

    scanf("%d",&tes);

    while(tes--){

        cont=j=0;

        scanf("%d",&qtdVertices);
        scanf("%d",&qtdArestas);
        getchar();

        for(int i=0;i<qtdVertices;i++){
            grafo[i].rotuloVertice = i;
            grafo[i].verticeFechado = false;
        }

        int contEntradaVertice1=0;
        int contEntradaVertice2 =0;

        for(int i=0;i<qtdArestas;i++){

            scanf("%c %c",&vertice1,&vertice2);
            getchar();

            while(vertice1 > 97){
                contEntradaVertice1++;
                vertice1--;
            }

            while(vertice2 > 97){
                contEntradaVertice2++;
                vertice2--;
            }

            grafo[contEntradaVertice1].listaArestas.push_back(contEntradaVertice2);
            grafo[contEntradaVertice2].listaArestas.push_back(contEntradaVertice1);

            contEntradaVertice1 = contEntradaVertice2 = 0;
        }

        printf("Case #%d:\n",casoTeste);

        while(j < qtdVertices){

            if(!grafo[j].verticeFechado){
                cont++; // cont qtd componentes conexos
                DFS(qtdVertices,j);
            }

            int cont2 = cont;
            while(cont2 > 0){
                sort(cc.begin(),cc.end());
                for(int p=0;p<cc.size();p++){
                    if(p < cc.size()-1)
                        printf("%c,",cc[p]+97);
                    else
                        printf("%c,\n",cc[p]+97);
                }
                cc.clear();
                cont2--;
            }
            j++;
        }
        printf("%d connected components\n",cont);

        for(int i=0;i<qtdVertices;i++){ // serve pra limpa o vector das aresta

            grafo[i].listaArestas.clear();
        }
        casoTeste++;

        printf("\n");
    }
    return 0;
}
