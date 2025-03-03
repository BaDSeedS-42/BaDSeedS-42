#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50


typedef struct{

    char codice[MAX];
    char nome[MAX];
    char cognome[MAX];
    char data[MAX];
    char via[MAX];
    char citta[MAX];
    int cap;

}Item;

typedef struct node{

    Item val;
    struct node *next;

}t_nodo, *link;

void stampaMenu();
link SortListIns(link h, Item val);
link newNode(Item val, link next);
void stampaLista(link h);
char *Split(char s[]);
Item itemSetVoid();
Item SortListSearch(link h, char k[]);
link SortListSearchD(link h, char k[]);
Item SortListDel(link *h, char k[]);
int compare(int k, Item persona);
void freeList(link head);




int main() {

    int scelta;
    FILE *file;
    FILE *fOut;
    char filename[MAX], codice[MAX], data1[MAX], data2[MAX], s[MAX], k[MAX], dataCorrente[MAX];
    Item persona; //struct di sostegno


    ///StampaMen�
    stampaMenu();

    /* La lista va ordinata per Data di Nascita */
    link head= NULL;

    // printf("\nMARCO");

    do{

        //stampaMenu();
        printf("\n\nInserisci l'opzione-->");
        scanf("%d", &scelta);

        switch(scelta){


            case 1: //Inserimento ordinato di un nuovo elemento in lista

                ///Inserimento persona da tastiera
                printf("\n");

                printf("\nInserisci il codice-->");
                scanf("%s", persona.codice);

                printf("\nInserisci il nome-->");
                scanf("%s", persona.nome);

                printf("\nInserisci il cognome-->");
                scanf("%s", persona.cognome);

                printf("\nInserisci la data di nascita(gg/mm/aaaa)-->");
                scanf("%s", persona.data);

                printf("\nInserisci la via-->");
                scanf("%s", persona.via);

                printf("\nInserisci la citta-->");
                scanf(" %s", persona.citta);

                printf("\nInserisci il CAP-->");
                scanf("%d", &persona.cap);


                head= SortListIns(head, persona);
                printf("\nLa persone inserita e': %s %s %s %s %s %s %d",persona.codice, persona.nome, persona.cognome, persona.data, persona.via, persona.citta, persona.cap);

                stampaLista(head);

                break;
            case 2:


                printf("\nInserisci il nome del file da cui caricare gli elementi-->");
                scanf("%s", filename);

                if((file=fopen(filename,"r"))==NULL){

                    printf("\nErrore durante l'aperura del file");
                    exit(1);
                }

                ///Cicliamo per ogni persona del file
                while(fscanf(file, "%s %s %s %s %s %s %d", persona.codice, persona.nome, persona.cognome, persona.data, persona.via, persona.citta, &persona.cap)==7)
                {
                    head= SortListIns(head, persona);
                }

                stampaLista(head);

                fclose(file);


                break;
            case 3:

                printf("\nInserisci il codice della persone che vuoi cercare-->");
                scanf("%s", codice);

                Item ris = SortListSearch(head, codice);
                if(head!=NULL) {
                    if (ris.cap != 0) {

                        printf("\nLa persone cercata e': %s %s %s %s %s %s %d", ris.codice, ris.nome, ris.cognome,
                               ris.data, ris.via, ris.citta, ris.cap);

                    } else {

                        printf("\nPersona non trovata!");
                    }
                }else{

                    printf("\nLa lista e' VUOTA!");
                }


                break;
            case 4:

                printf("\nInserisci il codice della persona che vuoi cancellare dalla lista-->");
                scanf("%s", codice);
                Item ris2=SortListDel(&head, codice);

                if(head!=NULL) {
                    if (ris2.cap != 0) {

                        printf("\nLa persone cancellata e': %s %s %s %s %s %s %d", ris2.codice, ris2.nome, ris2.cognome,
                               ris2.data, ris2.via, ris2.citta, ris2.cap);

                    } else {

                        printf("\nPersona non trovata!");
                    }
                }else{

                    printf("\nLa lista e' VUOTA!");
                }

                printf("\nLista aggiornata: ");
                stampaLista(head);

                break;
            case 5:

                printf("\nInserisci la prima data-->");
                scanf("%s", data1);

                printf("\nInserisci la seconda data-->");
                scanf("%s", data2);


                link x = SortListSearchD(head, data1);

                if(x==NULL)
                {
                    printf("\nLa ricerca non ha fornito risultati!");
                }else{

                    //printf("\nLa prima occorrenza dell'intervallo e' %s", x->val.codice);



                    link t;

                    //Costruiamo la seconda chiave
                    strcpy(k, Split(data2));



                    //scorriamo
                    /// for(t=x; t!=NULL; t=t->next)

                    t=x;
                    strcpy(s, t->val.data);
                    strcpy(dataCorrente, Split(s));



                    char cod[MAX];



                    while(strcmp(dataCorrente,k)<0 )
                    {
                        printf("\n k: %s dC: %s", k, dataCorrente);




                        // printf("\nk: %s dataCorrente %s", k, dataCorrente);

                        //Cancelliamo la persone comprese nell'intervallo
                        strcpy(cod, t->val.codice);


                        t=t->next;//andiamo avanti prima di cancellare
                        strcpy(s, t->val.data);
                        strcpy(dataCorrente, Split(s));


                        Item ris4=SortListDel(&head, cod);

                        printf("\nLa persone cancellata e': %s %s %s %s %s %s %d", ris4.codice, ris4.nome, ris4.cognome,
                               ris4.data, ris4.via, ris4.citta, ris4.cap);


                        if (ris4.cap != 0) {



                        } else {

                            printf("\nPersona non trovata!");
                        }






                    }

                    stampaLista(head);
                }



                break;

            case 6:



                if(head!=NULL) {
                    if ((fOut = fopen("out.txt", "w")) == NULL) {

                        printf("\nErrore durante l'aperura del file");
                        exit(1);
                    }

                    for (x = head; x != NULL; x = x->next) {


                        fprintf(file, "\n %s %s %s %s %s %s %d", x->val.codice, x->val.nome, x->val.cognome,
                                x->val.data, x->val.via, x->val.citta, x->val.cap);


                    }

                    fclose(fOut);
                    printf("\nFile salvato con successo!");
                }else{

                    printf("Non vi sono elementi in lista");

                }



                break;
            default:
                printf("\nIl programma è terminato!");
                freeList(head);
                exit(-1);
                break;



        }


    }while(scelta != -1);

    freeList(head);


    return 0;
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


///*****************************************
///CANCELAZIONE CON ESTRAZIONE

Item SortListDel(link *h, char k[]){



    link x, p; //p appoggio(ovverro l'elemento precedente)
    Item persona;

    if(h==NULL)//lista vuota
        return itemSetVoid();



    for(x=*h, p=NULL; x!=NULL; p=x, x=x->next)
    {

        if(strcmp(x->val.codice, k)==0)
        {
            ///Estrazione del dato
            persona=x->val;

            if(x==*h)//se il nodo da cancellare � il primo
                *h = x->next;//la lista avr� come head il secondo elemento della lista
            else
                p->next = x->next;//il successore di p, sar� il successore di x(cos� mettiamo fuori gioco x)


            free(x);//liberiamo x

            break;//e' inutile andare avanti

        }

    }

    return persona;

}


///**************************************
///RICERCA in Lista Ordinata per Data

link SortListSearchD(link h, char s[])
{

    link x;


    char k[MAX], dataCorrente[MAX];

    strcpy(k, Split(s));



    for(x=h; x!=NULL; x=x->next)
    {
        strcpy(s, x->val.data);
        strcpy(dataCorrente, Split(s));



        if(strcmp(dataCorrente, k)>=0) {


            return x;
        }

    }

    return NULL;

}


///**************************************
///RICERCA in Lista Ordinata per Codice

Item SortListSearch(link h, char k[])
{

    link x;

    for(x=h; x!=NULL; x=x->next)
    {

        if(strcmp(x->val.codice, k)==0) {


            return x->val;
        }

    }

    return itemSetVoid();

}



///*************************************
///INSERIMENTO ORDINATO

link SortListIns(link h, Item val){


    char dataHead[MAX], s[MAX], k[MAX], giorno[MAX], mese[MAX], anno[MAX], dataCorrente[MAX];
    int i=0;
    char *token;
    link x, p;
    int di,ki,dci;

    ///************************************************
    ///capovolgiamo le date per la strcmp


    //chiave del valore che vogliamo inserire
    strcpy(s, val.data);
    //creiamo la data k
    strcpy(k,Split(s));



    ki=atoi(k);
    //printf("\nk: %d", ki);

    //creaiamo la data della testa

    if(h!=NULL) {
        strcpy(s, h->val.data);
        strcpy(dataHead,Split(s));
        di=atoi(dataHead);

    }
    //se inserimento in testa oppure k precede la chiave del primo nodo
    if (h == NULL || di>ki) {

        return newNode(val, h);

    }

    /*  if(h!=NULL){

          x = h->next;
          //creiamo la data corrente
          strcpy(s, x->val.data);
          strcpy(dataCorrente,Split(s));
          dci=atoi(dataCorrente);
      }*/
    //printf("%\n k: %d dataCorrente: %d", ki, dci);
    for(x=h->next, p=h; x!=NULL && compare(ki, x->val)==1; p=x, x=x->next);

    // while(x!=NULL && ki>dci) {
/*
        printf("\n%d > %d ?", ki, dci);
        //printf("\n DataCorrenteVera: %s", x->val.data);

        //Prendiamo data corrente
        char s1[MAX];
        strcpy(s1, x->val.data);
        strcpy(dataCorrente, Split(s1));
        printf("\n%s", dataCorrente);
        dci=atoi(dataCorrente);

       //printf("%\n k: %d dataCorrente: %s", ki, dataCorrente);

       p=x;
       x=x->next;


    printf("\n--------------");*/
    p->next=newNode(val,x);

    return h;

}



int compare(int k, Item persona)
{
    int b=0;
    int data;

    char s[MAX];
    char dataS[MAX];

    strcpy(s, persona.data);
    strcpy(dataS, Split(s));
    data= atoi(dataS);

    if(k>data)
        b=1;

    return b;

}

///*******************************************************
//Funzione che ci costruisce le date

char *Split(char s[])
{


    char dataHead[MAX], k[MAX], giorno[MAX], mese[MAX], anno[MAX];
    int i=0;
    char *token;

    i=0;
    token= strtok(s, "/");



    while( token != NULL ) {
        //printf( " %s\n", token ); //stampiamo ogni token
        if(i==0)strcpy(giorno, token);
        if(i==1)strcpy(mese, token);
        if(i==2)strcpy(anno, token);
        i++;
        token = strtok(NULL, "/");

    }



    strcpy(k,anno);
    strcat(k,mese);
    strcat(k,giorno);



    return k;
}


//*************************************
//STAMPA LISTA
void stampaLista(link h){

    link x;
    printf("\n\n");
    for(x=h; x!=NULL; x=x->next){

        printf("\n %s %s %s %s %s %s %d",x->val.codice, x->val.nome, x->val.cognome, x->val.data, x->val.via, x->val.citta, x->val.cap);


    }

}

///*****************************************
///CREAZIONE NUOVO NODO
link newNode(Item val, link next){

    link x = malloc(sizeof *x);

    if(x==NULL)
        return NULL;
    else{

        x->val=val;
        x->next =next;

    }

    return x;

}


Item itemSetVoid()
{

    Item persona;

    strcpy(persona.codice, "\0");
    strcpy(persona.nome, "\0");
    strcpy(persona.cognome, "\0");
    strcpy(persona.data, "\0");
    strcpy(persona.via, "\0");
    strcpy(persona.citta, "\0");
    persona.cap=0;

    return persona;


}

void stampaMenu(){

    printf("\nSCELTE DISPONIBILI:");
    printf("\n\n1)Inserisci una nuova persona(da tastiera)");
    printf("\n2)Inserisci persone da file");
    printf("\n3)Cerca per codice una persona");
    printf("\n4)Cancella una persona per codice");
    printf("\n5)Cancella e visualizzazione delle persone comprese tra due date");
    printf("\n6)Stampa lista su File");
    printf("\n-1)Esci");
    printf("\n");


}
