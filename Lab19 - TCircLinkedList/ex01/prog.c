#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TCircLinkedList.h"

int main()
{
    CircList *list;
    struct aluno a = {1,"JOAO",10,10,10};
    struct aluno b = {1,"MARIA",10,10,10};

    list = list_create();

    list_push_back(list, a);

    list_push_back(list, b);

    list_print(list);

    return 0;
}