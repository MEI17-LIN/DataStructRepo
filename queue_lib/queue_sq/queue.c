#include <stdio.h>
#include <stdlib.h>

#include "queue.h"


queue * queue_create(void)
{
    queue *q = NULL;
    q = malloc(sizeof(*q));
    if(q == NULL)
        return NULL;
    q->head = 0;
    q->tail = 0;

    return q;
}

void queue_destroy(queue *q)
{
    free(q);
    return ;
}

int queue_isempty(queue *q)
{
    if(q->head == q->tail)
        return 0;
    return -1;
}


void queue_clear(queue *q)
{
    q->head = q->tail;
    return ;

}


int queue_enqueue(queue *q, datatype *data)
{
    if((q->tail + 1) % MAXSIZE == q->head) // the queue is full
        return -1;
    q->tail = (q->tail + 1) % MAXSIZE;
    q->data[q->tail] = *data;
    return 0;
}

int queue_dequeue(queue *q, datatype *data)
{
    if(queue_isempty(q) == 0)
        return -1;
    
    q->head = (q->head + 1) % MAXSIZE;
    *data = q->data[q->head];

    return 0;
}

void queue_travel(queue *q)
{
    if(queue_isempty(q) == 0)
        return;
    int i = (q->head + 1) % MAXSIZE;
    while(i != q->tail)
    {
        printf("%d ", q->data[i]);
        i = (i+1) % MAXSIZE;
    }
    printf("%d \n", q->data[i]);
    return ;
}


