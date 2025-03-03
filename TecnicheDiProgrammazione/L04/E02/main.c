#include <stdio.h>
void  ruota(int v[], int N, int P, int dir) {
    int i, j, supp;
    if (dir == 1)
    {

        for (j = 0; j < P; j++) {
            supp = v[0];
            for (i = 0; i < N - 1; i++) {
                v[i] = v[i + 1];
            }
            v[N - 1] = supp;
        }
    }
    else
        {
            for (j = 0; j < P; j++) {
                supp = v[N-1];
                for (i = N-1; i > 0; i--) {
                    v[i] = v[i - 1];
                }
                v[0] = supp;
            }

        }

    for (i = 0; i < N; i++)
    {
        printf("%d ", v[i]);
    }
}

int main()
{
    int maxN = 30, N, i, dir, P;
    printf("Inserisci la lunghezza del vettore, minore di 30:\n");
    scanf("%d", &N);
    while (N > 30 || N < 0)
    {
        printf("Valore errato, inserisci la lunghezza del vettore, minore di 30:\n");
        scanf("%d", &N);
    }
    int v[N];
    for (i = 0; i < N; i++)
    {
        printf("inserisci il valore %d:\n", i + 1);
        scanf("%d", &v[i]);
    }
    for (i = 0; i < N; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
    printf("Inserisci il verso di rotazione e di quanto ruotare il vettore. \n");
    printf("-1 per rotazione a destra e 1 per rotazione a sinistra.\n");
    scanf("%d", &dir);
    while (dir != 1 && dir != -1)
    {
        printf("Valore errato\n");
        printf("Inserisci il verso di rotazione\n");
        printf("-1 per rotazione a destra e 1 per rotazione a sinistra.\n");
        scanf("%d", &dir);
    }
    printf("Inserisci il numero di posti di cui vuoi ruotare il vettore. Inserisci 0 per terminare\n");
    scanf("%d", &P);
    while (P < 0 || P > N)
    {
        printf("Valore errato\n");
        printf("Inserisci il numero di posti di cui vuoi ruotare il vettore. Inserisci 0 per terminare\n");
        scanf("%d", &dir);
    }
    while (P != 0)
    {

        ruota(v, N, P, dir);

        printf("\n");
        printf("Inserisci il verso di rotazione e di quanto ruotare il vettore. \n");
        printf("-1 per rotazione a destra e 1 per rotazione a sinistra.\n");
        scanf("%d", &dir);
        while (dir != 1 && dir !=-1)
        {
            printf("Valore errato\n");
            printf("Inserisci il verso di rotazione\n");
            printf("-1 per rotazione a destra e 1 per rotazione a sinistra.\n");
            scanf("%d", &dir);
        }
        printf("Inserisci il numero di posti di cui vuoi ruotare il vettore. Inserisci 0 per terminare\n");
        scanf("%d", &P);
        while (P < 0 || P > N)
        {
            printf("Valore errato\n");
            printf("Inserisci il numero di posti di cui vuoi ruotare il vettore. Inserisci 0 per terminare\n");
            scanf("%d", &dir);
        }
    }
    return 0;
}