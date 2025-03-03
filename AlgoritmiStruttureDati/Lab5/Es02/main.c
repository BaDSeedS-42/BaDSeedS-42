#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct t{

    char colore1;
    char colore2;
    int n1;
    int n2;
    int preso;

}tessera;

typedef struct marcaggio{

    int preso;
    int rot;

}m;

tessera ruotaTessera(tessera t);
void stampaBoard(tessera *board, int k, int nc);
tessera disp(int pos, tessera *val, tessera *sol, m *mark, tessera max[], int  *punteggioMax, int nc, int nr);
tessera check( tessera *sol, int *punteggioMax, tessera vetMax[], int nc, int nr);


int main() {


    FILE *file;
    FILE *file1;
    int nr, nc, i;
    int nt;
    tessera *tessere;
    tessera *board;
    m *mark;
    int k=0;

    //*******************************************************************************
    //Step 1: carichiamo il vettore di tessere(o delle SCELTE)


    if((file1=fopen("tiles.txt","r"))==NULL){
        printf("\nErrore durante l'aperura del file");
        exit(1);
    }

    if(fscanf(file1, "%d", &nt)==1) {

       tessere = (tessera *)malloc((nt)*sizeof (tessera));


        for(i=0; i<nt; i++)
        {
            fscanf(file1, "\n%c %d %c %d", &tessere[i].colore1, &tessere[i].n1, &tessere[i].colore2, &tessere[i].n2);
            //printf("\n%c %d %c %d", tessere[i].colore1, tessere[i].n1, tessere[i].colore2, tessere[i].n2);

        }

    }else{
        printf("\nSi è verificato un errore durante l'apertura del file 'tiles.txt' !");
    }

    fclose(file1);




    //*******************************************************************************
    //Step 2: carichiamo la tabella iniziale
    if((file=fopen("board.txt","r"))==NULL){

        printf("\nErrore durante l'aperura del file");
        exit(1);
    }
    if(fscanf(file, "%d %d", &nr, &nc)==2) {

        board = (tessera *)malloc((nr*nc)*sizeof (tessera));
        mark = (m *)malloc((nr*nc)*sizeof (m));

        //inizializziamo mark
        for(i=0;i< (nr*nc); i++) {
            mark[i].preso = 0;
            mark[i].rot=0;
        }

        int indice;
        int rotazione;

        //Carichiamo i due vettori

        while(fscanf(file, "%d/%d", &indice, &rotazione)==2)
        {

            if(indice !=-1)
            {
                //carichiamo la board dal vettore di tessere
                board[k].colore1 = tessere[indice].colore1;
                board[k].colore2 = tessere[indice].colore2;
                board[k].n1 = tessere[indice].n1;
                board[k].n2 = tessere[indice].n2;
                board[k].preso=1;

               mark[indice].preso=1;
               mark[indice].rot=0;

                //ruotiamo la tessere oppure no
                if(rotazione==1){
                //ruota tessera
                    board[k]= ruotaTessera(tessere[indice]);
                    board[k].preso=1;
                    mark[indice].rot=1;
                }
                //altrimenti non succede niente, la carichiamo così


            }else{

                //carichiamo la board dal vettore di tessere

                board[k].n1 = -1;
                board[k].n2 = -1;


            }

            k++;


        }




    }else{
        printf("\nSi è verificato un errore durante l'apertura del file 'board.txt' !");
    }



    fclose(file);

    printf("\nLa scacchiera iniziale e': ");
    stampaBoard(board, k, nc);


    int pos=0;
    tessera *vetMax= malloc(k*sizeof(tessera));

    //Inizializziamo il vettoreMax
    for(i=0;i<k;i++)
    {
        vetMax[i].n1=0;
        vetMax[i].n2=0;
        vetMax[i].colore2='/';
        vetMax[i].colore1='/';

    }

    int punteggioMax;



    *vetMax = disp(pos, tessere, board, mark, vetMax, &punteggioMax, nc, nr);

    printf("\nLa scacchiera finale è: ");
       stampaBoard(vetMax, k, nc);

    free(vetMax);
    free(board);
    free(tessere);


    return 0;
}

