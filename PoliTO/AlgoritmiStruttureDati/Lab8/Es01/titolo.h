//
// Created by Utente on 07/01/2022.
//



#ifndef ES01_TITOLO_H
#define ES01_TITOLO_H

#define MAX 30

#include "stdlib.h"
#include "stdio.h"
#include "string.h"

#include "BST.h"

typedef struct WT *Titolo;

Titolo WPTitolo_init();
int titoliRead(FILE *fp, Titolo t, int n, char *codiceTitolo);
char *codiceTitolo(Titolo t);

void stampaTitolo(Titolo t);
Titolo setItemVoid();
int Update(Titolo t, FILE *fp, int n);
int nTransazioni(Titolo t);
void caricaBSTT(Titolo t, BST bst);


#endif //ES01_TITOLO_H
