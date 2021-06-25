//Lista de adj
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

typedef struct node *link;
static int count, aux[1000];

struct node{
    int v; 
    link prox;
    int c;
};

typedef struct{
    int v;
    int w;
} Edge;

Edge EDGE(int v, int w){
    Edge EDGE;
    EDGE.v = v;
    EDGE.w = w;
    return EDGE;
};

typedef struct graph *Graph;

struct graph{
    int V;
    int E; 
    link *adj;
};

link NEW(int v, link prox, int c){
    link m = malloc(sizeof*m);
    m->v=v; 
    m->prox=prox; 
    m-> c = c;
    return m;
}

Graph GRAPHinit(int v){
    Graph G=malloc(sizeof(*G));
    G->V=v; G->E=0;
    G->adj=malloc(v*sizeof(link));
    for(int i=0; i<v;i++){
        G->adj[i] = NULL;
    }
    return G;
}

void GRAPHInsertE(Graph G, Edge e, int c){
    int v = e.v;
    int w=e.w;
    G->adj[v] = NEW(w,G->adj[v],c);
    G->adj[w]= NEW(v,G->adj[w],c);
    G->E++;
}

int GRAPHEdges(Edge a[], Graph G){
    int v,E=0; link t;
    for(v=0;v<G->V;v++){
        for(t=G->adj[v]; t!=NULL; t=t->prox){
            if(v<t->v){
                a[E++]=EDGE(v, t->v);
            }
        }
    }
    return E;
}

//busca em profundidade 
//recursao ou pilha
//Edge e é a aresta que queremos começar a percorrer o grafo
void dfsR(Graph G, Edge e){
    int t, w=e.w; link l;
    aux[w] = count++;
    for(l=G->adj[w]; l!=NULL; l=l->prox){
        t = l->v;
        if(aux[t]==-1){
            dfsR(G,EDGE(w,t));
        }
    }
}

//versao ingenua
void GRAPHcptD1(Graph G, int s, int *pa, int *dist){
    bool mature[1000];
    for(int v = 0; v < G->V; v++){
        pa[v]=-1; mature[v]=false; dist[v]=INT_MAX;
    }
    pa[s] = 1; dist[s]=0;
    while(true){
        int min = INT_MAX;
        int y;
        for(int z = 0; z < G->V; z++){
            if(mature[z]) continue;
            if(dist[z] < min){
                min = dist[z];
                y = z;
            }
        }
        if(min == INT_MAX) break;
        for(link a = G->adj[y]; a!=NULL; a=a->prox){
            if(mature[a->v]) continue;
            if(dist[y] + a->c < dist[a->v]){
                dist[a->v] = dist[y] + a->c;
                pa[a->v] = y;
            }
        }
        mature[y] = true;
    }
}


int main(){
    int N,M,S,T,B;
    scanf("%d %d", &N, &M);
    Graph PONTES = GRAPHinit(N+2);
    int *pa = malloc(sizeof(int)*N+2);
	int *dist = malloc(sizeof(int)*N+2);

    for(int i = 0; i<M; i++){
        scanf("%d %d %d", &S, &T, &B);
        GRAPHInsertE(PONTES, EDGE(S, T), B);
    }

    GRAPHcptD1(PONTES, 0, pa, dist);
    printf("%d\n", dist[N+1]);

    return 0;
}