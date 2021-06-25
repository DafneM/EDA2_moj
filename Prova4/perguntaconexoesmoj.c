#include <stdio.h>
#include <stdlib.h>

static int count, pre[2001];

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

int **MATRIXinit(int a, int b, int x) {
	int **m = malloc(sizeof(*m) * a);
	for (int i = 0; i < a; i++){
		m[i] = malloc(sizeof(int) * b);
    }
	return m;
}

Graph GRAPHinit(int v){
    Graph G = malloc(sizeof(*G));
    G->V = v; G->E= 0;
    G->adj=MATRIXinit(v,v,0);
    return G;
}

void GRAPHInsertE(Graph G, Edge e){
    int v = e.v; int w=e.w;
    if(G->adj[v][w] == 0) G->E++;
    G->adj[v][w]=1;
}

void GRAPHInsertE2(Graph G, Edge e){
    int v = e.v; int w=e.w;
    if(G->adj[v][w] == 0) G->E++;
    G->adj[v][w]=1;
    G->adj[w][v]=1;
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
	G->tc = MATRIXinit(G->V, G->V, 0);
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

int main (void) {
	int numdevertices;
	scanf("%d", &numdevertices);
    int vertice1, vertice2, t, x, d;

	Graph CONEXOES = GRAPHinit(numdevertices);
    scanf("%d %d %d", &vertice1, &vertice2, &d);
	while (d != 0){
        if (d == 1){
            GRAPHInsertE(CONEXOES, EDGE(vertice1, vertice2));
        }
        else if(d == 2){
            GRAPHInsertE2(CONEXOES, EDGE(vertice1, vertice2));
        }
        scanf("%d %d %d", &vertice1, &vertice2, &d);
    }
    GRAPHFtc(CONEXOES);
    while(scanf("%d %d", &t, &x) != EOF){
        if(GRAPHreach(CONEXOES, t, x) && GRAPHreach(CONEXOES, x, t)){
            printf("Ida e Volta\n");
        }
        else if(GRAPHreach(CONEXOES, x, t)){
            printf("Apenas Volta\n");
        }
        else if(GRAPHreach(CONEXOES, t, x)){
            printf("Apenas Ida\n");
        }
        else{
            printf("Impossibru\n");
        }
    }
	return 0;
}