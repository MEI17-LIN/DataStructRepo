#ifndef LIST_H__
#define LIST_H__

typedef enum 
{
    LLIST_FORWARD,
    LLIST_BACKWARD
}LLISTMODE;

typedef void list_op(const void *); 
typedef int list_cmp(const void *, const void *);

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
    int (*insert)(struct node_hd *list, const void *data, LLISTMODE mode);
    void *(*find)(struct node_hd *list, const void *key, const list_cmp *cmp);
    int (*delete)(struct node_hd *list, const void *key, const list_cmp cmp);
    int (*fetch)(struct node_hd *list, const void *key, const list_cmp *cmp, void *data);
    void (*travel)(struct node_hd *list, list_op *op);

}LLIST;



LLIST *list_create(int initsize);
void list_destroy(LLIST *list);




#endif