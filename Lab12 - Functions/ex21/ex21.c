#include <stdio.h>
#include <stdlib.h>

void multvet(int *p, int n, int v){

    for (int i = 0; i < n; i++)
    {
        p[i] = p[i] * v;
    }
    
}

int main(){

int n, v, *p;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

p = (int*) malloc(n * sizeof(int*));

    for (int i = 0; i < n; i++)
    {
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &p[i]);
    }

    printf("Digite o valor do escalar: ");
    scanf("%d", &v);

    printf("\nO vetor de origem eh: ");

    for (int f = 0; f < n; f++)
    {
        printf("%d", p[f]);
        if (f < n - 1)
        {
            printf(", ");
        }
        
    }

    multvet(p, n, v);
    printf("\nO vetor final eh: ");

    for (int k = 0; k < n; k++)
    {
        printf("%d", p[k]);
        if (k < n - 1)
        {
            printf(", ");
        }
        
    }

    free(p);

    return 0;
}

/*
=> Faça uma função para multiplicar um vetor por um escalar 
(um número). Mostre, no programa principal, o vetor antes e depois 
da multiplicação.

Chamada:
multvet(vetor, n, escalar);


No programa principal, solicite ao usuário o tamanho do vetor, os valores
a serem computados e o valor do escalar.

-------------------------------------------------------------------------------
Exemplo de Saída:

Digite o tamanho do vetor: 5
Digite o valor 1: 2
Digite o valor 2: 4
Digite o valor 3: 10
Digite o valor 4: 6
Digite o valor 5: 5
Digite o valor do escalar: 3

O vetor de origem eh: 2, 4, 10, 6, 5
O vetor final eh: 6, 12, 30, 18, 15
-------------------------------------------------------------------------------
*/