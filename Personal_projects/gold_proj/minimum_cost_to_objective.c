#include <stdio.h>

int main(int argc, char **argv) {
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Impossibile aprire il file prezzi_oro.txt\n");
        return 1;
    }

    double prezzi[10000];
    int num_mesi = 0;
    while (fscanf(file, "%lf", &prezzi[num_mesi]) == 1) {
        num_mesi++;
    }
    fclose(file);

    int mese_inizio, anno_inizio;
    double quantita_target, spesa_mensile;
    printf("Inserisci mese e anno di inizio (mese da 1 a 12, anno da 2000): ");
    scanf("%d %d", &mese_inizio, &anno_inizio);
    printf("Inserisci la quantità target di oro in grammi: ");
    scanf("%lf", &quantita_target);
    printf("Inserisci la spesa mensile in euro: ");
    scanf("%lf", &spesa_mensile);

    int mese_corrente = (anno_inizio - 2000) * 12 + mese_inizio - 1;
    double quantita_corrente = 0.0;
    while (quantita_corrente < quantita_target && mese_corrente < num_mesi) {
        double min_prezzo = prezzi[mese_corrente];
        int mese_min_prezzo = mese_corrente;
        for (int mese = mese_corrente + 1; mese < num_mesi; mese++) {
            if (prezzi[mese] < min_prezzo) {
                min_prezzo = prezzi[mese];
                mese_min_prezzo = mese;
            }
        }
        if (min_prezzo <= spesa_mensile) {
            quantita_corrente += spesa_mensile / min_prezzo;
            printf("Hai acquistato oro nel mese %d dell'anno %d\n", mese_min_prezzo % 12 + 1, mese_min_prezzo / 12 + 2000);
        }
        mese_corrente = mese_min_prezzo + 1;
    }

    if (quantita_corrente >= quantita_target) {
        printf("Hai raggiunto il tuo obiettivo nel mese %d dell'anno %d\n", (mese_corrente - 1) % 12 + 1, (mese_corrente - 1) / 12 + 2000);
    } else {
        printf("Non hai raggiunto il tuo obiettivo. Hai acquistato %.2f grammi di oro.\n", quantita_corrente);
    }

    return 0;
}