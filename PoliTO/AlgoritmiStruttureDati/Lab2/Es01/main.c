#include <stdio.h>
#include <stdlib.h>


int gcd(int a, int b);
///Massimo Comune Divisore M.C.D.
///Fase ricorsiva composta da due parti:
///Discesa
///Risalita


int main()
{

    int a,b;


    printf("\nInserisci il numero a-->");
    scanf("%d", &a);

    printf("\nInserisci il numero b-->");
    scanf("%d", &b);

    printf("\nHai inserito i numeri a: %d e b: %d", a,b);


    int mcd =gcd(a,b);

    printf("\n\n-----------------------------------------------------");
    printf("\nIl Massimo Comune Divisore e': %d\n\n", mcd);

    return 0;
}

///*****************************************************
///FUNZIONE RICORSIVA

int gcd(int a, int b){

    int temp;

    ///1.Condizione di terminazione
    if(a==b)
        return a;

    if(a<b) ///Scambio, teniamo sott'occhio i due valori
    {
        temp =a;
        a=b;
        b=temp;
    }

    ///2.Vari casi (IN DISCESA: passiamo il lavoro all'istanza sottostante, IN SALITA: ritorniamo il valore all'istanza superiore)

    if(a%2==0 && b%2==0)
        return 2*gcd((a/2), (b/2));
    if(a%2!=0 && b%2==0)
        return gcd(a, (b/2));
    if(a%2==0 && b%2!=0)
        return gcd((a/2), b);
    if(a%2!=0 && b%2!=0)
        return gcd((a-b)/2, b);

}




