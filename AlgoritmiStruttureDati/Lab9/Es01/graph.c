//
// Created by Utente on 15/01/2022.
//

#include "graph.h"

#define filename "grafo2.txt"



struct graph {
    int V;
    int E;
    int **madj;
    ST tabellaSimboli;
};

struct node { int v; int wt; link next; } ;

struct graphL{

    int V;
    int E;
    link *ladj;
    ST pTabellaSimboli;
    link z;//sentinella
} ;

typedef struct v{

    char nome[MAX] ;
    int valArco;

}V;

static void removeE(GraphL GL, arco e);


//*******************************************
//CARICHIAMO IL GRAFO
void GRAPHload() {

    int V, i, id1, id2, wt,k=0;
    char label1[MAX], label2[MAX];
    Graph G;
    GraphL GL;


    FILE *file;
    if((file=fopen(filename,"r"))==NULL){
        printf("\nErrore durante l'aperura del file");
        exit(1);
    }
    G = GRAPHinit();//occorre inizializzare il Grafo
    caricaST(G->tabellaSimboli, file);


    //  ordinaST(G->tabellaSimboli);

    //Otteniamo il numero di vertici
      V= STsize(G->tabellaSimboli);
      G->V = V;
      G->madj = MATRIXinit(V, V, 0);



      while(fscanf(file,"%s %s  %d", label1, label2, &wt) == 3) {

          //Cerchiamo gli indici dei vertici nella tabella di simboli
          Item val1=STsearch(G->tabellaSimboli, label1);
          Item val2 =STsearch(G->tabellaSimboli, label2);

          id1=val1.indice;
          id2=val2.indice;



          if (id1 >= 0 && id2 >=0)
              GRAPHinsertE(G, id1, id2, wt);
      }



      fclose(file);

      int j;

      printf("\n");
      for(i=0;i<V;i++)
      {
          for(j=0;j<V;j++)
          {

              printf(" %d", G->madj[i][j]);

          }

          printf("\n");

      }

      //Generiamo la lista
      GL= generaLista(G, G->tabellaSimboli);



 //   liberaGRAPH(G);
   //  liberaGRAPHL(GL);

}




void GRAPHinsertE(Graph G, int id1, int id2, int wt) {
    insertE(G, EDGEcreate(id1, id2, wt));
}

static arco EDGEcreate(int v, int w, int wt) {
    arco e;
    e.v = v; e.w = w; e.wt = wt;
    return e;
}

static void insertE(Graph G, arco e) {
    int v = e.v, w = e.w, wt =e.wt;
    if (G->madj[v][w] == 0)
        G->E++;//incrementiamo il numero di archi
    G->madj[v][w] = wt; //Non si crea una simmetria nella matrice, poichè orientata
   // G->madj[w][v] = wt;
}
static void insertEL(GraphL G, arco e) {

    int v = e.v, w = e.w, wt = e.wt;

    //andiamo nella lista delle adiacenze, creiamo un nuovo nodo che inseriamo in testa, che contiene w
    // G->ladj[v] = NEW(w, wt, G->ladj[v]);
    G->ladj[v] = NEW(w, wt, G->ladj[v]);//solo PER GRAFI ORIENTATI //inseriamo w che sarà così connesso a v

    //ATTEZIONE: si possono inserire vertici uguali, in tal caso, stiamo facendo un CAPPIO

    G->E++;
}
static void insertEL2(GraphL G, arco e) {

    int v = e.v, w = e.w, wt = e.wt;

    //andiamo nella lista delle adiacenze, creiamo un nuovo nodo che inseriamo in testa, che contiene w
    G->ladj[v] = NEW(w, wt, G->ladj[v]);//inseriamo w che sarà così connesso a v
    G->ladj[w] = NEW(v, wt, G->ladj[w]);//solo PER GRAFI NON ORIENTATI

    //ATTEZIONE: si possono inserire vertici uguali, in tal caso, stiamo facendo un CAPPIO

    G->E++;
}


