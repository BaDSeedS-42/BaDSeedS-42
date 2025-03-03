//
// Created by Utente on 15/12/2021.
//

#ifndef PG_H_DEFINED
#define PG_H_DEFINED

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "equipArray.h"//ricordati che questo sarà in equip


typedef struct P {

    char cod[MAX];
    char nome[MAX];
    char classe[MAX];

    //statistiche base
    int stat1;
    int stat2;
    int stat3;
    int stat4;
    int stat5;
    int stat6;
    WrapperEquipaggiamento equip;

}Personaggio;


/* lettura e scrittura su file */
int pgRead(FILE *fp, Personaggio *p);
/* non essendo struct dinamica, pulisce chiamando il distruttire di equipArray */
void pg_clean(Personaggio *pgp);

void pgPrint(FILE *fp, Personaggio p, WrapperInventario invArray);

void aggiungiEquipaggiamentoP(Personaggio p, int pos);

void rimuoviEquipaggiamentoP(Personaggio p, int pos);

void statisticheP(Personaggio p, WrapperInventario invArray);

#endif
