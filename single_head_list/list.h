#ifndef LIST_H__
#define LIST_H__

typedef int datatype;

typedef struct node_st
{
	datatype val;
	struct node_st *next;

}listnode;

listnode *list_create();
void list_create1(listnode **);
void list_destroy(listnode *);

int list_insert_at(listnode*, int i, datatype *);
int list_order_insert(listnode *, datatype *);

int list_delete_at(listnode *, int i);
int list_delete(listnode *, datatype *);

int list_isempty(listnode *);

void list_display(listnode *);


#endif
