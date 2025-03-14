//
// Created by Utente on 31/12/2021.
//
#include "stdlib.h"
#include "string.h"
#include "st.h"



struct tabellaSimboli {

    Item *a;
    int maxN;
    int size;
};



void caricaST(ST st, FILE *file){

    int i;

    char nome1[MAX];
    char nome2[MAX];
    char rete1[MAX];
    char rete2[MAX];
    Item vertice;


   while(fscanf(file, "%s %s %s %s %*d", nome1, rete1, nome2, rete2)==4)
    {


        Item val= STsearch(st, nome1);

        if(val.indice==-1) //Il vertice non sia già stato inserito?
        {
            strcpy(vertice.nome,nome1);
            strcpy(vertice.rete,rete1);
            vertice.indice= st->size;
           // printf("\n size1: %d", st->size);

            STinsert(st, vertice);


        }

        val = STsearch(st, nome2);

        if(val.indice==-1)
        {
            strcpy(vertice.nome,nome2);
            strcpy(vertice.rete,rete2);

           // printf("\n size2: %d", st->size);
            vertice.indice=st->size;

            STinsert(st, vertice);
            //printf("Marco");

        }



    }

    printf("\nInserimento avvenuto con successo!");
    //printf("%d", k);




}

int STsize(ST st) {
    return st->size;
}

int indiceV(int i,ST st){

    return st->a[i].indice;

}





void ordinaST(ST st){


    int i,j;

    Item temp;

    for(i=0;i<st->size;i++)
    {
        for(j=0;j<st->size-1;j++)
        {

            if(strcmp( st->a[j].nome, st->a[j+1].nome)>0 )
            {
                temp = st->a[j];
                st->a[j]=st->a[j+1];
                st->a[j+1]=temp;


            }

        }


    }

    printf("\n I vertici inseriti sono: ");
    for(i=0;i<st->size;i++)
    {
        printf("\n%s", st->a[i].nome);
        printf(" %s", st->a[i].rete);
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

//***********************************
//ITEMvoid

Item ITEMsetvoid()
{
    Item I;

    strcpy(I.nome,"\0");
    strcpy(I.rete,"\0");
    I.indice=-1;

    return I;
}

void liberaST(ST st){

    free(st->a);
    free(st);

}