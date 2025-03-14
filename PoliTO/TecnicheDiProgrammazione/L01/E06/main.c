#include <stdio.h>

int main()
{
    FILE *fp_read, *fp_write;
    if ((fp_read = fopen("../Operations.txt", "r")) == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }
    if ((fp_write = fopen("../Results.txt", "w")) == NULL)
    {
        printf("Error opening file\n");
        return 2;
    }
    char operazione;
    float a, b, totale;
    while(!feof(fp_read))
    {
        do{
            operazione=fgetc(fp_read);
        }
        while(operazione=='\n');

        fscanf(fp_read, "%f", &a);
        fscanf(fp_read, "%f", &b);
        switch(operazione)
        {
            case '+':
                totale=a+b;
                fprintf(fp_write,"%c%10.2f\n",operazione,totale);
                break;
            case '-':
                totale=a-b;
                fprintf(fp_write,"%c%10.2f\n",operazione,totale);
                break;
            case '*':
                totale=a*b;
                fprintf(fp_write,"%c%10.2f\n",operazione, totale);
                break;
            case '/':
                totale=a/b;
                fprintf(fp_write,"%c%10.2f\n",operazione,totale);
                break;
            default:
                printf("Carattere sbagliato");
                return 1;
        }
    }



    fclose(fp_write);
    fclose(fp_read);
    return 0;
}
