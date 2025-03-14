//
// Created by Utente on 31/12/2021.
//

#include "graph.h"


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

void ordinaVertici(V *vertici, int n);

//*******************************************
//CARICHIAMO IL GRAFO
void GRAPHload() {

    int V, i, id1, id2, wt;
    char label1[MAX], label2[MAX];
    Graph G;
    GraphL GL;

    FILE *file;
    if((file=fopen("grafo.txt","r"))==NULL){
        printf("\nErrore durante l'aperura del file");
        exit(1);
    }
    G = GRAPHinit();
    caricaST(G->tabellaSimboli, file);//occorre inizializzare il Grafo
    fclose(file);

    ordinaST(G->tabellaSimboli);

    //Otteniamo il numero di vertici
    V= STsize(G->tabellaSimboli);
    G->V = V;
    G->madj = MATRIXinit(V, V, 0);



    if((file=fopen("grafo.txt","r"))==NULL){
        printf("\nErrore durante l'aperura del file");
        exit(1);
    }

    while(fscanf(file,"%s %*s %s %*s %d", label1, label2, &wt) == 3) {

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

    //***********************************
    //Gestione Menù


    printf("\nOperazioni sul GRAFO:");
    printf("\n1)elencare in ordine alfabetico i vertici e per ogni vertice gli archi che su di esso insistono, sempre"
           " in ordine alfabetico.");
    printf("\n2)Verificare se 3 vertici sono adiacenti a coppie");
    printf("\n3)Genera rappresentazione a Lista di ADIACENZA");
    printf("\n4)Verificare se 3 vertici sono adiacenti a coppie [VERSIONE CON LISTA]");
    printf("\n-1)Esci");

    int scelta;


    do{

        printf("\nscelta-->");
        scanf("%d", &scelta);

        switch (scelta) {


            case 1:

                stampaInOrdineAlfabetico(G, G->tabellaSimboli);
                break;

            case 2:

                grafoCompleto(G, G->tabellaSimboli);

                break;


            case 3:

                generaLista(G, G->tabellaSimboli);

                break;

            case 4:

               GL= generaLista(G, G->tabellaSimboli);
                grafoCompletoL(GL, G->tabellaSimboli);


                break;


            default:
                printf("La scelta effettuata non è valida!");
                break;

        }


    }while(scelta!=-1);

    liberaGRAPH(G);
    liberaGRAPHL(GL);

}

//***************************************************
//GENERA LISTA DA MATRICE DELLE ADIACENZE
GraphL generaLista(Graph G, ST st)
{

    GraphL GL;
    int V= STsize(st);
    int i, j, k, t;

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



    //Stampiamo la lista delle adiacenze

    link x;
    for(i=0;i<V;i++) {

            Item vertice =STsearchByIndex(st, i);

        printf("\n %s:\n ", vertice.nome);
        for (x = GL->ladj[i]; x != GL->z; x = x->next) {

            printf(" %d", x->v);

        }
    }
    printf("\nLista creata con successo!!");

    return GL;

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

static void insertEL(GraphL G, arco e) {

    int v = e.v, w = e.w, wt = e.wt;

    //andiamo nella lista delle adiacenze, creiamo un nuovo nodo che inseriamo in testa, che contiene w
   // G->ladj[v] = NEW(w, wt, G->ladj[v]);//inseriamo w che sarà così connesso a v
    G->ladj[w] = NEW(v, wt, G->ladj[w]);//solo PER GRAFI NON ORIENTATI

    //ATTEZIONE: si possono inserire vertici uguali, in tal caso, stiamo facendo un CAPPIO

    G->E++;
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


void grafoCompletoL(GraphL GL, ST st)
{

    int i,k;
    int b=0;
    Item vertici[3];

    //***********************************************
    //Inserimento vertici
   // vertici= malloc(3*sizeof(V));

    for(i=0;i<3;i++) {

        printf("\nInserisci il nome del vertice [%d]-->", i+1);
        scanf("%s", vertici[i].nome);

        Item vertice= STsearch(st, vertici[i].nome);

        if(vertice.indice==-1)
        {
            printf("Il nome del vertice inserito non esiste!");
            break;

        }else
            vertici[i].indice= vertice.indice;

    }

    //*********************************
    //Fase di CONTROLLO


    for(i=0;i<3;i++)//Per ogni vertice controlliamo se è collegato agli altri due
    {

        int cont=0;
        link x;

        //Scorriamo le «colonne» della lista, ovvero i vertici adiacenti
        for (x = GL->ladj[vertici[i].indice]; x != GL->z; x = x->next) {

            for(k=0;k<3;k++)
            {

               // printf("\n x->v: %d", x->v);
                //printf(" vertici[k].indice: %d", vertici[k].indice);

                if(x->v == vertici[k].indice)
                    cont++;

            }



        }

        if(cont<2)
            b=1;


    }

    if(b==0)
        printf("\nIl sottografo inserito  e' COMPLETO!");
    else
        printf("\nIl sottografo inserito NON e' completo");




}

//Matrice delle Adiacenze
//************************************************************************************************************************************************



//************************************
//È il SOTTOgrafo COMPLETO?

void grafoCompleto(Graph G, ST st)
{
    int i,j,k;
    Item vertici[3];

    //***********************************************
    //Inserimento vertici


    for(i=0;i<3;i++) {

        printf("\nInserisci il nome del vertice [%d]-->", i+1);
        scanf("%s", vertici[i].nome);

        Item vertice= STsearch(st, vertici[i].nome);

        if(vertice.indice==-1)
        {
            printf("Il nome del vertice inserito non esiste!");
            break;

        }else
         vertici[i].indice= vertice.indice;

    }

    //*********************************
    //Fase di CONTROLLO

    int size= STsize(st);
   //
    int b=0;

    for(i=0;i<3;i++)//Per ogni vertice controlliamo se è collegato agli altri due
    {
        int cont=0;

       //Controlliamo se gli altri due elementi ci sono
       for(j=0;j<size;j++)
       {


           if(G->madj[vertici[i].indice][j]!=0)
           {
              // printf(" %d", G->madj[vertici[i].indice][j]);
               for(k=0;k<3;k++)
               {

                   if(j==vertici[k].indice)
                    cont++;


               }


           }

       }


      //  printf("\ncont:%d", cont);
       if(cont<2)
           b=1;



    }

    if(b==0)
        printf("\nIl sottografo inserito  e' COMPLETO!");
    else
        printf("\nIl sottografo inserito NON e' completo");




}

void stampaInOrdineAlfabetico(Graph G, ST st)
{

    int i,j, t;
    int size= STsize(st);
    V *vertici;

    vertici=malloc(size*sizeof (V));



    for(i=0; i<size; i++)
    {
        //Cerchiamo dove il vertice si trova nella matrice(che è l'indice di riga, e l'indice di colonna sono con chi è collegato)

        int indice = indiceV(i, st);
        //Inizializziamo il vettore di supporto
        for(t=0;t<size;t++)
            vertici[t].valArco=0;
        int k=0;

        //dobbiamo ora scandire le colonne della riga
        for(j=0;j<size; j++)
        {
            if(G->madj[indice][j] != 0)
            {
                Item verticeAdiacente= STsearchByIndex(st, j); //Passiamo l'indice del vertice adiacente

                strcpy(vertici[k].nome,verticeAdiacente.nome);
                vertici[k].valArco=G->madj[indice][j];
                k++; //salviamo per ogni vertice i suoi vertici adiacenti

            }


        }

        Item verticeCorrente= STsearchByIndex(st, indice);
        printf("\n%s", verticeCorrente.nome);
        //Ordiniamo il vettore
        printf(": %d", k);
        ordinaVertici(vertici, k);
        printf("\n");


    }



}

void ordinaVertici(V *vertici, int n)
{

    int i,j;

    V temp;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {

            if(strcmp( vertici[j].nome,  vertici[j+1].nome)>0 )
            {
                temp = vertici[j];
                vertici[j]=vertici[j+1];
                vertici[j+1]=temp;


            }

        }


    }

    printf("\n Gli archi in ordine alfabetico sono: ");
    for(i=0;i<n;i++)
    {

        printf("\n%d", vertici[i].valArco);

    }







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
     G->madj[v][w] = wt; //si crea una simmetria nella matrice, poichè non orientata
     G->madj[w][v] = wt;
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