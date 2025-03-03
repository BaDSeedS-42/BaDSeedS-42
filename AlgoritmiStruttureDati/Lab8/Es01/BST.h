//
// Created by Utente on 08/01/2022.
//

#ifndef ES01_BST_H
#define ES01_BST_H


#include "quotazione.h"



typedef struct bynarysearchtree *BST;

BST BSTinit();
void BSTinsert_leafR(BST bst, Quotazione x);
void caricaBST(BST bst, char *codice, float quotazione, data Data);
void stampaBSTinOrder(BST bst);
void BSTfree(BST bst);
Quotazione BSTsearch(BST bst, data k);
void WrapperCercaInOrder(int data1, int data2, BST bst);
void WrapperCercaInOrderALL(BST bst);
int Max(int a, int b);
int WrappercamminoMax(BST bst);
int WrappercamminoMin(BST bst);
int Min(int a, int b);
void BSTbalance(BST bst);


#endif //ES01_BST_H
