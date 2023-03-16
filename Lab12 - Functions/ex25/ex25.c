#include <stdio.h>
#include <stdlib.h>

void imprime_vet(double*p, int n){

for (int f = 0; f < n; f++)
    {
        printf("%.2lf", p[f]);
        if (f < n - 1)
        {
            printf(", ");
        }
        
    }

}

int copia(double *X, int n){

double *Y;

Y = (double*) calloc(n , sizeof(double*));

    for (int i = 0; i < n; i++)
    {
        Y[i] = X[i];
    }

return Y;

}


int main(){

    double v1[5] = {1.20, 2.00, 3.20, 4.00, 5.10}, *vet_destino;

    printf("O vetor de origem eh: ");
    imprime_vet(v1, 5);

    vet_destino = copia(v1, 5);
    printf("\nO vetor de destino eh: ");
    imprime_vet(vet_destino,5);

    printf("\n");

    free(vet_destino);

    return 0;
}

/*
=> Faça uma função que copia um vetor de double para um 
outro vetor. Esse outro vetor é alocado dentro da função que faz a 
cópia. Mostre os dois vetores.

Chamada:
vet_destino  = copiarvet(vet_origem,  n);

-------------------------------------------------------------------------------
Exemplo de Saída:

O vetor de origem eh: 1.20, 2.00, 3.20, 4.00, 5.10
O vetor de destino eh: 1.20, 2.00, 3.20, 4.00, 5.10
-------------------------------------------------------------------------------
*/