//
// Created by Utente on 15/01/2022.
//

#ifndef ES01_GRAPH_H
#define ES01_GRAPH_H


#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "st.h"

typedef struct edge {

    int v;
    int w;
    int wt;

}arco;

typedef struct graph *Graph;
typedef struct graphL *GraphL;
typedef struct node *link;

//Matrice delle adiacenze
Graph GRAPHinit();
void liberaGRAPH(Graph G);
void GRAPHinsertE(Graph G, int id1, int id2, int wt);
static int **MATRIXinit(int r, int c, int val);
void GRAPHload();
static arco EDGEcreate(int v, int w, int wt);
static void insertE(Graph G, arco e);
//void stampaInOrdineAlfabetico(Graph G, ST st);
//void grafoCompleto(Graph G, ST st);

//Lista delle adiacenze

GraphL generaLista(Graph G, ST st);
static link NEW(int v, int wt, link next);
GraphL GRAPHinitL(int V);
void liberaGRAPHL(GraphL G);
static void insertEL(GraphL G, arco e);
void grafoCompletoL(GraphL GL, ST st);
void powerset(arco *val, GraphL GL, arco *sol);

void comb(arco *val, GraphL GL, arco *sol, int n, int pos, int start, int *max, arco *maxSol, int *N);
int isDAG(GraphL GL);
void DFS(GraphL GL, int v, int *discovered, int *departure, int time);
void dfsR(GraphL G, arco e, int *time, int *pre, int *post, int *st, int *B);
int esisteCiclo(GraphL G, int id);
int connesso(GraphL G);
static void insertEL2(GraphL G, arco e);
arco *caricaVetArchi(GraphL GL);
GraphL listaAdNO(GraphL GL);
void dfsRcc(GraphL G, int v, int id, int *cc);
void DAGrts(GraphL D);
void TSdfsR(GraphL D, int v, int *ts, int *pre, int *time);
#endif //ES01_GRAPH_H
