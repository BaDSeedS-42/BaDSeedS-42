//
// Created by Utente on 08/01/2022.
//

#ifndef ES01_QUOTAZIONE_H
#define ES01_QUOTAZIONE_H

#define MAX 30

#include "data.h"




//Quotazione(quello che starà dentro al BST)
typedef struct {

    char codiceTitolo[MAX];
    data Data;
    float valQuotazione;

}Quotazione;

Quotazione quotazioneSetNull();
Quotazione creaQuotazione(float quotazione, char *codice, data Data);
void stampaQuotazione(Quotazione q);

#endif //ES01_QUOTAZIONE_H
