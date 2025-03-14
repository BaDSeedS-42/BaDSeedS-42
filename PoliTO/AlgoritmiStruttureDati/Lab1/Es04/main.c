
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
void menuParola(struct corsa **listaCorse, int n, comando_e codComando);
void stampa(struct corsa listaCorse[], int n, char tipo[]);
void ordina(struct corsa **listaCorse, int n, char tipo[]);
int confronto(struct corsa **listaCorse, char tipo[], int j);
int sostituisci(struct corsa **listaCorse, int j);

int cerca(struct corsa listaCrose[], int n, char s[], int vet[]);
int cerca2(struct corsa listaCorse[], int n, char s[], int vet[]);

void date(struct corsa listaCorse[], int n, char data1[], char data2[]);
void ritardo(struct corsa listaCorse[], int n, char data1[], char data2[]);
void partenza(struct corsa listaCorse[], int n, char stazione[]);
void capolinea(struct corsa listaCorse[], int n, char stazione[]);

///MAIN
int main()
{

    int n,i;
    FILE *file;

    comando_e codComando;


    ///Step 1: Carica Lista
    if((file=fopen("log.txt","r"))==NULL){

            printf("\nErrore durante l'aperura del file");
    }

    ///Lettura numero di righe
    fscanf(file,"%d",&n);

    ///Dichiariamo la lista di corse grande quante corse ci sono
    struct corsa listaCorse[n], *listaRif[n];


    for(i=0;i<n;i++)
    {

        fscanf(file, "%s%s%s%s%s%s%d", &listaCorse[i].codice, &listaCorse[i].partenza,
        &listaCorse[i].destinazione, &listaCorse[i].data, &listaCorse[i].oraP, &listaCorse[i].oraA, &listaCorse[i].ritardo);

        listaRif[i]=&listaCorse[i]; ///Facciamo puntare listaRif ad ogni elemento di elenco

    }

    printf("\nLista Operazioni Disponibili: \n");
    printf("ordinaD ->ORDINA Tratte Per Data\n");
    printf("ordinaC ->ORDINA Tratte Per Codice\n");
    printf("ordinaSP ->ORDINA Tratte Per Stazione Partenza\n");
    printf("ordinaSA ->ORDINA Tratte Per Stazione Arrivo\n");

    printf("fine -> Termina programma\n");

    while(codComando != r_fine)
    {

            codComando=leggiComando();
            menuParola(listaRif, n, codComando);



    }


    return 0;
}

///***********************************
///LEGGI COMANDO
comando_e leggiComando(){


    comando_e c;
    char comando[15+1];
    ///Tabella di n comandi
    char *tabella[r_err]={"stampa", "ordinaD","ordinaC","ordinaSP", "ordinaSA","cerca", "fine"};

    printf("\n\nInserisci Comando (ed eventuali dati)-->");
    scanf("%s", &comando);

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



///****************************************
///MENU PAROLA
void menuParola(struct corsa **listaCorse, int n, comando_e codComando){



    char dato1[15+1];
    char dato2[15+1];
    char riga[30+2];

    ///Inizializziamo i dati
    dato1[0]='\0';
    dato2[0]='\0';
    riga[0]='\0';

    int i;

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
                        stampa(listaCorse, n, dato1);
                    }
                }

                break;


            case r_ordinaD: ///DATA

                    ordina(listaCorse, n, "data");
                    printf("\nDati ordinati con SUCCESSO!\n\n");

                    for(i=0; i<n;i++)
                    {
                        printf("\n%s %s %s %s %s %s %d", listaCorse[i]->codice, listaCorse[i]->partenza,
                                listaCorse[i]->destinazione, listaCorse[i]->data, listaCorse[i]->oraP, listaCorse[i]->oraA, listaCorse[i]->ritardo);
                    }




                break;

            case r_ordinaC: ///CODICE

                    ///vettore che contiene gli indici dei risultati
                    ordina(listaCorse, n, "codice");
                    printf("\nDati ordinati con SUCCESSO!\n\n");

                    for(i=0; i<n;i++)
                    {
                        printf("\n%s %s %s %s %s %s %d", listaCorse[i]->codice, listaCorse[i]->partenza,
                                listaCorse[i]->destinazione, listaCorse[i]->data, listaCorse[i]->oraP, listaCorse[i]->oraA, listaCorse[i]->ritardo);
                    }



                break;

            case r_ordinaSP: ///STAZIONE PARTENZA

                    ordina(listaCorse, n, "sp");
                    printf("\nDati ordinati con SUCCESSO!\n\n");

                    for(i=0; i<n;i++)
                    {
                        printf("\n%s %s %s %s %s %s %d", listaCorse[i]->codice, listaCorse[i]->partenza,
                                listaCorse[i]->destinazione, listaCorse[i]->data, listaCorse[i]->oraP, listaCorse[i]->oraA, listaCorse[i]->ritardo);
                    }

                break;

            case r_ordinaSA: ///STAZIONE ARRIVO

                    ordina(listaCorse, n, "sa");
                    printf("\nDati ordinati con SUCCESSO!\n\n");

                     for(i=0; i<n;i++)
                    {
                        printf("\n%s %s %s %s %s %s %d", listaCorse[i]->codice, listaCorse[i]->partenza,
                                listaCorse[i]->destinazione, listaCorse[i]->data, listaCorse[i]->oraP, listaCorse[i]->oraA, listaCorse[i]->ritardo);
                    }


                break;

            case r_cerca:

                gets(riga);
                if(riga[0]=='\0')///Se mancano entrambi i dati
                    printf("Attenzione: non hai inserito nessun dato!");
                else{
                    ///Se manca uno dei dati
                    if(sscanf(riga,"%s", dato1)!=1)
                        printf("Attenzione: manca un dato");
                    else{
                        //carica(listaCorse);
                        int vet[20];
                        int N= cerca(listaCorse, n, dato1, vet);

                        printf("\nRisultato ricerca:");

                        if(N!=0)
                        for(i=0;i<N;i++)
                        {
                              printf("\n%s %s %s %s %s %s %d", listaCorse[vet[i]]->codice, listaCorse[vet[i]]->partenza,
                                listaCorse[vet[i]]->destinazione, listaCorse[vet[i]]->data, listaCorse[vet[i]]->oraP, listaCorse[vet[i]]->oraA, listaCorse[vet[i]]->ritardo);

                        }
                        else
                            printf("\nLa ricerca NON ha fornito alcun risultato.");

                        ///RICERCA DICOTOMICA

                        int vet2[20];
                        N = cerca2(listaCorse, n, dato1, vet2);


                        printf("\nRisultato ricerca DICOTOMICA:");

                        if(N!=0)
                        for(i=0;i<N;i++)
                        {
                              printf("\n%s %s %s %s %s %s %d", listaCorse[vet[i]]->codice, listaCorse[vet[i]]->partenza,
                                listaCorse[vet[i]]->destinazione, listaCorse[vet[i]]->data, listaCorse[vet[i]]->oraP, listaCorse[vet[i]]->oraA, listaCorse[vet[i]]->ritardo);

                        }
                        else
                            printf("\nLa ricerca NON ha fornito alcun risultato.");



                    }
                }



                break;

            case r_err:
                printf("Attenzione il comando inserito non e' corretto!");
                break;


        }



}

