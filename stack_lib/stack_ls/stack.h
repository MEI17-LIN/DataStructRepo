#ifndef STACK_H__
#define STACK_H__

#include "list.h"

typedef LLIST STACK;

STACK *stack_create(int initsize);
void stack_destroy(STACK *st);

int stack_pop(STACK *st, void *data);
int stack_push(STACK *st, const void *data);




#endif // !STACK_H__
