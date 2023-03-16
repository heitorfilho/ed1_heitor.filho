#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int maior(int *p, int n){

int r = p[0];

    for (int i = 0; i < n; i++)
    {
        if (p[i] > r)
        {
            r = p[i];
        }
        
    }

    return r;

}

int menor(int *p, int n){

int r = p[0];

    for (int i = 0; i < n; i++)
    {
        if (p[i] < r)
        {
            r = p[i];
        }
        
    }

    return r;

}

int negativo(int *p, int n){

int r = 0;

    for (int i = 0; i < n; i++)
    {
        if(p[i] < 0)
        {
            r++;
        }
    }
    
return r;

}

void copia(int *X, int *Y, int n){

    for (int i = 0; i < n; i++)
    {
        Y[i] = X[i];
    }

}

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

void multvet(int *p, int n, int v){

    for (int i = 0; i < n; i++)
    {
        p[i] = p[i] * v;
    }
    
}

int main(){

int n, *p, *p2, v;

printf("Digite o tamanho do vetor: ");
scanf("%d", &n);

p = (int*) malloc(n * sizeof(int*));
p2 = (int*) malloc(n * sizeof(int*));

    for (int i = 0; i < n; i++)
    {
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &p[i]);
    }

    printf("\nVetor: ");

    for (int f = 0; f < n; f++)
    {
        printf("%d", p[f]);
        if (f < n - 1)
        {
            printf(", ");
        }
        
    }

printf("\nMaior: %d   Menor: %d\n", maior(p,n), menor(p,n));

printf("Numero de negativos: %d\n", negativo(p, n));

printf("Vetor absoluto: ");

    for (int k = 0; k < n; k++)
    {
        printf("%d", abs(p[k]));
        if (k < n - 1)
        {
            printf(", ");
        }
    }

printf("\n\nCopiando para outro vetor (alocado dinamicamente)\n");

    copia(p,p2,n);

    printf("\nVetor original: ");
    mostra(p,n);

    printf("\nVetor copiado: ");
    mostra(p2,n);

    printf("\n\nEntre com o valor escalar para multiplicar o vetor original: ");
    scanf("%d", &v);

    multvet(p, n, v);

    printf("\nVetor original: ");
    mostra(p,n);

    printf("\nVetor copiado: ");
    mostra(p2,n);
    printf("\n");

    free(p);

    return 0;
}

/*
=> Use as funções criadas nos exercícios anteriores em um único 
programa, mas agora trabalhe com vetores alocados 
dinamicamente no programa principal. Lembre-se de liberar a 
memória depois de usar os vetores.


No programa principal, solicite ao usuário o tamanho do vetor, os valores
a serem computados e posteriormente, o valor escalar para multiplicação do vetor.

-------------------------------------------------------------------------------
Exemplo de Saída:

Entre com o tamanho do vetor: 4
Entre com o elemento 1: 50
Entre com o elemento 2: 20
Entre com o elemento 3: 10
Entre com o elemento 4: -30

Vetor: 50, 20, 10, -30
Maior: 50   Menor: -30
Numero de negativos: 1
Vetor absoluto: 50, 20, 10, 30

Copiando para outro vetor (alocado dinamicamente)

Vetor original: 50, 20, 10, -30
Vetor copiado: 50, 20, 10, -30

Entre com o valor escalar para multiplicar o vetor original: 10

Vetor original: 500, 200, 100, -300
Vetor copiado: 50, 20, 10, -30
-------------------------------------------------------------------------------
*/