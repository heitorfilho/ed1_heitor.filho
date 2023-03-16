#ifndef _tqueueh_
#define _tqueueh_
#include "aluno.h"

typedef struct queue queue;

queue *queue_create(int qtd);
int queue_free(queue *qe);

int queue_push(queue *qe, struct aluno al);
int queue_pop(queue *qe);
int queue_top(queue *qe, struct aluno *al);

int queue_empty(queue *qe);
int queue_full(queue *qe);
int queue_print(queue *qe);

int realoca(queue *qe);

#endif