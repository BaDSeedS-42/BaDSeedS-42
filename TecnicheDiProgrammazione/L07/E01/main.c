//VERSIONE 1

#include <stdio.h>

typedef struct{
    int riga;
    int colonna;
    int altezza;
    int base;
    int area;
}struct_vettore;

typedef enum {altezza, base, area} dimensione;

//funzione che crea una matrice con i valori da file
int leggitabella(int nr,int nc, int tabella[nr][nc],FILE *file)
{
    int j,i;
    for(i=0;i<nr;i++)
    {
        for(j=0;j<nc;j++)
        {
            fscanf(file,"%d",&tabella[i][j]);
        }
    }
}

void inizializza_vettore(int dim,struct_vettore vettore[dim])
{
    int i;
    for (i=0;i<dim;i++)
    {
        vettore[i].colonna=-2;
        vettore[i].riga=-2;
        vettore[i].altezza=0;
        vettore[i].base=0;
        vettore[i].area=0;
    }
}

//funzione che carica un vettore di struct con le lunghezze dei segmenti verticali con la loro coordinata più in alto
void trova_altezze(int nr, int nc, int tabella[nr][nc],struct_vettore vettore[nr*nc])
{
    int i,j,a=-1,b,flag=1;
    int dim=nr*nc;
    inizializza_vettore(dim, vettore);
    for (j=0;j<nc;j++)
    {
        for(i=0;i<nr;i++)
        {
            if(tabella[i][j]==1)
            {
                flag=1;
                for (b = 0; b < dim; b++)
                {
                    if (i == vettore[b].riga &&  vettore[b].colonna==  j- 1)
                    {
                        flag = 0;
                        b=dim;
                    }
                }
                if(flag==1)
                {
                    a++;
                    vettore[a].riga=i;
                    vettore[a].colonna=j;
                    while(tabella[i][j]==1)
                    {
                        vettore[a].altezza++;
                        i++;
                    }
                }
                else
                {
                    while(tabella[i][j]==1)
                    {
                        i++;
                    }
                }
            }
        }
    }
}

//funzione che carica un vettore di struct con le lunghezze dei segmenti orizzontali con la loro coordinata più a sinistra
void trova_lunghezze(int nr, int nc, int tabella[nr][nc],struct_vettore vettore[nr*nc])
{
    int i,j,t;
    for(t=0;t<nr*nc;t++)
    {
        i=vettore[t].riga;
        j=vettore[t].colonna;
        while(tabella[i][j]==1)
        {
            vettore[t].base++;
            j++;
        }
    }

}

//funzione che calcola le aree delle zone nere
void calcola_aree(int dim, struct_vettore vettore[dim])
{
    int i;
    for (i=0;i<dim;i++)
    {
        if(vettore[i].riga!=-2)
        {
            vettore[i].area=vettore[i].base*vettore[i].altezza;
        }
        else
        {
            i=dim;
        }
    }
}

//funzione che trova il massimo del primo parametro inserito e i corrispondenti altri due parametri
void trovamax(dimensione x,int dim, struct_vettore vettore[dim])
{
    int i,max=0,hold;
    switch(x)
    {
        case altezza:
        {
            for(i=0;i<dim;i++)
            {
                if(vettore[i].altezza>max)
                {
                    max=vettore[i].altezza;
                    hold=i;
                }
            }
            printf("Max Altezza: estr. sup. SX=<%d,%d> b=%d, h=%d, Area=%d\n",vettore[hold].riga,vettore[hold].colonna,vettore[hold].base,vettore[hold].altezza,vettore[hold].area);
            break;
        }
        case base:
        {
            for(i=0;i<dim;i++)
            {
                if(vettore[i].base>max)
                {
                    max=vettore[i].base;
                    hold=i;
                }
            }
            printf("Max Base: estr. sup. SX=<%d,%d> b=%d, h=%d, Area=%d\n",vettore[hold].riga,vettore[hold].colonna,vettore[hold].base,vettore[hold].altezza,vettore[hold].area);
            break;
        }
        case area:
        {
            for(i=0;i<dim;i++)
            {
                if(vettore[i].area>max)
                {
                    max=vettore[i].area;
                    hold=i;
                }
            }
            printf("Max Area: estr. sup. SX=<%d,%d> b=%d, h=%d, Area=%d\n",vettore[hold].riga,vettore[hold].colonna,vettore[hold].base,vettore[hold].altezza,vettore[hold].area);
            break;
        }
    }
}


