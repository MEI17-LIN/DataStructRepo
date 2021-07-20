#include <stdio.h>
#include <stdlib.h>

#include "queue.h"


Queue *queue_create(int initsize)
{
    return list_create(initsize);
}
void queue_destroy(Queue*q)
{
    list_destroy(q);
}

int queue_enqueue(Queue*q, const void *data)
{
    return list_insert(q, data, LLIST_BACKWARD);       
}

static int always_match_(const void *p1, const void *p2)
{
    return 0;
}

int queue_dequeue(Queue*q, void *data)
{
    return list_fetch(q, (void *)0, always_match_, data);
}





