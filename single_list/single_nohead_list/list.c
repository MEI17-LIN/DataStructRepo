#include <stdio.h>
#include <stdlib.h>

#include "list.h"


listnode *list_create(listnode *me, struct score_st *tmp)
{
	listnode *node = me;
	node = malloc(sizeof(*node));
	if(node != NULL)
	{
		node->data = *tmp;
		node->next = NULL;
	}
	return node;
}

void list_destroy(listnode *me)
{
	listnode *node = me, *next;
	while(node)
	{
		next = node->next;
		free(node);
		node = next;
	}

	return ;
}


listnode *list_insert(listnode *me, struct score_st *tmp)
{
	listnode *node = NULL;
	node = malloc(sizeof(*node));
	node->next = me;
	node->data = *tmp;
	return node;

}

int list_insert1(listnode **me, struct score_st *tmp)
{
	
}

void list_display(listnode *me)
{
	listnode *node = me;
	while(node)
	{ 
		printf("%d %s %d %d \n", node->data.id, node->data.name, node->data.math, node->data.chinese);
		node = node->next;
	}

	return ;
}


listnode *list_delete(listnode *me)
{
	listnode *node = me->next;


	if(me == NULL)
		return NULL;

	free(me);

	return node;
}

int list_delete1(listnode **me)
{
	if(*me == NULL)
		return -1;

	listnode *node;
	node = *me;

	*me = (*me)->next;

	free(node);

	return 0;
}



struct score_st *list_find(listnode *me, int id)
{
	listnode *node = me;
	
	while(node)
	{
		if(node->data.id == id)
			return &node->data;
		node = node->next;
	}
	return NULL;
		
}