//********************************************************************
//FUNZIONE RICORSIVA
tessera disp(int pos, tessera *val, tessera *sol, m *mark, tessera max[], int *punteggioMax, int nc, int nr)
{
    int n=nr*nc;
    int i;


    if(pos>=n){
        tessera *t;
        t=malloc(n*sizeof (tessera));
        *t=check(sol, punteggioMax, max, nc, nr);

        if(t[0].n1!=-1) { //controlliamo se la soluzione è valida

            *max = check(sol, punteggioMax, max, nc, nr);


       }
        free(t);
        return *sol;

    }

    //cicliamo sulle scelte
    for(i=0;i<n;i++)
    {



       if(mark[i].preso == 0 ) //tessera non presa e casella vuota
        {


            if(sol[pos].preso!=1) {

                mark[i].preso = 1;
                mark[i].rot = 0;
                //prendiamo l'elemento
                sol[pos] = val[i];

                *max = disp(pos + 1, val, sol, mark, max, punteggioMax, nc, nr);

                //Backtrack sulle rotazioni
                mark[i].preso = 1;
                mark[i].rot = 1;
                sol[pos] = ruotaTessera(val[i]);

                disp(pos + 1, val, sol, mark, max, punteggioMax, nc, nr);


                //Backtrack
                mark[i].preso = 0;

            }else{

                *max = disp(pos + 1, val, sol, mark, max, punteggioMax, nc, nr);
                return *max;

            }



        }





    }


    return *max;

}


//**********************************************************
//FUNZIONE DI CHECK
tessera check( tessera *sol, int *punteggioMax, tessera vetMax[], int nc, int nr) //ritorniamo
{


    int i,j,k;
    int n= nc*nr;
    int punteggioR=0, punteggioC=0;
    int count;
    int b;



    //controlliamo per riga
    for(i=0;i<=nr;i++)//per ogni riga
    {
        b=1;
        count=0;
        while(count<nc-1)
        {
            if(sol[count+(nr-1)*i].colore1==sol[count+1+(nr-1)*i].colore1)
                 punteggioR+=sol[count+(nr-1)*i].n1;
            else
                b=0;

            count++;

        }
        if(b!=0)
          punteggioR+=sol[count+(nr-1)*i].n1;
    }


    //Controlliamo le colonne
    int c;
    for(i=0;i<nc;i++)//per ogni colonna
    {
        count=0;
        c=1;
        while(count<nr-1)
        {
            if(sol[(count*nr)+i].colore2 == sol[((count+1)*nr)+i].colore2)
            {

                punteggioC+= sol[(count*nr)+i].n2;

            }

            else{
                c=0;
            }

            count++;
        }

        if(c!=0)
             punteggioC += sol[(count*nr)+i].n2;

        if(c==0)
            punteggioC=0;


    }


    if((c==0) && (b==0))
    {
        tessera *t;
        t=malloc(n*sizeof (tessera));

        t[0].n1=-1;


        return *t;

    }
    //La soluzione è migliorata?
    if(*punteggioMax < (punteggioC+punteggioR))
    {

        *punteggioMax = punteggioC + punteggioR;

        for(i=0;i<n;i++)
            vetMax[i] = sol[i];

        return *vetMax;

    }else{ //non è migliorata

        tessera *t;
        t=malloc(n*sizeof (tessera));

        t[0].n1=-1;


        return *t;

    }


}



//************************************************
//STAMPA BOARD
void stampaBoard(tessera *board, int k, int nc)
{
    int cont=0;
    int i;

    printf("\n");

    //Stampiamo la Board
    for(i=0;i<k;i++)
    {
        if(board[i].n2!=-1) {
            printf("\t %c %d %c %d", board[i].colore1, board[i].n1, board[i].colore2, board[i].n2);

        }else
        {

            printf("\t-1 -1 -1 -1");
        }
        cont++;

        if (cont == nc) {
            printf("\n");
            cont=0;
        }


    }




}

//**************************************************
//RUOTA TESSERA
tessera ruotaTessera(tessera t)
{

    tessera tval;

    tval.colore1=t.colore2;
    tval.colore2=t.colore1;
    tval.n1=t.n2;
    tval.n2=t.n1;

    return tval;


}