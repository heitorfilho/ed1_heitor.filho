#ifndef _tstackh_
#define _tstackh_

typedef struct TStack TStack;

TStack *stack_create();
int stack_free(TStack *st);

int stack_push(TStack *st, char c);
char stack_pop(TStack *st);
int stack_top(TStack *st, char *c);

int stack_empty(TStack *st);
int stack_full(TStack *st);
int stack_print(TStack *st);
int bemFormada(char *s);

#endif