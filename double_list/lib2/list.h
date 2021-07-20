#ifndef LIST_H__
#define LIST_H__

typedef enum 
{
    LLIST_FORWARD,
    LLIST_BACKWARD
}LLISTMODE;





typedef void list_op(const void *); 
typedef int list_cmp(const void *, const void *);


LLIST *list_create(int initsize);
void list_destroy(LLIST *list);

int list_insert(LLIST *list, const void *data, LLISTMODE mode);

void *list_find(LLIST *list, const void *key, const list_cmp *cmp); 

// delete是直接删除
int list_delete(LLIST *list, const void *key, const list_cmp cmp);
// fetch是删除并能"拿出来"
int list_fetch(LLIST *list, const void *key, const list_cmp *cmp, void *data);


void list_travel(LLIST *list, list_op *op);


#endif