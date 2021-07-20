#include <stdio.h>
#include <stdlib.h>

#include "queue.h"


int main()
{
    queue *q = NULL;
    datatype arr[] = {3,4,57,8,3,2};
    datatype tmp;
    q = queue_create();
    if(q==NULL)
        exit(1);
    
    for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        if(queue_enqueue(q, &arr[i])!=0)
            printf("queue is full!\n");
    }
    queue_travel(q);

    for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        if(queue_dequeue(q, &tmp) !=0 )
        {
            printf("queue is empty!\n");
            break;
        }
        printf("deque %d\n", tmp);
    }

    queue_destroy(q);

    exit(0); //
}