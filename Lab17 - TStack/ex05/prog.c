#include <stdio.h>
#include <stdlib.h>
#include<string.h>
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

         case '+':  pilha[c] = inf[i]; c++;
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

    char s[100];
    char *i;
    char *pilha;

    s[0] = '(';
    s[1] = '1';
    s[2] = '+';
    s[3] = '2';
    s[4] = '*';
    s[5] = '3';
    s[6] = ')';
    s[7] = '\0';

    i = infixaParaPosfixa(pilha,s);

    printf("%s",i);

    return 0;
}