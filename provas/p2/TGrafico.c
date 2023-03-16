#include <stdio.h>
#include <stdlib.h>
#include "TGrafico.h"

struct TGrafico
{
    int qtd;
    struct ponto ptos[MAX];
    char nome_eixo_x[100];
    char nome_eixo_y[100];
    char titulo[100];
};


TGrafico* cria_grafico(){

}

void apaga_grafico(TGrafico* li){
}

int definir_nomes_eixos(TGrafico* li, char *eixo_x, char *eixo_y){
}

int definir_titulo(TGrafico* li, char *titulo){
}

int insere_ponto_inicio(TGrafico* li, struct ponto pto){
}

int insere_ponto_fim(TGrafico* li, struct ponto pto){
}

int mostrar_grafico(TGrafico* li){
 
}

int busca_maior(TGrafico* li){

int i;
struct ponto maior;
// check:<<<erro: e2.2 faltou testar se a lista está vazia E/OU faltou testar se a lista é null>>>>
maior = li->ptos[0];

    if (li == NULL)
    {
        return -1;
    }
    

    for (i = 0; i < li->qtd; i++)
    {
        if (li->ptos[i].y > maior.y)
        {
            maior.y = li->ptos[i].y;
        }
        
    }
    // check:<<<erro: e2.4 falta retorno da função (0 ou 1)>>>>
return maior.y;


}

int inserir(TGrafico* li, int pos, float pontox, float pontoy){

    if (li == NULL)
    {
        return -1;
    }
    if (pos >= li->qtd)
    {
        return -1;
    }
    
// check:<<<erro: e3.1 erro de teste lista nula E/OU lista cheia E/OU pos negativo E/OU pos > max>>>>
    // check:<<<erro: e3.3 não fez parte importante do exercício>>>>
    int i;

    for (i = li->qtd-1; i > pos - 1; i--)
    {
        li->ptos[i+1] = li->ptos[i];
    }
    
    li->ptos[pos-1].x = pontox;
    li->ptos[pos-1].y = pontoy;
    return 0;

}
