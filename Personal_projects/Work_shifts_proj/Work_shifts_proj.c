#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_DIPENDENTI 10
#define MAX_GIORNI 7
#define MAX_TURNI_GIORNALIERI 2

typedef struct {
    char nome[50];
    int ore_settimanali;
    int ferie[MAX_GIORNI];  // 1 se in ferie, 0 se disponibile
    int ore_assegnate;
} Dipendente;

void leggi_dipendenti(Dipendente dipendenti[], int *num_dip, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Errore nell'apertura del file %s!\n", filename);
        exit(1);
    }

    *num_dip = 0;
    while (fscanf(file, "%s %d", dipendenti[*num_dip].nome, &dipendenti[*num_dip].ore_settimanali) == 2) {
        for (int i = 0; i < MAX_GIORNI; i++) {
            fscanf(file, "%d", &dipendenti[*num_dip].ferie[i]);
        }
        dipendenti[*num_dip].ore_assegnate = 0;
        (*num_dip)++;
    }
    fclose(file);
}

void genera_turni(Dipendente dipendenti[], int num_dip) {
    srand(time(NULL));
    int turni[MAX_GIORNI][MAX_TURNI_GIORNALIERI];

    printf("\nTabella Turni Settimanale\n");
    for (int giorno = 0; giorno < MAX_GIORNI; giorno++) {
        printf("Giorno %d:\n", giorno + 1);
        int assegnati = 0;

        while (assegnati < MAX_TURNI_GIORNALIERI) {
            int index = rand() % num_dip;
            if (!dipendenti[index].ferie[giorno] && dipendenti[index].ore_assegnate < dipendenti[index].ore_settimanali) {
                dipendenti[index].ore_assegnate += 8;
                turni[giorno][assegnati] = index;
                printf(" - %s\n", dipendenti[index].nome);
                assegnati++;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso: %s <file_dipendenti>\n", argv[0]);
        return 1;
    }

    Dipendente dipendenti[MAX_DIPENDENTI];
    int num_dip = 0;

    leggi_dipendenti(dipendenti, &num_dip, argv[1]);
    genera_turni(dipendenti, num_dip);

    return 0;
}