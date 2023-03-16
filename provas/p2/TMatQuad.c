#include<stdio.h>
#include<stdlib.h>
#include "TMatQuad.h"

struct TMatQuad
{
    int *dados;
    int ordem; // ordem indica o tamanho da matriz. Por exemplo, ordem 3 indica uma matriz 3x3
};


TMatQuad* cria_matquad(int ordem){

}

void libera_matquad(TMatQuad *mat){

}

TMatQuad* cria_mat_identidade(int ordem){

    TMatQuad *mat;
// check:<<<erro: testes?>>>>
    mat = (TMatQuad*)malloc(sizeof(struct TMatQuad));
    mat->dados = (int *)malloc((ordem * ordem)*sizeof(int));
    mat->ordem = ordem;

int o = mat->ordem * mat->ordem;

int i, k;

// i = colunas
// j = linhas

    for (i = 0; i < o; i++)// check:<<<erro: i não por ir até o>>>>
    {
        for (k = 0; k < o; k++)
        {
            if (i == k)
            {
                mat->dados[k] = 1;
            }else{
                mat->dados[k] = 0;
            }
        }
        
    }
    
return mat;

}

int* copia_diagonal(TMatQuad *m){

    int *v;
    v = (int*)malloc( m->ordem * sizeof(int));

int o = m->ordem * m->ordem;
int c = 0;

int i, k;

    if (v == NULL)
    {
        return NULL;
    }
// check:<<<erro: ineficiente>>>>
     for (i = 0; i < o; i++)
    {
        for (k = 0; k < o || c < m->ordem; k++)
        {
            if (i == k)
            {
                v[c] = m->dados[k];
                c++;
            }
        
        }
    }  
    
    return v;

}
