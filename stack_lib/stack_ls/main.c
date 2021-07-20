#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

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
    printf("%d %s %d %d\n", r->id, r->name, r->math, r->chinese);
    return;
}

int main()
{
    int i;
    STACK *st;
    struct score_st *tmp = NULL;
    tmp = malloc(sizeof(struct score_st));
    if(tmp == NULL)
        exit(1);

   
    st = stack_create(sizeof(struct score_st));
    if(st == NULL)
    {
        printf("stack_create() failed\n");
        exit(1);
    }
        
    for(i = 0; i < 8;i++)
    {
        tmp->id = i;
        snprintf(tmp->name, NAMESIZE, "std[%d]", i);
        tmp->math = rand() % 101;
        tmp->chinese = rand() % 101;
        if(stack_push(st, tmp))
            exit(1);
    }
    while(1)
    {
        if(stack_pop(st, tmp))
            break;
        print_s(tmp);
    }
    
    free(tmp);
    tmp = NULL;

    stack_destroy(st);



    exit(0);
}