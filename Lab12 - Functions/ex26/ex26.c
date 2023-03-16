#include <stdio.h>
#include <stdlib.h>

void mostra(int *p, int n){

for (int f = 0; f < n; f++)
    {
        printf("%d", p[f]);
        if (f < n - 1)
        {
            printf(", ");
        }
        
    }

}

void converte(double *p1, int *p, int n){

    for (int i = 0; i < n; i++)
    {
        p1[i] = (double) p[i];
    }
    

}

int main(){

int *p, n;
double *p1;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    p = (int*) malloc(n * sizeof(int*));
    p1 = (double*) malloc(n * sizeof(double*));
    
        for (int i = 0; i < n; i++)
        {
            printf("Digite o valor %d: ", i + 1);
            scanf("%d", &p[i]);
        }

    printf("\nO vetor de origem eh: ");
    mostra(p,n);

    printf("\nO vetor convertido para double eh: ");
    converte(p1,p,n);

    for (int f = 0; f < n; f++)
    {
        printf("%.2lf", p1[f]);
        if (f < n - 1)
        {
            printf(", ");
        }
        
    }

    free(p);
    free(p1);

    return 0;
}

/*
=> Faça a função to_double, que recebe um vetor de inteiro e 
retorna um vetor com o mesmo conteúdo, mas convertido para 
double.

Chamada:
vet_double = to_double(vet_int,n);

-------------------------------------------------------------------------------
Exemplo de Saída:

Digite o tamanho do vetor: 4
Digite o valor 1: 1
Digite o valor 2: 3
Digite o valor 3: 5
Digite o valor 4: 4

O vetor de origem eh: 1, 3, 5, 4
O vetor convertido para double eh: 1.00, 3.00, 5.00, 4.00
-------------------------------------------------------------------------------
*/