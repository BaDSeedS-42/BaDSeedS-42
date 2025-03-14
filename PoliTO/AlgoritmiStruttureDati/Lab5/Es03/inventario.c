//
// Created by Utente on 10/12/2021.
//

#include "inventario.h"


//***************************************************
//CARICAMENTO Inventario

//Cosa vuoi ritornare al main?
WrapperInventario caricaInventario()
{

    WrapperInventario b;
    FILE *file;
    int n,i;

    //Apriamo il file
    if((file=fopen("inventario.txt","r"))==NULL){
        printf("\nErrore durante l'aperura del file");
        exit(1);
    }

    fscanf(file,"%d", &n);

    //Carichiamo il numero di elementi
    b.nElementi=n;

    //Allochiamo il vettore degli elementi
    b.elementi=malloc(n*sizeof (Inventario));


    for(i=0;i<n; i++)
    {

        fscanf(file,"%s %s %d %d %d %d %d %d", b.elementi[i].nome, b.elementi[i].tipo, &b.elementi[i].stat1, &b.elementi[i].stat2, &b.elementi[i].stat3, &b.elementi[i].stat4, &b.elementi[i].stat5, &b.elementi[i].stat6);

        stampaElemento(b.elementi[i]);

    }



    fclose(file);





    return b;

}


//***************************************************************
//RICERCA DI UN ELEMENTO DELL'INVENTARIO PER NOME

int cercaElementoInventario(char nome[], WrapperInventario b)//ci ritorna la posizione dell'elemento nell'inventario
{

    int i, pos=-1;

    for(i=0;i<b.nElementi;i++)
    {
        if(strcmp(nome, b.elementi[i].nome)==0)
            pos=i;

    }

    return pos;


}



//***************************************************************
//STAMPA DETTAGLI DI UN ELEMENTO


stampaElemento(Inventario oggetto)
{

    printf("\n%s %s %d %d %d %d %d %d", oggetto.nome, oggetto.tipo, oggetto.stat1, oggetto.stat2, oggetto.stat3, oggetto.stat4, oggetto.stat5, oggetto.stat6);

}
