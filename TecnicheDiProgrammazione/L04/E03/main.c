#define L 30
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



typedef enum {r_date,r_partenza,r_capolinea,r_ritardo,r_ritardo_tot,r_fine} t_comando;
typedef struct{
    char codice[L];
    char partenza[L];
    char destinazione[L];
    char data[L];
    char ora_partenza[L];
    char ora_arrivo[L];
    char ritardo[L];
}riga;

void stampa_riga(int N, int i,riga vettore_righe[N])
{
        printf("%s ",vettore_righe[i].codice);
        printf("%s ",vettore_righe[i].partenza);
        printf("%s ",vettore_righe[i].destinazione);
        printf("%s ",vettore_righe[i].data);
        printf("%s ",vettore_righe[i].ora_partenza);
        printf("%s ",vettore_righe[i].ora_arrivo);
        printf("%s\n",vettore_righe[i].ritardo);

}
t_comando leggiComando(void)
{
    t_comando c;
    char vett[][L]={"date","partenza","capolinea","ritardo","ritardo_tot","fine"};
    char comando[L];
    printf("Inserisci il comando:\n1)date  \n2)partenza \n3)capolinea \n4)ritardo \n5)ritardo_tot \n6)fine\n>>");
    scanf("%s",comando);
    c=r_date;
    while (c<r_fine && strcmp(comando, vett[c]) != 0)
    {
        c++;
    }
    if(strcmp(comando,"fine")!=0&&c==r_fine)
    {
        c=100;
    }
    return c;
}

int menuParola(int  n_comando, int N, riga vettore_righe[N])
{
    int i;

    switch(n_comando)
    {
        case r_date:
        {
            char data1[L],data2[L];
            printf("inserisci le date di inizio e fine nella forma AA/GG/MM\n");
            scanf("%s%s",data1,data2);
            for (i=0;i<N;i++)
            {
                if(strcmp(data1,vettore_righe[i].data)<=0&&strcmp(data2,vettore_righe[i].data)>=0)
                {
                    stampa_riga(N,i,vettore_righe);
                }
            }
            break;
        }
        case r_partenza:
        {
            char fermata[L];
            printf("inserisci la fermata di partenza\n");
            scanf("%s",fermata);
            for (i=0;i<N;i++)
            {
                if(strcmp(fermata,vettore_righe[i].partenza)==0)
                {
                    stampa_riga(N,i,vettore_righe);
                }
            }
            break;
        }
        case r_capolinea:
        {
            char fermata[L];
            printf("inserisci la fermata di arrivo\n");
            scanf("%s",fermata);
            for (i=0;i<N;i++)
            {
                if(strcmp(fermata,vettore_righe[i].destinazione)==0)
                {
                    stampa_riga(N,i,vettore_righe);
                }
            }
            break;
        }
        case r_ritardo:
        {
            char data1[L],data2[L];
            printf("inserisci le date di inizio e fine nella forma AA/GG/MM\n");
            scanf("%s%s",data1,data2);
            for (i=0;i<N;i++)
            {
                if(strcmp(data1,vettore_righe[i].data)<=0&&strcmp(data2,vettore_righe[i].data)>=0&&strcmp(vettore_righe[i].ritardo,"0")>0)
                {
                    stampa_riga(N,i,vettore_righe);
                }
            }
            break;
        }
        case r_ritardo_tot:
        {
            int rit_tot=0;
            char codice[L];
            printf("inserisci il codice della corsa\n");
            scanf("%s",codice);
            for (i=0;i<N;i++)
            {
                if(strcmp(codice,vettore_righe[i].codice)==0)
                {
                    int val = atoi(vettore_righe[i].ritardo);
                    rit_tot=rit_tot+val;
                }
            }
            printf("%d\n",rit_tot);
            break;
        }
        case r_fine:
        {
            break;
        }
    }
}



int main() {
    FILE *file;
    if((file=fopen("../corse.txt", "r"))==NULL)
    {
        printf("Error opening the file");
        return 1;
    }
    int N,n_comando,i=0;
    char comando[L];
    fscanf(file,"%d",&N);
    fgetc(file);
    riga vettore_righe[N];
    for (i=0;i<N;i++)
    {
        fscanf(file,"%s",vettore_righe[i].codice);
        fscanf(file,"%s",vettore_righe[i].partenza);
        fscanf(file,"%s",vettore_righe[i].destinazione);
        fscanf(file,"%s",vettore_righe[i].data);
        fscanf(file,"%s",vettore_righe[i].ora_partenza);
        fscanf(file,"%s",vettore_righe[i].ora_arrivo);
        fscanf(file,"%s",vettore_righe[i].ritardo);
    }
    while(n_comando!=r_fine)
    {
        n_comando=leggiComando();
        if(n_comando!=100)
        {
            menuParola(n_comando,N,vettore_righe);
        }
    }
    fclose(file);
    return 0;
}
