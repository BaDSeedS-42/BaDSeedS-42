#include <stdio.h>
#include "inventario.h"
#include "personaggi.h"


int main() {

    int scelta;
    WrapperInventario inventario;
    WrapperPersonaggi personaggi;
    personaggi.head=NULL;
    personaggi.tail=NULL;


    printf("Seleziona una opzione tra le seguenti:\n");
    printf("\n1)Carica i personaggi.");
    printf("\n2)Carica l'inventario.");
    printf("\n3)Aggiungi un nuovo personaggio.");
    printf("\n4)Elimina un personaggio.");
    printf("\n5)Aggiungi equippaggiamento al personaggio.");
    printf("\n6)Rimuovi equippaggiamento al personaggio.");
    printf("\n7)Calcola statistiche personaggio");
    printf("\n-1)Esci");

    //Menù

    do {

        printf("\nInserisci un opzione-->");
        scanf("%d", &scelta);

        switch(scelta)
        {

            case  1:

                personaggi= caricaPersonaggi();
               // printf("Marco");

                break;
            case 2://carica l'inventario

                //printf("\nCaso 2:");
                inventario= caricaInventario();

                break;
            case 3: //Aggiungi un nuovo personaggio

                Personaggio personaggio;

                printf("\nInserisci Il Codice-->");
                scanf("%s", personaggio.codice);

                printf("\nInserisci Il Nome-->");
                scanf("%s", personaggio.nome);

                printf("\nInserisci la Classe-->");
                scanf("%s", personaggio.classe);

                personaggio.prese=0;

                printf("\nInserisci stat1-->");
                scanf("%d", &personaggio.stat1);

                printf("\nInserisci stat2-->");
                scanf("%d", &personaggio.stat2);

                printf("\nInserisci stat3-->");
                scanf("%d", &personaggio.stat3);

                printf("\nInserisci stat4-->");
                scanf("%d", &personaggio.stat4);

                printf("\nInserisci stat5-->");
                scanf("%d", &personaggio.stat5);

                printf("\nInserisci stat6-->");
                scanf("%d", &personaggio.stat6);


                //Inserimento in coda
                listInsTFast(&personaggi.head, &personaggi.tail, personaggio);

                stampaLista(personaggi.head);

                printf("\nInserimento avvenuto con successo!\n");


                break;
            case 4: //eliminare un personaggio

                char codice[MAX];
                printf("\nInserisci il codice del personaggio che vuoi eliminare-->");
                scanf("%s", codice);

                Personaggio p = delete(&personaggi.head, codice);

                if(p.codice!="\0") {
                    stampaLista(personaggi.head);
                    printf("\nOperazione avvenuta con successo!");
                }
                else
                    printf("Non è stato trovato l'elemento cercato!");

                break;


            case 5: //Aggiungere equipaggio al personaggio(Ipotizziamo che un personaggio li possa aggiungere anche non distintamente)

                char codP[MAX];
                char nomeE[MAX];


                printf("\nInserisci il codice del personaggio a cui vuoi aggiungere l'equipaggiamento-->");
                scanf("%s", codP);

                printf("\nInserisci il nome dell'equipaggiamento che vuoi aggiungere-->");
                scanf("%s", nomeE);


                //dato l'elemento dell'inventario, otteniamo l'indice di quell'elemento
                int posE = cercaElementoInventario(nomeE, inventario);


                if(posE==-1)
                    printf("\nNon è stato trovato alcun oggetto nell'inventario con quel nome!");
                else {


                    //cerchiamo la posizione del personaggio, dato il codice e inseriamo l'quipaggiamento
                    link x= ListSearch(personaggi.head, codP);

                    if(x!=NULL) {
                        //Inserimento O(1)
                        if (x->val.prese < 8) {
                            x->val.equippagiamento[x->val.prese] = posE;
                            x->val.prese++;

                            stampaPersonaggio(x, inventario);
                            printf("\n\nEquipaggiamento inserito con successo!");
                        } else {

                            printf("\nIl tuo personaggio non può avere più di 8 elementi nell'equipaggiamento!");
                        }
                    }else{

                        printf("\nIl personaggio non e' stato trovato");

                    }



                }

                //stampaLista(personaggi.head);


                break;
            case 6: //Rimuoviamo equipaggiamento dal personaggio

                char codPD[MAX];
                char nomeED[MAX];
                int i,j;

                printf("\nInserisci il codice del personaggio a cui vuoi eliminare  dall'equipaggiamento-->");
                scanf("%s", codPD);

                printf("\nInserisci il nome dell'equipaggiamento che vuoi eliminare-->");
                scanf("%s", nomeED);


                //dato l'elemento dell'inventario, otteniamo l'indice di quell'elemento
                int posED = cercaElementoInventario(nomeED, inventario);
                int t=0;


                if(posED!=-1) //l'elemento cercato è stato trovato nell'inventario
                {

                    link x = ListSearch(personaggi.head, codPD);

                    if(x!=NULL)
                    {

                        //Cerchiamo nel vettore equippaggiamento se troviamo il posED


                            for (i = 0; i < x->val.prese; i++) {

                                if (posED == x->val.equippagiamento[i])//se troviamo corrispondenza tra l'elemento inserito e quello dell'equippaggiamento
                                {

                                    t=1;
                                    //traslazione degli elementi rimanenti
                                    for (j = i; j < x->val.prese - 1; j++) {
                                        x->val.equippagiamento[j] = x->val.equippagiamento[j + 1];
                                    }


                                    x->val.prese--;//decrementiamo il numero di elementi occupati

                                    printf("\nEquippagiamento Eliminato con successo!");

                                    stampaPersonaggio(x, inventario);
                                   // stampaLista(personaggi.head);

                                    break;

                                }

                            }

                            if(t==0)
                                printf("\nTale personaggio non ha quell'equipaggiamento!");




                    }else{
                        printf("\nIl personaggio non e' stato trovato");
                    }




                }else
                    printf("\nNon è stato trovato alcun oggetto nell'inventario con quel nome!");








                break;
            case 7: //calcolare le statistiche di un personaggio

                char codPS[MAX];
                int somme[6];
                printf("Inserisci il codice del giocatore di cui vuoi visualizzare le statistiche-->");
                scanf("%s", codPS);



                //Dobbiamo cercare il personaggio e per ogni suo equipaggiamento sommiamo il punteggio
                link x = ListSearch(personaggi.head, codPS);

                //Inizializziamo Somme
                somme[0]=x->val.stat1;
                somme[1]=x->val.stat2;
                somme[2]=x->val.stat3;
                somme[3]=x->val.stat4;
                somme[4]=x->val.stat5;
                somme[5]=x->val.stat6;


                if(x->val.prese>0)//il personaggio ha degli equipaggiamenti
                {
                    for(i=0; i<x->val.prese; i++)
                    {
                        //Prendiamo l'elemento dall'inventario

                        //printf("\nStat1: %d", inventario.elementi[x->val.equippagiamento[i]].stat3);
                        somme[0]=somme[0]+inventario.elementi[x->val.equippagiamento[i]].stat1;
                        somme[1]=somme[1]+inventario.elementi[x->val.equippagiamento[i]].stat2;
                        somme[2]=somme[2]+inventario.elementi[x->val.equippagiamento[i]].stat3;
                        somme[3]=somme[3]+inventario.elementi[x->val.equippagiamento[i]].stat4;
                        somme[4]=somme[4]+inventario.elementi[x->val.equippagiamento[i]].stat5;
                        somme[5]=somme[5]+inventario.elementi[x->val.equippagiamento[i]].stat6;

                    }


                    printf("\nStatistiche di:");
                    printf("\n\n%s %s %s", x->val.codice, x->val.nome, x->val.classe);

                    for(i=0;i<6; i++)
                    {
                         if(somme[i]<0)
                             printf(" 0");
                         else
                             printf(" %d", somme[i]);

                    }

                }else{
                    printf("\nStatistiche di:");
                    printf("\n\n%s %s %s", x->val.codice, x->val.nome, x->val.classe);
                    printf(" %d  %d  %d  %d  %d  %d", x->val.stat1,  x->val.stat2, x->val.stat3, x->val.stat4, x->val.stat5, x->val.stat6);


                }




                break;
            default:
                if(scelta!=-1)
                printf("Attenzione: l'opzione inserira non esiste!");
                break;

        }



    }while(scelta!=-1);


    //Gestiamo le free
    free(inventario.elementi);
    freeList(personaggi.head);



    return 0;
}




