#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX_NUMBERS 1000
#define GROUP_SIZE 12

// Funzione di confronto per qsort
int compare(const void *a, const void *b) {
    return (*(double*)b > *(double*)a) - (*(double*)b < *(double*)a);
}

int main() {
    FILE *fp;
    double numbers[MAX_NUMBERS];
    int n, i, j, groupCount;

    setbuf(stdout,0);

    // Apertura del file
    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Impossibile aprire il file.\n");
        return 1;
    }

    // Lettura dei numeri dal file
    i = 0;
    while (fscanf(fp, "%lf", &numbers[i]) == 1) {
        i++;
    }

    // Chiusura del file
    fclose(fp);

    // Richiesta del valore di n all'utente
    printf("Quanti mesi vuoi escludere(considerarli quindi come i mesi peggiori)?: ");
    scanf("%d", &n);

    // Calcolo del numero di gruppi
    groupCount = i / GROUP_SIZE;

    // Trova gli n numeri più grandi per ogni gruppo e somma i restanti numeri
    for (i = 0; i < groupCount; i++) {
        // Ordina il gruppo corrente
        qsort(&numbers[i * GROUP_SIZE], GROUP_SIZE, sizeof(double), compare);

        // Somma i restanti numeri
        double sum = 0.0;
        for (j = n; j < GROUP_SIZE; j++) {
            sum += 1/numbers[i * GROUP_SIZE + j];
        }

        // Stampa il risultato
        setlocale(LC_NUMERIC, "French_Canada.1252");
        //printf("Somma gruppo %d: %.5lf\n", i + 1, sum);
        printf("%.5lf\n", sum);
    }

    return 0;
}
