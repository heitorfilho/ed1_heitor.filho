#define SUCCESS 0
#define INVALID_NULL_POINTER -1
#define OUT_OF_MEMORY -2
#define OUT_OF_RANGE -3
#define ELEM_NOT_FOUND -4

struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};

typedef struct circlist CircList;

CircList *list_create();
int list_free(CircList *list);

int list_push_front(CircList *list, struct aluno al);
int list_push_back(CircList *list, struct aluno al);

int list_size(CircList *list);
int list_pop_front(CircList *list);
int list_pop_back(CircList *list);

int list_front(CircList *list, struct aluno *al);
int list_back(CircList *list, struct aluno *al);
int list_print(CircList *list);