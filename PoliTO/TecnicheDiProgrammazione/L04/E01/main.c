#include <stdio.h>
int sottosequenze(int v[],int N)
{
    int i,inizio, max=0,j;
    for (i=0;i<N;i++)
    {
        if(v[i]!=0)
        {
            inizio=i;
            while (v[i]!=0 && i<N)
            {
                i++;
            }
            if(max<(i-inizio))
            {
                max=i-inizio;
            }
        }
    }

    int appoggio[max],flag=1;
    for (i=0;i<N;i=i+max)
    {
        for (j=0;j<max;j++)
        {
            //printf("%d   i \n",i);
            //printf("%d\n",v[i+j]);
            if(v[i+j]!=0)
            {
                appoggio[j]=v[i+j];
            }
            else
            {
                i=i-max+j+1;
                flag=0;
                j=max+1;
            }
        }
        if(flag==1)
        {
            printf("[");
            for (j=0;j<max;j++)
            {
                printf("%d",appoggio[j]);
                if (j<max-1)
                {
                    printf(", ");
                }
            }
            printf("]");
        }
        flag=1;
    }
}

int main() {
    int N,i;
    printf("Inserisci il numero di elementi nel vettore, minore di 30\n");
    scanf("%d",&N);
    while (N>30 || N<0)
    {
        printf("Valore errato, inserisci il numero di elementi nel vettore, minore di 30\n");
        scanf("%d",&N);
    }
    int v[N];
    for (i=0;i<N;i++)
    {
        printf("inserisci il valore %d:\n", i+1);
        scanf("%d",&v[i]);
    }
    sottosequenze(v,N);
    return 0;
}
