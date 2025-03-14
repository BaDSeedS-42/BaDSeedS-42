#include <stdio.h>
#include <stdlib.h>

int malloc2dP(int ***mat, int nr, int nc, FILE *file);
void separa(int **mat, int nr, int nc, int **vetB, int **vetN, int *b, int *n);
void stampa(int *v, int n);

int main()
{

    FILE *file;
    int nr, nc, i, j;
    int **mat, *vetB, *vetN, *b, *n;

    /// Step 1: apriamo il file
    if ((file = fopen("mat.txt", "r")) == NULL)
    {

        printf("\nErrore durante l'aperura del file");
    }

    /// leggiamo il numero di righe e colonne

    fscanf(file, "%d %d", &nr, &nc);

    /// Step 2: carichiamo la matrice
    malloc2dP(&mat, nr, nc, file);

    if (vetB == NULL || vetN == NULL)
    {
        printf("\nC'e' stato un errore.");
    }

    separa(mat, nr, nc, &vetB, &vetN, &b, &n);

    /// Stampiamo i vettori
    printf("\nCaselle Bianche: ");
    // printf("\n vet: %d", vetB[0]);

    stampa(vetB, b);
    printf("\n\n");
    printf("Caselle Nere: ");
    stampa(vetN, n);
    printf("\n\n");

    /// Facciamo le free dei vettori allocati
    free(vetB);
    free(vetN);

    /// Free della matrice
    for (i = 0; i < nr; i++)
    {

        free(mat[i]); /// Liberiamo le righe
    }
    free(mat); /// Liberiamo il vettore di puntatori verticale

    return 0;
}

void stampa(int *v, int n)
{

    int i;

    for (i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
}

int malloc2dP(int ***mat, int nr, int nc, FILE *file)
{

    int **m; /// matrice di appoggio
    int i, j;

    /// Allocchiamo le righe
    m = (int **)malloc(nr * sizeof(int *));

    if (m == NULL)
    {
        printf("Si � verificato un Errore.");
        return;
    }

    /// Allocchiamo le colonne
    for (i = 0; i < nr; i++)
    {
        m[i] = (int *)malloc(nc * sizeof(int));

        if (m[i] == NULL)
        {
            printf("Si è verificato un Errore.");
            return;
        }
    }

    /// Carichiamo la matrice
    for (i = 0; i < nr; i++)
    {
        for (j = 0; j < nc; j++)
        {

            fscanf(file, "%d", &m[i][j]);
        }
    }

    *mat = m; /// assegniamo a mat

    fclose(file);
}

void separa(int **mat, int nr, int nc, int **vetB, int **vetN, int *b, int *n)
{

    /// Dobbiamo allocare un pezzo alla volta
    int i, j, MAXB = 1, MAXN = 1;

    int *v, *v2;

    v = malloc(MAXB * (sizeof(int)));
    v2 = malloc(MAXN * (sizeof(int)));

    int contN = 0;
    int contB = 0;

    for (i = 0; i < nr; i++)
    {

        for (j = 0; j < nc; j++)
        {

            if ((i + j) % 2 == 0) /// la somma degli indici � pari?
            {

                /// Pari
                if (contB == MAXB) /// � pieno?
                {

                    MAXB = MAXB * 2;

                    /// Riallocchiamo
                    v = realloc(v, MAXB * sizeof(int));
                }

                v[contB] = mat[i][j];

                contB++;
            }
            else
            {

                /// Dispari
                if (contN == MAXN) /// � pieno?
                {
                    MAXN = MAXN * 2;
                    /// Riallocchiamo
                    v2 = realloc(v2, MAXN * sizeof(int));
                }
                v2[contN] = mat[i][j];
                contN++;
            }
        }
    }

    *vetB = v;
    *vetN = v2;

    *b = contB;
    *n = contN;

    free(v2);
    free(v);
}
