//
// Created by Utente on 08/01/2022.
//


#include "stdlib.h"
#include "stdio.h"

#include "BST.h"
#define FLT_MAX 3.402823466e+38F /* max value */


typedef struct BSTnode *link;
struct BSTnode {

    Quotazione quotazione;
    link p;//padre
    link l; //figlio sinistro
    link r;//figlio destro
    int N;
};
struct bynarysearchtree{

    link root; //radice
    link z;//sentinella

};
static link NEW(Quotazione quotazione, link p, link l, link r, int N);
static link insertR(link h, Quotazione x, link z);
static void inOrder(link root);
static link rotR(link h);
static link rotL(link h);
static link partR(link h, int r);
static link balanceR(link h, link z);


static link NEW(Quotazione quotazione, link p, link l, link r, int N) {
    link x = malloc(sizeof *x);

    x->quotazione = quotazione;
    x->p = p;
    x->l = l;
    x->r = r;
    x->N = N;

    return x;
}

static void treeFree(link h, link z);

void BSTfree(BST bst) {
    if (bst == NULL)
        return;
    treeFree(bst->root, bst->z);
    free(bst->z);
    free(bst);
}


static void treeFree(link h, link z) {
    if (h == z)
        return;
    treeFree(h->l, z);
    treeFree(h->r, z);
    free(h);
}
static void inOrder(link root)
{

    if(root==NULL)
        return;

    inOrder(root->l);
    stampaQuotazione(root->quotazione);
    inOrder(root->r);

}
//Funzione Wrapper per la inOrder
void stampaBSTinOrder(BST bst){

    inOrder(bst->root);

}

static void cercaInOrder(link root, int data1, int data2, float *max, float *min){



    if(root==NULL) //caso albero vuoto
        return;

    cercaInOrder(root->l, data1, data2, max, min);
    int data= root->quotazione.Data.anno + root->quotazione.Data.mese + root->quotazione.Data.giorno;
   // printf("%d", data);
   if(data>=data1 && data<=data2) {

        if (root->quotazione.valQuotazione > *max) {
            *max = root->quotazione.valQuotazione;
        }

        if (root->quotazione.valQuotazione < *min) {
            *min = root->quotazione.valQuotazione;

        }
    }

    cercaInOrder(root->r, data1, data2, max, min);

}


void WrapperCercaInOrder(int data1, int data2, BST bst)
{


    float min =FLT_MAX;
    float max=0;


    cercaInOrder(bst->root, data1, data2, &max, &min);

    printf("\n La quotazione massima nell'intervallo di date considerato vale: %f", max);
    printf("\n La quotazione minima nell'intervallo di date considerato vale: %f", min);


}

static void cercaInOrderALL(link root, float *max, float *min){



    if(root==NULL) //caso albero vuoto
        return;

    cercaInOrderALL(root->l, max, min);

    // printf("%d", data);

    if(root->quotazione.valQuotazione!=0) {
        if (root->quotazione.valQuotazione > *max) {
            *max = root->quotazione.valQuotazione;
        }

        if (root->quotazione.valQuotazione < *min) {
            *min = root->quotazione.valQuotazione;

        }
    }


    cercaInOrderALL(root->r, max, min);

}

int Max(int a, int b)
{
    return a>b ? a:b;
}

int Min(int a, int b)
{
    return a<b ? a:b;
}

static int camminoMin(link nodo)
{
    // L'albero è vuoto
    if (nodo==NULL)
        return 0;

    // 1+ massimo del figlio
    return 1 + Min(camminoMin(nodo->l), camminoMin(nodo->r));
}
int WrappercamminoMin(BST bst)
{
    int min=camminoMin(bst->root);//Gli passiamo la radice
    printf("\n Il cammino minimo vale: %d", min-1);

    return min;

}

static int camminoMax(link nodo)
{
    // L'albero è vuoto
    if (nodo==NULL)
        return 0;

    // 1+ massimo del figlio
    return 1 + Max(camminoMax(nodo->l), camminoMax(nodo->r));
}

