#include <stdio.h>
#include <stdlib.h>

double maior(double *p, int n){

double r = p[0];

    for (int i = 0; i < n; i++)
    {
        if (p[i] > r)
        {
            r = p[i];
        }
        
    }

    return r;

}

double menor(double *p, int n){

double r = p[0];

    for (int i = 0; i < n; i++)
    {
        if (p[i] < r)
        {
            r = p[i];
        }
        
    }

    return r;

}

int main(){

int n;
double *p;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

p = (double*) malloc(n * sizeof(double*));

    for (int i = 0; i < n; i++)
    {
        printf("Digite o valor %d: ", i + 1);
        scanf("%lf", &p[i]);
    }
    
    printf("\nO vetor principal eh: ");

    for (int f = 0; f < n; f++)
    {
        printf("%.2f", p[f]);
        if (f < n - 1)
        {
            printf(", ");
        }
        
    }
    
   printf("\nO maior valor eh %.2lf\n", maior(p,n));

   printf("O menor valor eh %.2lf\n", menor(p,n));


    free(p);
    return 0;
}

/*
=> Crie um procedimento que recebe um vetor de double como 
entrada e devolve o maior e o menor elemento do vetor. Mostre no 
programa principal o vetor, o maior e o menor elemento.


No programa principal, solicite ao usuário o tamanho do vetor, e os
valores a serem computados.

-------------------------------------------------------------------------------
Exemplo de Saída:

Digite o tamanho do vetor: 3
Digite o valor 1: -1
Digite o valor 2: 0.02
Digite o valor 3: 3

O vetor principal eh: -1.00, 0.02, 3.00
O maior valor eh 3.00
O menor valor eh -1.00
-------------------------------------------------------------------------------
Obs: note que para este caso, foram consideradas duas casas após o ponto. 
*/