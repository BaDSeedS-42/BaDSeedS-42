#include <stdio.h>

typedef struct arco
{
    int u;
    int v;

};

int powerset(int *val, int k, int *sol, struct arco *archi, int E);
int powerset_r(int *val, int k, int *sol, int n, int pos, int start, struct arco *archi, int E);
int Esiste(int *val, int n, int N);
int controllo(int *sol, int n, struct arco *archi, int E);



int main() {

    int *sol, *val, E, N,i,k, t=0;
    FILE *file;

    struct arco *archi;
    //STEP 1: carichiamo il vettore val e la struct
    if((file=fopen("grafo.txt","r"))==NULL){

        printf("\nErrore durante l'aperura del file");
        exit(1);
    }
    //Leggiamo il numero di vertici e archi
    fscanf(file, "%d %d", &N, &E);

    //Allochiamo i vari vettori
    val=malloc(N*sizeof(int));
    sol=malloc(N*sizeof(int));
    archi=malloc(E*sizeof(struct arco));
    k=N;

    //Per ogni arco, carichiamo gli archi
    for(i=0;i<E; i++)
    {
        fscanf(file, "%d %d", &archi[i].u, &archi[i].v);

        //Carichiamo il vettore val con elementi distinti
        if(Esiste(val, archi[i].u, N)==0)
        {
            val[t]=archi[i].u;

            t++;


        }
        if(Esiste(val, archi[i].v, N)==0)
        {
            val[t]=archi[i].v;

            t++;

        }



    }

    //Facciamo il powerset
    powerset(val, k, sol,archi, E);

    free(val);
    free(sol);
    free(archi);

    return 0;
}

/**********************
 * ESISTE
 * ****************************/

int Esiste(int *val, int n, int N)
{

    int b=0,i;

    for(i=0;i<N;i++)
    {

        if(val[i]==n)
            b=1;

    }

    return b;


}

/**********************
 *  CONTROLLA se è un vertex cover il sudetto insieme
 * ****************************/
int controllo(int *sol, int n, struct arco *archi, int E)
{
    int b=1, i;
    //Per ogni arco, controlliamo se almeno uno dei vertici è presente nel vettore sol

        //per ogni arco
        for(i=0; i<E;i++)
        {
            //Succede che un arco non contiene nessuno dei vertici del sottoinsieme
            if(Esiste(sol, archi[i].u,n)==0 && Esiste(sol, archi[i].v,n)==0)
                b=0;

        }



    return b;
}



/**Wrapper**/
int powerset(int *val, int k, int *sol, struct arco *archi, int E){

 int count=0;
 int n;
 count++;

 for(n=1; n<=k; n++)
 {
     count+=powerset_r(val, k, sol, n, 0, 0, archi, E);
 }

 return count;
}


int powerset_r(int *val, int k, int *sol, int n, int pos, int start, struct arco *archi, int E){


    int count=0;
    int i;


    if(pos>=n)
    {

        ///Bel controllo qui
        if(controllo(sol, n, archi, E)==1)
        {
            printf("(");
            for (i = 0; i < n; i++) {
                if(i!=0)
                    printf(",");
                printf("%d", sol[i]);
            }

            printf(")\n");
            return 1;
        }
        return 0;

    }

    for(i=start; i<k; i++)
    {
        sol[pos]=val[i];
        count+= powerset_r(val, k, sol, n, pos+1, i+1, archi, E);

    }




}
