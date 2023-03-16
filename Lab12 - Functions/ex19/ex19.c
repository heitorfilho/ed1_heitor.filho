#include <stdio.h>
#include <stdlib.h>

int negativos(float *X, int n){

int r = 0;

    for (int i = 0; i < n; i++)
    {
        if (X[i] < 0)
        {
            r++;
        }
        
    }
    

return r;

}

int main(){

int n;
float *p;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

p = (float*) malloc(n * sizeof(float*));

    for (int i = 0; i < n; i++)
    {
        printf("Digite o valor %d: ", i + 1);
        scanf("%f", &p[i]);
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

    printf("\nO vetor tem %d numero(s) negativo(s)\n", negativos(p,n));

    free(p);
    return 0;
}

/*
=> Implemente uma função que receba como parâmetro um 
vetor de n números reais (VET) de tamanho N e retorne quantos 
números negativos há a nesse vetor. Use o seguinte protótipo:

int negativos(float *vet, int N); 

No programa principal, solicite ao usuário o tamanho do vetor, e os
valores a serem computados.
-------------------------------------------------------------------------------
Exemplo de Saída:

Digite o tamanho do vetor: 3
Digite o valor 1: -1
Digite o valor 2: 3
Digite o valor 3: -2

O vetor principal eh: -1.00, 3.00, -2.00
O vetor tem 2 numero(s) negativo(s)
-------------------------------------------------------------------------------
*/