#include <stdio.h>
#include "TStack.h"

int main()
{

    int x;

    char c[100];

    c[0] = '(';
    c[1] = '(';
    c[2] = ')';
    c[3] = '[';
    c[4] = ']';
    c[5] = ')';


    x = bemFormada(c);
    printf("%d\n", x);

    return 0;
}