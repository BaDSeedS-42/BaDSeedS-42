#include <stdio.h>
#include <ctype.h>
int main() {
    char ch,ch2;
    int riga=0, attuali=0;
    FILE *in , *out;
    if((in=fopen("../input.txt", "r"))==NULL)
    {
        printf("errore nell'aprire il file");
        return 1;
    }
    if((out=fopen("../output.txt", "w"))==NULL)
    {
        printf("errore nell'aprire il file");
        return 2;
    }
    ch=fgetc(in);
    while (!feof(in))
    {
        riga=0;
        attuali=0;
        while (riga<25 && !feof(in))
        {
            ch2=fgetc(in);
            if(isdigit(ch))
            {
                fprintf(out, "*");
                riga++;
            }
            if(ispunct(ch))
            {
                fprintf(out, "%c",ch);
                riga++;
                attuali++;
                if(!isspace(ch2))
                {
                    fprintf(out, " ");
                    riga++;
                }
                if ((ch=='.' || ch=='!' || ch=='?' ) && isalpha(ch2))
                {
                    ch2=toupper(ch2);
                }
            }
            if((isalpha(ch) || isspace(ch))&& ch!='\n')
            {
                fprintf(out, "%c",ch);
                riga++;
                attuali++;
            }
            if(ch=='\n')
            {
                while (riga<25)
                {
                    fprintf(out, " ");
                    riga++;
                }
            }
            ch=ch2;
        }
        if (feof(in))
        {
            while (riga<25)
            {
                fprintf(out, " ");
                riga++;
            }
        }
        fprintf(out, "| c:%d\n",attuali);
    }

    fclose(in);
    fclose(out);

    return 0;
}