///*********************************************
///STAMPA

void stampa(struct corsa listaCorse[], int n, char tipo[]){

    int i;
    FILE *file;

    ///Video
    if(strcmp(tipo, "video")==0)
    {


        for(i=0; i<n; i++)
        {

            printf("\n%s %s %s %s %s %s %d", listaCorse[i].codice, listaCorse[i].partenza,
                listaCorse[i].destinazione, listaCorse[i].data, listaCorse[i].oraP, listaCorse[i].oraA, listaCorse[i].ritardo);


        }



    }else if(strcmp(tipo, "file")==0)
    {

        ///Step 1: Carica Lista
        if((file=fopen("corse.txt","w"))==NULL){

            printf("\nErrore durante l'aperura del file");
        }

        for(i=0;i<n;i++)
        {

            fprintf(file, "\n%s %s %s %s %s %s %d", listaCorse[i].codice, listaCorse[i].partenza,
                listaCorse[i].destinazione, listaCorse[i].data, listaCorse[i].oraP, listaCorse[i].oraA, listaCorse[i].ritardo);

        }



        fclose(file);
        printf("\n File salvato con successo!");

    }






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

int sostituisci(struct corsa **listaCorse,  int j)
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



///*****************************************
///CERCA

int cerca(struct corsa listaCorse[], int n, char s[], int vet[])
{

        int i,k=0;

        ///RICERCA LINEARE

        for(i=0;i<n;i++)
        {
            if(strstr(listaCorse[i].partenza, s) != NULL)///Puntatore ritornato non è NULL
            {
                ///Così facendo prendiamo il PREFISSO
                if(listaCorse[i].partenza[0]==s[0])
                    vet[k++]=i;


            }


        }






        return k;


}
///*****************************************
///CERCA DICOTOMICA

int cerca2(struct corsa listaCorse[], int n, char s[], int vet[])
{

    int i,k=0;


    ///Indice di mezzo, indice di sinistra, indice di destra
	int m, found=0, l=0, r=n-1;


	while(l<=r && found==0){

		m =(l+r)/2;


		if(strstr(listaCorse[m].partenza, s) != NULL)
        {

            if(listaCorse[m].partenza[0]==s[0])
                {
                    vet[k++]=m;
                    found=1;
                }

        }

        ///Costruiamo la stringa da confrontare
        char s1[20];
        for(i=0;i<strlen(s);i++)
            s1[i]=listaCorse[m].partenza[i];

		if(strcmp(s1, s)<0)
			l=m+1;
		else
			r=m-1;

	}

    ///Cerchiamo le rimanenti chiavi

        int fine=0;
        i=1;
        while(fine==0 && i<n-m)
        {

            if(strcmp(listaCorse[m].partenza, listaCorse[m+i].partenza) == 0 )
            {
                fine=1;
                vet[k++]=m+i;

            }
            i++;

        }

        i=1;
        fine=0;

        while(fine==0 && i<n-m){

            if(strcmp(listaCorse[m].partenza, listaCorse[m-i].partenza) ==0)
            {
                fine=1;
                vet[k++]=m-i;
            }

            i++;
        }




        return k;


}





