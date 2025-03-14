//
// Created by Utente on 07/01/2022.
//



#include "data.h"
#include "titolo.h"



typedef struct t{

    data data; //quasi-ADT
    ora ora;  //quasi-ADT
    int valore;
    int numero;

}Transazione;

struct WT{

    char codTitolo[MAX];
    int nTransazioni;
    Transazione *transazioni; //dovremmo reallocarlo ogni volta

};

Titolo WPTitolo_init(){

    Titolo b = malloc(sizeof(struct WT));

    b->nTransazioni=0;
    strcpy(b->codTitolo, "\0");

    return b;
}

///************************************************************
///CARICA BST
void caricaBSTT(Titolo t, BST bst){



    int i;

    int numeratore=0;
    int denominatore=0;
    float quotazione;

    if(t->nTransazioni>1) {

        for (i = 0; i < t->nTransazioni - 1; i++) //per ogni transazione
        {


            //Mandiamo tutti i dati necessari poer creare una quotazione

            int data1 = t->transazioni[i].data.anno + t->transazioni[i].data.mese + t->transazioni[i].data.giorno;
            int data2 = t->transazioni[i + 1].data.anno + t->transazioni[i + 1].data.mese +
                        t->transazioni[i + 1].data.giorno;


            if (data1 == data2) {

                numeratore += t->transazioni[i].valore * t->transazioni[i].numero;
                denominatore += t->transazioni[i].numero;

            } else //se la data dopo è diversa, salviamo tale quotazione giornaliera
            {
                //Costruiamo la quotazione giornaliera


                numeratore += t->transazioni[i].valore * t->transazioni[i].numero;
                denominatore += t->transazioni[i].numero;

                quotazione = numeratore / denominatore;

                caricaBST(bst, t->codTitolo, quotazione, t->transazioni[i].data);

                numeratore=0;
                denominatore=0;

            }

            if (i + 1 == t->nTransazioni - 1) //L'ultima transazione
            {
                numeratore += t->transazioni[i+1].valore * t->transazioni[i+1].numero;
                denominatore += t->transazioni[i+1].numero;



                //Costruiamo la quotazione giornaliera
               // printf("\n%d", numeratore);
                //printf(" %d", denominatore);

                quotazione = numeratore / denominatore;

               // printf("\nMarco");


                caricaBST(bst, t->codTitolo, quotazione, t->transazioni[i+1].data);

            }


        }


    }else{


        //Costruiamo la quotazione giornaliera
        //printf("\n%d", numeratore);
        //printf(" %d", denominatore);

        quotazione = t->transazioni[0].valore * t->transazioni[0].numero/ t->transazioni[0].numero;

        //printf("\nMarco");


        caricaBST(bst, t->codTitolo, quotazione, t->transazioni[0].data);



    }

}


/* lettura e scrittura su file */
int titoliRead(FILE *fp, Titolo t, int n, char *codiceTitolo)
{


    int i;
    strcpy(t->codTitolo, codiceTitolo);

    t->transazioni=malloc(n*sizeof(Transazione));

    //Per ogni transazione del titolo
    for(i=0;i<n;i++) {

            if(fscanf(fp, "%d/%d/%d %d:%d %d %d", &t->transazioni[i].data.anno, &t->transazioni[i].data.mese, &t->transazioni[i].data.giorno, &t->transazioni[i].ora.ore, &t->transazioni[i].ora.minuti, &t->transazioni[i].valore, &t->transazioni[i].numero)!=7)
                return -1;


    }

    t->nTransazioni=n;

    printf("\n");

    return 1;


}

void stampaTitolo(Titolo t){

    int i;

    printf("\n%s", t->codTitolo);
    for(i=0;i<t->nTransazioni;i++) {

        printf("\n %d/%d/%d %d:%d %d %d", t->transazioni[i].data.anno, t->transazioni[i].data.mese, t->transazioni[i].data.giorno, t->transazioni[i].ora.ore, t->transazioni[i].ora.minuti, t->transazioni[i].valore, t->transazioni[i].numero);

    }


};

char *codiceTitolo(Titolo t){

    return t->codTitolo;

}


int nTransazioni(Titolo t){
    return t->nTransazioni;
}


Titolo setItemVoid(){


    Titolo t;

    t= WPTitolo_init();

    return t;
}
//*********************************************************
//UPDATE: modifichiamo il titolo
int Update(Titolo t, FILE *fp, int n)
{
    //costruiamo la nuova dimensione del vettore transazioni
    int N= n + t->nTransazioni;
    int i;

    printf("\nN:%d", N);

    //printf("\n Dimensione transazioni1: %d ", sizeof(t->transazioni));

    t->transazioni = realloc(t->transazioni, N*sizeof(Transazione));


    //printf("\n Dimensione transazioni: %d ", sizeof(t->transazioni));


    for(i=t->nTransazioni; i< N; i++)
    {

        if(fscanf(fp, "%d/%d/%d %d:%d %d %d", &t->transazioni[i].data.anno, &t->transazioni[i].data.mese, &t->transazioni[i].data.giorno, &t->transazioni[i].ora.ore, &t->transazioni[i].ora.minuti, &t->transazioni[i].valore, &t->transazioni[i].numero)!=7)
            return -1;

         //printf("\n %d/%d/%d %d:%d %d %d", t->transazioni[i].data.anno, t->transazioni[i].data.mese, t->transazioni[i].data.giorno, t->transazioni[i].ora.ore, t->transazioni[i].ora.minuti, t->transazioni[i].valore, t->transazioni[i].numero);


    }

    t->nTransazioni=N;

    return 1;



}