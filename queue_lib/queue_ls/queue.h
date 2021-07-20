#ifndef QUEUE_H__
#define QUEUE_H__

#include "list.h"

typedef LLIST Queue;


Queue* queue_create(int initsize);
void queue_destroy(Queue*q);

int queue_enqueue(Queue*q, const void *data);
int queue_dequeue(Queue*q, void *data);


#endif // !QUEUE_H__