int main() {
    FILE *file;
    int nr, nc;
    if((file=fopen("../mappa.txt","r"))==NULL)
    {
        printf("errore di apetura del file\n");
        return 1;
    }
    fscanf(file,"%d%d",&nr,&nc);
    //printf("%d  %d\n",nr, nc);
    int tabella[nr][nc];
    leggitabella(nr,nc,tabella,file);

    int dim=nr*nc;
    struct_vettore vettore[dim];
    trova_altezze(nr,nc,tabella, vettore);
    trova_lunghezze(nr,nc,tabella, vettore);
    calcola_aree(dim,vettore);

    trovamax(base,dim,vettore);  //max base
    trovamax(area,dim,vettore);  //max area
    trovamax(altezza,dim,vettore);  //max altezza

    return 0;
}


/*VERSIONE 2, CREATA DOPO IL LAB 8

#include <stdio.h>
#define MAXR 50

void leggitabella(int tabella[MAXR][MAXR], int *pr, int *pc, FILE *file)
{
    int j,i;
    fscanf(file,"%d%d",pr,pc);
    for(i=0;i<*pr;i++)
    {
        for(j=0;j<*pc;j++)
        {
            fscanf(file,"%d",&tabella[i][j]);
        }
    }

}

int riconosciRegione(int tabella[MAXR][MAXR], int nr, int nc, int c, int r, int *pb, int *ph)
{
    int i=0,j=0;
    if (tabella[r][c]==1)
    {
        if(r==0)
        {
            if(c==0)
            {
                while(tabella[r+i][c]==1 && r+i<nr)
                {
                    (*ph)++;
                    i++;
                }
                while(tabella[r][c+j]==1 && c+j<nc)
                {
                    (*pb)++;
                    j++;
                }
                return 1;
            }
            else
            {
                if(tabella[r][c-1]==0)
                {
                    while(tabella[r+i][c]==1 && r+i<nr)
                    {
                        (*ph)++;
                        i++;
                    }
                    while(tabella[r][c+j]==1 && c+j<nc)
                    {
                        (*pb)++;
                        j++;
                    }
                    return 1;
                }
            }
        }
        else
        {
            if(tabella[r-1][c]==0)
            {
                if(c==0)
                {
                    while(tabella[r+i][c]==1 && r+i<nr)
                    {
                        (*ph)++;
                        i++;
                    }
                    while(tabella[r][c+j]==1 && c+j<nc)
                    {
                        (*pb)++;
                        j++;
                    }
                    return 1;
                }
                else
                {
                    if(tabella[r][c-1]==0)
                    {
                        while(tabella[r+i][c]==1 && r+i<nr)
                        {
                            (*ph)++;
                            i++;
                        }
                        while(tabella[r][c+j]==1 && c+j<nc)
                        {
                            (*pb)++;
                            j++;
                        }
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}
typedef struct{
    int riga;
    int colonna;
    int altezza;
    int base;
    int area;
}massimo;

int main()
{
    FILE *file;
    int nr, nc, area;

    if((file=fopen("../mappa.txt","r"))==NULL)
    {
        printf("errore di apertura del file\n");
        return 1;
    }

    //printf("%d  %d\n",nr, nc);
    int tabella[MAXR][MAXR];
    leggitabella(tabella,&nr,&nc,file);
    int c,r,b,h;
    massimo maxa, maxb,maxh;
    maxa.area=0;
    maxb.base=0;
    maxh.altezza=0;
    for(r=0;r<nr;r++)
    {
        for(c=0;c<nc;c++)
        {
            b=0;
            h=0;
            if(riconosciRegione(tabella,nr,nc,c,r,&b,&h))
            {
                area=b*h;
                if(maxa.area<area)
                {
                    maxa.area=area;
                    maxa.base=b;
                    maxa.altezza=h;
                    maxa.riga=r;
                    maxa.colonna=c;
                }
                if(maxb.base<b)
                {
                    maxb.area=area;
                    maxb.base=b;
                    maxb.altezza=h;
                    maxb.riga=r;
                    maxb.colonna=c;
                }
                if(maxh.altezza<h)
                {
                    maxh.area=area;
                    maxh.base=b;
                    maxh.altezza=h;
                    maxh.riga=r;
                    maxh.colonna=c;
                }
            }
        }
    }
    printf("Max Base: estr. sup. SX=<%d,%d> b=%d, h=%d, Area=%d\n",maxb.riga,maxb.colonna,maxb.base,maxb.altezza,maxb.area);
    printf("Max Area: estr. sup. SX=<%d,%d> b=%d, h=%d, Area=%d\n",maxa.riga,maxa.colonna,maxa.base,maxa.altezza,maxa.area);
    printf("Max Altezza: estr. sup. SX=<%d,%d> b=%d, h=%d, Area=%d\n",maxh.riga,maxh.colonna,maxh.base,maxh.altezza,maxh.area);
    return 0;
}
 */