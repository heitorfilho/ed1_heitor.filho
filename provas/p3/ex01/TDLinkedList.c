#include <stdlib.h>
#include <stdio.h>
#include "TDLinkedList.h"

typedef struct DLNode DLNode;

struct DLNode
{
    struct aluno data;
    DLNode *prev;
    DLNode *next;
};

// estrutura do descritor da lista
struct TDLinkedList
{
    DLNode *begin;
    DLNode *end;
    int size;
};

TDLinkedList *list_create()
{
    TDLinkedList *list;
    list = malloc(sizeof(TDLinkedList));
    if (list != NULL)
    {
        list->begin = NULL;
        list->end = NULL;
        list->size = 0;
    }
    return list;
}

int list_push_front(TDLinkedList *list, struct aluno al)
{
    if (list == NULL)
        return INVALID_NULL_POINTER;

    DLNode *node;
    node = malloc(sizeof(DLNode));
    if (node == NULL)
        return OUT_OF_MEMORY;

    node->data = al;
    node->prev = NULL;
    node->next = list->begin;

    if (list->begin == NULL)
    { // a lista está vazia
        list->begin = node;
        list->end = node;
        list->size = 1;
    }
    else
    { // a lista possui um nó
        list->begin->prev = node;
        list->begin = node;
        list->size++;
    }
    return SUCCESS;
}

int list_push_back(TDLinkedList *list, struct aluno al){

    if (list == NULL){
        return INVALID_NULL_POINTER;
    }

    DLNode *node;
    node = malloc(sizeof(DLNode));
    if (node == NULL){
        return OUT_OF_MEMORY;
    }

    node->data = al;
    node->next = NULL;

    if (list->begin == NULL)
    { 
        list->begin = node;
        list->end = node;
        list->size = 1;
        node->prev = NULL;
    }
    else
    { 
        node->prev = list->end;
        list->end->next = node;
        list->end = node;
        list->size ++;
    }
    
    return SUCCESS;

}

int list_size(TDLinkedList *list){

    if (list == NULL){
        return INVALID_NULL_POINTER;
    }

    return list->size;
}

int list_pop_front(TDLinkedList *list){

    if (list == NULL){
        return INVALID_NULL_POINTER;
    }

    if (list->begin == NULL)
    {
        return ELEM_NOT_FOUND;
    }

    else if (list->begin->next == NULL)
    {
        list->begin = NULL;
        list->end = NULL;
        list->size = 0;
        return SUCCESS;
    }
    else
    {
        DLNode *aux;
        aux = malloc(sizeof(DLNode));
        if (aux == NULL){
            return OUT_OF_MEMORY;
        }

        aux = list->begin;
        aux = aux->next;
        aux->prev = NULL;
        list->begin = aux;
        list->size --;
        
        return SUCCESS;
    }
    
}

int list_pop_back(TDLinkedList *list){

    if (list == NULL){
        return INVALID_NULL_POINTER;
    }

    if (list->begin == NULL)
    {
        return ELEM_NOT_FOUND;
    }
    else if (list->begin->next == NULL)
    {
        list->begin = NULL;
        list->end = NULL;
        list->size = 0;
        return SUCCESS;
    }
    else
    {
        DLNode *aux;
        aux = malloc(sizeof(DLNode));
        if (aux == NULL){
            return OUT_OF_MEMORY;
        }

        aux = list->end;
        aux = aux->prev;
        aux->next = NULL;
        list->end = aux;
        list->size --;

        return SUCCESS;
    }
    

}

int list_erase(TDLinkedList *list, int pos){

    if (list == NULL){
        return INVALID_NULL_POINTER;
    }

    if (list->begin == NULL)
    {
        return ELEM_NOT_FOUND;
    }
    else if (pos > list->size || pos < 1)
    {
        return ELEM_NOT_FOUND;
    }
    else if (pos == 1)
    {
        DLNode *aux;
        aux = malloc(sizeof(DLNode));
        if (aux == NULL){
            return OUT_OF_MEMORY;
        }

        aux = list->begin;
        aux = aux->next;
        aux->prev = NULL;
        list->begin = aux;
        list->size --;
        return SUCCESS;
    }
    else if (pos == list->size)
    {
        DLNode *aux;
        aux = malloc(sizeof(DLNode));
        if (aux == NULL){
            return OUT_OF_MEMORY;
        }

        aux = list->end;
        aux = aux->prev;
        aux->next = NULL;
        list->end = aux;
        list->size --;
        return SUCCESS;
    }
    else
    {
        DLNode *aux;
        aux = malloc(sizeof(DLNode));
        if (aux == NULL){
            return OUT_OF_MEMORY;
        }

        DLNode *aux2;
        aux2 = malloc(sizeof(DLNode));
        if (aux2 == NULL){
            return OUT_OF_MEMORY;
        }

        int contador = 1;
        aux = list->begin;

        while (contador < pos -1)
        {
            aux = aux->next;
            contador ++;
        }
        
        aux2 = aux->next;
        aux2 = aux2->next;
        aux->next = aux2;
        aux2->prev = aux;
        list->size --;
        return SUCCESS;

    }
    
}

