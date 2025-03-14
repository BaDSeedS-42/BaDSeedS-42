//
// Created by Utente on 10/12/2021.
//

#ifndef ES03_PERSONAGGI_H
#define ES03_PERSONAGGI_H

#endif //ES03_PERSONAGGI_H

#define MAX 30


typedef struct P{

    char codice[MAX];
    char nome[MAX];
    char classe[MAX];
    int prese; //intero da 0 a 8
    int equippagiamento[8]; //conterrà l'indice dell'elemento dell'inventario (una sorta di relazione tra le due tabelle)
    int stat1;
    int stat2;
    int stat3;
    int stat4;
    int stat5;
    int stat6;

}Personaggio;

typedef struct node{

   Personaggio val;
   struct node *next;

}t_nodo, *link;


typedef struct WP{

    int nPersonaggi;
    link head;
    link tail;

}WrapperPersonaggi;

link newNode(Personaggio val, link next);
void listInsTFast(link *hp, link *tp, Personaggio val);
void stampaLista(link h);
WrapperPersonaggi caricaPersonaggi();
link ListSearch(link h, char k[]);
Personaggio itemSetVoid();
Personaggio delete(link *h, char k[]);
void stampaPersonaggio(link x, WrapperInventario b);
void freeList(link head);