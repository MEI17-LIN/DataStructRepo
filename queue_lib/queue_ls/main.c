#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

#define NAMESIZE 32

struct score_st
{
    int id;
    char name[NAMESIZE];
    int math;
    int chinese;
};

void print_s(const void *record)
{
    const struct score_st *r = record;
    printf("%d %s %d %d\n",r->id, r->name, r->math, r->chinese);
    return ;
} 

int main()
{
    Queue* q;
    struct score_st tmp;
    q = queue_create(sizeof(struct score_st));
    if(q==NULL)
        exit(1);

    for(int i=0; i < 5; i++)
    {
        tmp.id = i;
        snprintf(tmp.name, NAMESIZE, "std[%d]",i);
        tmp.math = rand()%101;
        tmp.chinese = rand()%101;
        
        if(queue_enqueue(q, &tmp))
        {
            printf("queue_enqueue() failed\n");
            break;
        }
    }


    while(1)
    {
        if(queue_dequeue(q, &tmp) != 0)
            break;
        print_s(&tmp);
    }

    queue_destroy(q);

    exit(0);
}