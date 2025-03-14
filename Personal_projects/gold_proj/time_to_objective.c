#include <stdio.h>

int main(int argc, char **argv) {
    // Apri il file contenente i prezzi al grammo
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Errore nell'apertura del file.\n");
        return -1;
    }

    // Variabili per l'input dell'utente
    double obiettivo;
    double investimentoMensile;
    int meseInizio;
    int annoInizio;

    // Chiedi all'utente di inserire l'obiettivo, l'importo mensile, il mese e l'anno di inizio
    printf("Inserisci l'obiettivo di investimento in grammi: ");
    scanf("%lf", &obiettivo);

    printf("Inserisci l'importo mensile in euro: ");
    scanf("%lf", &investimentoMensile);

    printf("Inserisci il mese di inizio (1-12): ");
    scanf("%d", &meseInizio);

    printf("Inserisci l'anno di inizio(da 2000): ");
    scanf("%d", &annoInizio);

    // Variabili per la lettura del file
    double prezzoGrammo;
    int mese = 1;
    int anno = 2000;
    int investimentoTotale = 0.0;
    double grammiAcquistati = 0.0;
    double prezzoGrammoTotale = 0.0;
    double prezzoMedio;

    // Cerca nel file la posizione di partenza
    while (fscanf(file, "%lf", &prezzoGrammo) == 1) {
        if (mese == meseInizio && anno == annoInizio) {
            break;
        }

        mese++;
        if (mese > 12) {
            mese = 1;
            anno++;
        }
    }

    // Leggi i prezzi al grammo dal file e calcola il tempo necessario per raggiungere l'obiettivo
    while (fscanf(file, "%lf", &prezzoGrammo) == 1) {
        investimentoTotale += investimentoMensile;
        prezzoGrammoTotale += prezzoGrammo;

        // Calcola quanti grammi possono essere acquistati con l'investimento totale
        grammiAcquistati = grammiAcquistati + (investimentoMensile/ prezzoGrammo);

        // Controlla se l'obiettivo è stato raggiunto
        if (grammiAcquistati >= obiettivo) {
            prezzoMedio = prezzoGrammoTotale/(((anno-annoInizio)*12)+mese);
            printf("Obiettivo raggiunto dopo %d anni e %d mesi (%d/%d) con un investimento di %d euro.\n"
                   "Durante questo periodo il prezzo medio e' stato di %f g/euro", anno - annoInizio, mese - meseInizio, mese, anno, investimentoTotale, prezzoMedio);
            break;
        }
        mese++;
        if (mese > 12) {
            mese = 1;
            anno++;
        }
        if (feof(file)) {
            fprintf(stderr, "Impossibile raggiungere l'obiettivo con i dati forniti.\n");
            fclose(file);
            return 1;
        }
    }

    // Chiudi il file
    fclose(file);

    return 0;
}