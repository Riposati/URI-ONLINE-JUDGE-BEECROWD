#include <stdio.h>
#include <vector>
#include <map>
#include <queue>
#include <string>
#define MAX 5000

using namespace std;

typedef vector <vector<int> > vvi;

int BFS(vvi Grafo,int inicio,int destino){

    vector<int> visitado(MAX,0);
    vector<int> D(MAX,0);
    queue<int> F;
    D[inicio]=0;
    visitado[inicio]=1;
    F.push(inicio);

    while(!F.empty()){
        int u  = F.front();
            F.pop();
        for(int i=0;i<Grafo[u].size();i++){
            int v  = Grafo[u][i];
            if(!visitado[v]){
                F.push(v);
                visitado[v]=1;
                D[v]=D[u]+1;
            }
        }
    }
return D[destino];
}



int main()
{

    char M1[100],M2[100];
    int vertices,arestas;

    scanf("%d %d",&vertices, &arestas);
    getchar();
    int cont=0;

    map<string,int> Smap;
    vvi Grafo(MAX);

    while(arestas--)
    {

        scanf("%s %s",M1,M2);
        getchar();

        if(Smap.find(M1)==Smap.end())Smap[M1]=cont++;
        if(Smap.find(M2)==Smap.end())Smap[M2]=cont++;
        int u,v;

        u = Smap[M1];
        v = Smap[M2];

        Grafo[u].push_back(v);
        Grafo[v].push_back(u);
    }
    int resp = BFS(Grafo,Smap["Entrada"],Smap["*"]) + BFS(Grafo,Smap["*"],Smap["Saida"]);
    printf("%d\n",resp);
    return(0);
}
