#include <stdio.h>

int main() {
    FILE *in;
    int n,n1,n2, max, min,scartati=0;
    if((in= fopen("../numeri.txt","r"))==NULL)
    {
        printf("errore aprendo il file\n");
        return 1;
    }
    fscanf(in, "%d %d ",&n,&n1);
    if(n>n1)
    {
        max=n;
        min=n1;
    }
    else
    {
        max=n1;
        min=n;
    }
    while (!feof(in))
    {
        fscanf(in,"%d",&n2);
        if(n1!=0 && (n2==n+n1 || n2==n-n1 || n2==n*n1 || n2==n/n1))
        {
            if(n2>max)
            {
                max=n2;
            }
            if(n2<min)
            {
                min=n2;
            }
            n=n1;
            n1=n2;
        }
        else
        {
            if(n1==0 && (n2==n+n1 || n2==n-n1 || n2==n*n1))
            {
                if(n2>max)
                {
                    max=n2;
                }
                if(n2<min) {
                    min = n2;
                }
                n=n1;
                n1=n2;
            }
            else
            {
                scartati++;
            }
        }
    }
    printf("sono stati scartati %d numeri\nil massimo e' %d\nil minimo e' %d",scartati,max,min);
    return 0;
}