//Crea un grafo non orientato a partire da un grafo orientato
GraphL listaAdNO(GraphL GL)
{
    int i=0;

    GraphL GNO;
    GNO = GRAPHinitL(GL->V);//occorre inizializzare il Grafo

    GNO->pTabellaSimboli= GL->pTabellaSimboli;

    //Stampiamo la lista delle adiacenze
    link x;
    for(i=0;i<GL->V;i++) {

        Item vertice =STsearchByIndex(GL->pTabellaSimboli, i);

        for (x = GL->ladj[i]; x != GL->z; x = x->next) {


            Item vertice2 = STsearchByIndex(GL->pTabellaSimboli, x->v);

            insertEL2(GNO, EDGEcreate(vertice.indice, vertice2.indice, x->wt));



        }
    }

    //Stampiamo la lista delle adiacenze


 /*  for(i=0;i<GNO->V;i++) {

        Item vertice =STsearchByIndex(GNO->pTabellaSimboli, i);

        printf("\n %s:  ", vertice.nome);
        for (x = GNO->ladj[i]; x != GNO->z; x = x->next) {


            Item vertice2 = STsearchByIndex(GNO->pTabellaSimboli, x->v);
            printf(" %s", vertice2.nome);
            printf(" %d", x->wt);


        }
    }
    printf("\nLista creata con successo!!");*/



 return GNO;

}




//******************************************************
//INIZIALIZZAZIONE MATRICE DELLE ADIACENZE
static int **MATRIXinit(int r, int c, int val) {
    int i, j;
    int **t = malloc(r * sizeof(int *));
    for (i=0; i < r; i++)
        t[i] = malloc(c * sizeof(int));
    for (i=0; i < r; i++)
        for (j=0; j < c; j++)
            t[i][j] = val;
    return t;
}

//****************************************************
//INIZIALIZZAZIONE DEL GRAFO
Graph GRAPHinit() {
    Graph G = malloc(sizeof *G); //G->V = V;
    G->E = 0;

    G->tabellaSimboli= STinit(MAX);
    return G;
}



//Free del GRAFO
void liberaGRAPH(Graph G) {
    int i;
    for (i=0; i<G->V; i++)
        free(G->madj[i]);
    free(G->madj);
    liberaST(G->tabellaSimboli);
    free(G);
}


void liberaGRAPHL(GraphL G) {
    int v;
    link t, next;

    for (v=0; v < G->V; v++) //per ogni vertice
        for (t=G->ladj[v]; t != G->z; t = next) { //cancelliamo un elemento corrente alla volta
            next = t->next; //dobbiamo ricordarci il prossimo così possiamo freearlo
            free(t);
        }

    liberaST(G->pTabellaSimboli);
    free(G->ladj); free(G->z); free(G);
}



//Inizializzazione del grafo
GraphL GRAPHinitL(int V) {

    int v;
    GraphL G = malloc(sizeof *G);
    G->V = V;//numero di vertici
    G->E = 0;//il numero di archi non è noto
    G->z = NEW(-1, -1, NULL);//sentinella
    G->ladj = malloc(G->V*sizeof(link));//allocchiamo la lista delle adiacenze, vettore con puntatori a nodi

    for (v = 0; v < G->V; v++)
        G->ladj[v] = G->z; //inizializzazione a nodi sentinella, per ogni casella di ladj


    //G->pTabellaSimboli = STinit(V);
    return G;

}


//Generiamo un nuovo nodo
static link NEW(int v, int wt, link next) {

    link x = malloc(sizeof *x);

    //Piazziamo in testa perchè O(1)
    x->v = v;
    x->wt = wt;
    x->next = next;

    return x;
}

