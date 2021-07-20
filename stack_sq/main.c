#include <stdio.h>
#include <stdlib.h>

#include "sqstack.h"

int main()
{
    datatype arr[] = {12,35,0, 54,86};
    sqstack *st;
    datatype tmp = 1;
    st = st_create();
    if(st == NULL)
        exit(1);
    for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
        st_push(st, &arr[i]);

    st_travel(st);

    while(st_pop(st, &tmp) == 0)
    {
        printf("pop: %d\n", tmp);
    }

    // if(st_push(st, &tmp) == -1)
    //     printf("Error!\n");
    // else
    //     st_travel(st);

    st_destroy(st);
    exit(0);
}