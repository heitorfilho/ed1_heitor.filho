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

typedef struct TSULinkedList TSULinkedList;

TSULinkedList *list_create();
int list_free(TSULinkedList *list);

int list_push_front(TSULinkedList *list, struct aluno al);
int list_push_back(TSULinkedList *list, struct aluno al);
int list_insert(TSULinkedList *list, int pos, struct aluno al); 
int list_insert_sorted(TSULinkedList *list, struct aluno al);
int list_size(TSULinkedList *list);


int list_pop_front(TSULinkedList *list);
int list_pop_back(TSULinkedList *list);
int list_erase(TSULinkedList *list, int pos);

int list_find_pos(TSULinkedList *list, int pos, struct aluno *al);
int list_find_mat(TSULinkedList *list, int nmat, struct aluno *al);
int list_front(TSULinkedList *list, struct aluno *al);

int list_back(TSULinkedList *list, struct aluno *al);
int list_get_pos(TSULinkedList *list, int nmat, int *pos);
int list_print(TSULinkedList *list);