//***************************************************
//GENERA LISTA DA MATRICE DELLE ADIACENZE
GraphL generaLista(Graph G, ST st)
{

    GraphL GL;
    int V= STsize(st);
    int i, j, k, t;
    arco *vetArchi;

    //Inizializziamo il grafo
    GL= GRAPHinitL(V);
    GL->pTabellaSimboli=G->tabellaSimboli;



    //Ogni casella di adj(che sarà all'indice del vertice, quindi indice riga della matrice) punterà ad una lista

    for(i=0;i<V;i++)
    {

        for(j=0;j<V;j++)
        {
            //Per ogni riga della matrice, creiamo un arco e lo inseriamo nella lista ladj[i] con v=i e w=j

            if(G->madj[i][j]!=0) {
                arco a= EDGEcreate(i, j, G->madj[i][j]);

                insertEL(GL, a); //inseriamo l'arco nella posizione ladj[i]

            }


        }

    }
    //Allochiamo il vettore di archi
    vetArchi= malloc(G->E*sizeof(arco));


    //Stampiamo la lista delle adiacenze
    k=0;
    link x;
    for(i=0;i<V;i++) {

        Item vertice =STsearchByIndex(st, i);

        printf("\n %s:  ", vertice.nome);
        for (x = GL->ladj[i]; x != GL->z; x = x->next) {


            Item vertice2 = STsearchByIndex(st, x->v);
            printf(" %s", vertice2.nome);
            printf(" %d", x->wt);
            vetArchi[k]= EDGEcreate(vertice.indice, vertice2.indice, x->wt);
            printf("\n%d %d %d", vetArchi[k].v, vetArchi[k].w, vetArchi[k].wt);

            k++;



        }
    }
    printf("\nLista creata con successo!!");



    arco *sol;

    sol= malloc(GL->E*sizeof (arco));


    if(esisteCiclo(GL,0)==0)
    {
        printf("\nIl grafo non presenta cicli!");
    }else
        printf("\nIl grafo presenta cicli!");

    powerset(vetArchi, GL, sol);


    //listaAdNO(GL);

    return GL;

}

arco *caricaVetArchi(GraphL GL){

    arco *vetArchi;

    vetArchi= malloc(GL->E*sizeof(arco));

    int k,i;

    k=0;
    link x;
    for(i=0;i<GL->V;i++) {

        Item vertice =STsearchByIndex(GL->pTabellaSimboli, i);


        for (x = GL->ladj[i]; x != GL->z; x = x->next) {


            Item vertice2 = STsearchByIndex(GL->pTabellaSimboli, x->v);

            vetArchi[k]= EDGEcreate(vertice.indice, vertice2.indice, x->wt);


            k++;


        }
    }



    return vetArchi;
}


int esisteCiclo(GraphL G, int id) {


    int v, time=0, *pre, *post, *st, B=0;

    pre=malloc(G->V * sizeof(int));//allochiamo i vettori
    post=malloc(G->V * sizeof(int));//allochiamo i vettori
    st = malloc(G->V * sizeof(int));//allochiamo i vettori

    for (v=0;v<G->V;v++) {

        pre[v]=-1; post[v]=-1; st[v]=-1; //inizializziamo i vettori

    }
    dfsR(G, EDGEcreate(id,id,0), &time, pre, post, st, &B); //opera a partire da un arco che parte da un vertice, che viene creato con la funzione EDGEcreate

    //Abbiamo visitato in profondità, tutti i vertici che sono raggiungibili dal vertice di partenza

    //Possono esserci degli indici bianchi(non ancora visitati)
    for (v=0; v < G->V; v++)
        if (pre[v]==-1)
            dfsR(G,EDGEcreate(v,v,0),&time,pre,post,st, &B); //se così, facciamo partire un'altra discesa ricorsiva

   // if(B!=0)
     //   printf("\nIl grafo presenta almeno un ciclo!");
    //else
      //  printf("\nIl grafo NON presenta cicli(DAG)");
      return B;

}

void dfsR(GraphL G, arco e, int *time, int *pre, int *post, int *st, int *B){

    link t;
    int v, w = e.w; //consideriamo l'arco fittizio
    arco x;

   // if (e.v != e.w) //se l'arco non è fittizio, ovvero i due vertici non sono uguali, quindi è un arco che abbiamo percorso, quindi di tipo T
       // printf("(%s, %s): T \n",STsearchByIndex(G->pTabellaSimboli, e.v).nome,STsearchByIndex(G->pTabellaSimboli, e.w).nome);

    st[e.w] = e.v;//registriamo il padre
    pre[w] = (*time)++; //abbiamo scoperto il nodo w, e lo ettichettiamo con il tempo
    for (t = G->ladj[w]; t != G->z; t = t->next)//esaminiamo la lista delle adiacenze(CONDIZIONE DI TERMINAZIONE IMPLICITA: QUANDO FINISCE IL FOR)
        if (pre[t->v] == -1) //è un nodo ancora da visitare?

            dfsR(G, EDGEcreate(w, t->v,0), time, pre, post, st, B);//discesa ricorsivamente attraverso l'arco che da w va a t->v

        else {//questo nodo è già stato scoperto

            v = t->v;//indice che corrisponde a t->v
            x = EDGEcreate(w, v,0);



            ///GRAFI DI TIPO ORIENTATO
            if (post[v] == -1) {//(BACKWARD)il vertice a cui sta ritornando, ha un post che vale -1? allora quel vertice è un antenato del vertice corrente
                //printf("(%s, %s): B\n", STsearchByIndex(G->pTabellaSimboli, x.v).nome,
                      // STsearchByIndex(G->pTabellaSimboli, x.w).nome);
                *B=1;

            }

        }


    //Bolliamo il vertice come nero, e incrementiamo il contatore di tempo time
    post[w] = (*time)++;


}





