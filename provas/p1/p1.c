#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
--- Instruções da prova--- 
Qualquer exercício copiado de um colega ou da internet implicará nota zero em toda a prova,
 mesmo que a cópia seja feita somente de um trecho

A nota será zerada tanto para quem deixou copiar quanto para quem fez a cópia.

Não enviar o enunciado nem as respostas para os colegas

Não haverá checagem de exercício correto. 

Formate a saída de seu programa da melhor forma possível. Por exemplo, se o exercício
pede para informar o valor de um produto, escreva no printf um texto que seja adequado 
ao que for pedido:

Forma correta 
Digite o preço do produto 1: 20
Digite o preço do produto 2: 50.6

Forma errada
20
produto: 50.6

Fique atento também à saída gerada pelo programa. Escreva textos contextualizando os cálculos 
realizado e não somente mostre número Por exemplo:

Forma correta
O consumo de gasolina no mês 5 foi 50L – valor alto
O consumo de gasolina no mês 2 foi 20L – valor baixo

Forma errada
50L
50L – alto
*/



// Fazer um programa para cadastro de carros. As informações para cadastro são: 
// modelo (ex: gol, ka, c3), o ano (ex: 1999, 2015, 2021) e o consumo (ex: 10 Km/l, 7 km/l, 16 Km/l)
// Verificar no main() abaixo os exercícios da prova


// Definir as estruturas necessárias aqui:

typedef struct cadastro
{
    char modelo[20];
    int ano;
    float consumo;
}cad;

typedef struct crlv
{
    char nome[100];
    int cpf;
    cad cadastro;
}crlv;



// Função: Busca Maior Consumo (ex02)
// Essa função retorna o carro de maior consumo
// Entrada: todos os carros cadastrados 
// Saída: índice do vetor indicando a posição de maior valor
// (se houver empate pode ser retornado qualquer um dos carros)

int busca_maior (cad *p){

int maior;

    for (int i = 0; i < sizeof(p); i++)
    {
        if (p[i].consumo <= p[i+1].consumo)
        {
            maior = i;
        }
        
    }
    
return maior;

}


// Função: Índice de Eficiência (ex03)
// Essa calcula a eficiência energética de um carro
// o índice de eficiência é calculado usando a seguinte fórmula
//
//                                 ano_veiculo - 1991
//   ind = consumo (em km/l)  *  ---------------------            
//                                        30                   
//
// A função deve retornar um valor inteiro de acordo com a classificação listada na tabela abaixo.
// Valores inválidos correspondem a números negativos, zeros e ano menor que 1980 e maior que 2021
// Todos os comandos de entrada e saída devem estar no programa principal
// Todos os cálculos devem ser feitos na função.

/*
+-------------------+-----------------------------------------------+----------------+
| Retorno da Função | Valor do índice de eficiência                 | Classificação  |
+-------------------+-----------------------------------------------+----------------+
| -1                | -                                             | Valor invalido |
+-------------------+-----------------------------------------------+----------------+
| 1                 | acima ou igual 10                             | A              |
+-------------------+-----------------------------------------------+----------------+
| 2                 | acima ou igual a 8,8 e menor que 10           | B              |
+-------------------+-----------------------------------------------+----------------+
| 3                 | acima ou igual a 7,5 e menor que 8,8          | C              |
+-------------------+-----------------------------------------------+----------------+
| 4                 | abaixo de 7,5                                 | D              |
+-------------------+-----------------------------------------------+----------------+

*/

int eficiencia(cad *p){

float efic;

    efic = (p->consumo * (p->ano/30.0))/100.0;

    if (efic <= 0)
    {
        return -1;
    }
    else if (efic >= 10)
    {
        return 1;
    }
    else if (efic < 10 && efic >= 8.8)
    {
        return 2;
    }
    else if (efic < 8.8 && efic >= 7.5)
    {
        return 3;
    }
    else if (efic < 7.5)
    {
        return 4;
    }

}

// Função: Busca Maior Consumo - retorno Ponteiro (ex05)
// Essa função retorna o carro de maior consumo
// Entrada: todos os carros cadastrados 
// Saída: ponteiro para posição de vetor de maior valor
// (se houver empate pode ser retornado qualquer um dos carros)



