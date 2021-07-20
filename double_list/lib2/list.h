#ifndef LIST_H__
#define LIST_H__

typedef enum 
{
    LLIST_FORWARD,
    LLIST_BACKWARD
}LLISTMODE;

typedef void LLIST;


typedef void list_op(const void *); 
typedef int list_cmp(const void *, const void *);


LLIST *list_create(int initsize);
void list_destroy(LLIST *);

int list_insert(LLIST *, const void *data, LLISTMODE mode);

void *list_find(LLIST *, const void *key, const list_cmp *cmp); 

// delete是直接删除
int list_delete(LLIST *, const void *key, const list_cmp cmp);
// fetch是删除并能"拿出来"
int list_fetch(LLIST *, const void *key, const list_cmp *cmp, void *data);


void list_travel(LLIST *list, list_op *op);


#endif