//***************************************************************************************************************************************************

//Vettore delle scelte val
void powerset(arco *val, GraphL GL, arco *sol)
{
    int n,i;

    int max=0;
    int N=0;
    arco *maxSol;
    maxSol=malloc(GL->E * sizeof(arco));
    printf("\n%d", GL->E);


    for(n=0;n<GL->E;n++) {

        comb(val, GL, sol, n, 0, 0, &max, maxSol, &N);

    }
    printf("\nLa soluzione a peso maggiore e' quella in cui si eliminano i seguenti archi: ");

    for(i=0;i<N;i++)
    {
        printf("\n%d %d %d", maxSol[i].v, maxSol[i].w, maxSol[i].wt);
        removeE(GL, EDGEcreate(maxSol[i].v, maxSol[i].w, maxSol[i].wt));

    }


    printf("\n PESO TOTALE: %d", max);
    DAGrts(GL);



}

//*********************************************************
//COMBINAZIONI SEMPLICI
void comb(arco *val, GraphL GL, arco *sol, int n, int pos, int start, int *max, arco *maxSol, int *N)
{

    int i;
    if(pos>=n)//È stato ragiunto il numero prefissato di elementi nell'insieme attuale
    {

        int pesoCorrente=0;
        printf("\n");
        //Terminazione, abbiamo gli archi da eliminare
        for(i=0;i<n;i++)
        {
            //Eliminiamo gli archi
            arco e= EDGEcreate(sol[i].v, sol[i].w, sol[i].wt);

            pesoCorrente+=sol[i].wt;

            printf("\n%d %d %d", sol[i].v, sol[i].w, sol[i].wt);
            removeE(GL,e);

        }

        ////NON Presenta cicli? e Non abbiamo sconesso il grafo? (ABBIAMO RIMOSSO TROPPI ARCHI DAL GRAFO DI PARTENZA)
        ///DISCLAIMER: anche se si disconettesse il grafo originale, potrebbe essere un DAG
        ///Assumiamo che l'esercizio non vuole che noi disconettiamo il grafo, anche se non è sbagliato
        ///Potevamo andare a cerca gli SCC con Kosaraju, trovare i cicli negli SCC ed elimarli, ma il problema si sarebbe ripresentato, poichè nel segliere
        //quali archi eliminare avremo di nuovo dovuto effettuare la scelta: disconnettere il grafo oppure no? [Anche se tale soluzione sarebbe stata più efficiente]
        if( esisteCiclo(GL, 0)==0 && connesso(listaAdNO(GL))==1)
        {

            printf("\nIl grafo creato e' un DAG!");

            //La soluzione è migliorata?
          //  printf("\n max:%d pesoCorrente: %d", *max, pesoCorrente);
            if(pesoCorrente>*max)
            {
                *max=pesoCorrente;
                *N=n;
                printf("\nLa soluzione e' migliorata!");
                printf("\n%d ", *N);
               for(i=0;i<*N;i++)
                {
                    maxSol[i]=sol[i];
                   // maxSol[i]->v=sol[i].v;
                   // maxSol[i]->wt=sol[i].wt;

                }

            }
        }
        //Reinseriamo gli archi nel grafo
        for(i=0; i<n;i++)
        {
            arco e=EDGEcreate(sol[i].v, sol[i].w, sol[i].wt);
            insertEL(GL,e);
        }
        printf("\n");

    }

    //Per tutti gli elementi da start in poi
    for(i=start; i<GL->E;i++)
    {

        sol[pos] = val[i];
        comb(val, GL, sol, n, pos+1, i+1, max, maxSol, N);


    }




}
//*******************************************
//wrapper CONNESSO?
int connesso(GraphL G) {

    int v, id = 0, *cc;
    cc = malloc(G->V * sizeof(int));//allocchiamo il vettore cc che serve per registrare a quali componenti connesse appartengono i vertici
    for (v = 0; v < G->V; v++) cc[v] = -1;

    for (v = 0; v < G->V; v++) //partiamo dal primo vertice e proeguiamo
        if (cc[v] == -1) //sono bianchi
            dfsRcc(G, v, id++, cc);//lanciamo visite in profondità, finchè non abbiamo visitato tutti i vertici in profondità

    //stampiamo le componenti connesse
   // printf("Connected component(s) \n");
    for (v = 0; v < G->V-1; v++) {
       // printf("node %s in cc %d\n", STsearchByIndex(G->pTabellaSimboli, v), cc[v]);

        if(cc[v+1]!=cc[v])
            return 0;

    }

    return 1;
   // return id;


}


