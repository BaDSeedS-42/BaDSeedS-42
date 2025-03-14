#include <stdio.h>
#include <stdlib.h>



typedef struct A{

    int inizio;
    int fine;
    int durata;

}Attivita;

void LISprint(Attivita *val, int *P, int i);
void LISDP(Attivita *val, int n);

int main() {

    FILE *file;

    if((file=fopen("att.txt","r"))==NULL){

        printf("\nErrore durante l'aperura del file");
        exit(1);
    }

    int n,i;
    fscanf(file, "%d", &n);

    Attivita *att;
    att=malloc(n*sizeof (Attivita));

    for(i=0;i<n;i++)
    {
        fscanf(file, "%d %d", &att[i].inizio, &att[i].fine);
        att[i].durata= att[i].fine - att[i].inizio;

        printf("\n %d,%d  durata: %d", att[i].inizio, att[i].fine, att[i].durata);
    }

    LISDP(att, n);


    fclose(file);

    free(att);
    return 0;
}


void LISDP(Attivita *val, int n)
{
    int i, j, ris = 1, *L, *P, last=1;

    L = malloc(n * sizeof(int));
    P = malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
    {
        //inizializzazione dei vettori Lenght e Sub-Sequence
        L[i] = 0; P[i] = -1;
        for (j = 0; j<i; j++)
        {
            //Controlliamo che non si scavalchino(anche se così prevede anche il L.I.S.), possono essere uguali poichè nel testo sono insiemi APERTI
            if (val[j].fine <= val[i].inizio && L[i] < L[j] + (val[j].durata)) //questo serve per quei casi in cui occorre scegliere il nuovo valore di Lenght[i], e abbiamo due valori da mettere, scegliamo il più grande
            {
                L[i] =  (val[j].durata) + L[j];//Al posto di 1 ci sarà la durata
                P[i] = j;
            }
        }
        if (ris < L[i] + (val[i].durata)) //se il vecchio valore è più piccolo, allora lo sostituiamo
        {
            ris = L[i] + (val[i].durata);
            last = i;
        }
    }


    printf("\n\nUna soluzione: ");
    LISprint(val, P, last);
    printf("\nValore massimale delle attivita' compatibili: %d\n", ris);



    free(L);
    free(P);

}

//l'indice last ci dice nel vettore P, dove si trova l'elemento che precede l'ultimo e così via
void LISprint(Attivita *val, int *P, int i) {

    if (P[i]==-1) { //terminazione, finchè non siamo nell'unica casella vuota rimasta
        printf("\n%d, %d ", val[i].inizio, val[i].fine);
        return;
    }

    //ricorsivamente, andiamo a stampare ogni elemento che è il precedente
    LISprint(val, P, P[i]);
    printf("\n%d, %d", val[i].inizio, val[i].fine);
}
