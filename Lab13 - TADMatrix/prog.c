// programa principal

#include <stdio.h>
#include <stdlib.h>
#include "TMat2D.h"

void imprime(TMat2D *mat){

int nrows;
int ncolumns;

nrows = getnrows(mat);
ncolumns = getncolumns(mat);


    for (int i = 0; i <= ncolumns; i++)
    {
        for (int f = 0; f < nrows; f++)
        {
            printf("%.2lf ", acessar(f,i,mat));
        }
        
    }
    printf("\n\n");

}

int main(){

int g, g1;

double n, n1, n2, n3;

double *v, *v1;

TMat2D *x = NULL;
TMat2D *x1 = NULL;

// FUNCAO QUE CRIA UMA MATRIX

x = mat2D_create(3,4);
x1 = mat2D_create(3,4);

// FUNCAO ESCREVER UM VALOR EM UMA POSICAO DO VETOR

        n1 = acessar(2,2,x);

        printf("O antigo valor eh: %.2lf\n", n1);

        n1 = 0.0;

        if (escrever(2,2,x,2.0) == 0)
        {
            n1 = acessar(2,2,x);

            printf("O novo valor eh: %.2lf\n", n1);
        }

        else
        {
            printf("erro\n");
        }

// FUNCAO ACESSAR

    n = acessar(2,2,x);

        if (n != -1)
        {
           printf("O conteudo da posicao indicada eh: %.2lf\n\n", n);
        }
        else
        {
            printf("erro\n");
        }

// FUNCAO QUE PREENCHE A MATRIX COM VALORES ENTRE O MENOR E O MAIOR NUMERO INFORMADO 

    preencher(1.0,100.0,x);
    
    printf("A primeira matrix eh: ");
    imprime(x);

    preencher(1.0,100.0,x1);


// FUNCAO QUE SOMA DUAS MATRIZES E RETORNA O VALOR NA PRIMEIRA MATRIX

        if (somar(x,x1) != -1)
        {
            printf("A soma das duas matrizes eh: ");
            imprime(x);
        }
        else
        {
            printf("erro\n");
        }

// FUNCAO QUE MULTIPLICA UMA MATRIX PELA OUTRA

        if (multiplicar(x,x1) != -1)
        {
            printf("A multiplicacao das duas matrizes eh: ");
            imprime(x);
        }
        else
        {
            printf("erro\n");
        }


// FUNCAO MULTIPLICA MATRIX POR VALOR ESCALAR

        if (multiplicar_escalar(x,5) == 0)
        {
            printf("A matriz eh: ");
           imprime(x);

        }else
        {
            printf("erro");
        }

// FUNCAO QUE CALCULA O TRACO DA MATRIX
        
    n2 = traco(x);

        if (n2 != -1)
        {
           printf("O traco da matrix eh: %.2lf\n", n2);

        }else
        {
            printf("erro\n");
        }

// FUNCAO SOMA LINHA

g = getnrows(x);

v = malloc(g * sizeof(double));

    if (soma_linha(x,v) == 0)
    {
        printf("A soma das linhas eh: ");
        for (int i = 0; i < g; i++)
        {
            printf("%.0lf ", v[i]);
        } 
        printf("\n");
    }
    else
    {
        printf("ERRO\n");
    }
    
// FUNCAO SOMA COLUNA

g1 = getncolumns(x);

v1 = malloc(g1 * sizeof(double));

    if (soma_coluna(x,v1) == 0)
    {
        printf("A soma das colunas eh: ");
        for (int i = 0; i < g1; i++)
        {
            printf("%.0lf ", v1[i]);
        } 
        printf("\n");
    }
    else
    {
        printf("ERRO\n");
    }

    return 0;
}