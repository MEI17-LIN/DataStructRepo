#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

STACK *stack_create(int initsize)
{
    return list_create(initsize);
}

void stack_destroy(STACK *st)
{
    list_destroy(st);
    return;
}

static int always_match_(const void *p, const void *q)
{
    return 0;
}


int stack_pop(STACK *st, void *data)
{
    return list_fetch(st, (void *)0, always_match_, data);
}

int stack_push(STACK *st, const void *data)
{
    return list_insert(st, data, LLIST_FORWARD);
}