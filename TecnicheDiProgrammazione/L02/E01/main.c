#include <stdio.h>

int main() {
    int a,b,max,min,supporto;
    printf("Inserisci due numeri interi positivi\n\n");
    printf("Inserisci il primo numero:\n");
    scanf("%d",&a);
    printf("Inserisci il secondo numero:\n");
    scanf("%d",&b);
    if(a<=b)
    {
        min=a;
        max=b;
    }
    else
    {
        min=b;
        max=a;
    }

    while (max%min!=0)
    {
        supporto=min;
        min=max%min;
        max=supporto;
    }
    printf("MCD=%d",min);



    return 0;
}
