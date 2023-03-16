#include <stdio.h>
#include <stdlib.h>

void troque(int *A, int *B){

int a, b;

a = *A;
b = *B;

*A = b;
*B = a;

}

int main(){

int A, B;

    printf("Digite o numero A: ");
    scanf("%d", &A);
    printf("Digite o numero B: ");
    scanf("%d", &B);

troque(&A,&B);  

    printf("O numero A eh: %d\n", A);
    printf("O numero B eh: %d\n", B);

    return 0;
}

/*
=> Faça um procedimento “Troque”, que recebe duas variáveis reais A e B
e troca o valor delas (i.e., A recebe o valor de B e B recebe o valor de A).
Mostre no programa principal o resultado da troca. 


No programa principal, solicite ao usuário o número A e o número B.

-------------------------------------------------------------------------------
Exemplo de Saída:

Digite o número A: 2
Digite o número B: 5
O número A eh: 5
O número B eh: 2
-------------------------------------------------------------------------------
*/