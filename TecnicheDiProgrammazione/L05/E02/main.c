#include <stdio.h>
#include <string.h>
void creadizionario(FILE *file,int S, char tabella[S][30])  //crea un vettore di stringhe dove parola
{                                                    // da cercare e codice da scrivere sono uno dopo l'altro
    int i;
    for (i=0;i<S;i=i+2)
    {

        fscanf(file,"%s%s",&tabella[i],&tabella[i+1]);
    }
}

void createsto(FILE *file,int N, char stringa[N]) //crea una stringa che contiene tutto il testo
{
    int i=0;
    while(!feof(file))
    {
        stringa[i]=getc(file);
        i++;
    }
    stringa[i]='\0';
}

char * codifica( int N, char stringa[N], int S, char table[S][30], FILE *file) //codifica la stringa e la
{                                                                             //scrive su file
    char nuovo[N],hold[N],help[N],codice[N];
    int i,j,a,b,count,len=0,hcount, lencodice=0;
    strcpy(nuovo,stringa);
    for (i=1;i<S;i=i+2)      //itera le parole da cercare
    {
        strcpy(help,table[i]);      //salva la parola da cercare in help
        strcpy(codice,table[i-1]);    // salva il codice da scrivere al posto della parola in codice
        len=0;
        lencodice=0;
        a=0;
        while(help[a]!='\0')   //calcola la lunghezza della parola
        {
            len++;
            a++;
        }
        a=0;
        while(codice[a]!='\0')      //calcola la lunghezza del codice
        {
            lencodice++;
            a++;
        }
        a=0;
        hcount=0;
        while(nuovo[a]!='\0')    //itera tutti i caratteri del testo
        {
            j=0;
            count=0;
            while(nuovo[a]==help[j]) //conta quante lettere del testo sono uguali alla parola da cercare
            {
                count++;
                a++;
                j++;
            }
            if(count==len)    //se le lettere sono uguali alla lunghezza totale della parola da cercare
            {
                for (b=0;b<lencodice;b++)  //scrive il codice corrispondente
                {
                    hold[hcount]=codice[b];
                    hcount++;
                }
                a--;
            }
            else // se il numero di lettere uguali non forma l'intera parola
            {
                for (b=0;b<=count;b++) //scrive le lettere controllate senza modifiche
                {
                    hold[hcount]=nuovo[a-count+b];
                    hcount++;
                }
            }
            a++;
        }
        hold[hcount]='\0';
        strcpy(nuovo,hold);
        strcpy(hold,"");
    }
    a=0;
    while(nuovo[a+1]!='\0')//scrivo il testo codificato dopo aver cercato tutte le parole nel file
    {
        fputc(nuovo[a],file);
        a++;
    }
}



int main() {
    FILE *dizionario,*file,*uscita;
    int S,N=200;
    if((dizionario=fopen("../dizionario.txt", "r"))==NULL)
    {
        printf("Error opening the file");
        return 1;
    }
    if((file=fopen("../sorgente.txt", "r"))==NULL)
    {
        printf("Error opening the file");
        return 2;
    }
    if((uscita=fopen("../ricodificato.txt", "w"))==NULL)
    {
        printf("Error opening the file");
        return 3;
    }
    fscanf(dizionario,"%d",&S);
    char table[2*S][30], testo[N], nuovo[N];
    S=S*2;
    creadizionario(dizionario,S,table);
    createsto(file,N,testo);
    codifica(N, testo,S, table,uscita);
    fclose(file);
    fclose(dizionario);
    fclose(uscita);
    return 0;
}
