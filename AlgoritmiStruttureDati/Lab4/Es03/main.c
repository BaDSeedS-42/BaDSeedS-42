#include <stdio.h>
#include <stdlib.h>

#define filename "hard_test_set.txt"
#define MAX 4

typedef enum {zaffiro,rubino,topazio,smeraldo}pietra;

int controlla(int *sol, int pos);
int calcolaMaxCollana(int *sol, int pos, int N, int max, int val[]);

int main() {

    FILE *file;
    int n,i,N,*sol,val[MAX];

    if((file=fopen(filename,"r"))==NULL){
        printf("\nErrore durante l'aperura del file");
        exit(1);
    }

    //Leggiamo il numero di volte che dobbiamo leggere i dati
    fscanf(file, "%d", &n);

    for(i=0; i <n; i++) {
        fscanf(file, "%d %d %d %d", &val[zaffiro], &val[rubino], &val[topazio], &val[smeraldo]);

        //Calcoliamo la lunghezza della soluzione per caso peggiore
        N = val[zaffiro]+val[rubino]+val[topazio]+val[smeraldo];

        //allocchiamo ad ogni giro il vettore delle soluzioni
        sol = (int*) malloc(N * sizeof(int));

        printf("\nTEST #%d\nzaffiro = %d, rubino = %d, topazio = %d, smeraldo = %d, TOT = %d",i+1, val[zaffiro], val[rubino], val[topazio], val[smeraldo], N);

        //Chiamata ricorsiva
        printf("\nCollana massima di lunghezza %d", calcolaMaxCollana(sol, 0, N, 0, val));



        //Liberiamo il vettore delle soluzioni
        free(sol);
    }
    fclose(file);

    return 0;
}

//************************************
//CONTROLLA

int controlla(int *sol, int pos) {


    int b=1;
    int i;

  for(i=1;i<pos;i++)
  {

      if(sol[i]==zaffiro || sol[i]==topazio)

          //Se non segue nessuna delle due pietre
          if(sol[i+1]!=zaffiro && sol[i+1]!=rubino)
              b=0;

      if(sol[i]==smeraldo || sol[i]==rubino )

          //Se non segue nessuna delle due pietre
          if(sol[i+1]!=smeraldo && sol[i+1]!=topazio)
              b=0;



  }
    //printf("\n%d: b",  b);
   return b;


}

//******************************************************
//CALCOLA MAX.COLLANA

int calcolaMaxCollana(int *sol, int pos, int N, int max, int val[]) {


    if(pos+1 > max && controlla(sol, pos) == 1) {

        max = pos + 1; //la dimensione è cresciuta
    }

   /* if(pos==N) {
        printf("\n%d, %d, %d, %d ", val[zaffiro], val[rubino], val[smeraldo], val[topazio]);

    }*/


    //Inizialmente la collana è lunga 0
    if(pos==0) {
        for(pietra i = zaffiro; i <= smeraldo; i++) { //per ogni pietra
            if(val[i] > 0) { //se ci sono ancora pezzi disponibili di quella pietra

                sol[pos] = i;//carichiamo il vettore delle soluzioni
                val[i]--;//la prendiamo
                if(controlla(sol, pos) == 1)
                    max = calcolaMaxCollana(sol, pos + 1, N, max, val);
                val[i]++; //backtrack, annulliamo la scelta
            }
        }
    }
    //per i casi con lunghezza inferiore a N
    else if(pos < N - 1) {

        if (sol[pos - 1] == zaffiro || sol[pos - 1] == topazio) { //la pietra prima, perchè adesso abbiamo ricorso per pos+1
            if (val[zaffiro] > 0) {
                sol[pos] = zaffiro; //carichiamo il vettore delle soluzionei
                val[zaffiro]--; //prendiamo la soluzione
                if(controlla(sol, pos) == 1) //pruning
                     max = calcolaMaxCollana(sol, pos + 1, N, max, val);//discesa ricorsiva
                val[zaffiro]++;//backtrack
            } else if (val[rubino] > 0) {
                sol[pos] = rubino;//carichiamo il vettore delle soluzionei
                val[rubino]--;//prendiamo la soluzione
                if(controlla(sol, pos) == 1)//pruning
                     max = calcolaMaxCollana(sol, pos + 1, N, max, val);//discesa ricorsiva
                val[rubino]++;//backtrack
            }
        }


        if (sol[pos - 1] == smeraldo || sol[pos - 1] == rubino) {

            if (val[smeraldo] > 0) {

                //Prendiamo lo smeraldo
                sol[pos] = smeraldo;//carichiamo il vettore delle soluzionei
                val[smeraldo]--;//prendiamo la soluzione
                if(controlla(sol, pos) == 1)//pruning
                    max = calcolaMaxCollana(sol, pos + 1, N, max, val);//discesa ricorsiva
                val[smeraldo]++;//backtrack
            } else if (val[topazio] > 0) {
                sol[pos] = topazio;//carichiamo il vettore delle soluzionei
                val[topazio]--;//prendiamo la soluzione
                if(controlla(sol, pos) == 1)//pruning
                    max = calcolaMaxCollana(sol, pos + 1, N, max, val);//discesa ricorsiva
                val[topazio]++;//backtrack
            }

        }



    }else{

        //Prendiamo i RIMANENTI valori che sono rimasti esclusi

            if (val[rubino] > 0) {

                sol[pos] = rubino;
                val[rubino]--;

            } else if (val[topazio] > 0) {

                sol[pos] = topazio;
                val[topazio]--;

            }

    }



    return max;//risalita ricorsiva
}