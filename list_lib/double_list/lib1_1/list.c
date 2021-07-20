#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"



LLIST *list_create(int initsize)
{
    LLIST *me;
    me = malloc(sizeof(*me));
    if(me == NULL)
        return NULL;
    me->size = initsize;
    me->head.prev = &me->head; 
    me->head.next = &me->head;

    return me;

}
void list_destroy(LLIST *list)
{
    listnode *node = NULL, *next = NULL;
    
    if(list == NULL)
        return;
    
    node = list->head.next;

    while(node != &list->head)
    {
        next = node->next;        
        free(node);
        node = next;
    }
    free(list);
    return ;

}

int list_insert(LLIST *list, const void *data, LLISTMODE mode)
{

    listnode *node = NULL, *p = &list->head;

    node = malloc(sizeof(*node) + list->size); // allocate memory for prev, next and data
    if(node == NULL)
        return -1;
    //node->data = data;
    memcpy(node->data, data, list->size);

    switch(mode)
    {
        case LLIST_FORWARD:
            node->next = p->next;
            node->prev = p;
            break;

        case LLIST_BACKWARD:
            node->next = p;
            node->prev = p->prev;
            break;

        default:
            return -3;
    }
    node->next->prev = node;
    node->prev->next = node;
    return 0;
}


static listnode *find_(LLIST *list, const void *key, list_cmp *cmp)
{
    listnode *node = list->head.next;
    // while(node != &list->head)
    // {
    //     if(cmp(key, node->data) == 0)
    //         return node;
    //     node = node->next;
    // }
    // return NULL;

    while(node != &list->head)
    {   
        if(cmp(key, node->data) == 0)
            break;
        node = node->next;

    }
    return node; // 如果找不到返回的就是头节点的node的指针, 其data为NULL

}

void *list_find(LLIST *list, const void *key, const list_cmp *cmp)
{
    listnode *p = NULL;
    p = find_(list, key, cmp);
    if(p == &list->head)
        return NULL;
    return p->data;

    //return find_(list, key, cmp)->data;
}

int list_delete(LLIST *list, const void *key, const list_cmp *cmp)
{
    listnode *p = NULL;
    p = find_(list, key, cmp);
    if(p == &list->head)//if(p->data == NULL)
        return -1;
    p->prev->next = p->next;
    p->next->prev = p->prev;
    free(p);
    return 0;
}

int list_fetch(LLIST *list, const void *key, const list_cmp *cmp, void *data)
{
    listnode *p = NULL;
    p = find_(list, key, cmp);
    if(p == &list->head)//if(p->data == NULL)
        return -1;
    // data = p->data; 这句其实并没有把数据传回去，因为这个data不是原来的指针
    // 如果这样写，要用二级指针

    memcpy(data, p->data, list->size); // 用memcpy可以解决问题
    p->prev->next = p->next;
    p->next->prev = p->prev;
    free(p);
    return 0;
}

void list_travel(LLIST *list, list_op *func)
{
    listnode *node = list->head.next;

    while(node != &list->head)
    {
        func(node->data);
        node = node->next;
    }
    return;

}