#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

char *infixaParaPosfixa (char *pilha, char *inf) {
    int n = strlen(inf);
    char *posf; 
    char reserva;
    posf = malloc((n+1) * sizeof(char));
    pilha = malloc(100 * sizeof(char));
    pilha[0] = inf[0];
    int c = 1;
    int j = 0;
   for (int i = 1; inf[i] != '\0'; ++i) {
      switch (inf[i]) {
         char x;
         case '(': pilha[c] = inf[i]; c++;
                   break;

         case ')': c--;
                    x = pilha[c]; 
                   
                   while (x != '(') {
                      posf[j++] = x;
                      c--;
                      x = pilha[c];
                   }
                   break;

         case '+':  
                    pilha[c] = inf[i]; c++;
                    break;

         case '-':  pilha[c] = inf[i]; c++;
                    break;

         case '*':  pilha[c] = inf[i]; c++;
                    break;

         case '/':  x = pilha[c]; c--;
                   while (x != '(' && x != '+' && x != '-') {
                      posf[j++] = x;
                      x = pilha[c]; c--;
                   }
                   pilha[c] = inf[i]; c++;
                   pilha[c] = inf[i]; c++;
                   break;
         default:  posf[j++] = inf[i];
      }
   }
   posf[j] = '\0';      
   return posf;
}  

int main()
{
    char equacao1[101];
    char *equacao;
    char *pilha;
    char sinais[10];
    float valores[26];
    float num;
    char c; 

    int cont1 = 0;
    int cont2 = 0;

    printf("Digite a expressao (maximo 100 caracteres):");
    fgets(equacao1,100,stdin);
    equacao1[strcspn(equacao1, "\n")] = '\0'; 
    
    equacao = infixaParaPosfixa(pilha,equacao1);

    printf("\nExpressao digitada:\n%s",equacao);

    for (int i = 0; i< strlen(equacao); i++)
    {
        c = equacao[i];

        if (c == '+' || c == '-' || c == '*' || c == '/'){
            printf("\noperador: %c", c);
            sinais[cont1] = c; cont1++;
        } else if (c>=65 && c <= 90){ // testa se a letra é maior que A e menor que Z
            printf("\noperando: %c (%d)", c,c);
            printf("\nDigite o valor para %c = ",c);
            scanf("%f",&valores[c-65]); // letra A é mapeada na posição zero do vetor
            cont2++;
        }

    }

    float result = 0;
    cont1--;

    for (int k = cont2; k >= 0; k--)
    {
        if(k == cont2)
        {
            result = valores[k];
        }
        else{
            if(sinais[cont1] == '+')
            {
                result = result + valores[k];
            }
            else if(sinais[cont1] == '-')
            {
                result = result - valores[k];
            }
            else if(sinais[cont1] == '*')
            {
                result = result * valores[k];
            }
            else if(sinais[cont1] == '/')
            {
                result = result / valores[k];
            }
        }
    }
    
    printf("\nO Resultado eh: %.2f\n", result);

    return 0;
}