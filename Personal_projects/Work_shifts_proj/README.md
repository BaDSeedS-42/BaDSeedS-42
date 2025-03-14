# Generatore di Turni di Lavoro

Questo programma in C genera turni di lavoro settimanali per un'azienda, rispettando vincoli di ore settimanali e ferie dei dipendenti.

## Funzionamento

Il programma legge da un file di testo le informazioni sui dipendenti e genera casualmente i turni, garantendo che:

- Ogni dipendente non superi il limite di ore settimanali assegnate.
- I turni siano distribuiti in modo equo.
- I giorni di ferie dei dipendenti vengano rispettati.

## Requisiti

- Compilatore C (es. `gcc`)
- File di input con elenco dipendenti e vincoli

## Formato del File di Input

Il file dei dipendenti deve avere il seguente formato:

```
Nome Ore_settimanali Ferie[7]
Mario 40 0 0 1 0 0 0 1
Anna 32 0 1 0 0 1 0 0
```

Dove:

- `Nome`: Nome del dipendente
- `Ore_settimanali`: Numero massimo di ore a settimana
- `Ferie[7]`: Un array di 7 valori (1 per ferie, 0 per disponibilità)

## Compilazione ed Esecuzione

Compilare il programma con:

```
gcc -o turni generatore_turni.c
```

Eseguire il programma specificando il file dei dipendenti:

```
./turni dipendenti.txt
```

## Output

Il programma stamperà a schermo una tabella settimanale dei turni assegnati ai dipendenti.

## Possibili Miglioramenti

- Implementare un'interfaccia grafica.
- Aggiungere la possibilità di specificare turni di durata variabile.
- Salvare i turni generati su un file di output.
