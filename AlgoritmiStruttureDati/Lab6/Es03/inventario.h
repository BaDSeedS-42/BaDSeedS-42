//
// Created by Utente on 14/12/2021.
//



#ifndef INV_H_DEFINED
#define INV_H_DEFINED

#include <stdlib.h>
#include <string.h>
#include <stdio.h>


#define MAX 100
#define MIN_STAT 1
#define Nstatistiche 6


//QUASI-ADT(struct visible)

typedef struct I{

    char nome[MAX];
    char tipo[MAX];

    //statistiche
    int stat1;
    int stat2;
    int stat3;
    int stat4;
    int stat5;
    int stat6;

}Inventario;



/* funzioni di input/output di un oggetto dell'inventario */
Inventario inv_read(FILE *fp);
void inv_print(FILE *fp, Inventario oggetto);


int *statisticheI( Inventario oggetto);







#endif
