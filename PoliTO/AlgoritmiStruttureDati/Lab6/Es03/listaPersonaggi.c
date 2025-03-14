//
// Created by Utente on 15/12/2021.
//

#include "listaPersonaggi.h"


typedef struct node{

    Personaggio val;
    struct node *next;

}t_nodo, *link;

struct WP{

    int nPersonaggi;
    link head;
    link tail;

};

//Inizializzazione Wrapper
WrapperPersonaggi pgList_init(){

    WrapperPersonaggi b=malloc(sizeof(struct WP));

    b->head=NULL;
    b->tail=NULL;
    b->nPersonaggi=0;

    return b;

}


//*******************************
//READ PERSONAGGI
void pgListRead(FILE *fp,  WrapperPersonaggi pgList){

    Personaggio p;
    int cont=0;

    while(pgRead(fp, &p)!= -1) //scan
    {


        //Inserimento in coda

        pgListInsert(pgList, p);
        cont++;


    }


    pgList->nPersonaggi=cont;

}

//******************************************
//PRINT PERSONAGGI

void pgListPrint(FILE *fp, WrapperPersonaggi pgList,  WrapperInventario invArray)
{

    link x;
    for(x=pgList->head; x!=NULL; x=x->next)
    {

        pgPrint(fp, x->val, invArray);

    }


}
//*****************************************
//CANCELLAZIONE PERSONAGGIO
void pgListRemove(WrapperPersonaggi pgList, char* k)
{
    Personaggio personaggio;

    link x, p; //p appoggio(ovverro l'elemento precedente)

    //if(pgList->head==NULL)//In caso la lista fosse vuota


    for(x= pgList->head , p=NULL; x!=NULL; p=x, x=x->next)
    {
        if(strcmp(x->val.cod, k)==0)
        {
            ///Estrazione del dato
            personaggio=x->val;

            if(x==pgList->head)//se il nodo da cancellare � il primo
                pgList->head = x->next;//la lista avr� come head il secondo elemento della lista
            else
                p->next = x->next;//il successore di p, sar� il successore di x(cos� mettiamo fuori gioco x)


            free(x);//liberiamo x

            break;//e' inutile andare avanti

        }

    }

}



void aggiungiEquipaggiamentoLP(Personaggio p, char *codiceRicerca, WrapperInventario invArray){



    //cerchiamo l'indice dato il nome dell'equipaggiamento nell'inventario

    int pos = cercaEquipaggiamentoPerNome(codiceRicerca, invArray);

    if(pos!=-1)
        aggiungiEquipaggiamentoP(p, pos);
    else
        printf("\nL'equipaggiamento cercato non è stato trovato!");





}

void rimuoviEquipaggiamentoLP(Personaggio p, char *codiceRicerca, WrapperInventario invArray){


    //cerchiamo l'indice dato il nome dell'equipaggiamento nell'inventario
    int pos = cercaEquipaggiamentoPerNome(codiceRicerca, invArray);

    if(pos!=-1)
        rimuoviEquipaggiamentoP(p, pos);
    else
        printf("\nL'equipaggiamento cercato non è stato trovato!");


}
void  statisticheLP(Personaggio p, WrapperInventario invArray){



    statisticheP(p, invArray);


}


///******************************************
///FREE della LISTA

void freeList(WrapperPersonaggi pgList)
{
    link tmp;

    while (pgList->head != NULL)
    {
        tmp = pgList->head;
        pgList->head = pgList->head->next;
        free(tmp);
    }

}



Personaggio itemSetVoid()
{

    Personaggio persona;

    strcpy(persona.cod, "\0");
    strcpy(persona.nome, "\0");
    strcpy(persona.classe, "\0");


    persona.stat1=0;
    persona.stat2=0;
    persona.stat3=0;
    persona.stat4=0;
    persona.stat5=0;
    persona.stat6=0;

    return persona;


}

///**************************************
///RICERCA in Lista per Codice

Personaggio *pgList_searchByCode(WrapperPersonaggi pgList, char* k)
{

    link x;

    for(x=pgList->head; x!=NULL; x=x->next)
    {

        if(strcmp(x->val.cod, k)==0) {

            return &x->val; //ci ritorna il personaggio trovato
        }

    }


    return NULL;

}




///*****************************************
///CREAZIONE NUOVO NODO
link newNode(Personaggio val, link next){

    link x = malloc(sizeof *x);

    if(x==NULL)
        return NULL;
    else{

        x->val=val;
        x->next =next;

    }

    return x;

}

//Inseriamo in lista il personaggio, in coda
void pgListInsert(WrapperPersonaggi pgList, Personaggio p)
{

    if (pgList->head==NULL) //se head è NULL, ma anche la tail è NULL
        pgList->head = pgList->tail = newNode(p, NULL); //assegniamo lo stesso puntatore con lo stesso valore sia al head che alla tail
    else { //non vi è più bisogno di trovare l’ultimo
        (pgList->tail)->next = newNode(p, NULL); //agganciamo un nuovo nodo
        pgList->tail = (pgList->tail)->next; //ci spostiamo sul prossimo
    }

}


