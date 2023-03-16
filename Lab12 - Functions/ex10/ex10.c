#include <stdio.h>
#include <stdlib.h>

typedef struct ponto
{
    float x;
    float y;
}ponto;

void imprime_ponto(ponto p){

printf("O ponto digitado eh: (%.0f,%.0f)\n", p.x,p.y);

}

int main(){

ponto x;

    printf("Digite o valor de x: ");
    scanf("%f",&x.x);
    printf("Digite o valor de y: ");
    scanf("%f",&x.y);

    imprime_ponto(x);

    return 0;
}

/*
Observação: Para os próximos exercícios, crie uma struct chamada ponto, que 
armazena dois números reais que representam coordenadas cartesianas.

=> Faça uma função chamada imprime_ponto, que recebe uma 
struct do tipo ponto e mostra na tela o ponto no seguinte formato 
(ponto.x, ponto.y)

Exemplo de chamada da função:
imprime_ponto(p)

-------------------------------------------------------------------------------
Exemplo de Saída:

Digite o valor de x: 10
Digite o valor de y: 5
O ponto digitado eh: (10,5)
-------------------------------------------------------------------------------
*/