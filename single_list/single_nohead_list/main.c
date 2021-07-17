#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

int main()
{
	int i;
	struct score_st *p;
	listnode *list = NULL;
	struct score_st tmp;

	for(i = 0; i < 7; i++)
	{
//		printf("%d:a\n",i);
		strcpy(tmp.name, "stu");
		tmp.id = i;
		tmp.math = rand()%101;
		tmp.chinese	= rand()%101;
		
//		printf("%d:b\n",i);
		if(i == 0)
			list = list_create(list, &tmp);
		else
			list = list_insert(list, &tmp);

	}

	list_display(list);

	list_delete1(&list);
	list_display(list);


	if(p = list_find(list, 3))
	{
		printf("%d, %s, %d, %d\n",p->id, p->name,p->chinese, p->math);
	}
	else
		printf("Not find!\n");


	list_destroy(list);
	list = NULL;

	exit(0);
}