int list_find_pos(TDLinkedList *list, int pos, struct aluno *al){

    if (list == NULL){
        return INVALID_NULL_POINTER;
    }

    if (pos > list->size || pos < 1)
    {
        return ELEM_NOT_FOUND;
    }

    else if (list->begin == NULL)
    {
        return ELEM_NOT_FOUND;
    }
    
    else
    {
        DLNode *aux;
        aux = malloc(sizeof(DLNode));
        if (aux == NULL){
            return OUT_OF_MEMORY;
        }

        aux = list->begin;
        int contador = 1;

        while (contador < pos)
        {
            aux = aux->next;
            contador++;
        }

        (*al) = aux->data;
        return SUCCESS;
    }
    



}

int list_find_mat(TDLinkedList *list, int nmat, struct aluno *al){

    if (list == NULL){
        return INVALID_NULL_POINTER;
    }

    if (list->begin == NULL)
    {
        return ELEM_NOT_FOUND;
    }

    else{
        
        DLNode *aux;
        aux = malloc(sizeof(DLNode));
        if (aux == NULL){
            return OUT_OF_MEMORY;
        }

        aux = list->begin;

        while (aux->data.matricula != nmat && aux != NULL)
        {
            aux = aux->next;
        }
        
        if (aux == NULL)
        {
            return ELEM_NOT_FOUND;
        }
        else
        {
            (*al) = aux->data;
            return SUCCESS;
        }

    }
}

int list_front(TDLinkedList *list, struct aluno *al){

    if (list == NULL){
        return INVALID_NULL_POINTER;
    }

    if (list->begin == NULL)
    {
        return ELEM_NOT_FOUND;
    }
    else
    {
        (*al) = list->begin->data;
        return SUCCESS;
    }
}

int list_back(TDLinkedList *list, struct aluno *al){

    if (list == NULL){
        return INVALID_NULL_POINTER;
    }

    if (list->begin == NULL)
    {
        return ELEM_NOT_FOUND;
    }
    else
    {
        (*al) = list->end->data;
        return SUCCESS;
    }

}

int list_get_pos(TDLinkedList *list, int nmat, int *pos){

    if (list == NULL){
        return INVALID_NULL_POINTER;
    }

    if (list->begin == NULL)
    {
        return ELEM_NOT_FOUND;
    }

    else
    {
        DLNode *aux;
        aux = malloc(sizeof(DLNode));
        if (aux == NULL){
            return OUT_OF_MEMORY;
        }

        int contador = 1;
        aux = list->begin;

        while (aux->data.matricula != nmat && aux != NULL)
        {
            aux = aux->next;
            contador ++;
        }

        if (contador > list->size)
        {
            return ELEM_NOT_FOUND;
        }
        else
        {
            (*pos) = contador;
            return SUCCESS;
        }

    }
    
}

