#include "stdio.h"
#include "stdlib.h"
#include "assert.h"
//#include "../../Modulo01/src/202301/fila.h"
#include "fila.h"

typedef struct  grafo
{
    int tam_vertice;
    int tam_aresta;
    void* **matriz;

    /* data */
} t_grafo;

t_grafo* criar_grafo(int nro_vertices){
    t_grafo* g = malloc(sizeof(t_grafo));
    g->tam_vertice = nro_vertices;
    g->tam_aresta = 0;

    g->matriz = malloc(sizeof(int*)*g->tam_vertice);
    for(int i=0;i<g->tam_vertice;i++){
        g->matriz[i] = malloc(sizeof(void*)*g->tam_vertice);

    }
    for(int i=0;i<g->tam_vertice;i++){
        for(int j=0;j<g->tam_vertice;j++){
            g->matriz[i][j] = NULL;
        }
    }
    return g;
}

void adicionar_aresta_grafo(t_grafo *g, int u, int v, void* info){
    assert((u>=0 && u<g->tam_vertice));
    assert((v>=0 && v<g->tam_vertice));

    g->matriz[u][v] = info;

}

int adjs_vertice_grafo(t_grafo *g, int u, int adjs[]){
    int nro_adjs = 0;
    for(int v=0; v<g->tam_vertice; v++ ){
        if( g->matriz[u][v] != NULL ){
            nro_adjs++;
            adjs[nro_adjs-1] = v;
        }
    
    }
    return nro_adjs;
}

int nro_vertice_grafo(t_grafo *G){
    return G->tam_vertice;
}

void print_grafo(t_grafo *G){
    for (int i=0;i<G->tam_vertice;i++){
        for (int j=0;j<G->tam_vertice;j++){
            printf(" (%02d, %02d) %c", i,j,(G->matriz[i][j]?'T':'F'));
        }
        printf("\n");
    }
}


// contexto BFS
#define BRANCO 1
#define CINZA 2
#define PRETO 3

#define INFINITO  999999
#define NIL -1

typedef struct info_bfs{
    int id;
    int pi;
    int cor;
    int distancia;
} t_info_bfs;

t_info_bfs* criar_info_bfs(int id){
    t_info_bfs* v = malloc(sizeof(t_info_bfs));
    v->id = id;
    v->pi = NIL;
    v->cor = BRANCO;
    v->distancia = INFINITO;
    return v;
}

void mostrar_info_bfs(t_info_bfs* v){
    printf("%d %d %d %d\n", v->id, v->pi, v->cor, v->distancia);
}

t_info_bfs** bfs(t_grafo *G, int fonte){

    int nro_vertices = nro_vertice_grafo(G);
    t_info_bfs** vertices_bfs = malloc(sizeof(t_info_bfs)*nro_vertices);
    
    for(int i=0;i<nro_vertices;i++){
        vertices_bfs[i] = criar_info_bfs( i );
    }

    t_fila*  no_explorados = criar_fila(nro_vertice_grafo(G));
    t_info_bfs *s = vertices_bfs[fonte];
    s->cor = CINZA;
    s->distancia = 0;

    enfileirar(no_explorados,s);

    while (tamanho_fila(no_explorados)>0){
        t_info_bfs* u = desenfileirar(no_explorados);
        
        int adjs[nro_vertices];
        int nro_adjs = adjs_vertice_grafo(G, u->id, adjs);

        printf("iniciou a exploração: %d ", u->id);
        printf("nro_adjs: %d\n", nro_adjs);

        for(int i=0;i< nro_adjs;i++){
            //printf("adj: (%d %d)\n", u->id, adjs[i]);

            t_info_bfs* v = vertices_bfs[ adjs[i] ];
            if (v->cor == BRANCO){
                v->cor = CINZA;
                v->pi = u->id;
                v->distancia = u->distancia + 1;

                enfileirar(no_explorados,v);        
            }
        }
        u->cor = PRETO;
        printf("Encerrou exploração: %d\n", u->id);
    }
    printf("Encerrou exploração\n");

    return vertices_bfs;
}

void __print_caminho_bfs(t_info_bfs* u, t_info_bfs* grafo_bfs[]){
    if (u->pi == NIL){
        printf("%d ", u->id );
        return;
    }
    __print_caminho_bfs( grafo_bfs[u->pi],grafo_bfs);
    printf("%d ", u->id);
}

void print_grafo_bfs(t_info_bfs* vertices_bfs[], int nro_vertices){

    for(int i=0;i<nro_vertices;i++){
        t_info_bfs *dest = vertices_bfs[i];
        if (dest->pi != NIL){
            __print_caminho_bfs(dest,vertices_bfs);
            printf("\n");
        }else{
            printf("%d Sem caminho\n", dest->id);
        }
    }
}

int main(){
    int *info = malloc(sizeof(int)); *info = 1;
    int u,v, nro_vertices;
    printf("informe nro vertices: ");
    scanf("%d", &nro_vertices);
    t_grafo *G = criar_grafo(nro_vertices);

    do{
        printf("informe aresta (u,v):");
        scanf("%d %d", &u, &v);
        if ((u>=0) && (v>=0)){
            adicionar_aresta_grafo(G,u,v,info);
            adicionar_aresta_grafo(G,v,u,info);
        }
    }while ((u>=0) && (v>=0));
    
    printf("iniciando a busca....\n");
    printf("informe o nó fonte: "); scanf("%d", &u);
    
    print_grafo(G);

    t_info_bfs** grafo_bfs = bfs(G,u);
    print_grafo_bfs(grafo_bfs, nro_vertices);
    
    return 0;

}