#include <stdio.h>
#include <stdlib.h>

void DesenhaLinha(int X){

char linha = '=';
int R = 0;

    while (R < X)
    {
       printf("%c", linha);
       R++;
    }
        
    printf("\n");

}

void fatorial( int *X){

int fatorial = 1, c;
c = *X;

    for (int i = 0; c > 0; i++)
    {
        fatorial = fatorial * c;
        c--;
    }

*X = fatorial;

}



int main(){

int n, f,f1;

    printf("Digite o tamanho da linha: ");
    scanf("%d", &n);
    printf("Digite o numero que deseja calcular o fatorial: ");
    scanf("%d", &f);

    f1 = f;

    fatorial(&f);

    DesenhaLinha(n);
    printf("O fatorial de %d eh %d\n",f1, f);
    DesenhaLinha(n);

    return 0;
}

/*
=> Faça uma função para calcular o fatorial de um número. Use essa função
para calcular o fatorial de um número que o usuário digitar.
Colocar todas as funções E/S (entrada e saída) no programa principal.
(use também a função DesenhaLinha – esta pode conter comandos de saída fora do programa principal). 

Ex: Fatorial(5) tem como saída 120 
    DesenhaLinha(10) tem  como saída ==========

No programa principal, solicite ao usuário o tamanho da linha a ser desenhada e o número que se
deseja calcular o fatorial.

-------------------------------------------------------------------------------
Exemplo de Saída:

Digite o tamanho da linha: 10
Digite o numero que deseja calcular o fatorial: 5
==========
O fatorial de 5 eh 120
==========
-------------------------------------------------------------------------------
*/