int main(){

int quantidade, f;
char classe[20];
float indice;

cad *p;

    // Ex 01: permitir que o usuário cadastre quantos carros desejar
    //  - ler do teclado a quantidade de carros que o usuário escolheu
    //  - ler do teclado as informações dos carros 
    printf("Informe quantos carros deseja cadastrar: ");
    scanf("%d", &quantidade);
    fflush(stdin); 

p = (cad *) malloc(quantidade * sizeof (cad*));

    for (int i = 0; i < quantidade; i++)
    {
        printf("Digite o modelo do carro: ");
        gets(p[i].modelo);
        fflush(stdin); 

        printf("Digite o ano do carro: ");
        scanf("%d", &p[i].ano);
        fflush(stdin);

        printf("Digite o consumo do carro: ");
        scanf("%f", &p[i].consumo);
        fflush(stdin);
    }


printf("\n");

   // Ex02: utilizando a função de buscar o maior consumo, mostre
   // todas as informações do carro que possui o maior consumo.
   // Todas as funções de entrada e saída devem estar no programa
   // principal


f = busca_maior(&p);
    

   printf("Modelo do carro com maior consumo: %s\n", p[f].modelo);
   printf("Ano do carro com maior consumo: %d\n", p[f].ano);
   printf("Consumo do carro com maior consumo: %.2f Km/L\n", p[f].consumo);

printf("\n");

   // Ex03: utilizando a função de cálculo de eficiência de um carro
   // mostre para todos os carros o seu índice de eficiência e 
   // a sua classificação de eficiência
   // exemplo de saída:
   // Ford Ka - 2020 - 10 km/l; Indice: 9.7; Classificação: B

   for (int k = 0; k < quantidade; k++)
   {
       if (eficiencia(&p[k]) == -1)
       {
           strncpy( classe,"Valor invalido", 20);
           classe[strcspn(classe, "\n")] = '\0'; 
           fflush(stdin);
       }
       else if (eficiencia(&p[k]) == 1)
       {
           strncpy(classe, "A", 20);
           classe[strcspn(classe, "\n")] = '\0'; 
           fflush(stdin);
       }
       else if (eficiencia(&p[k]) == 2)
       {
           strncpy(classe, "B", 20);
           classe[strcspn(classe, "\n")] = '\0'; 
           fflush(stdin);
       }
       else if (eficiencia(&p[k]) == 3)
       {
           strncpy(classe, "C", 20);
           classe[strcspn(classe, "\n")] = '\0'; 
           fflush(stdin);
       }
       else if (eficiencia(&p[k]) == 4)
       {
           strncpy(classe, "D", 20);
           classe[strcspn(classe, "\n")] = '\0'; 
           fflush(stdin);
       }

    indice = (p[k].consumo * (p[k].ano/30.0)) / 100.0;
    
    printf("%s - %d - %.1f Km/L; Indice: %.1f; Classificacao: %s\n", p[k].modelo, p[k].ano, p[k].consumo, indice, classe);       
       
   }

   // Ex04: Crie uma estrutura para guardar informações sobre o
   // documento de um carro CRLV (Certificado de Registro e
   //  Licenciamento de Veículo)
   // Nesse documento deverá ter o Nome, CPF, e as informações
   // do carro (deve-se utilizar a estrutura dos exercícios anteriores)
   // Crie uma variável dessa estrutura e inicialize ela com valores 
   // constantes (não precisa ler do teclado) e depois mostre esses valores
 
 crlv cadastro = {"Joao Pereira", 123456789, "Ford KA", 2020, 10.0 };

printf("\n\n");

    printf("O cadastro e Nome: %s\n", cadastro.nome);
    printf("CPF: %d\n", cadastro.cpf);
    printf("Modelo: %s\n",cadastro.cadastro.modelo); 
    printf("Ano: %d\n",cadastro.cadastro.ano);
    printf("Consumo: %.1f\n",cadastro.cadastro.ano);

   // Ex05: Duplique o exercício 2 e modifique ele para que ao invés de 
   // retornar o índice da posição do vetor que retorne um ponteiro
   // para a posição do vetor. Mostre no programa principal os dados
   // do carro utilizando o ponteiro retornado.
   
   free(p);
    return 0;
}