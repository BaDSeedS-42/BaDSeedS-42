#include <stdio.h>
#include <stdlib.h>


///Per ogni amico
typedef struct {

    int *scelte;///vettore
    int num_scelte;
    char **canzoni; ///vettore di stringhe


}Livello;

int princ_molt(int pos, Livello *val, char **sol, int n, int cnt);


int main()
{

    FILE *file;
    int n;
    int i,j=0, k;
    char s[256];

    char *sol[256];
    int cnt=0, pos=0;

    /// Vettore di struct
    Livello *val;


   ///Step 1: Carica Vettore di Amici
   ///**************************************************************************************************************

    if((file=fopen("brani.txt","r"))==NULL){

        printf("\nErrore durante l'aperura del file");
        exit(1);
    }

    ///Leggiamo il numero di amici
    fscanf(file, "%d", &n);

    ///Dobbiamo allocare dinamicamente la struct(non sappiamo a rigore quanti amici ci sono)
    val= malloc(n*sizeof(Livello));

    if(val==NULL)
        printf("Si è verificato un errore nell'allocazione");

    while(fscanf(file, "%d", &k)==1) ///Per ogni amico
    {

        val[j].canzoni = (char**) malloc(k*sizeof(char*));
        val[j].scelte = (int*) malloc(k*sizeof(int*));



        for(i=0; i<k;i++) ///Per ogni canzone
        {
            fscanf(file, "%s", s);


            ///Allocchiamo la canzone in canzoni (+1 per terminatore di stringa)

            int t = strlen(s)+1;
            val[j].canzoni[i] = (char *) malloc(t*sizeof(char));

            ///Carichiamo le canzoni
            strcpy(val[j].canzoni[i], s);

            ///Carichiamo l'id canzone per amico
            val[j].scelte[i]=i;



            printf("\n %s", val[j].canzoni[i]);
            printf(" %d", val[j].scelte[i]);


        }

        ///Carichiamo il numero di scelte
        val[j].num_scelte=k;


         j++;

    }

    ///Fine caricamento



    ///*****************************************************************************************************************
    ///Step 2: Possibili Playlists

    cnt=princ_molt(pos, val, sol, n, cnt);

    printf("\nLe possibili playlists sono: %d", cnt);

    ///Fare un for con le free per liberare gli amici

    return 0;
}


int princ_molt(int pos, Livello *val, char **sol, int n, int cnt)
{

    //printf("\n\n%s", val[0].canzoni[0]);

    int i;

    if(pos>=n)    ///Terminazione
    {

        for(i=0;i<n;i++)
            printf("\n%s", sol[i]);

        printf("\n");
        return cnt+1;

    }

    for(i=0; i<val[pos].num_scelte; i++)
    {

        sol[pos]= val[pos].canzoni[i];

        cnt = princ_molt(pos+1, val, sol, n, cnt);
    }

    return cnt;
}


