#include <stdio.h>
// Created by Utente on 10/12/2021.
//
#include "inventario.h"
#include "personaggi.h"





WrapperPersonaggi caricaPersonaggi(){

    WrapperPersonaggi wp;
    Personaggio p;
    FILE *file;
    int n,i;
    int cont=0;
    link head=NULL, tail =NULL;

    //Apriamo il file
    if((file=fopen("pg.txt","r"))==NULL){
        printf("\nErrore durante l'aperura del file");
        exit(1);
    }


    while(fscanf(file, "%s %s %s %d %d %d %d %d %d",  p.codice, p.nome, p.classe, &p.stat1, &p.stat2, &p.stat3, &p.stat4, &p.stat5, &p.stat6)==9)
    {
        p.prese=0;
        listInsTFast(&head, &tail, p);



     cont++;
    }

    wp.nPersonaggi=cont;
    wp.tail=tail;
    wp.head=head;

    fclose(file);

    if(head==NULL)
        printf("NULL");

    stampaLista(head);

    printf("\n\nIl numero di personaggi e': %d\n", wp.nPersonaggi);


    return wp;


}


//*************************************
//STAMPA LISTA
void stampaLista(link h){

    link x;
    printf("\n\n");
    for(x=h; x!=NULL; x=x->next){

        printf("\n %s %s %s %d %d %d %d %d %d %d",x->val.codice, x->val.nome, x->val.classe, x->val.prese, x->val.stat1, x->val.stat2, x->val.stat3, x->val.stat4, x->val.stat5, x->val.stat6);

    }


}


//*********************************
//RICERCA per CODICE








///**************************************
///RICERCA in Lista per Codice

link ListSearch(link h, char k[])
{

    link x;

    for(x=h; x!=NULL; x=x->next)
    {

        if(strcmp(x->val.codice, k)==0) {


            return x; //ci ritorna il personaggio trovato
        }

    }


    return NULL;

}

//*****************************************
//CANCELLAZIONE PERSONAGGIO

Personaggio delete(link *h, char k[]){

    Personaggio personaggio;

    link x, p; //p appoggio(ovverro l'elemento precedente)

    if(h==NULL)//In caso la lista fosse vuota
        return itemSetVoid();


    for(x=*h, p=NULL; x!=NULL; p=x, x=x->next)
    {
        if(strcmp(x->val.codice, k)==0)
        {
            ///Estrazione del dato
            personaggio=x->val;

            if(x==*h)//se il nodo da cancellare � il primo
                *h = x->next;//la lista avr� come head il secondo elemento della lista
            else
                p->next = x->next;//il successore di p, sar� il successore di x(cos� mettiamo fuori gioco x)


            free(x);//liberiamo x

            break;//e' inutile andare avanti

        }

    }

    return personaggio;
}


Personaggio itemSetVoid()
{

    Personaggio persona;

    strcpy(persona.codice, "\0");
    strcpy(persona.nome, "\0");
    strcpy(persona.classe, "\0");

    persona.prese=0;
    persona.stat1=0;
    persona.stat2=0;
    persona.stat3=0;
    persona.stat4=0;
    persona.stat5=0;
    persona.stat6=0;

    return persona;


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

//*************************************
//Inserimento in Coda
void listInsTFast(link *hp, link *tp, Personaggio val) {

    if (*hp==NULL) //se head è NULL, ma anche la tail è NULL
        *hp = *tp = newNode(val, NULL); //assegniamo lo stesso puntatore con lo stesso valore sia al head che alla tail
    else { //non vi è più bisogno di trovare l’ultimo
        (*tp)->next = newNode(val, NULL); //agganciamo un nuovo nodo
        *tp = (*tp)->next; //ci spostiamo sul prossimo
    }
}


void stampaPersonaggio(link x, WrapperInventario b)
{

    int i=0;
    printf("\n%s %s %s", x->val.codice, x->val.nome, x->val.classe);

    //Stampiamo equippaggiamento se e solo se vi è presente
    if(x->val.prese>0)
    {
        printf("\nEQUIPPAGGIAMENTO: ");

        for(i=0; i<x->val.prese; i++)//per ogni equipaggiamento che il personaggio detiene
            stampaElemento(b.elementi[x->val.equippagiamento[i]]);//gli passiamo l'elemento pos-esimo dell'elemento presente nell'equipaggiamento(sorta di JOIN)

    }

   // printf("\nStatistiche Personaggio: ");
   // printf("\n%d  %d  %d  %d  %d  %d", x->val.stat1, , x->val.stat2, x->val.stat3, x->val.stat4, x->val.stat5, x->val.stat6);

}

///******************************************
///FREE della LISTA

void freeList(link head)
{
    link tmp;

    while (head != NULL)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }

}
