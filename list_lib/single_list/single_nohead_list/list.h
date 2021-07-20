#ifndef LIST_H__
#define LIST_H__

#define NAMESIZE 32

struct score_st
{
	int id;
	char name[NAMESIZE];
	int math;
	int chinese;
};

typedef struct node_st
{
	struct score_st data;
	struct node_st *next;
}listnode;


listnode *list_create(listnode *, struct score_st* );
void list_destroy(listnode *);

listnode *list_delete(listnode *me);
int list_delete1(listnode **me);

listnode *list_insert(listnode * node, struct score_st*);
void list_display(listnode *p);
struct score_st *list_find(listnode *, int);

#endif