int WrappercamminoMax(BST bst)
{
    int max=camminoMax(bst->root);//Gli passiamo la radice
    printf("\n Il cammino massimo vale: %d", max-1);

    return max;

}

void WrapperCercaInOrderALL(BST bst){

    float min =FLT_MAX;
    float max=0;


    cercaInOrderALL(bst->root, &max, &min);

    printf("\n La quotazione massima nell'intervallo di date considerato vale: %f", max);
    printf("\n La quotazione minima nell'intervallo di date considerato vale: %f",min);


}


BST BSTinit( ) {

    BST bst = malloc(sizeof *bst) ;

    bst->root = ( bst->z = NEW(quotazioneSetNull(), NULL, NULL, NULL, 0));

    //bst->z sarà il nostro nodo fittizio

    return bst;
}


link rotR(link h) {
    link x = h->l;
    h->l = x->r;
    x->r->p = h;
    x->r = h;
    x->p = h->p;
    h->p = x;
    x->N = h->N;
    h->N = 1;
    h->N += h->l->N;
    h->N += h->r->N;
    return x;
}

link rotL(link h) {
    link x = h->r;
    h->r = x->l;
    x->l->p = h;
    x->l = h;
    x->p = h->p;
    h->p = x;
    x->N = h->N;
    h->N = 1;
    h->N += h->l->N;
    h->N += h->r->N;
    return x;
}
link partR(link h, int r) {
    int t  = h->l->N;
    if ( t > r) {
        h->l = partR(h->l, r);
        h = rotR(h);
    }
    if ( t < r) {
        h->r = partR(h->r, r-t-1);
        h = rotL(h);
    }
    return h;
}

//*****************************************
//BALANCE
static link balanceR(link h, link z) {

    int r;
    if (h == z)
        return z;
    r = (h->N+1)/2-1;
    h = partR(h, r);

//------------------------------------------

    h->l = balanceR(h->l, z);
    h->r = balanceR(h->r, z);
    return h;
}

void BSTbalance(BST bst) {
    bst->root = balanceR(bst->root, bst->z);
}

static Quotazione searchR(link h, data k, link z) {

    if (h == z)
        return quotazioneSetNull();
    int datak= k.anno+k.mese+k.giorno;
    int dataQuotazione= h->quotazione.Data.anno+ h->quotazione.Data.mese+h->quotazione.Data.giorno;

    if (datak==dataQuotazione)
        return h->quotazione;

    if (datak<dataQuotazione)
        return searchR(h->l, k, z);
    else
        return searchR(h->r, k, z);
}

Quotazione BSTsearch(BST bst, data k) {
    return searchR(bst->root, k, bst->z);
}

static link insertR(link h, Quotazione x, link z) {

    if (h == z)
        return NEW(x, z, z, z, 1);

    int data1 = x.Data.anno+ x.Data.mese + x.Data.giorno;
    int data2 = h->quotazione.Data.anno + h->quotazione.Data.mese + h->quotazione.Data.giorno;


    if (data1<data2) {

        //Si scende a sinistra
        h->l = insertR(h->l, x, z);
        h->l->p = h;
    }
    else {
        //si scende a destra
        h->r = insertR(h->r, x, z);
        h->r->p = h;
    }

    h->N++;


    return h;
}

//*************************************
//Funzione Wrapper

void BSTinsert_leafR(BST bst, Quotazione x) {

    bst->root = insertR(bst->root, x, bst->z);


   // printf("\n %s", bst->root->quotazione.codiceTitolo);


}


//**************************************************
//Inseriamo le quotazioni nel BST

void caricaBST(BST bst, char *codice, float quotazione, data Data){



    //impacchettiamo in quotazioni
    Quotazione  q= creaQuotazione( quotazione, codice, Data);
    BSTinsert_leafR(bst, q);


}


