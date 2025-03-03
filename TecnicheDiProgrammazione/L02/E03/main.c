#include <stdio.h>

int comprimi(FILE*fread,FILE*fwrite)
{
    char carattere,carattere2;
    int count=0;
    carattere = fgetc(fread);
    while (!feof(fread))
    {
        carattere2=fgetc(fread);
        //printf("%c %c",carattere,carattere2);
        while(carattere2==carattere && count<9 && carattere2!=' ' && carattere2!='\n')
        {
            count++;
            carattere2=fgetc(fread);
        }
        fputc(carattere, fwrite);
        if(count==0)
        {
            carattere=carattere2;
        }
        else
        {
            fputc('$',fwrite);
            fprintf(fwrite,"%d",count);
            count=0;
            carattere=carattere2;

        }
    }
    return 0;
}

int decomprimi(FILE*fin,FILE*fout)
{
    char carattere, carattere2,ripetizioni;
    int i, r;
    carattere=fgetc(fin);
    while(!feof(fin))
    {
        carattere2=fgetc(fin);
        if(carattere2=='$')
        {
            ripetizioni= fgetc(fin);
            r=ripetizioni-'0';
           for(i=0;i<r;i++)
            {
                fputc(carattere, fout);
            }
        }
        else
        {
            fputc(carattere,fout);
            carattere=carattere2;
        }
    }
    return 0;
}
int main() {

    FILE *fread, *fwrite, *fread2, *fwrite2;
    if((fread = fopen("../sorgente.txt","r")) == NULL)   //controlla che il file non sia vuoto
    {
        printf("Error opening the file\n");
        return 1;
    }
    if ((fwrite = fopen("../compresso.txt", "w")) == NULL) //controlla che sia possibile creare un file di output dove scrivere
    {
        printf("Error opening the file\n");
        return 2;
    }
    if((fread2 = fopen("../sorgente2.txt","r")) == NULL)   //controlla che il file non sia vuoto
    {
        printf("Error opening the file\n");
        return 1;
    }
    if ((fwrite2 = fopen("../decompresso.txt", "w")) == NULL) //controlla che sia possibile creare un file di output dove scrivere
    {
        printf("Error opening the file\n");
        return 2;
    }
    comprimi(fread,fwrite);
    decomprimi(fread2,fwrite2);
    return 0;
}
