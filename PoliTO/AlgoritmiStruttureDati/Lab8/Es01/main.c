#include <stdio.h>




#include "titolo.h"
#include "listaTitoli.h"

#define soglia 2

#include "BST.h"



int main() {


    FILE *file;
    char filename[MAX];
    char codice[MAX];
    int nTitoli;
    int pos;
    //Inizializziamo la listaTitoli

    WrapperTitoli  listaTitoli;
    listaTitoli= List_init();

    BST *bst;
    int primavolta=0;

    Titolo t;
    Quotazione q;



    printf("\n1)Acquisisci transazioni da File");
    printf("\n2)Cerca un Titolo azionario");
    printf("\n3)Cerca quotazione Titolo in una certa data");
    printf("\n4)Cerca quotazione MIN e MAX in un intervallo di date di un Titolo");
    printf("\n5)Cerca quotazione MIN e MAX durante tutta la vita del titolo");
    printf("\n6)Dato un Titolo, bilanciare l'albero");
    printf("\n-1)Esci");

    int scelta;

    do{

        printf("\nSelezione una scelta-->");
        scanf("%d", &scelta);

        switch (scelta) {

            case 1:


                printf("\nInserisci il nome del file che vuoi aggiungere-->");
                scanf("%s", filename);


                if((file=fopen(filename,"r"))==NULL){
                    printf("\nErrore durante l'aperura del file");
                    exit(1);
                }


                ListRead(file, listaTitoli);


                printf("\n---------------------");




                nTitoli= numeroTitoli(listaTitoli);
                bst=malloc(nTitoli*sizeof (BST));



                caricaBSTLT(listaTitoli, bst, primavolta);



                //printf("Marco");


                fclose(file);

                break;

            case 2:

                printf("\nInserisci il codice del titolo che vuoi ricercare-->");
                scanf("%s", codice);

                t= cercaTitoloPerCodice(listaTitoli, codice);

                if(nTransazioni(t)!=0)
                {
                    stampaTitolo(t);

                }else{
                    printf("Il titolo non e' stato trovato!");
                }



                break;

            case 3:

                printf("\nInserisci il codice del titolo che vuoi ricercare-->");
                scanf("%s", codice);
                pos= titoloPos(listaTitoli, codice);

                if(pos!=-1) {

                    printf("\nInserisci la data che vuoi ricercare(gg/mm/aaaa)-->");
                    data d;
                    scanf("%d/%d/%d", &d.giorno, &d.mese, &d.anno);

                    q=BSTsearch(bst[pos],d);


                    printf("\nEcco i dati della quotazione giornaliera: ");
                    stampaQuotazione(q);

                }else{

                    printf("\nIl titolo cercato non è stato trovato!");

                }


                break;


            case 4:

                printf("\nInserisci il codice del titolo che vuoi ricercare-->");
                scanf("%s", codice);
                 pos= titoloPos(listaTitoli, codice);

                if(pos!=-1) {


                    data d1;
                    data d2;

                    printf("\nInserisci la PRIMA data (gg/mm/aaaa)-->");
                    scanf("%d/%d/%d", &d1.giorno, &d1.mese, &d1.anno);

                    printf("\nInserisci la SECONDA data (gg/mm/aaaa)-->");
                    scanf("%d/%d/%d", &d2.giorno, &d2.mese, &d2.anno);

                    int data1= d1.anno+d1.mese+d1.giorno;
                    int data2= d2.anno+d2.mese+d2.giorno;


                    WrapperCercaInOrder(data1, data2, bst[pos]);


                }else{

                    printf("\nIl titolo cercato non è stato trovato!");

                }


                break;

            case 5:

                printf("\nInserisci il codice del titolo che vuoi ricercare-->");
                scanf("%s", codice);
                pos= titoloPos(listaTitoli, codice);

                if(pos!=-1) {


                    WrapperCercaInOrderALL(bst[pos]);


                }else{

                    printf("\nIl titolo cercato non è stato trovato!");

                }

                break;

            case 6:


                printf("\nInserisci il codice del titolo che vuoi ricercare-->");
                scanf("%s", codice);
                pos= titoloPos(listaTitoli, codice);

                if(pos!=-1) {


                    int max= WrappercamminoMax(bst[pos]);
                    int min=WrappercamminoMin(bst[pos]);

                    float rapporto= (max-1)/(min-1);

                   // printf("\nIl rapporto vale: %f", rapporto);

                    if(rapporto>soglia)
                    {

                        BSTbalance(bst[pos]);
                        printf("\n\nIl rapporto ha superato la soglia, l'albero e' stato bilanciato! Per vederne gli effetti riprova con questa opzione.");
                    }else{

                        printf("\n\nIl rapporto non supera la soglia, non e' necessario bilanciare!");
                    }


                }else{

                    printf("\nIl titolo cercato non è stato trovato!");

                }


                break;

            default:

                if(scelta!=-1)
                printf("\nLa scelta effettuata non è valida!");


                break;


        }




    }
    while(scelta!=-1);

    int i;

    //FREEIAMO TUTTO

    for(i=0;i<nTitoli;i++)
    {
        BSTfree(bst[i]);
    }

    free(bst);

    freeList(listaTitoli);

    printf("\nArriverci e grazie per aver utilizzato i nostri servizi!");



    return 0;
}
