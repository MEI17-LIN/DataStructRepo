#include <stdio.h>
#include <stdlib.h>

#include "list.h"

#define NAMESIZE 32

struct score_st
{
    int id;
    char name[NAMESIZE];
    int math;
    int chinese;
};


void print_score_st(const void *record)
{   
    const struct score_st *st = record;
    printf("%d %s %d %d\n", st->id, st->name, st->math, st->chinese);
    return ;
}

int id_cmp(const void *key, const void *record)
{
    const int *k = key;
    const struct score_st *st = record;
    // if(st->id == *k) 
    //     return 0;
    // return -1;
    return (*k - st->id);
}



int main()
{
    LLIST *handle = NULL;
    struct score_st stu;
    int ret;
    int stu_id;

    handle = list_create(sizeof(struct score_st));
    if(handle == NULL)
        exit(1);

    for(int i = 0; i < 7;i++)
    {   
        stu.id = i;
        snprintf(stu.name, NAMESIZE, "std[%d]",i);
        stu.math = rand()%101;
        stu.chinese = rand()%101;        
        ret = list_insert(handle, &stu, LLIST_FORWARD);
        //ret = list_insert(handle, &stu, LLIST_BACKWARD);
        
        if(ret != 0)
            exit(1);
        
    }


    //list_insert(handle,);

    list_travel(handle, print_score_st);

    int status;
    struct score_st *tmp;
    
    printf("Input the id of student you want to find:(q to quit)");
    while(scanf("%d",&stu_id) == 1) 
    {
        tmp = list_find(handle, &stu_id, id_cmp);
        if(tmp == NULL)
            printf("id %d can not be found.\n", stu_id);
        else
            print_score_st(tmp);
        printf("Input the id of student you want to find:(q to quit)");
    }
    printf("exit from the find.\n");
    getchar();

    printf("Input the id of student you want to delete:(q to quit)");
    while(scanf("%d",&stu_id) == 1) 
    {
        status = list_delete(handle, &stu_id, id_cmp);
        if(status != 0)
            printf("id %d can not be found.\n", stu_id);
        else
            printf("Successfully deleted.\n");
        list_travel(handle, print_score_st);
        printf("Input the id of student you want to delete:(q to quit)");
    }
    printf("exit from the delete.\n");
    getchar();

    tmp = malloc(sizeof(*tmp));
    printf("Input the id of student you want to fetch:(q to quit)");
    while(scanf("%d",&stu_id) == 1) 
    {
        status = list_fetch(handle, &stu_id, id_cmp, tmp);
        if(status != 0)
            printf("id %d can not be found.\n", stu_id);
        else
            {
                printf("The fetched data is ");
                print_score_st(tmp);
            }
        list_travel(handle, print_score_st);
        printf("Input the id of student you want to fetch:(q to quit)");
    }
    free(tmp);
    tmp = NULL;
    printf("exit from the fetch.\n");

    list_destroy(handle);

    exit(0);
}