#include <stdlib.h>
#include <stdio.h>
#include "TSULinkedList.h" 

typedef struct list_node list_node;

struct list_node
{
    struct aluno data;
    list_node *next;
};

struct TSULinkedList
{
    list_node *head;
    int size;
    int sorted;
};

TSULinkedList *list_create()
{
    TSULinkedList *list;
    list = malloc(sizeof(TSULinkedList));
    if (list != NULL)
    {
        list->head = NULL;
        list->size = 0;
        list->sorted = 0;
    }
    return list;
}

int list_push_front(TSULinkedList *list, struct aluno al)
{
    if (list == NULL)
    {
        return INVALID_NULL_POINTER;
    }

    if (list->sorted == 1)
    {
        return -5;
    }
    else
    {
        list_node *node;
        node = malloc(sizeof(list_node));
        if (node == NULL)
        {
            return OUT_OF_MEMORY;
        }
        
        node->data = al;

        if (list->size == 1 && list->head->data.matricula > node->data.matricula)
        {
            list->sorted = 1;
        }
        else
        {
            list->sorted = 0;
        }
        

        node->next = list->head;
        list->head = node;

        list->size++;

        return SUCCESS;
    }
}

int list_push_back(TSULinkedList *list, struct aluno al)
{
    if (list == NULL)
    {
        return INVALID_NULL_POINTER;
    }

    if (list->sorted == 1)
    {
        return -5;
    }

    else
    {
        list_node *node;
        node = malloc(sizeof(list_node));
        if (node == NULL)
            return OUT_OF_MEMORY;
        node->data = al;
        node->next = NULL;
        if (list->head == NULL)
        { // a lista está vazia
            list->head = node;
            list->size ++;
        }
        else
        { // a lista tem pelo menos um nó

            if (list->size == 1 && node->data.matricula > list->head->data.matricula)
            {
                list->sorted = 1;
            }

            list_node *aux;
            aux = list->head;
            while (aux->next != NULL)
            {
                aux = aux->next;
            }
            aux->next = node;
            list->size ++;
        }
        return SUCCESS;
    }
}

int list_insert(TSULinkedList *list, int pos, struct aluno al){

    if (list == NULL)
    {
        return INVALID_NULL_POINTER;
    }

    if (list->sorted == 1)
    {
        return -5;
    }

    else{

    list_node *node;

    node = malloc(sizeof(list_node));
    if (node == NULL){
        return OUT_OF_MEMORY;
    }

    node->data = al;

    list_node *aux;
    aux = malloc(sizeof(list_node));
    aux = list->head;

   for(int i = 1;i < pos-1 && aux->next != NULL; i++)
    {
        aux = aux->next;
    }

    if (list->size == 1 && pos > 1 && node->data.matricula > list->head->data.matricula)
    {
        list->sorted = 1;
    }
    else if (list->size == 1 && pos == 1 && node->data.matricula < list->head->data.matricula)
    {
        list->sorted = 1;
    }
    
    
    if (aux->next != NULL)
    {
        node->next = aux->next;
        aux->next = node;
        list->size ++;
        
    }
    else
    {
        aux->next = node;
        node->next = NULL;
        list->size ++;
    }
    
    return SUCCESS;

    }

}

