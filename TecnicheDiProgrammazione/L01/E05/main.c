#include <stdio.h>

int main() {
    char operazione;
    float a, b, totale;
    printf("inserisci il simbolo che indica l?operzione, +, -, * o / \n");
    operazione=getchar();
    printf("Inserisci i due valori dell'operazione: \nOperando 1:");
    scanf("%f",&a);
    printf("Operando 2: ");
    scanf("%f",&b);
    switch(operazione)
    {
        case '+':
            totale=a+b;
            printf("%c%10.2f",operazione,totale);
            return 0;
        case '-':
            totale=a-b;
            printf("%c%10.2f",operazione,totale);
            return 0;
        case '*':
            totale=a*b;
            printf("%c%10.2f",operazione, totale);
            return 0;
        case '/':        //se op2=0
            totale=a/b;
            printf("%c%10.2f",operazione,totale);
            return 0;
        default:
            printf("Carattere sbagliato");
            return 1;
    }




    return 0;
}
