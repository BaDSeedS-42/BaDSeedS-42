//
// Created by Utente on 15/12/2021.
//

#include "equipArray.h"

//ADT I CLASSE
struct EA{

    int prese;
    int equipaggiamento[8];

};


/* creatore e distruttore */
WrapperEquipaggiamento equipArray_init(){


    WrapperEquipaggiamento b= malloc(sizeof (WrapperEquipaggiamento));
    b->prese=0;


    return b;

}

void equipArrayPrint(FILE *fp, WrapperEquipaggiamento equipArray, WrapperInventario invArray){

    int i;
    printf("\nEquipaggiamento: ");
    printf("(%d)", equipArray->prese);

    for(i=0; i< equipArray->prese;i++) {

        //stampare equipaggiamento dato un indice

        stampaEquipaggiamentoIndice(fp, invArray, equipArray->equipaggiamento[i]);
    }
    printf("\n");

}

//*******************************************************************
//AGGIUNGI EQUIPAGGIAMENTO
void aggiungiEquipaggiamentoEA(WrapperEquipaggiamento equipArray, int pos){


if(equipArray->prese<=8) {
    equipArray->equipaggiamento[equipArray->prese] = pos;

    equipArray->prese++;

}else{


    printf("\nHai già inserito 8 equipaggiamenti!!!");
}



}

void rimuoviEquipaggiamentoEA(WrapperEquipaggiamento equipArray, int pos){


    int i=0,j;
    int b=0;
    //Cerchiamo nel vettore equipaggiamento se troviamo il pos

    for(i=0; i<equipArray->prese; i++)
    {

        if(pos== equipArray->equipaggiamento[i])
        {
            b=1;

            //traslazione degli elementi rimanenti
            for (j = i; j < equipArray->prese - 1; j++) {
                equipArray->equipaggiamento[j] = equipArray->equipaggiamento[j + 1];
            }

            equipArray->prese--;//decrementiamo il numero di elementi occupati


        }


    }

    if(b==0)
        printf("\nTale personaggio non ha quell'equipaggiamento!");

    printf("\nEquipaggiamento Eliminato con successo!");

}

int prese(WrapperEquipaggiamento equipArray){

return equipArray->prese;

}


int pos(WrapperEquipaggiamento equipArray, int i){


    return equipArray->equipaggiamento[i];


}