//******************************************
//Funzione ricorsiva
void dfsRcc(GraphL G, int v, int id, int *cc) {

    //id=0 inizialmente, serve per marcare il vertice da cui partiamo
    link t;
    cc[v] = id;
    for (t = G->ladj[v]; t != G->z; t = t->next)//esploriamo la lista delle adiacenze
        if (cc[t->v] == -1)
            dfsRcc(G, t->v, id,
                   cc); //visita in profondità ogni qualvolta troviamo un nodo che non è stato ancora visitato



}

    static void removeE(GraphL GL, arco e) {
    int v = e.v, w = e.w; link x;

    if (GL->ladj[v]->v == w) {
        GL->ladj[v] = GL->ladj[v]->next;
        GL->E--;
    }
    else
        for (x = GL->ladj[v]; x != GL->z; x = x->next)
            if (x->next->v == w) {
                x->next = x->next->next;
                GL->E--;
            }

}


//*************************************************
//ORDINAMENTO TOPOLOGICO DI UN DAG
void TSdfsR(GraphL D, int v, int *ts, int *pre, int *time) {
    link t; pre[v] = 0;
    for (t = D->ladj[v]; t != D->z; t = t->next)
        if (pre[t->v] == -1)
            TSdfsR(D, t->v, ts, pre, time);
    ts[(*time)++] = v;
}


void DAGrts(GraphL D) {


    int v, time = 0, *pre, *ts;
    /* allocazione di pre e ts */
    pre= malloc(D->V*sizeof(int));
    ts= malloc(D->V*sizeof(int));

    for (v=0; v < D->V; v++)
    {
        pre[v] = -1;
        ts[v] = -1;
    }
    for (v=0; v < D->V; v++)
        if (pre[v]== -1) TSdfsR(D, v, ts, pre, &time);
   // printf("\nDAG nodes in reverse topological order \n");

    int *d=malloc(D->V*sizeof(int));
    int i;

    //Inizializziamo il vettore delle distanze a 0
    for(i=0;i<D->V;i++)
        d[i]=0;



    arco *vetArchi;

    vetArchi= caricaVetArchi(D);

    for (v=0;v<D->V;v++) {//Per ogni vertice in ordine topologico

        //Per ogni arco
        for(i=0;i<D->E;i++)
        {
            //printf("\nd[vetArchi[%d].w]: %d d[ts[v]]: %d vetArchi[i].wt: %d", i, d[vetArchi[i].w],d[ts[v]],  vetArchi[i].wt );

            if(d[vetArchi[i].w] <= d[ts[v]] + vetArchi[i].wt) //RELAXATION INVERSA
            {
                d[vetArchi[i].w]= d[ts[v]] + vetArchi[i].wt;
            }

        }

    }

    printf("\nMASSIMA DISTANZA:");
    //printf("%s ", STsearchByIndex(D->pTabellaSimboli, ts[v]).nome);
    for(v=0;v<D->V;v++)
    {
        printf("\nVertice: %s, distMax: %d  ", STsearchByIndex(D->pTabellaSimboli, ts[v]).nome, d[ts[D->V-1-v]]);
    }


    printf("\n");
}