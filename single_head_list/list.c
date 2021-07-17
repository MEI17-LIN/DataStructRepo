#include <stdio.h>
#include <stdlib.h>

#include "list.h"


listnode *list_create()
{
	listnode *me;
	me = malloc(sizeof(*me));
	if(me == NULL)
		return NULL;
	me->next = NULL;
	return me;
}

void list_create1(listnode **me)
{
	*me = malloc(sizeof(**me));
	if(*me != NULL)
		(*me)->next = NULL;
	return ;
}

void list_destroy(listnode *me)
{
	listnode *node,*next;
	node = me;
	while(node)
	{
		next = node->next;
		free(node);
		node = next;
	}

	return ;
}


int list_insert_at(listnode *me, int i, datatype *data)
{
	int j;
	listnode *node, *newnode;
	node = me;
	if(i < 0)
		return -1;

	for(j = 0; j < i && node; j++)
	{
		node = node->next;
	}
	if(node)
	{
		newnode = malloc(sizeof(*newnode));
		if(newnode == NULL)
			return -1;
		newnode->val = *data;
		newnode->next = node->next;
		node->next = newnode;
		return 0;
	}
	else
		return -2; 
}

int list_order_insert(listnode *me, datatype *data)
{
	int i = 0;
	listnode *node, *newnode;
	
	if(me == NULL)
		return -1;

	node = me;
	while(node->next && node->next->val < *data)
	{
		node = node->next;
		++i;
	}
	newnode = malloc(sizeof(*newnode));
	if(newnode == NULL)
		return -2;
	newnode->val = *data;
	newnode->next = node->next;
	node->next = newnode;
	return 0;
	/*
	newnode = malloc(sizeof(*newnode));
	newnode->next = NULL;
	newnode->val = *data;

	node = me;
	
	while(node)
	{
		if(node->next)
		{
			if(node->next->val > *data)
			{
				newnode->next = node->next;
				node->next = newnode;
				return i;
			}
		}
		else
		{
			node->next = newnode;
			return i;
		}
		node = node->next;
		++i;
	} 
	*/
}

int list_delete_at(listnode *me, int i)
{
	int j = 0;
	listnode *node;
	if(me == NULL)
		return -1;
	node = me;
	while(j < i && node->next)
	{
		node = node->next;
		++j;
	}
	
	if(node->next == NULL)
		return -2;
	node->next = node->next->next;
	return j;


}

int list_delete(listnode *me, datatype *data)
{
	int i = 0;
	listnode *node;
	if(me == NULL)
		return -1;

	node = me;
	while(node->next && node->next->val != *data)
	{
		
		node = node->next;
		i++;
	}
	if(node->next)
	{
		node->next = node->next->next;
		return i;
	}
	return -2;
	
}


int list_isempty(listnode *me)
{
	if(me->next == NULL)
		return 0;
	return -1;

}

void list_display(listnode *me)
{
	listnode *node = me->next;
	if(list_isempty(me) == 0)
		return ;
	while(node)
	{
		printf("%d ",node->val);
		node = node->next;
	}
	printf("\n");

	return ;
}


