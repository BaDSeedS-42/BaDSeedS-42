#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 30


typedef struct E {

    char nome[MAX];
    int tipo;
    int dirI;
    int dirU;
    int precedente;
    int successivo;
    float punteggio;
    int difficolta;
    float spec; //è un coefficiente in nase a cui ordinerememo gli elementi

}elemento;

typedef struct D{

    int nElementi;
    int vettEl[5];
    float punteggio;


}diagonale;

void stampa(elemento *elementi, int n);
elemento *ordinaPerFrontale(elemento *elementi, int n);
int greedy(elemento *elementi, int n, int resD, float *punteggio);
int cercaFrontale(elemento *elementi, int n);
elemento *ordinaPerSpec(elemento *elementi, int inizio, int fine);

int main() {


    FILE *file;
    int i,n, DD, DP, resOld;
    float punteggio=0.0;

    elemento *elementi;

    //Step 1: carichiamo gli elementi in un vettore di struct
    //Apriamo il file
    if((file=fopen("elementi.txt","r"))==NULL){
        printf("\nErrore durante l'aperura del file");
        exit(1);
    }
    //leggiamo il numero di elementi
    fscanf(file,"%d", &n);

    elementi=malloc(n*sizeof(elemento));

    for(i=0;i<n;i++)
    {

        fscanf(file,"%s %d %d %d %d %d %f %d", elementi[i].nome, &elementi[i].tipo, &elementi[i].dirI, &elementi[i].dirU, &elementi[i].precedente, &elementi[i].successivo, &elementi[i].punteggio, &elementi[i].difficolta);
        elementi[i].spec= (elementi[i].punteggio/elementi[i].difficolta);

    }
    fclose(file);

    //Ordiniamo per appetibilità dell'elemento(Coefficiente ed entrata frontale)
    elementi = ordinaPerFrontale(elementi, n);
    int inizio= cercaFrontale(elementi, n);

    elementi= ordinaPerSpec(elementi, 0, inizio);
    elementi= ordinaPerSpec(elementi, inizio, n);


    printf("\n\n");
    stampa(elementi, n);

    printf("\nInserisci la difficolta' massima per la diagonale-->");
    scanf("%d", &DD);

    printf("\nInserisci la difficolta' massima per il programma-->");
    scanf("%d", &DP);


    //*******************************************************************************************************************
    //Calcoliamo il residuo rimanente per ogni diagonale
    int resD = greedy(elementi, n, DD, &punteggio);
    int diffConsumata = DD - resD;



     resOld = (DP - diffConsumata) / 2;

    printf("\n");

    if(resOld>DD)
        resD = greedy(elementi, n, DD, &punteggio);
    else
        resD = greedy(elementi, n, resOld, &punteggio);

    diffConsumata = abs((DP - diffConsumata) / 2 - resD);

    printf("\n");

    if((resOld + (resOld - diffConsumata))>DD)
        resD = greedy(elementi, n, DD, &punteggio);
    else
        resD = greedy(elementi, n, abs(resOld + (resOld - diffConsumata)), &punteggio);

    //***************************************************************************************************************

    printf("\nIl punteggio totale del programma e': %.2f", punteggio);



    return 0;
}


int cercaFrontale(elemento *elementi, int n)
{

    int i;

    for(i=0;i<n;i++)
    {


            if(elementi[i].dirI==0)
            {
                return i;
            }


    }


}

//COSTRUZIONE DIAGONALE
int greedy(elemento *elementi, int n, int resD, float *punteggio)
{
    int i;

    diagonale *diag;
    diag= malloc(sizeof (diagonale));

    diag->nElementi=0;
    diag->punteggio=0;


  for(i=0; i<n  ; i++)// se il singolo elemento supera la difficolta
    {


       //********************************************
      //È soluzione tale elemento?
     //*******************************************
            if(resD >= elementi[i].difficolta)
            {
         //Siamo il primo elemento della diagonale?
         if (diag->nElementi == 0 && elementi[i].dirI == 1 && elementi[i].precedente == 0 && elementi[i].successivo == 0)//Siamo il primo elemento della diagonale
         {


             diag->vettEl[diag->nElementi] = i;
             diag->nElementi++;
             *punteggio+=elementi[i].punteggio;
             diag->punteggio += elementi[i].punteggio;
             resD -= elementi[i].difficolta;
             printf("\nelementi[%d]: %s ", i, elementi[i].nome);


         }
         if (diag->nElementi > 0 && resD>= elementi[i].difficolta) {//Non siamo il primo elemento, oppure siamo l'ultimo(BONUS)


             //sono in sequenza?
             if (elementi[diag->vettEl[diag->nElementi - 1]].dirU == elementi[i].dirI) {

                //Posso ancora inserire elementi dopo?
                 if(elementi[i].successivo==1)
                 {
                     diag->vettEl[diag->nElementi] = i;
                     diag->nElementi++;
                     *punteggio+=elementi[i].punteggio;
                     diag->punteggio += elementi[i].punteggio;
                     resD -= elementi[i].difficolta;
                     printf("\nelementi[%d]: %s  ", i, elementi[i].nome);

                     break;

                 }

                 if (diag->nElementi < 5) {


                     diag->vettEl[diag->nElementi] = i;
                     diag->nElementi++;
                     *punteggio+=elementi[i].punteggio;
                     diag->punteggio += elementi[i].punteggio;
                     resD -= elementi[i].difficolta;
                     printf("\nelementi[%d]: %s  ", i, elementi[i].nome);


                 }


             }



         }
         }






    }

    //Controlliamo se l'ultimo elemento inserito ha difficolta >=8
   if( elementi[diag->vettEl[diag->nElementi - 1]].difficolta>=8) {
       diag->punteggio = (diag->punteggio) * (1.5);
       printf("\nPunteggio Diagonale (BONUS): %.2f", diag->punteggio );

   }else
       printf("\nPunteggio Diagonale: %.2f", diag->punteggio );




        return resD;

}
//********************************************************************
//ORDINA PER COEFFICIENTE
elemento *ordinaPerSpec(elemento *elementi, int inizio, int fine){

    int i,j;
    elemento temp;


    for(i=inizio;i<fine;i++)
    {
        for(j=inizio;j<fine-1;j++)
        {

            if( elementi[j].spec < elementi[j+1].spec) //&& elementi[j].dirI < elementi[j+1].dirI
            {
                temp = elementi[j];
                elementi[j]=elementi[j+1];
                elementi[j+1]=temp;


            }

        }


    }



    return elementi;



}

//****************************************************************
//ORDINA PER ORDINE DECRESCENTE IN BASE AL COEFFICIENTE
elemento *ordinaPerFrontale(elemento *elementi, int n)
{

    int i,j;
    elemento temp;


    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {

            if( elementi[j].dirI < elementi[j+1].dirI) //&& elementi[j].dirI < elementi[j+1].dirI
            {
                temp = elementi[j];
                elementi[j]=elementi[j+1];
                elementi[j+1]=temp;


            }

        }


    }



    return elementi;


}



//************************
//STAMPA
void stampa(elemento *elementi, int n){


    int i;
    for(i=0;i<n;i++)
    {
        printf("\n%s %d %d %d %d %d %.1f %d %.2f", elementi[i].nome, elementi[i].tipo, elementi[i].dirI, elementi[i].dirU, elementi[i].precedente, elementi[i].successivo, elementi[i].punteggio, elementi[i].difficolta, elementi[i].spec);
    }


}