//
// Created by Utente on 15/12/2021.
//

#include "personaggi.h"



/* lettura e scrittura su file */
int pgRead(FILE *fp, Personaggio *p)
{


    if(fscanf(fp, "%s %s %s %d %d %d %d %d %d",  p->cod, p->nome, p->classe, &p->stat1, &p->stat2, &p->stat3, &p->stat4, &p->stat5, &p->stat6)==9)
    {

        p->equip= equipArray_init(); //impostiamo prese a 0
        return 1;
    }


    return -1;

}


void pgPrint(FILE *fp, Personaggio p, WrapperInventario invArray)
{



    printf("\n%s %s %s %d %d %d %d %d %d ", p.cod, p.nome, p.classe, p.stat1, p.stat2, p.stat3, p.stat4, p.stat5, p.stat6);



    equipArrayPrint(fp, p.equip, invArray); //Passiamo quel determinato Wrapper Equippaggiamento(che appartiene al singolo giocatore)


}
//************************************************
//AGGIUNGI EQUIPAGGIAMENTO
void aggiungiEquipaggiamentoP(Personaggio p, int pos){


    aggiungiEquipaggiamentoEA(p.equip, pos);





}

void rimuoviEquipaggiamentoP(Personaggio p, int pos){


    rimuoviEquipaggiamentoEA(p.equip, pos);


}


void statisticheP(Personaggio p, WrapperInventario invArray){



    int i,j;
    int somme[6];

    //Inizializziamo Somme con le statistiche del personaggio
    somme[0]=p.stat1;
    somme[1]=p.stat2;
    somme[2]=p.stat3;
    somme[3]=p.stat4;
    somme[4]=p.stat5;
    somme[5]=p.stat6;

    int n= prese(p.equip);




    if(n>0)//il personaggio ha degli equipaggiamenti?
    {


        for(i=0; i<n; i++)
        {

            int *statistiche = statisticheIA(pos(p.equip,i), invArray);

            for(j=0;j<Nstatistiche;j++)
                somme[j]=somme[j]+ statistiche[j];


        }


        printf("\nStatistiche di:");
        printf("\n%s %s %s", p.cod, p.nome, p.classe);

        for(i=0;i<6; i++)
        {
            if(somme[i]<=0) //convenzione stampa
                printf(" 1");
            else
                printf(" %d", somme[i]);

        }




    }
    else{
        printf("\nStatistiche di:");
        printf("\n\n%s %s %s", p.cod, p.nome, p.classe);
        printf(" %d  %d  %d  %d  %d  %d",p.stat1,  p.stat2, p.stat3, p.stat4, p.stat5, p.stat6);


    }







}






