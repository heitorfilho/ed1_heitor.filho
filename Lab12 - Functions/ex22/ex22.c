#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void absoluto(int *p, int n){

for (int i = 0; i < n; i++)
    {
        p[i] = abs(p[i]);
    }

}

int main(){

int n, *p;

printf("Digite o tamanho do vetor: ");
scanf("%d", &n);

p = (int*) malloc(n * sizeof(int*));

    for (int i = 0; i < n; i++)
    {
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &p[i]);
    }

printf("\nO vetor de origem eh: ");

    for (int f = 0; f < n; f++)
    {
        printf("%d", p[f]);
        if (f < n - 1)
        {
            printf(", ");
        }
        
    }

absoluto(p, n);

printf("\nO vetor com valores absolutos eh: ");

      for (int f = 0; f < n; f++)
    {
        printf("%d", p[f]);
        if (f < n - 1)
        {
            printf(", ");
        }
        
    }

    free(p);
    return 0;
}

/*
=> Faça uma função para transformar os números de um vetor 
de inteiros em seu valor absoluto (use a função abs (math.h)).

Chamada:
    abs_vet(vet);

No programa principal, solicite ao usuário o tamanho do vetor e os valores
a serem computados. Imprima o vetor de origem e o vetor com valores absolutos.

-------------------------------------------------------------------------------
Exemplo de Saída:

Digite o tamanho do vetor: 3
Digite o valor 1: 1
Digite o valor 2: -1
Digite o valor 3: 2

O vetor de origem eh: 1, -1, 2
O vetor com valores absolutos eh: 1, 1, 2
-------------------------------------------------------------------------------
*/