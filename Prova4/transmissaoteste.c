#include <stdio.h>
#include <stdlib.h>

static int count, pre[1000];

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

struct graph {
    int V;
    int E; 
    int **adj;
    int **tc;
};


int **MATRIXInit(int w, int h, int value) {
	int **arr = malloc(sizeof(*arr) * w);
	for (int i = 0; i < w; i++)
		arr[i] = malloc(sizeof(int) * h);
	return arr;
}

Graph GRAPHinit(int v){
    Graph G = malloc(sizeof(*G));
    G->V = v; G->E= 0;
    G->adj=MATRIXInit(v,v,0);
    return G;
}

void GRAPHInsertE(Graph G, Edge e){
    int v = e.v; int w=e.w;
    if(G->adj[v][w] == 0) G->E++;
    G->adj[v][w]=1;
}


int GRAPHEdges(Edge a[], Graph G){
    int v,w,E=0;
    for(v=0; v<G->V;v++){
        for(w=v+1; w<G->V;w++){
            if (G->adj[v][w] == 1)
            a[E++]=EDGE(v,w);
        }
    }
    return E;
}

void GRAPHFtc(Graph G) {
	int s, i, t;
	G->tc = MATRIXInit(G->V, G->V, 0);
	for (s = 0; s < G->V; s++){
		for (t = 0; t < G->V; t++){
			G->tc[s][t] = G->adj[s][t];
		}
	}
	for (s = 0; s < G->V; s++) {
		G->tc[s][s] = 1;
	}
	for (i = 0; i < G->V; i++){
		for (s = 0; s < G->V; s++){
			if (G->tc[s][i] == 1){
				for (t = 0; t < G->V; t++){
					if (G->tc[i][t] == 1)
						G->tc[s][t] = 1;
				}
			}
		}
	}
}

int GRAPHreach(Graph G, int s, int t) {
	return G->tc[s][t];
}

int main(){

    int E, L; int n=1;
    scanf("%d %d", &E, &L);
    Graph TRANSMISSAO = GRAPHinit(E+1);
    int X, Y, contador = 1;
    int falha = 0;

    for(int i = 0; i<L; i++){
        scanf("%d %d", &X, &Y);
        GRAPHInsertE(TRANSMISSAO, EDGE(X, Y));
    }

    while(X != 0 && Y != 0){
        if(contador == 1){
            scanf("%d %d", &X, &Y);
            GRAPHFtc(TRANSMISSAO);
            if(!GRAPHreach(TRANSMISSAO, X, Y)) falha++;
            contador++;
        }
        else if(contador == 2){
            scanf("%d %d", &X, &Y);
            GRAPHFtc(TRANSMISSAO);
            if(!GRAPHreach(TRANSMISSAO, X, Y)) falha++;
            contador = 1;
            printf("Teste %d\n", n);
            if(falha == 0){
                 printf("normal\n");
            }
            else{
                 printf("falha\n");
            }
        }
        n++;
    }

    return 0;
}