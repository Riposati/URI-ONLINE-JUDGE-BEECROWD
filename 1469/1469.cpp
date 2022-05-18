#include <stdio.h>
#include <vector>
#include <queue>
#define  INF 999999

using namespace std;

typedef vector< vector<int> > vii;

int BFS(vii Grafo,int *idades,int *indices,int ini)
{
    int tam = Grafo.size();
    vector<int> visitados(tam,0);
    queue <int> F;
    int minimo = INF;
    F.push(ini);
    while(!F.empty())
    {
        int u = F.front();
        F.pop();
        for(int i=0; i<Grafo[u].size(); i++)
        {
            int v = Grafo[u][i];
            if(visitados[v]==0)
            {
                minimo = min(minimo,idades[v]);
                visitados[v]=1;
                F.push(v);
            }
        }
    }
    return minimo;
}

int main()
{
    int V,A,C;

    while(scanf("%d %d %d",&V,&A,&C)==3)
    {
        int salv1=0,salv2=0;
        int Idade[V],MAP[V],x,y;

        vii Grafo(V);
        for(int i=0; i<V; i++)
        {
            scanf("%d",&Idade[i]);
            MAP[i]=i;
        }

        while(A--)
        {
            scanf("%d %d",&x,&y);
            Grafo[y-1].push_back(x-1);
        }

        char comando;
        getchar();

        while(C--){

            scanf("%c %d",&comando,&x);
            if(comando == 'T'){
                    scanf("%d",&y);
                    swap(Idade[MAP[x-1]],Idade[MAP[y-1]]);
                    swap(MAP[x-1],MAP[y-1]);
            }else{
                int resp =  BFS(Grafo,Idade,MAP,MAP[x-1]);
                if(resp==INF)
                    printf("*\n");
                else
                    printf("%d\n",resp);
            }

         getchar();
        }
    }
    return(0);
}
