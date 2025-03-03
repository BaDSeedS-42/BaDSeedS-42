//
// Created by Utente on 15/12/2021.
//

#ifndef ES03_EQUIPARRAY_H
#define ES03_EQUIPARRAY_H

#include "invArray.h"


/* ADT di prima classe collezione di oggetti di equipaggiamento */
typedef struct EA *WrapperEquipaggiamento;

/* creatore e distruttore */
WrapperEquipaggiamento equipArray_init();
void equipArray_free(WrapperEquipaggiamento equipArray);

/* quanti equipaggiamenti sono in uso */
int equipArray_inUse(WrapperEquipaggiamento equipArray);

/*Per ogni personaggio stampiamo il suo equipaggiamento */
void equipArrayPrint(FILE *fp, WrapperEquipaggiamento equipArray, WrapperInventario invArray);

/* modifica equipaggiamento scegliendo un oggetto da inventario */
void equipArray_update(WrapperEquipaggiamento equipArray, WrapperInventario invArray);


//Aggiungiamo equipaggiamento
void aggiungiEquipaggiamentoEA(WrapperEquipaggiamento equipArray, int pos);

void rimuoviEquipaggiamentoEA(WrapperEquipaggiamento equipArray, int pos);

//Ci ritorna il numero di elementi
int prese(WrapperEquipaggiamento equipArray);

//Ci deve ritornare pos
int pos(WrapperEquipaggiamento equipArray, int i);


#endif //ES03_EQUIPARRAY_H
