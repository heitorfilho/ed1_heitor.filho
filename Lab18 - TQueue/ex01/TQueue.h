#ifndef _tqueueh_
#define _tqueueh_
#include "aluno.h"

typedef struct TQueue TQueue;

TQueue *queue_create();
int queue_free(TQueue *qe);

int queue_push(TQueue *qe, struct aluno al);
int queue_pop(TQueue *qe);
int queue_top(TQueue *qe, struct aluno *al);

int queue_empty(TQueue *qe);
int queue_full(TQueue *qe);
int queue_print(TQueue *qe);

#endif