#include <stdio.h>
# include <stdlib.h>

int Quadrado(int X, int n){

int quadrado = 1;

    for (int i = 0; i < n; i++)
    {
        quadrado = quadrado * (X);
    }

return quadrado;

}

int main(){

int x, n;

    printf("Digite o valor de x: ");
    scanf("%d", &x);
    printf("Digite o valor de n: ");
    scanf("%d", &n);

    printf("O valor de %d elevado a %d eh %d\n", x, n, Quadrado(x,n));

    return 0;
}

/*
=> Faça uma função para calcular xn. Não utilizar o operador pow (nem ^ - que não existe em C).
No programa principal permita ao usuário informar o valor de x e de n (inteiro). 
Lembre que n pode assumir valor negativo.

Ex: Elevado(2,4) tem como saída 16; 
    

No programa principal, solicite ao usuário o valor de x e o valor de n.

-------------------------------------------------------------------------------
Exemplo de Saída:

Digite o valor de x: 2
Digite o valor de n: 4
O valor de 2 elevado a 4 eh 16
-------------------------------------------------------------------------------
*/