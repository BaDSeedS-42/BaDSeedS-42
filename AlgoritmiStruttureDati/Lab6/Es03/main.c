#include <stdio.h>
#include <string.h>
#include <stdio.h>



#include "listaPersonaggi.h"
#include "invArray.h"

//#include "pg.h"

#define N_SCELTE 7
#define DBG 0



int main() {



    char codiceRicerca[MAX];
    int scelta;
    FILE *fin;



    printf("Seleziona una opzione tra le seguenti:\n");
    printf("\n1)Stampa i personaggi(e loro statistiche BASE).");
    printf("\n2)Stampa l'inventario.");
    printf("\n3)Cerca Personaggio.");
    printf("\n4)Aggiungi un nuovo personaggio.");
    printf("\n5)Elimina un personaggio.");
    printf("\n6)Aggiungi equipaggiamento al personaggio.");
    printf("\n7)Rimuovi equipaggiamento al personaggio.");
    printf("\n8)Calcola statistiche personaggio(con EQUIPAGGIAMENTO)");
    printf("\n-1)Esci");





    WrapperPersonaggi pgList = pgList_init();
    WrapperInventario invArray = invArray_init();
    Personaggio *p, pg;

     //   pg_t *pgp, pg;


     // Carichiamo i giocatori
   fin = fopen("pg.txt","r");
    pgListRead(fin, pgList);
    fclose(fin);




   if((fin=fopen("inventario.txt","r"))==NULL){
        printf("\nErrore durante l'aperura del file");
        exit(1);
    }

    //Carichiamo invArray
     invArray_read(fin, invArray);
     fclose(fin);



    do {

        printf("\nInserisci un opzione-->");
        scanf("%d", &scelta);

        switch (scelta) {


            case 1:
               pgListPrint(stdout, pgList, invArray);


                break;
            case 2:

                invArray_print(stdout, invArray);
                break;

            case 3:
                printf("Inserire codice personaggio: ");
                scanf("%s", codiceRicerca);

                p = pgList_searchByCode(pgList, codiceRicerca);
                if (p!=NULL) {
                    printf("\nPersonaggio trovato con successo!");
                    pgPrint(stdout, *p, invArray);
                }

                break;
            case 4: {
                printf("Cod Nome Classe HP MP ATK DEF MAG SPR: ");
                if (pgRead(stdin, &pg) != 0) {
                    pgListInsert(pgList, pg);
                    printf("\nPersonaggio Inserito con successo!");
                }
            } break;

            case 5: {
                printf("Inserire codice personaggio: ");
                scanf("%s", codiceRicerca);
                pgListRemove(pgList, codiceRicerca);
                printf("\nPersonaggio Eliminato con successo!");

            } break;

            case 6: //Aggiunta equipaggiamento al personaggio
            {
                printf("Inserire codice personaggio: ");
                scanf("%s", codiceRicerca);

                p = pgList_searchByCode(pgList, codiceRicerca);
                if (p!=NULL) {

                    printf("Inserire nome equipaggiamento che si vuole inserire-->");
                    scanf("%s", codiceRicerca);

                    aggiungiEquipaggiamentoLP(*p, codiceRicerca, invArray);

                    printf("\nEquipaggiamento inserito con successo!");


                }else{

                    printf("\nPersonaggio non trovato!");

                }
            }
            break;

            case 7: //Rimozione equipaggiamento al personaggio
            {
                printf("Inserire codice personaggio: ");
                scanf("%s", codiceRicerca);

                p = pgList_searchByCode(pgList, codiceRicerca);
                if (p!=NULL) {

                    printf("Inserire nome equipaggiamento che si vuole eliminare-->");
                    scanf("%s", codiceRicerca);

                    rimuoviEquipaggiamentoLP(*p, codiceRicerca, invArray);




                }else{

                    printf("\nPersonaggio non trovato!");

                }
            }
                break;

            case 8:
                printf("Inserire codice personaggio di cui vuoi visualizzare le statistiche: ");
                scanf("%s", codiceRicerca);

                p = pgList_searchByCode(pgList, codiceRicerca);
                if (p!=NULL) {


                    statisticheLP(*p, invArray);



                }else{

                    printf("\nPersonaggio non trovato!");

                }

                break;

            default:
                if(scelta!=-1)
                    printf("Attenzione: l'opzione inserita non esiste!");
                break;

        }



    }while(scelta!=-1);


    free(invArray);
   //Funzione di free della lista
    freeList(pgList);

            return 0;
}

