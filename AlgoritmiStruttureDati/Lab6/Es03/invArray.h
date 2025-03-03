//
// Created by Utente on 14/12/2021.
//

#ifndef INVARRAY_H_DEFINED
#define INVARRAY_H_DEFINED

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "inventario.h"

/* ADT di prima classe collezione di oggetti di inventario */
typedef struct WI *WrapperInventario; //puntatore a struct


/* creatore e distruttore */
WrapperInventario invArray_init();
void invArray_free(WrapperInventario invArray);

/* lettura e scrittura su file */
void invArray_read(FILE *fp, WrapperInventario invArray);//richiameremo poi la inv_read ad ogni giro
void invArray_print(FILE *fp, WrapperInventario invArray);

void stampaEquipaggiamentoIndice(FILE *fp, WrapperInventario invArray, int pos);

int cercaEquipaggiamentoPerNome(char *codiceRicerca, WrapperInventario invArray);

int *statisticheIA( int pos, WrapperInventario invArray);




#endif
