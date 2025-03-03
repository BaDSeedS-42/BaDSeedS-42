//
// Created by Utente on 08/01/2022.
//


#include "stdlib.h"
#include "stdio.h"
#include "string.h"

#include "quotazione.h"


Quotazione quotazioneSetNull(){


    Quotazione q;

    strcpy(q.codiceTitolo, "\0");
    q.Data.giorno=0;
    q.Data.mese=0;
    q.Data.anno=0;
    q.valQuotazione=0;



    return q;


}

Quotazione creaQuotazione(float quotazione, char *codice, data Data)
{
    Quotazione q;


    q.Data=Data;
    q.valQuotazione=quotazione;
    strcpy(q.codiceTitolo, codice);

    return q;




}

void stampaQuotazione(Quotazione q){

    if(strcmp(q.codiceTitolo,"\0")!=0) {

        printf("\n\t%s %f ", q.codiceTitolo, q.valQuotazione);
        stampaData(q.Data);


    }else{

        printf("\n\t--");
    }



}