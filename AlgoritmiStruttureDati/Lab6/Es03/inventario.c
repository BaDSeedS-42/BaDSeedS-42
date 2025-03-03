//
// Created by Utente on 14/12/2021.
//

#include "inventario.h"



Inventario inv_read(FILE *fp){

    Inventario elemento;

    fscanf(fp,"%s %s %d %d %d %d %d %d", elemento.nome, elemento.tipo, &elemento.stat1, &elemento.stat2, &elemento.stat3, &elemento.stat4, &elemento.stat5, &elemento.stat6);

    return elemento; //ritorniamo struct per valore (QUASI-ADT)

}

void inv_print(FILE *fp, Inventario oggetto){


    fprintf(fp, "\n%s %s %d %d %d %d %d %d", oggetto.nome, oggetto.tipo, oggetto.stat1, oggetto.stat2, oggetto.stat3, oggetto.stat4, oggetto.stat5, oggetto.stat6);

}
int *statisticheI( Inventario oggetto){

    int *somme= malloc(Nstatistiche*sizeof(int));
    int i;
    //inizializziamo

    for(i=0;i<Nstatistiche;i++)
        somme[i]=0;

    somme[0]=somme[0]+oggetto.stat1;
    somme[1]=somme[1]+oggetto.stat2;
    somme[2]=somme[2]+oggetto.stat3;
    somme[3]=somme[3]+oggetto.stat4;
    somme[4]=somme[4]+oggetto.stat5;
    somme[5]=somme[5]+oggetto.stat6;




    return somme;



}