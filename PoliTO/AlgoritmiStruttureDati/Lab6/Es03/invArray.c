//
// Created by Utente on 14/12/2021.
//

#include "invArray.h"


 struct WI{

    int nElementi;
    Inventario *elementi;

};


//Inizializziamo invArray
WrapperInventario invArray_init(){



    WrapperInventario invArray = malloc(sizeof (struct WI));


    invArray->nElementi=0;
    invArray->elementi=NULL;


    return invArray;

}


void invArray_read(FILE *fp, WrapperInventario invArray){


    int n,i;
//leggiamo il numero di elementi presenti
    fscanf(fp,"%d", &n);

    //printf("\n n: %d", n);

    invArray->elementi=malloc(n*sizeof (Inventario));


    for(i=0;i<n; i++) {

         invArray->elementi[i]=inv_read(fp);

    }



    invArray->nElementi=n;

}



void invArray_print(FILE *fp, WrapperInventario invArray){

    //cicliamo  per nElementi volte  la funzione inv_print

    int i;

    //printf("nElementi: %d", invArray->nElementi);

    for(i=0;i<invArray->nElementi; i++)
    {

        inv_print(stdout, invArray->elementi[i]);
    }


}


//Stampare un equipaggiamento dato un indice
void stampaEquipaggiamentoIndice(FILE *fp, WrapperInventario invArray, int pos)
{



       inv_print(stdout, invArray->elementi[pos]);



}
//*****************************************************
//CERCA EQUIPAGGIAMENTO PER NOME

int cercaEquipaggiamentoPerNome(char *codiceRicerca, WrapperInventario invArray){


    int i, pos=-1;

    for(i=0;i<invArray->nElementi;i++)
    {
        if(strcmp(codiceRicerca, invArray->elementi[i].nome)==0)
            pos=i;

    }

    return pos;


}
int *statisticheIA(int pos, WrapperInventario invArray){


    return statisticheI( invArray->elementi[pos] );



}