int list_print_forward(TDLinkedList *list)
{
    if (list == NULL)
        return INVALID_NULL_POINTER;
    DLNode *aux;
    aux = list->begin;
    printf("\nImprimindo a lista\n");

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

int list_print_reverse(TDLinkedList *list)
{
    if (list == NULL)
        return INVALID_NULL_POINTER;
    DLNode *aux;
    aux = list->end;
    printf("\nImprimindo a lista - reverso\n");

    while (aux != NULL)
    {
        printf("\n------------------\n");
        printf("Matricula: %d\n", aux->data.matricula);
        printf("Nome: %s\n", aux->data.nome);
        printf("Notas: %f; %f; %f;\n", aux->data.n1, aux->data.n2, aux->data.n3);

        aux = aux->prev;
    }
    printf("\nFim da lista \n");
}

int list_insert(TDLinkedList *list, int pos, struct aluno al)
{
    if (list == NULL)
        return INVALID_NULL_POINTER;
    // teste se a posição de inserção é válida
    if ((pos < 1) || (pos > list->size + 1))
        return OUT_OF_RANGE;

    DLNode *node;
    node = malloc(sizeof(DLNode));
    if (node == NULL)
        return OUT_OF_MEMORY;
    node->data = al;

    
    if (list->size == 0)
    { // a lista está vazia
        node->next = NULL;
        node->prev = NULL;
        list->begin = node;
        list->end = node;
        list->size = 1;
    }
    else if (pos == 1)
    { //insere no início da lista
        node->prev = NULL;
        node->next = list->begin;
        list->begin->prev = node;
        list->begin = node;
        list->size = list->size + 1;
    }
    else if (pos == list->size + 1)
    { // inserção no fim da lista
        node->next = NULL;
        node->prev = list->end;
        list->end->next = node;
        list->end = node;
        list->size++;
    }
    else
    {
        int cont;
        DLNode *aux;

        cont = 1;
        aux = list->begin;
        while (cont < pos - 1)
        {
            aux = aux->next;
            cont = cont + 1;
        }
        node->prev = aux;
        node->next = aux->next;
        aux->next->prev = node;
        aux->next = node;
        list->size++;
    }
    return SUCCESS;
}
// check:<<<erro: exercício bem distinto do que foi pedido>>>>
int list_erase_zeros(TDLinkedList *list){

    if (list == NULL){
        return INVALID_NULL_POINTER;
    }

    if (list->begin == NULL)
    {
        return ELEM_NOT_FOUND;
    }
    else
    {
        DLNode *aux;
        aux = malloc(sizeof(DLNode));
        if (aux == NULL){
            return OUT_OF_MEMORY;
        }

        aux = list->begin;

        for (int i = 0; i <= list->size; i++)
        {
            if (aux->data.n1 == 0.0 && aux->data.n2 == 0.0 && aux->data.n3 == 0.0)
            {
                if (aux->prev == NULL)
                {
                    aux = aux->next;
                    aux->prev = NULL;
                    list->begin = aux;
                    list->size--;
                }
                else if (aux->next == NULL)
                {
                    aux = aux->prev;
                    aux->next = NULL;
                    list->end = aux;
                    list->size--;
                }
                else if (aux->prev == NULL && aux->next == NULL)
                {
                    list->begin = NULL;
                    list->end = NULL;
                }
                
                else
                {
                    DLNode *aux2;
                    aux2 = malloc(sizeof(DLNode));
                    if (aux2 == NULL){
                    return OUT_OF_MEMORY;
                    }

                    aux2 = aux;
                    aux2 = aux2->next;
                    aux = aux->prev;
                    aux->next = aux2;
                    aux2->prev = aux;  
                    list->size--;
                }                   
            }
            aux = aux->next;
            
        }
        
        return SUCCESS;

    }
    
}

/*
int list_splice(TDLinkedList *dest, TDLinkedList *source, int pos){

    if (dest == NULL){
        return INVALID_NULL_POINTER;
    }

    else if (source->begin == NULL)
    {
        return INVALID_NULL_POINTER;
    }

    else if (pos > dest->size || pos < 1)
    {
        return OUT_OF_RANGE;
    }
    
    else
    { 
        int contador = pos;
        DLNode *auxS;
        auxS = malloc(sizeof(DLNode));// check:<<< erro: ?>>>>
        if (auxS == NULL){
            return OUT_OF_MEMORY;
        }
        auxS = source->begin;
        
        if (auxS != NULL)
        {
            for (int i = 1; i <= source->size; i++)
            {   
                if (auxS->next != NULL)
                {
                    list_insert(dest, contador, auxS->data);
                    auxS = auxS->next;
                    contador ++;
                }
                else
                {
                    list_insert(dest, contador, auxS->data);
                    contador ++;
                }
            }
           
        }
        
        source->begin = NULL;
        source->end = NULL;
        source->size = 0;

        return SUCCESS;

    }
    
}
*/

int list_splice(TDLinkedList *dest, TDLinkedList *source, int pos){

    if (dest == NULL){
        return INVALID_NULL_POINTER;
    }

    else if (source->begin == NULL)
    {
        return INVALID_NULL_POINTER;
    }

    else if (pos > dest->size || pos < 1)
    {
        return OUT_OF_RANGE;
    }
    else
    { 
        DLNode *auxS;
              
        if (pos == 1)
        { // inserir no começo da lista

            source->end->next = dest->begin;
            dest->begin->prev = source->end;
            dest->begin = source->begin;
            dest->size = dest->size + source->size;
        }
        else if (pos == dest->size)
        { // inserir no final da lista

            auxS = source->begin;
            auxS->prev = dest->end;
            dest->end->next = auxS;
            dest->end = source->end;
            dest->size = dest->size + source->size;
        }
        else
        { // inserir no meio da lista

            DLNode *auxD;

            auxD = dest->begin;

            for (int i = 0; i < pos - 1; i++)
            {
                auxD = auxD->next;
            }

            auxS = auxD->next;
            source->begin->prev = auxD;
            auxD->next = source->begin;
            auxS->prev = source->end;
            source->end->next = auxS;
            dest->size = dest->size + source->size;
        }

        source->begin = NULL;
        source->end = NULL;
        source->size = 0;

        return SUCCESS;
    }
}   
