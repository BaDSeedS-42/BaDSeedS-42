#include <stdio.h>
#include <string.h>
#include<ctype.h>

#define MAX 30

char *cercaRegexp(char *src, char *regexp);
int contaCaratteri(char rExp[]);
int in(char vet[], char c, int n);

int main()
{

    char s[MAX], rExpr[MAX], *p;


    printf("\nInserisci una stringa-->");
    scanf("%s", s);
    printf("\nInserisci l'espressione regolare-->");
    scanf("%s", rExpr);

    p=cercaRegexp(s, rExpr);
    int i, n= contaCaratteri(rExpr);

    if(p == NULL)
        printf("\nNESSUNA occorrenza trovata");
    else
    {

        printf("\n\nPRIMA OCCORRENZA TROVATA in src:\n\n");
        for(i=0; i<n; i++)
        {

            printf("%c", p[i]);


        }
        printf("\n\n");

    }





    return 0;
}

///Restituisce la lungheza che la sottostringa dovrebbe avere
int contaCaratteri(char rExp[])
{

    int i, cont=0, quadre=0;

    for(i=0;i<strlen(rExp);i++)
    {


        if(rExp[i]=='[')
            quadre=1;

        if(rExp[i]==']')
            quadre=0;


        ///Non siamo nelle quadre //A[^f]\anR.d,\A[aeiou]5t[123]
       if(quadre==0)
       {
            if(rExp[i]!='.' && rExp[i]!='\\' && rExp[i-1]!='\\')
                cont++;

            if(rExp[i]=='.')
                cont++;
            if(rExp[i-1]=='\\')
                cont++;

       }

    }

 return cont;
}

///****************************************************************
///Controlla se ESISTE il carattere nel vettore
///********************************************
int in(char vet[], char c, int n){


    int i, val=0;



    for(i=0; i<n; i++)
    {
        //printf("\n->%c", vet[i]);
        if(vet[i]==c)
            val=1;


    }

    return val;


}

///********************************************
///Funzione di esecuzione Espressioni regolari

char *cercaRegexp(char *src, char *regexp)
{
    char *p=NULL;
    char blackList[MAX], whiteList[MAX];
    int i,j,k, b=0, trovato, t=0,z;
    ///siamo dentro le quadre?
    int quadre=0;

    int n= contaCaratteri(regexp);

    printf("\nLa lunghezza che la sottostringa dovrebbe avere e' : %d ", n);


    ///Scorriamo la stringa src
    for(i=0;i<strlen(src)-n+1;i++)
    {

        k=0;
        b=0;
        quadre=0;


        ///Scorriamo con un blocco di n caratteri la stringa src, se troviamo qualcosa che non va usciamo
        for(j=i; j<i+n+1 && b==0; j++)
        {

            ///***********************************************************************************************************
            ///GESTIONE QUADRE
            ///***************************

            if(regexp[k]=='[')
            {
                quadre=1;
                trovato=0;
            }

            ///Siamo nelle quadre e siamo il primo elemento è '^'
              if(quadre==1 && regexp[k+1]=='^')
               {
                    k+=2;///Saltiamo il '^'
                    ///Carichiamo la black list
                    while(regexp[k]!=']')
                    {
                        if(regexp[k]!='[')
                        {
                            blackList[t++]=regexp[k];
                        }

                        k++;

                    }

                    ///FINE QUADRA
                    if(regexp[k]==']')
                    {

                        printf("\nBlackList");
                        for(z=0;z<t;z++)
                             printf(" %c", blackList[z]);

                        if(in(blackList, src[j], t)==0)
                        printf("\n->carattere valido: %c ",  src[j]);

                        ///Se è nella black list, fermiamo il ciclo
                        if(in(blackList, src[j], t)==1)
                        {
                            b=1;///Fermiamo il ciclo
                            printf("\n->carattere NON valido: %c ",  src[j]);
                            return NULL;

                        }


                        ///PULIZIA VETTORE
                        for(z=0; z<t; z++)
                           whiteList[z]=0;

                        //k++;
                        t=0;
                        quadre=0;

                    }


            }

            ///Siamo nelle quadre e siamo il primo elemento e non siamo '^'
           else if(quadre==1 && regexp[k]!='^')
           {

                ///Carichiamo la white list
                while(regexp[k]!=']')
                {
                    if(regexp[k]!='[')
                    {
                        whiteList[t++]=regexp[k];

                    }

                    k++;

                }

                ///FINE QUADRA
                if(regexp[k]==']')
                {

                    printf("\nWhiteList");
                    for(z=0;z<t;z++)
                         printf(" %c", whiteList[z]);


                    if(in(whiteList, src[j], t)==1)
                    printf("\n->carattere valido: %c ",  src[j]);

                    ///Se non è nella white list, fermiamo il ciclo
                    if(in(whiteList, src[j], t)==0)
                    {
                        b=1;
                        printf("\n->carattere NON valido: %c ",  src[j]);
                    }



                    ///PULIZIA VETTORE
                    for(z=0; z<t; z++)
                       whiteList[z]=0;

                    //k++;
                    t=0;
                    quadre=0;

                }


        }








        /**********************************************************************************************/


            ///Non siamo nelle quadre
            if(quadre==0)
            {
                if(regexp[k]!='.' && regexp[k]!='\\' && regexp[k-1]!='\\'  && regexp[k]!=']') ///NO metadati
                {
                   // printf("\n regexp[%d]: %c, src[%d]: %c", k, regexp[k], j, src[j]);
                  // printf("\n regexp[%d]: %c, src[%d]: %c", k, regexp[k], j, src[j]);
                    if(regexp[k] != src[j]) ///Caratteri NON uguali
                    {

                            b=1; ///Usciamo dal ciclo


                           // printf("\nj-i: %d", j-i);
                    }





                }
                else
                {



                        // printf("\nelse: j-i: %d", j-i);
                     //printf("\n regexp[%d]: %c, src[%d]: %c", k, regexp[k], j, src[j]);

                    if(regexp[k-1]=='\\')
                    {
                        k++;
                    }



                    ///MAIUSCOLO
                    if(regexp[k] == '\\' && regexp[k+1]=='A')
                    {

                        if(!isupper(src[j])) ///Se non è maiuscolo
                        {
                            b=1;
                        }



                    }
                    ///MINUSCOLO
                    if(regexp[k] == '\\' && regexp[k+1]=='a')
                    {

                        if(!islower(src[j])) ///Se non è minuscolo
                        {
                            b=1;

                        }



                    }





                }


            }

            k++;

            ///Controlliamo se la sottostringa rispetta i parametri
            //printf("\nFine ciclo j-i: %d ", j-i);
            if((j-i)==n)
            {

                return p=&src[i];

            }

        }

    }


    return p;
}
