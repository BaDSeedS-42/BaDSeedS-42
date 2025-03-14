//
// Created by Utente on 07/01/2022.
//
#include "stdlib.h"
#include "stdio.h"

#include "titolo.h"
#include "listaTitoli.h"



typedef struct node{

    Titolo titolo;
    struct node *next;

}t_nodo, *link;

struct WPT{

    int nTitoli;
    link head;
    link tail;

};


//Inizializzazione Wrapper
WrapperTitoli List_init(){

    WrapperTitoli b= malloc(sizeof(struct WPT));

    b->head=NULL;
    b->tail=NULL;
    b->nTitoli=0;

    return b;
}


//***************************************************************
//CARICA BST

void caricaBSTLT(WrapperTitoli listaTitoli, BST *bst, int primaVolta)
{
    int i;
    int k=0;

   // printf("\n NtitoliOld: %d, nTitoliCorrenti: %d", nTitoliOld, listaTitoli->nTitoli);

    //Per Ogni Titolo
    link x;
    for(x=listaTitoli->head; x!=NULL; x=x->next){

        bst[k]=BSTinit();
        caricaBSTT(x->titolo, bst[k]);
        printf("\n%s:", codiceTitolo(x->titolo));
        stampaBSTinOrder(bst[k]);
        k++;

    }


    //for(i=0;i<nTitoliOld; i++)
    //{

     //  printf("Marco");
     //  BSTfree(bst[i]);
  //  }



}

//*******************************
//READ Titoli
void ListRead(FILE *fp,  WrapperTitoli  listaTitoli){


    int n, nT, i;
    char codice[MAX];



    fscanf(fp, "%d", &n);


    for(i=0;i<n;i++) //per ogni titolo
    {


        Titolo t = WPTitolo_init();


        fscanf(fp,"%s %d", codice, &nT);



        //Questo titolo esiste già in lista?(grazie al codice lo potremmo capire)

        //printf("\nEsiste: %d", Esiste(listaTitoli, codice));
        if(Esiste(listaTitoli, codice)==1) {

            //cerchiamo il titolo nella lista
            Titolo t2 = cercaTitoloPerCodice(listaTitoli, codice);

            //facciamo una funzione Update(titolo, file, n) che realloca il vettore delle transazioni e ci inserisce le nuove transazioni del titolo

            int res= Update(t2, fp, nT); //Aggiungiamo le transazioni al titolo


          //  printf("\nMarco");

            if(res==-1)
                printf("Si e' verificato un errore nell'Update!");


        }
        else //Inseriamo il nuovo titolo con le sue transazioni
        {
            if(titoliRead(fp, t, nT, codice)!=-1)
                SortListIns(listaTitoli, t);
        }



    }

   // printf("Marco");



    printf("\nNumero titoli: %d", listaTitoli->nTitoli);
    link x;
    for(x=listaTitoli->head; x!=NULL; x=x->next){


        stampaTitolo(x->titolo);

    }


}

void stampaLista(WrapperTitoli listaTitoli)
{

    link x;
    for(x=listaTitoli->head; x!=NULL; x=x->next){


        stampaTitolo(x->titolo);

    }

}





///**************************************
///Cerca Titolo per codice

Titolo cercaTitoloPerCodice(WrapperTitoli listaTitoli, char k[])
{

    link x;

    for(x=listaTitoli->head; x!=NULL; x=x->next)
    {
        if(strcmp(codiceTitolo(x->titolo), k)==0) {

            return x->titolo;
        }

    }

    return setItemVoid();

}

int titoloPos(WrapperTitoli listaTitoli, char k[]){

    link x;
    int pos=0;


    for(x=listaTitoli->head; x!=NULL; x=x->next)
    {
        if(strcmp(codiceTitolo(x->titolo), k)==0) {

            return pos;
        }

        pos++;
    }

    return -1;


}

///**************************************
///Esiste?

int Esiste(WrapperTitoli listaTitoli, char k[])
{

    link x;

    for(x=listaTitoli->head; x!=NULL; x=x->next)
    {
        if(strcmp(codiceTitolo(x->titolo), k)==0) {

            return 1;
        }

    }

    return 0;

}



///*****************************************
///CREAZIONE NUOVO NODO
link newNode(Titolo val, link next){

    link x = malloc(sizeof *x);

    if(x==NULL)
        return NULL;
    else{

        x->titolo=val;
        x->next =next;

    }

    return x;

}

//***********************************************************
//Inseriamo in lista il titolo, in lista ordinata

void SortListIns(WrapperTitoli listaTitoli, Titolo t) {
    link x, p;
    char k[MAX];

    strcpy(k, codiceTitolo(t)); //prendiamo la chiave del dato obiettivo che vogliamo inserire

    listaTitoli->nTitoli++;
    //se inserimento in testa oppure k precede la chiave del primo nodo
    if (listaTitoli->head == NULL || strcmp(codiceTitolo(listaTitoli->head->titolo), k) > 0) {
       listaTitoli->head = newNode(t, listaTitoli->head);//torniamo il puntatore al primo nodo head
        return;
    }


    //Attraversamento della lista	//il for si ferma quando x punta a, è diventato NULL oppure se esiste la chiave che è più grande
    for (x=listaTitoli->head->next, p=listaTitoli->head; x != NULL && strcmp(k, codiceTitolo(x->titolo)) > 0; p=x, x=x->next);
         p->next = newNode(t, x); //nuovo nodo, successore di p



}

int numeroTitoli(WrapperTitoli listaTitoli)
{

    return listaTitoli->nTitoli;

}

///******************************************
///FREE della LISTA

void freeList(WrapperTitoli listaTitoli)
{
    link tmp;

    while (listaTitoli->head != NULL)
    {
        tmp = listaTitoli->head;
        listaTitoli->head = listaTitoli->head->next;
        free(tmp);
    }

}