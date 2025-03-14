//
// Created by Utente on 15/01/2022.
//

#ifndef ES01_ST_H
#define ES01_ST_H

#define MAX 30
#include "stdio.h"
#include "stdlib.h"
#include "string.h"


typedef struct tabellaSimboli *ST;

//Scegliamo di definire l'Item direttamente nella tabella di simboli
typedef struct I{

    char nome[MAX];
    //char rete[MAX];
    int indice;

}Item;

ST STinit(int maxN);
void liberaST(ST st);

void STinsert(ST st, Item val);
Item STsearch(ST st, char *k);
int GETindex(char  *k);
Item ITEMsetvoid();

void caricaST(ST st, FILE *file);

int STsize(ST st);

void ordinaST(ST st);
int indiceV(int i,ST st);
Item STsearchByIndex(ST st, int indice);



#endif //ES01_ST_H
