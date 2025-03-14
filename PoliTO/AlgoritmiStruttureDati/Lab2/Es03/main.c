
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct corsa{

    char codice[30+1];
    char partenza[30+1];
    char destinazione[30+1];
    char data[30+1];
    char oraP[30+1];
    char oraA[30+1];
    int ritardo;

};

typedef enum{

    r_stampa, r_ordinaD, r_ordinaC, r_ordinaSP, r_ordinaSA, r_cerca, r_fine, r_err


}comando_e;


comando_e leggiComando();
void toLower(char s[]);
void menuParola(struct corsa **listaCorse, int *n, comando_e codComando);
int carica(struct corsa **listaCorse, char filename[]);

void ordina(struct corsa **listaCorse, int n, char tipo[]);
int confronto(struct corsa **listaCorse, char tipo[], int j);
void sostituisci(struct corsa **listaCorse, int j);
void Free(struct corsa *listaCorse);





///MAIN
int main()
{

    int n,i;
    struct corsa *listaCorse=NULL;
    FILE *file;

    comando_e codComando;

    char dato1[15+1];
    char dato2[15+1];
    char riga[30+2];


    ///Inizializziamo i dati
    dato1[0]='\0';
    dato2[0]='\0';
    riga[0]='\0';


    struct corsa **listaRif; ///Lista dei riferimenti



    ///Step 1: Carica Lista

    ///RICHIAMO DI CARICA
    n = carica(&listaCorse, "log.txt");



    printf("\n\nLista Operazioni Disponibili: \n");
    printf("carica <nomeFile.txt> -> CARICA dati da File\n");
    printf("ordinaD ->ORDINA Tratte Per Data\n");
    printf("ordinaC ->ORDINA Tratte Per Codice\n");
    printf("ordinaSP ->ORDINA Tratte Per Stazione Partenza\n");
    printf("ordinaSA ->ORDINA Tratte Per Stazione Arrivo\n");

    printf("fine -> Termina programma\n");

    while(codComando != r_fine)
    {

            codComando=leggiComando();


        switch(codComando){


            case  r_stampa:

                gets(riga);
                if(riga[0]=='\0')///Se mancano entrambi i dati
                    printf("Attenzione: non hai inserito nessun dato!");
                else{
                    ///Se manca uno dei dati
                    if(sscanf(riga,"%s", dato1)!=1)
                        printf("Attenzione: manca un dato");
                    else{
                        ///Se va tutto bene procediamo con la procedura di caricamento


                        Free(listaCorse);
                        ///RICHIAMO DI CARICA
                        n = carica(&listaCorse, dato1);

                        for(i=0; i<n;i++)
                        {
                              printf("\n%s %s %s %s %s %s %d", listaCorse[i].codice, listaCorse[i].partenza,
                                listaCorse[i].destinazione, listaCorse[i].data, listaCorse[i].oraP, listaCorse[i].oraA, listaCorse[i].ritardo);
                        }


                        printf("\n");




                    }
                }

                break;


            case r_ordinaD: ///DATA


                  // n = stampa(&listaCorse,"log2.txt");

                    ///Gestione riferimenti

                    listaRif=malloc(n*sizeof(struct corsa*));

                    if(listaRif==NULL)
                        printf("Errore malloc");


                    for(i=0; i<n; i++)
                        listaRif[i]= &listaCorse[i];

                    ordina(listaRif, n, "data");
                    printf("\nDati ordinati con SUCCESSO!\n\n");

                    for(i=0; i<n;i++)
                    {
                        printf("\n%s %s %s %s %s %s %d", listaRif[i]->codice, listaRif[i]->partenza,
                               listaRif[i]->destinazione, listaRif[i]->data, listaRif[i]->oraP, listaRif[i]->oraA, listaRif[i]->ritardo);

                    }
                    free(listaRif);

                break;


                case r_ordinaC: ///CODICE


                    ///Gestione riferimenti

                    listaRif=malloc(n*sizeof(struct corsa*));

                    if(listaRif==NULL)
                        printf("Errore malloc");



                    for(i=0; i<n; i++)
                        listaRif[i]= &listaCorse[i];

                    ordina(listaRif, n, "codice");
                    printf("\nDati ordinati con SUCCESSO!\n\n");

                    for(i=0; i<n;i++)
                    {
                        printf("\n%s %s %s %s %s %s %d", listaRif[i]->codice, listaRif[i]->partenza,
                               listaRif[i]->destinazione, listaRif[i]->data, listaRif[i]->oraP, listaRif[i]->oraA, listaRif[i]->ritardo);

                    }


                    free(listaRif);
                break;

            case r_ordinaSP: ///STAZIONE PARTENZA


                    ///Gestione riferimenti

                    listaRif=malloc(n*sizeof(struct corsa*));

                    if(listaRif==NULL)
                        printf("Errore malloc");



                    for(i=0; i<n; i++)
                        listaRif[i]= &listaCorse[i];

                    ordina(listaRif, n, "sp");
                    printf("\nDati ordinati con SUCCESSO!\n\n");

                    for(i=0; i<n;i++)
                    {
                        printf("\n%s %s %s %s %s %s %d", listaRif[i]->codice, listaRif[i]->partenza,
                               listaRif[i]->destinazione, listaRif[i]->data, listaRif[i]->oraP, listaRif[i]->oraA, listaRif[i]->ritardo);

                    }


                    free(listaRif);

                break;

            case r_ordinaSA: ///STAZIONE ARRIVO

                     ///Gestione riferimenti

                    listaRif=malloc(n*sizeof(struct corsa*));

                    if(listaRif==NULL)
                        printf("Errore malloc");



                    for(i=0; i<n; i++)
                        listaRif[i]= &listaCorse[i];

                    ordina(listaRif, n, "sa");
                    printf("\nDati ordinati con SUCCESSO!\n\n");

                    for(i=0; i<n;i++)
                    {
                        printf("\n%s %s %s %s %s %s %d", listaRif[i]->codice, listaRif[i]->partenza,
                               listaRif[i]->destinazione, listaRif[i]->data, listaRif[i]->oraP, listaRif[i]->oraA, listaRif[i]->ritardo);

                    }


                    free(listaRif);

                break;



            case r_err:
                printf("Attenzione il comando inserito non e' corretto!");
                break;


        }




    }

    Free(listaCorse);


    return 0;
}

