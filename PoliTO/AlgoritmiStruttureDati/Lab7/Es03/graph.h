//
// Created by Utente on 31/12/2021.
//

#ifndef ES03_GRAPH_H
#define ES03_GRAPH_H

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
void stampaInOrdineAlfabetico(Graph G, ST st);
void grafoCompleto(Graph G, ST st);

//Lista delle adiacenze

GraphL generaLista(Graph G, ST st);
static link NEW(int v, int wt, link next);
GraphL GRAPHinitL(int V);
void liberaGRAPHL(GraphL G);
static void insertEL(GraphL G, arco e);
void grafoCompletoL(GraphL GL, ST st);

#endif //ES03_GRAPH_H
