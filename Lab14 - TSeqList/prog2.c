#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "TVarSeqList.h"

int main(){

int n, n1, n2, n3;

    struct aluno a[4] = {{2,"Andre",9.5,7.8,8.5},
    {4,"Ricardo",7.5,8.7,6.8},
    {1,"Bianca",9.7,6.7,8.4},
    {3,"Ana",5.7,6.1,7.4}};

struct aluno a1 = {5,"Carlos", 7.0,8.5,9.5};

    Lista *li = NULL;

    li = cria_Lista(4);

    int i;
    
    for(i=0; i < 4; i++){
        insere_lista_ordenada(li,a[i]);
    }
    imprime_lista(li);

    printf("\n\n\n\n");

    n2 = tamvet(li);
    printf("A lista possue %d posicoes maximas\n",n2);

    printf("Adicionando um novo aluno\n\n");
    insere_lista_ordenada(li,a1);
    imprime_lista(li);

    printf("\n\n");

    n = tamvet(li);
    printf("A lista agora possue %d posicoes maximas\n", n);
    printf("\n\n");

    printf("Removendo o novo aluno\n\n");
    remove_lista_otimizado(li,a1.matricula);
    imprime_lista(li);

    n1 = tamvet(li);
    printf("A lista possue %d posicoes maximas", n1);
    printf("\n\n");

    compactar_lista(li);
    n3 = tamvet(li);
    imprime_lista(li);
    printf("A lista compactada agora possue %d posicoes maximas\n", n3);

free(li);

return 0;
}