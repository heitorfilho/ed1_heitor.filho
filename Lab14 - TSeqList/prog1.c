#include <stdio.h>
#include <stdlib.h>
#include "TSeqList.h"

int main(){

int n, n1;

    struct aluno a[4] = {{2,"Andre",9.5,7.8,8.5},
    {4,"Ricardo",7.5,8.7,6.8},
    {1,"Bianca",9.7,6.7,8.4},
    {3,"Ana",5.7,6.1,7.4}};

struct aluno a1 = {5,"Carlos", 7.0,8.5,9.5};

    Lista *li = NULL;
    
    li = cria_Lista();

    int i;
    
    for(i=0; i < 4; i++){
        insere_lista_ordenada(li,a[i]);
    }
    imprime_lista(li);

    printf("\n\n\n\n");

    printf("Adicionando um novo aluno\n");
    insere_lista_ordenada(li,a1);
    imprime_lista(li);

    printf("\n\n");

    n = tamanho_lista(li);
    printf("O numero de alunos eh: %d\n", n);
    printf("\n\n");

    printf("Removendo o novo aluno\n");
    remove_lista_otimizado(li,a1.matricula);
    imprime_lista(li);
    printf("\n\n");

    n1 = tamanho_lista(li);
    printf("O novo numero de alunos eh: %d", n1);
    printf("\n\n");

    for(i=0; i < 5; i++){

        if (remove_lista_otimizado(li,i)==-1){
            printf("Erro\n");
        }else{
            imprime_lista(li);
            printf("\n\n\n\n");
        }
    }

libera_lista(li);
system("pause");
return 0;
}