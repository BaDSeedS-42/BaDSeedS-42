#ifndef PGLIST_H_DEFINED
#define PGLIST_H_DEFINED

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "personaggi.h"


/* ADT di prima classe collezione di personaggi */
typedef struct WP *WrapperPersonaggi; //puntatore a struct


/* creatore e distruttore */
WrapperPersonaggi pgList_init();


/* lettura e scrittura su file */
void pgListRead(FILE *fp,  WrapperPersonaggi pgList);
void pgListPrint(FILE *fp, WrapperPersonaggi pgList,  WrapperInventario invArray);


/* inserimento di un nuovo personaggio in LISTA */
void pgListInsert(WrapperPersonaggi pgList, Personaggio p);

/* ricerca per codice, ritornando il puntatore */
Personaggio *pgList_searchByCode(WrapperPersonaggi pgList, char* k);

Personaggio itemSetVoid();
/* cancellazione con rimozione */
void pgListRemove(WrapperPersonaggi pgList, char* k);

void aggiungiEquipaggiamentoLP(Personaggio p, char *codiceRicerca, WrapperInventario invArray);
void rimuoviEquipaggiamentoLP(Personaggio p, char *codiceRicerca, WrapperInventario invArray);

void  statisticheLP(Personaggio p, WrapperInventario invArray);

void freeList(WrapperPersonaggi pgList);

#endif
