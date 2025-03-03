#include <stdio.h>

void selection_sort(int len,int vett[len])
{
    printf("SELECTION SORT\n\n");
    int i, j, l=0, min,x,scambi=0,iter_e=0,iter_i=0,iter_tot=0;
    for (i = l; i < len-1; i++)
    {
        iter_i=0;
        min = i;
        for (j = i+1; j <= len-1; j++)
        {
            if (vett[j] < vett[min])
            {
                min = j;
            }
            iter_i++;
        }
        if (min != i)
        {
            x = vett[i];
            vett[i] = vett[min];
            vett[min] = x;
            scambi++;
        }
        iter_e++;
        printf("iterazioni interne dell'iterazione %d esterna: %d\n",iter_e,iter_i);
        iter_tot=iter_tot+iter_i+1;
    }
    printf("\nIterazioni esterne del selection sort: %d\n",iter_e);
    printf("Iterazioni totali del selection sort: %d\n\n",iter_tot);
}
void insertion_sort(int len,int vett[len])
{
    printf("INSERTION SORT\n\n");
    int i, j, x,scambi=0,iter_e=0,iter_i=0,iter_tot=0;
    for (i = 1; i <= len-1; i++)
    {
        x = vett[i];
        j = i - 1;
        iter_i=0;
        while (j >= 0 && x < vett[j])
        {
            vett[j+1] = vett[j];
            scambi++;
            j--;
            iter_i++;
        }
        vett[j+1] = x;
        scambi++;
        iter_e++;
        printf("iterazioni interne dell'iterazione %d esterna: %d\n",iter_e,iter_i);
        iter_tot=iter_tot+iter_i+1;
    }
    printf("\nIterazioni esterne dell'insertion sort: %d\n",iter_e);
    printf("Iterazioni totali dell'insertion sort: %d\n\n",iter_tot);
}
void shell_sort(int len,int vett[len]) //con sequenza di knuth
{
    printf("SHELL SORT\n\n");
    int i, j, x, h=1,scambi=0,iter_e=0,iter_i=0,iter_tot=0;
    while (h < len/3)
    {
        h = 3 * h + 1;
    }
    while(h >= 1)
    {
        iter_i=0;
        for (i = h; i <= len-1; i++)
        {
            j = i;
            x = vett[i];
            while(j >= h && x < vett[j-h])
            {
                vett[j] = vett[j-h];
                j -=h;
                iter_i++;
            }
            vett[j] = x;
            iter_i++;
        }
        iter_e++;
        printf("iterazioni interne dell'iterazione %d esterna: %d\n",iter_e,iter_i);
        iter_tot=iter_tot+iter_i+1;
        h = h/3;
    }
    printf("\nIterazioni esterne del shell sort: %d\n",iter_e);
    printf("Iterazioni totali del shell sort: %d\n\n",iter_tot);
}

int main() {
    FILE *file;
    if((file=fopen("../sort.txt", "r"))==NULL)
    {
        printf("Errore durante l'apertura del file\n");
        return 1;
    }
    int S,i, len,j,a;
    fscanf(file,"%d",&S);
    for (i=0;i<S;i++)
    {
        fscanf(file,"%d",&len);
        int vett[len],vett2[len],vett3[len];
        for(j=0;j<len;j++)
        {
            fscanf(file,"%d",&vett[j]);
            vett2[j]=vett[j];
            vett3[j]=vett[j];
        }
        selection_sort(len,vett);
        for (a=0;a<len;a++)
            {
            printf("%d ", vett[a]);
            }
        printf("\n");
        insertion_sort(len,vett2);
        for (a=0;a<len;a++)
        {
            printf("%d ", vett2[a]);
        }
        printf("\n");
        shell_sort(len,vett3);
        for (a=0;a<len;a++)
        {
            printf("%d ", vett3[a]);
        }
        printf("\n\n");
    }
    return 0;
}