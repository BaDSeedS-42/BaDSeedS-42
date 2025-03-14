# 🏅 Gold_proj

Questa cartella contiene una serie di algoritmi in C per l'analisi degli investimenti in oro. Gli script analizzano dati storici e forniscono informazioni utili per ottimizzare gli acquisti.

## 📂 File Contenuti

### 1️⃣ **time_to_objective.c**
- Calcola il tempo necessario per raggiungere un obiettivo di investimento in oro, dato un importo mensile.
- **Input**: Un file contenente i prezzi storici dell'oro.
- **Output**: Il numero di mesi necessari per raggiungere l'obiettivo.

### 2️⃣ **minimum_cost_to_objective.c**
- Trova il modo più economico per acquistare una quantità target di oro.
- **Input**: Un file di prezzi storici e parametri dell'utente.
- **Output**: I mesi migliori per acquistare oro al costo più basso.

### 3️⃣ **proj_gold.c**
- Analizza i mesi peggiori e migliori per l'acquisto di oro.
- **Input**: Un file con i prezzi storici.
- **Output**: Suggerimenti basati sulla distribuzione dei prezzi.

## 📌 Utilizzo

Compila ed esegui i programmi con:
```bash
gcc nomefile.c -o nomefile.out
./nomefile.out
```
Se il programma richiede un file di input, specificalo in fase di esecuzione:
```bash
./time_to_objective.out input_time_to_objective.txt
```

## 🚀 Contributi & Feedback
Se vuoi migliorare il codice o proporre nuove funzionalità, sentiti libero di aprire una issue o fare un fork del progetto!