int list_pop_front(TSULinkedList *list){

    if (list == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    else{

    list_node *node;
    node = malloc(sizeof(list_node));
    if (node == NULL){
        return OUT_OF_MEMORY;
    }

    node = list->head;
    list->head = node->next;
    list->size --;

    return SUCCESS;

}
}

int list_pop_back(TSULinkedList *list){

    if (list == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    else{

    int x = 1, tam = list_size(list);

    list_node *aux;
    aux = malloc(sizeof(list_node));
    if (aux == NULL){
        return OUT_OF_MEMORY;
    }

    aux = list->head;

    while (x < tam-1)
    {
        aux = aux->next;
        x++;
    }
    
    aux->next = NULL;
    list->size --;

    return SUCCESS;

}
}

int list_erase(TSULinkedList *list, int pos){

    if (list == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    else{

    list_node *aux;
    aux = malloc(sizeof(list_node));

    list_node *aux2;
    aux2 = malloc(sizeof(list_node));
    if (aux == NULL){
        return OUT_OF_MEMORY;
    }
    if (aux2 == NULL){
        return OUT_OF_MEMORY;
    }

    aux = list->head;

    if (pos == 1)
    {
        list->head = aux->next;
        return SUCCESS;
    }
    else{

    for (int i = 1; i < pos - 1 && aux->next != NULL; i++)
    {
        aux = aux->next;
    }
    
    
    aux2 = aux->next;
    aux2 = aux2->next;

    aux->next = aux2;
    list->size --;

    return SUCCESS;
    }
}
}

int list_find_pos(TSULinkedList *list, int pos, struct aluno *al){

    if (list == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    else{

    list_node *aux;
    aux = malloc(sizeof(list_node));

    if (aux == NULL){
        return OUT_OF_MEMORY;
    }

    aux = list->head;

    for (int i = 1; i < pos; i++)
    {
        aux = aux->next;
    }
    

    (*al) = aux->data;


    return SUCCESS;

    }

}

int list_find_mat(TSULinkedList *list, int nmat, struct aluno *al){

    if (list == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    else{

    list_node *aux;
    aux = malloc(sizeof(list_node));

    if (aux == NULL){
        return OUT_OF_MEMORY;
    }

    aux = list->head;

    while (aux->data.matricula != nmat && aux->next != NULL)
    {
        aux = aux->next;
    }
    
    (*al) = aux->data;

    return SUCCESS;  

    }
}

int list_front(TSULinkedList *list, struct aluno *al){

    if (list == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    else{

    list_node *aux;
    aux = malloc(sizeof(list_node));

    if (aux == NULL){
        return OUT_OF_MEMORY;
    }

    aux = list->head;

    if (aux == NULL)
    {
       return ELEM_NOT_FOUND;
    }
    

    (*al) = aux->data;
    return SUCCESS;

    }
}

int list_back(TSULinkedList *list, struct aluno *al){

    if (list == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    else{

    list_node *aux;
    aux = malloc(sizeof(list_node));

    if (aux == NULL){
        return OUT_OF_MEMORY;
    }

    aux = list->head;

    if (aux == NULL)
    {
        return ELEM_NOT_FOUND;
    }
    

    while (aux->next != NULL)
    {
        aux = aux->next;
    }
    
    (*al) = aux->data;

    return SUCCESS;

    }
}

int list_get_pos(TSULinkedList *list, int nmat, int *pos){

    if (list == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    else{

    list_node *aux;
    aux = malloc(sizeof(list_node));

    if (aux == NULL){
        return OUT_OF_MEMORY;
    }

    int contador = 1;
    aux = list->head;

    if (aux == NULL)
    {
        return ELEM_NOT_FOUND;
    }
    
    while (aux->data.matricula != nmat && aux->next != NULL)
    {
        aux = aux->next;
        contador ++;
    }
    
    (*pos) = contador;

    return SUCCESS;

    }
}

int list_print(TSULinkedList *list)
{
    if (list == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    else
    {
        list_node *aux;
        aux = list->head;
        printf("\nImprimindo a lista (tamanho %d)\n", list_size(list));

        while (aux != NULL)
        {
            printf("\n------------------\n");
            printf("Matricula: %d\n", aux->data.matricula);
            printf("Nome: %s\n", aux->data.nome);
            printf("Notas: %f; %f; %f;\n", aux->data.n1, aux->data.n2, aux->data.n3);

            aux = aux->next;
        }
        printf("\nFim da lista \n");
    }
}

int list_free(TSULinkedList *list)
{
    if (list == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    else
    {
        list_node *aux;

        aux = list->head;
        while (aux != NULL)
        {
            list->head = aux->next;
            free(aux);
            aux = list->head;
        }

        // segunda forma
        // while (list->head != NULL)
        // {
        //     aux = list->head;
        //     list->head = list->head->next;
        //     free(aux);
        // }
        free(list);
        return SUCCESS;
    }
}


int list_size(TSULinkedList *list){
    if (list == NULL){
        return INVALID_NULL_POINTER;
    } else {
        
        return list->size;
    }
}


int list_insert_sorted(TSULinkedList *list, struct aluno al){

    if (list == NULL)
        return INVALID_NULL_POINTER;

    if (list->size > 1 && list->sorted == 0)
    {
        return -5;
    }
    else{

    list_node *node;
    node = malloc(sizeof(list_node));
    if (node == NULL)
        return OUT_OF_MEMORY;
    node->data = al;

    list_node *aux, *prev;

    prev = NULL;
    aux = list->head;
    while ( (aux != NULL) && (node->data.matricula > aux->data.matricula)){
        prev = aux;
        aux = aux->next;
    }
    if (prev == NULL) { // inserção na cabeça (lista vazia ou matricula de menor de valor da lista)
        node->next = aux;
        list->head = node;
        list->size ++;
        list->sorted = 1;
    } else {
       prev->next = node;
       node->next = aux;
       list->size ++;
       list->sorted = 1;
    }
    return SUCCESS;   
    }
}