#include <stdio.h>
#include <stdlib.h>

void imprime_vet_int(int *v, int n){

printf("Os valores inseridos neste vetor de inteiros eh: ");

    for (int i = 0; i < n; i++)
    {
        printf("%d " , v[i]);
    }
    

}

void imprime_vet_float(float *v, int n){

printf("Os valores inseridos neste vetor de float eh: ");

    for (int i = 0; i < n; i++)
    {
        printf("%.2f " , v[i]);
    }
    

}

void imprime_vet_double(double *v, int n){

printf("Os valores inseridos neste vetor de double eh: ");

    for (int i = 0; i < n; i++)
    {
        printf("%.2lf ", v[i]);
    }
    

}


int main(){

int v1[5] = {1,2,3,4,5};
float v2[5] = {1.20,2.30,3.40,4.50,5.50};
double v3[5] = {1.20,2.30,3.40,4.50,5.50};

    imprime_vet_int(v1,5);
    printf("\n");

    imprime_vet_float(v2,5);
    printf("\n");

    imprime_vet_double(v3,5);
    printf("\n");


    return 0;
}

/*
=> Crie três funções chamadas imprime_vet_int, 
imprime_vet_double, imprime_vet_float que mostra o conteúdo de 
um vetor de inteiros, double, e float, respectivamente. Use essas 
funções sempre que precisar mostrar um vetor.


Exemplo de Chamada:

    imprime_vet_int(vetori,n);
    imprime_vet_double(vetord,n);
    imprime_vet_float(vetorf,n);

-------------------------------------------------------------------------------
Exemplo de Saída:

Os valores inseridos neste vetor de inteiros eh: 1 2 3 4 5 
Os valores inseridos neste vetor de float eh: 1.20 2.30 3.40 4.50 5.50 
Os valores inseridos neste vetor de double eh: 1.20 2.30 3.40 4.50 5.50 
-------------------------------------------------------------------------------
*/