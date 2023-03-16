#include <stdlib.h>
#include <stdio.h>
#include "TCircLinkedList.h" 

typedef struct circlist circList;
typedef struct clistnode CList_node;

struct circlist{
    CList_node *end;
};

struct clistnode{
    struct aluno data;
    CList_node *next;
};

CircList *list_create()
{
    CircList *list;
    list = malloc(sizeof(CircList));
    if (list != NULL)
    {
        list->end = NULL;
    }
    return list;
}

int list_free(CircList *list){

    if (list == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    else
    {
        free(list);
    }
}

int list_push_front(CircList *list, struct aluno al)
{
    if (list == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    else
    {
        CList_node *node;
        node = malloc(sizeof(CList_node));
        if (node == NULL)
        {
            return OUT_OF_MEMORY;
        }
        else
        {
            if(list->end == NULL)
            {
                node->next = NULL;
                list->end = node;
                return SUCCESS;
            }
            else if (list->end->next == NULL)
            {
                node->data = al;
                node->next = list->end;
                list->end->next = node;
                return SUCCESS;
            }
            else
            {
                node->data = al;
                node->next = list->end->next;
                list->end->next = node;
                return SUCCESS;
            }
        }
    }
}

int list_push_back(CircList *list, struct aluno al)
{
    if (list == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    else
    {
        CList_node *node;
        node = malloc(sizeof(CList_node));
        if (node == NULL)
        {
            return OUT_OF_MEMORY;
        }
        else
        {
            node->data = al;

            if(list->end == NULL)
            {
                node->next = NULL;
                list->end = node;
                return SUCCESS;
            }
            else if (list->end->next == NULL)
            { 
                node->next = list->end;
                list->end->next = node;
                list->end = node;
                return SUCCESS;
            }
            else
            { 
                node->next = list->end;
                list->end = node;
                return SUCCESS;
            }
        }
    }
}

int list_pop_front(CircList *list){

    if (list == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    else
    {
        CList_node *node;
        node = malloc(sizeof(CList_node));
        if (node == NULL)
        {
            return OUT_OF_MEMORY;
        }
        else
        {
            node = list->end->next;
            node = node->next;
            list->end->next = node;
            return SUCCESS;
        }
    }
}

int list_pop_back(CircList *list){

    if (list == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    else
    {
        CList_node *aux;
        aux = malloc(sizeof(CList_node));
        if (aux == NULL)
        {
            return OUT_OF_MEMORY;
        }
        else
        {
            aux = list->end->next;
            list->end = aux;
            return SUCCESS;
        }
    }
}

int list_size(CircList *list){

    if (list == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    else
    {
        if (list->end == NULL)
        {
            return 0;
        }
        else if (list->end->next == NULL)
        {
            return 1;
        }
        else
        {
            int tam = 1;

            CList_node *aux;
            aux = malloc(sizeof(CList_node));
            if (aux == NULL)
            {
                return OUT_OF_MEMORY;
            }
            else
            {
                aux = list->end->next;
                while (aux != list->end)
                {
                    aux = aux->next;
                    tam++;
                }
                return tam;
            }         
        }                     
    }
}

int list_front(CircList *list, struct aluno *al){

    if (list == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    else
    {
        CList_node *aux;
        aux = malloc(sizeof(CList_node));
        if (aux == NULL)
        {
            return OUT_OF_MEMORY;
        }
        else
        {
            aux = list->end->next;
            (*al) = aux->data;
            return SUCCESS;
        }
    }
}

int list_back(CircList *list, struct aluno *al){

    if (list == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    else
    {
        (*al) = list->end->data;
    }
}

int list_print(CircList *list)
{
    if (list == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    else
    {
        CList_node *aux;
        aux = list->end;
        printf("\nImprimindo a lista (tamanho %d)\n", list_size(list));

        for(int i = 0; i <= list_size(list); i++);
        {
            printf("\n------------------\n");
            printf("Matricula: %d\n", aux->data.matricula);
            printf("Nome: %s\n", aux->data.nome);
            printf("Notas: %f; %f; %f;\n", aux->data.n1, aux->data.n2, aux->data.n3);

            aux = aux->next;
        }
        printf("\nFim da lista \n");
        return SUCCESS;
    }
}
