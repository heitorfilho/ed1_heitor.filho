#include <stdlib.h>
#include <stdio.h>
#include "TLinkedList.h" 

typedef struct list_node list_node;

struct list_node
{
    struct aluno data;
    list_node *next;
};

struct TLinkedList
{
    list_node *head;
};

struct TStack{
    TLinkedList *list;
};

TLinkedList *list_create()
{
    TLinkedList *list;
    list = malloc(sizeof(TLinkedList));
    if (list != NULL)
    {
        list->head = NULL;
    }
    return list;
}

int list_push_front(TLinkedList *list, struct aluno al)
{
    if (list == NULL)
    {
        return INVALID_NULL_POINTER;
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
        node->next = list->head;
        list->head = node;

        return SUCCESS;
    }
}

int list_push_back(TLinkedList *list, struct aluno al)
{
    if (list == NULL)
    {
        return INVALID_NULL_POINTER;
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
        }
        else
        { // a lista tem pelo menos um nó
            list_node *aux;
            aux = list->head;
            while (aux->next != NULL)
            {
                aux = aux->next;
            }
            aux->next = node;
        }
        return SUCCESS;
    }
}

int list_insert(TLinkedList *list, int pos, struct aluno al){

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

    node->data = al;

    list_node *aux;
    aux = malloc(sizeof(list_node));
    aux = list->head;

   for(int i = 1;i < pos-1 && aux->next != NULL; i++)
    {
        aux = aux->next;
    }
    
    if (aux->next != NULL)
    {
        node->next = aux->next;
        aux->next = node;
        
    }
    else
    {
        aux->next = node;
        node->next = NULL;
    }
    
    return SUCCESS;

    }

}

int list_pop_front(TLinkedList *list){

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

    return SUCCESS;

}
}

int list_pop_back(TLinkedList *list){

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

    return SUCCESS;

}
}

int list_erase(TLinkedList *list, int pos){

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

    return SUCCESS;
    }
}
}

int list_find_pos(TLinkedList *list, int pos, struct aluno *al){

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

int list_find_mat(TLinkedList *list, int nmat, struct aluno *al){

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

int list_front(TLinkedList *list, struct aluno *al){

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

int list_back(TLinkedList *list, struct aluno *al){

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

int list_get_pos(TLinkedList *list, int nmat, int *pos){

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

int list_print(TLinkedList *list)
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

int list_free(TLinkedList *list)
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


int list_size(TLinkedList *list){
    if (list == NULL){
        return INVALID_NULL_POINTER;
    } else {
        int contador = 0;
        list_node *aux;
        aux = list->head;
        while (aux != NULL)
        {
            aux = aux->next;
            contador = contador + 1;
        }
        return contador;
    }
}


int list_insert_sorted(TLinkedList *list, struct aluno al){
    if (list == NULL)
        return INVALID_NULL_POINTER;
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
    } else {
       prev->next = node;
       node->next = aux;
    }
    return SUCCESS;   
}

TStack *stack_create(){
    TStack *st;
    st = malloc(sizeof(TStack));
    if (st != NULL){
        st->list = list_create();
        if (st->list == NULL){
            free(st);
            return NULL;
        }
    }
    return st;
}  

int stack_push(TStack *st, struct aluno al)
{
    if (st == NULL)
        return INVALID_NULL_POINTER;
    
    return list_push_back(st->list, al);

}

int list_print_reverse(TStack *st, TLinkedList *list){

    if (st == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    else
    {
        list_node *aux;
        aux = malloc(sizeof(list_node));
        if (aux == NULL){
        return OUT_OF_MEMORY;
        }
        aux = list->head;

        for (int i = 1; i < (list_size(list)); i++)
        {
            if (aux != NULL)
            {
                list_push_front(st->list, aux->data);
                aux = aux->next;
            }    
        }
        
        list_print(st->list);
        return SUCCESS;
    }
    
}
// check:<<<erro: e2.1 não usou o tad pilha, que era fundamental para o exercício>>>>>>>>
