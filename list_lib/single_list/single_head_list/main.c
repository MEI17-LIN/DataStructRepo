#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main()
{
	int i;
	datatype arr[] = {34,22,3,4,15};
	listnode *lst1=NULL;


	lst1 = list_create(lst1);
	if(lst1 == NULL)
	{
		fprintf(stderr, "list_create() failded!\n");
		exit(1);
	}
	
	for(i = 0; i < sizeof(arr)/sizeof(*arr);i++)
	{
		//if(list_insert_at(lst1, 0, &arr[i])!=0)
		if(list_order_insert(lst1,&arr[i]) < 0)
			exit(1);
	}
	
	list_display(lst1);
	
	list_delete_at(lst1, 2);

	list_display(lst1);
	
	list_destroy(lst1);
	lst1 = NULL;	
	exit(0);
}
