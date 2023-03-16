#include <stdio.h>
#include <stdlib.h>
#include "TGrafico.h"
#include "TMatQuad.h"

int main(){ 

    TGrafico *grafico = NULL;
    struct ponto pontos[MAX];// check:<<<erro: e1.5 Não precisa alocar um vetor só para ler todos os pontos. A própria lista da estrutura é quem armazena os pontos>>>>

    grafico = cria_grafico();

    int npontos;
    int pos;
    float novox;
    float novoy;

    char nome_x[100];
    char nome_y[100];
    char titulo[100];

    float maior;

    printf("Digite o nome do eixo x: ");
    gets(nome_x);

    printf("Digite o nome do eixo y: ");
    gets(nome_y);

    definir_nomes_eixos(grafico, nome_x, nome_y);

    printf("Digite o nome do titulo: ");
    gets(titulo);
    definir_titulo(grafico,titulo);

    printf("Digite quantos pontos deseja inserir na lista: ");
    scanf("%d", &npontos);

    for (int i = 0; i < npontos; i++)
    {
        printf("Digite a coordenada (x) do ponto %d: ", i+1);
        scanf("%f", &pontos[i].x);
        printf("Digite a coordenada (y) do ponto %d: ", i+1);
        scanf("%f", &pontos[i].y);
    }
    
    insere_ponto_inicio(grafico,*pontos);// check:<<<erro: essa função deveria estar dentro do laço e ser inserção no final>>>>
    insere_ponto_inicio(grafico,*pontos);

    mostrar_grafico(grafico);
    // check:<<<erro: e1.8 Faltou chamar a função que apaga o gráfico>>>>

    maior = busca_maior(grafico);

    if (maior == -1)
    {
        printf("ERRO\n");
    }

    for (int i = 0; i < npontos; i++)
    {
        if (maior == pontos[i].y)
        {
            printf("Maior valor: %.0f (ponto x=%.0f;y=%.0f)", maior, pontos[i].x,pontos[i].y);
        }
        
    }
    
    printf("Digite a posicao em que o ponto sera inserido: ");
    scanf("%d", &pos);

    printf("Digite a coordenada (x) do ponto %d: ", pos);
    scanf("%f", &novox);

    printf("Digite a coordenada (x) do ponto %d: ", pos);
    scanf("%f", &novoy);

    inserir(grafico,pos,novox,novoy);

    TMatQuad *m = NULL;
    int *v = NULL;

    m = cria_mat_identidade(3);
    v = copia_diagonal(m);

    printf("Os valores presentes nas diagonas sao: ");

    for (int i = 0; i < 3; i++)
    {
        printf("%d ", v[i]);
    }

}