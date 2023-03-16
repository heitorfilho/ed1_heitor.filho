#include <stdio.h>
#include <stdlib.h>

int incp(float Y, float X){

float Z;
    if (Y > 0)
    {
        Z = X + ((X*Y));
        return Z;
    }
    else
    {
       Z = X - ((X*Y));
        return Z;
    }
    

}

int main(){

int i;
float y, x;

    printf("Digite o valor de y: ");
    scanf("%f",&y);
    printf("Digite o percentual de alteracao x: ");
    scanf("%f",&x);

    i = incp(x,y);

    printf("O valor alterado eh: %d\n", i);

    return 0;
}

/*
=> Faça uma função que altere um valor de um número real em x%. Se 
o valor de x for negativo ele deve ser decrementado, se for positivo 
aumente.

Uso da função: 
x = incp(y,10);
z = incp(y,-20);

-------------------------------------------------------------------------------
Exemplo de Saída 1:

Digite o valor de y: 100
Digite o percentual de alteracao: 0.10 // 0.10 equivale a 10%
O valor alterado eh: 110
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
Exemplo de Saída 2:

Digite o valor de y: -100
Digite o percentual de alteração: .10
O valor alterado eh: -110
-------------------------------------------------------------------------------
*/