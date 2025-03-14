

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Created by Utente on 10/12/2021.
//
//Protezione
#ifndef ES03_INVENTARIO_H
#define ES03_INVENTARIO_H

#endif //ES03_INVENTARIO_H

#define MAX 35

typedef struct I{

    char nome[MAX];
    char tipo[MAX];

    //statistiche(Non bellissimo ma funzionale)
    int stat1;
    int stat2;
    int stat3;
    int stat4;
    int stat5;
    int stat6;

}Inventario;

typedef struct WI{

    int nElementi;
    Inventario *elementi;

}WrapperInventario;



WrapperInventario caricaInventario();
stampaElemento(Inventario oggetto);
int cercaElementoInventario(char nome[], WrapperInventario b);
