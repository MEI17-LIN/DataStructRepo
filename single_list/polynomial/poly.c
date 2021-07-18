#include <stdio.h>
#include <stdlib.h>

typedef struct node_st
{
	int coef;
	int exp;
	struct node_st *next;
}polynode;


polynode *poly_create(int a[][2], int n)
{
	int i;
	polynode *me = NULL, *node = NULL, *cur = NULL;
	me = malloc(sizeof(*me));
	if(me ==NULL)
		return NULL;
	
	me->next = NULL;
	cur = me;
	
	for(i = 0; i < n; i++)
	{
		node = malloc(sizeof(*node));
		if(node ==NULL)
			return NULL;
		node->coef = a[i][0];
		node->exp = a[i][1];
		node->next = NULL;
		
		cur->next = node;
		cur = cur->next;
	}

	return me;

}

void poly_show(const polynode * const me)
{
	polynode *cur;
	if(me == NULL)
	{
		printf("poly is empty!\n");
		return ;
	}
	cur = me->next;
	while(cur)
	{
		printf("(%d %d) ", cur->coef, cur->exp);
		cur = cur->next;
	}
	printf("\n");
	return ;
}

void poly_destroy(polynode *me)
{
	polynode *cur = NULL;
	if(me == NULL)
		return;
	cur = me;
	while(cur)
	{
		cur = cur->next;
		free(me);
		me = cur;
	}
		
	return;
}

int poly_union(polynode *lst1, polynode *lst2) 
{
	//There is a bad result, because the lst2 wil be changed too.
	//Therefore, when destroying them, some node will be freed twice.
	polynode *p1=NULL, *p2 = NULL, *r = NULL;
	int i = 0;
	
	r = lst1;
	p1 = lst1->next;
	p2 = lst2->next;
	
	while(p1 && p2)
	{	printf("i = %d: ",i);
		i++;
		if(p1->exp < p2->exp)
		{
			r->next = p1;
			r = p1;
			p1 = p1->next;
			printf("p1 min, r->exp = %d, r->coef = %d", r->exp,r->coef);
		}
		else if(p1->exp >  p2->exp)
		{
			r->next = p2;
			r = p2;
			p2 = p2->next;

			printf("p2 min, r->exp = %d, r->coef = %d", r->exp,r->coef);
		}
		else
		{
			p1->coef += p2->coef;
			if(p1->coef)
			{
				r->next = p1;
				r = p1;
			}
			p1 = p1->next;
			p2 = p2->next;
			
			printf("eq,  r->exp = %d, r->coef = %d", r->exp,r->coef);
		}
		printf("\n");
	}
	if(p1 == NULL)
		r->next = p2;
	else
		r->next = p1;	

	return 0;
}

int main()
{

	int a[][2] = {{5,0},{2,1},{8,8},{3,16}};
	int b[][2] = {{6,1},{16,6},{-8,8}};
	polynode *p1 = NULL, *p2 = NULL;

	p1 = poly_create(a,4);
	if(p1 == NULL)
		exit(1);

	p2 =poly_create(b,3);
	if(p2 == NULL)
		exit(1);
	
	
	poly_show(p1);
	poly_show(p2);


	poly_union(p1, p2);
	
	poly_show(p1);
	poly_show(p2);


//	poly_destroy(p1);
//	poly_destroy(p2);


	exit(0);
}
