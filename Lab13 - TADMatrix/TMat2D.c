// tad
#include <stdlib.h>
#include "TMat2D.h"

struct TMat2D
{
    int nrows; // númemro de linhas ;
    int ncolumns; // número de colunas;
    double *data; // dados: local onde armazena os dados da matriz
};

TMat2D *mat2D_create(int nrow, int ncol){
    TMat2D *mat;
    mat = malloc(sizeof(TMat2D));
    if (mat == NULL){
        return NULL;
    }

    mat->nrows  =  nrow;
    mat->ncolumns = ncol;
    mat->data = malloc(ncol*nrow*sizeof(double));

    //int i = 3;
    //int j = 2;
    //int pos;
    //pos = j * mat->nrows + i;
    //mat->data[0] = 9.1;


    if (mat->data == NULL){
        free(mat);
        return NULL;
    }
    
    return mat;
}

// retorna 0: sucesso
// retorna -1: erro
int mat2d_free(TMat2D *mat){
    if (mat == NULL){
        return -1;
    } else{
      free(mat->data);
      free(mat);
      return 0;
    }
}

double acessar(int nrow, int ncolums, TMat2D *mat){

double mostra;

int pos;
pos = ncolums * mat->nrows + nrow;

    if (mat == NULL)
    {
        return -1;
    }
    else
    {
        mostra = mat->data[pos];
        return mostra;
    }
    
}

int escrever (int nrow, int ncolums, TMat2D *mat, double n ){

    int pos;
    pos = ncolums * mat->nrows + nrow;

    if (pos > (mat->ncolumns * mat->nrows))
    {
        return -1;
    }
    else
    {
        mat->data[pos] = n;
        return 0;
    }
    
}

int preencher(double n1, double n2, TMat2D *mat){

double n = n1;

    if (mat->data == NULL)
    {
        return -1;
    }
    else
    {
        for (int i = 0; i < (mat->nrows * mat->ncolumns); i++)
        {
            if (n < n2)
            {
                mat->data[i] = n;
                n++;
            }else
            {
                mat->data[i] = n;
            }     
        }

        return 0;
    }

    for (int i = 0; i < (mat->nrows * mat->ncolumns); i++)
    {
        if (n <= n2)
        {
            mat->data[i] = n;
            n++;
        }else
        {
            mat->data[i] = n;
        }     
    }
    

}

int somar(TMat2D *mat1, TMat2D *mat2){

int pos;
pos = mat1->ncolumns * mat1->nrows;

    if (mat1->data == NULL || mat2->data == NULL)
    {
        return -1;
    }
    else
    {
        for (int i = 0; i < pos; i++)
        {
            mat1->data[i] = mat1->data[i] + mat2->data[i];
        }

        return 0;
        
    }
}

int multiplicar(TMat2D *mat1, TMat2D *mat2){

int pos;
pos = mat1->ncolumns * mat1->nrows;

    if (mat1->data == NULL || mat2->data == NULL)
    {
        return -1;
    }
    else
    {
        for (int i = 0; i < pos; i++)
        {
            mat1->data[i] = mat1->data[i] * mat2->data[i];
        }

        return 0;
        
    }
}

int multiplicar_escalar(TMat2D *mat1, double escalar){

int pos;
pos = mat1->ncolumns * mat1->nrows;

    if (mat1->data == NULL)
    {
        return -1;
    }
    else
    {
        for (int i = 0; i < pos; i++)
        {
            mat1->data[i] = mat1->data[i] * escalar;
        }

        return 0;
        
    }
}

double traco(TMat2D *mat){

int pos;
double soma = 0.0;

    if (mat->data == NULL)
    {
        return -1;
    }
    else
    {
        for (int i = 0; i < mat->nrows && i < mat->ncolumns; i++)
        {
            pos =  i * mat->nrows + i;
            soma = soma + mat->data[pos];
        }
        
        return soma;

    }

}

int getnrows(TMat2D *mat){

int n;

n = mat->nrows;

return n;

}

int getncolumns(TMat2D *mat){

int n;

n = mat->nrows;

return n;

}

int soma_linha(TMat2D *mat, double *v){

int nrows;
int pos;
double soma;

nrows = mat->nrows;

    if (mat == NULL)
    {
        return -1;
    }
    else
    {
        for (int i = 0; i < nrows; i++)
        {

            for (int j = 0; j < mat->ncolumns; j++)
            {
                pos = j * mat->nrows + i;
                soma = soma + mat->data[pos];
            }

            v[i] = soma;
            soma = 0.0;
        }

        return 0;
    }
}

int soma_coluna(TMat2D *mat, double *v){

int ncolumns;
int pos;
double soma;

ncolumns = mat->ncolumns;

    if (mat == NULL)
    {
        return -1;
    }
    else
    {
        for (int i = 0; i < ncolumns; i++)
        {

            for (int j = 0; j < mat->nrows; j++)
            {
                pos = i * mat->nrows + j;
                soma = soma + mat->data[pos];
            }

            v[i] = soma;
            soma = 0.0;
        }

        return 0;
    }
}