///***********************************
///LEGGI COMANDO
comando_e leggiComando(){


    comando_e c;
    char comando[15+1];
    ///Tabella di n comandi
    char *tabella[r_err]={"carica", "ordinaD","ordinaC","ordinaSP", "ordinaSA","cerca", "fine"};

    printf("\n\nInserisci Comando (ed eventuali dati)-->");
    scanf("%s", comando);

    //toLower(comando);

    ///Primo comando
    c=r_stampa;
    ///Finchè non troviamo il comando nella tabella
    while(c<r_err && strcmp(comando, tabella[c])!=0)
    {
        c++;
    }

    return c;









}
///************************************
///TOLOWER
void toLower(char s[]){

int i;

for(i=0;s[i]!='\0';i++)
{

    s[i]= tolower(s[i]);

}



}





void Free(struct corsa *listaCorse)
{
    free(listaCorse); ///Il punto interessante è che i tuoi dati saranno lì fino a quando il sistema operativo
    ///non allocherà questa memoria a qualche altro processo e quel processo lo sovrascriverà.
}


///*********************************************
///Carica




int carica(struct corsa **listaCorse, char filename[]){

    int i, n;
    FILE *file;



    ///Step 1: Carica Lista
    if((file=fopen(filename,"r"))==NULL){

        printf("\nErrore durante l'aperura del file (STAMPA)");
        exit(1);
    }

    ///Lettura numero di righe
    fscanf(file,"%d",&n);

    struct corsa *v;///Appoggio
    v = malloc(n*sizeof(struct corsa));

    for(i=0;i<n;i++)
    {

        fscanf(file, "%s%s%s%s%s%s%d", v[i].codice, v[i].partenza,
            v[i].destinazione, v[i].data, v[i].oraP, v[i].oraA, &v[i].ritardo);
    }


    *listaCorse=v;

    fclose(file);
    printf("\nFile caricato con successo!");


    return n;

}





///************************************************
///ORDINA

void ordina(struct corsa **listaCorse, int n, char tipo[]){

    ///BUBBLE SORT OTTIMIZZATO --> STABILE



    int i,j, l=0, r=n-1, flag=1;

    for(i=l; i<r && flag==1; i++){
        flag=0;

        for(j=l; j<r-i+l; j++){

            if(confronto(listaCorse, tipo, j)==1)
            {
                flag=1;
                sostituisci(listaCorse, j);
            }

        }

    }




}

///*************************************************
///CONFRONTO

int confronto(struct corsa **listaCorse, char tipo[], int j){



    ///Caso DATA
    if(strcmp(tipo, "data")==0)
    {
        if(listaCorse[j]->data!=NULL && listaCorse[j+1]->data!=NULL)
        {

            ///Sono uguali le date?
            if(strcmp(listaCorse[j]->data, listaCorse[j+1]->data)==0)
            {
                ///Confrontiamo le ore
                if(strcmp(listaCorse[j]->oraP, listaCorse[j+1]->oraP)>0)
                {
                    return 1;
                }

            ///Se la data j-esima è maggiore della j-esima +1
            }else if(strcmp(listaCorse[j]->data, listaCorse[j+1]->data)>0)
            {

                return 1;

            }
        }else{

            printf("\nErrore");

        }



    }

    ///CODICE
    if(strcmp(tipo, "codice")==0)
    {
        if(strcmp(listaCorse[j]->codice, listaCorse[j+1]->codice)>0)
            return 1;
    }

    ///STAZIONE PARTENZA
   if(strcmp(tipo, "sp")==0)
    {
        if(strcmp(listaCorse[j]->partenza, listaCorse[j+1]->partenza)>0)
            return 1;
    }
   ///STAZIONE ARRIVO
   if(strcmp(tipo, "sa")==0)
    {
        if(strcmp(listaCorse[j]->destinazione, listaCorse[j+1]->destinazione)>0)
            return 1;
    }



    return 0;

}

///****************************
///SOSTITUISCI

void sostituisci(struct corsa **listaCorse,  int j)
{
        ///Scambiamo i puntatori

        ///A[j]
        struct corsa *temp;
        temp=listaCorse[j];


        ///A[j]=A[j+1];
        listaCorse[j]=listaCorse[j+1];


        ///A[j+1]= temp
        listaCorse[j+1]= temp;



}





