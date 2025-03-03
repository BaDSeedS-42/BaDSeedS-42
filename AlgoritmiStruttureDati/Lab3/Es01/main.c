#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int majority(int *a, int N);
int conta(int cont, int a[], int N, int n, int k);

int main()
{

    int i=0, j, n, vet[MAX];

    ///Step 1: acquisiamo i dati
    while(n!=-1){

        printf("Inserisci un intero(-1 per terminare)-->");
        scanf("%d", &n);
        vet[i]=n;
        i++;
    }

    i--;

    ///Step 2: ricorsione
    int t = majority(&vet, i);

    if(t!=-1)
        printf("\nIl maggioritario e': %d", t);
    else
        printf("\nNESSUN numero inserito è maggioritario");


    return 0;
}

///*******************************************
///Wrapper

int majority(int *a, int n){

    int b=-1, val, cont=0, i;


    ///Per ogni elemento del vettore cerchiamo se è il maggioritario
    for(i=0;i<n;i++)
    {

        val=conta(cont, a, a[i], n, 0);

        if(val > (n/2))
            return a[i];



    }

    return b;

}

///Funzione ricorsiva che conta il numero di apparizioni
int conta(int cont, int a[], int N, int n, int k)
{

    ///Condizione di terminazione(se siamo giunti alla fine del vettore)
    if(k==n)
    {
        return cont;
    }

    ///PARTE RICORSIVA: Richiamiamo ricorsivamente

    if(a[k]==N)
        cont++;
    k++;
    conta(cont, a, N, n, k); ///incrementiamo k ogni volta

}
