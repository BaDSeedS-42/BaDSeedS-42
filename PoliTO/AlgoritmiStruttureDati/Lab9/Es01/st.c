//
// Created by Utente on 15/01/2022.
//

#include "st.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"




struct tabellaSimboli {

    Item *a;
    int maxN;
    int size;
};


void caricaST(ST st, FILE *file){

    int i;


    int n;
    Item vertice;

    fscanf(file,"%d\n", &n);




    for(i=0; i<n;i++)
    {

        fscanf(file, "%s", vertice.nome);
        vertice.indice = st->size;

        STinsert(st, vertice);

    }

    printf("\nInserimento avvenuto con successo!");


    printf("\n I vertici inseriti sono: ");
    for(i=0;i<st->size;i++)
    {
        printf("\n%s", st->a[i].nome);
        printf(" %d", st->a[i].indice);

    }


}



//****************************************************
//INIZIALIZZAZIONE TABELLA DI SIMBOLI
ST STinit(int maxN) {

    ST st; int i;
    st = malloc(sizeof(struct tabellaSimboli));
    //Inizializziamo il vettore di vertici
    st->a = malloc(maxN * sizeof(Item));
    for (i = 0; i < maxN; i++)
        st->a[i] = ITEMsetvoid();
    st->maxN = maxN;
    st->size = 0;
    return st;
}

//*******************************************
//INSERIMENTO DI UN VERTICE
void STinsert(ST st, Item val) {

    int i = st->size;
    //Nel caso si superasse la dimensione massima consentita
    if (st->size >= st->maxN) {
        st->a=realloc(st->a,(2*st->maxN)*sizeof(Item));
        if (st->a == NULL) return;
        st->maxN = 2*st->maxN;
    }
    st->a[i] = val;
    st->size++;
}

//********************************************
//RICERCA PER INDICE
Item STsearchByIndex(ST st, int indice) {
    int i;
    if (st->size == 0) return ITEMsetvoid();
    for (i = 0; i < st->size; i++)
        if (indice== st->a[i].indice)
            return st->a[i];  //gli ritorniamo direttamente tutto le informazioni del vertice
    return ITEMsetvoid();
}

//*******************************************
//RICERCA PER CHIAVE
Item STsearch(ST st, char *k) {
    int i;
    if (st->size == 0) return ITEMsetvoid();
    for (i = 0; i < st->size; i++)
        if (strcmp(k, st->a[i].nome)==0)
            return st->a[i];  //gli ritorniamo direttamente tutto le informazioni del vertice
    return ITEMsetvoid();
}

//***********************************
//ITEMvoid

Item ITEMsetvoid()
{
    Item I;

    strcpy(I.nome,"\0");

    I.indice=-1;

    return I;
}

void liberaST(ST st){

    free(st->a);
    free(st);

}

int STsize(ST st) {
    return st->size;
}

int indiceV(int i,ST st){

    return st->a[i].indice;

}
