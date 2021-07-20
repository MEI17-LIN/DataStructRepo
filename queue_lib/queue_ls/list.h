#ifndef LIST_H__
#define LIST_H__

typedef enum 
{
    LLIST_FORWARD,
    LLIST_BACKWARD
}LLISTMODE;

// 存放data的另一种写法【或者说变长节点的另一种写法】
typedef struct node_st 
{           
    //void *data;
    struct node_st *next;
    struct node_st *prev;
    char data[0]; // C99才支持0长度的数组，为了移植性也可以改成1
}listnode;

typedef struct node_hd
{
    int size;
    listnode head;
}LLIST;

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