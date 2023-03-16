#include <stdio.h>
#include <stdlib.h>

void copia(int *X, int *Y, int n){

    for (int i = 0; i < n; i++)
    {
        Y[i] = X[i];
    }

}

int main(){

int v1[5] = {1,2,3,4,5}, v2[5] = {1,2,3,3,6};

    printf("O vetor de origem eh: ");

    for (int i = 0; i < 5; i++)
    {
        if(i < 4)
        {
        printf("%d, ", v1[i]);
        }else
        {
        printf("%d\n", v1[i]);
        }
    }
    
    printf("O vetor de destino eh: ");

    for (int j = 0; j < 5; j++)
    {
        if(j < 4)
        {
        printf("%d, ", v2[j]);
        }else
        {
        printf("%d\n", v2[j]);
        }
        
    }

    printf("O vetor de destino apos a copia eh: ");
    copia(v1,v2,5);

     for (int k = 0; k < 5; k++)
    {
        if(k < 4)
        {
        printf("%d, ", v2[k]);
        }else
        {
        printf("%d\n", v2[k]);
        }
    }

    return 0;
}

/*
=> Faça uma função para copiar um vetor inteiro para outro 
vetor. Ambos vetores devem ter o mesmo tamanho. Mostre no 
programa principal os dois vetores.

Chamada:
copiarvet(vet_origem, vet_destino, n);


Os valores são definidos na função principal.
-------------------------------------------------------------------------------
Exemplo de Saída:

O vetor de origem eh: 1, 2, 3, 4, 5
O vetor de destino eh: 1, 2, 3, 3, 6
O vetor de destino apos a copia eh: 1, 2, 3, 4, 5
-------------------------------------------------------------------------------
*/