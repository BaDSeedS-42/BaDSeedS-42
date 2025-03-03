//
// Created by Utente on 07/01/2022.
//

#ifndef ES01_LISTATITOLI_H
#define ES01_LISTATITOLI_H





/* ADT di prima classe collezione di Titoli */
typedef struct WPT *WrapperTitoli; //puntatore a struct

WrapperTitoli List_init();
void ListRead(FILE *fp,  WrapperTitoli  listaTitoli);
void SortListIns(WrapperTitoli listaTitoli, Titolo t);
int Esiste(WrapperTitoli listaTitoli, char k[]);
Titolo cercaTitoloPerCodice(WrapperTitoli listaTitoli, char k[]);
void stampaLista(WrapperTitoli listaTitoli);
void caricaBSTLT(WrapperTitoli listaTitoli, BST *bst, int primaVolta);
int numeroTitoli(WrapperTitoli listaTitoli);
int titoloPos(WrapperTitoli listaTitoli, char k[]);
void freeList(WrapperTitoli listaTitoli);


#endif //ES01_LISTATITOLI_H

