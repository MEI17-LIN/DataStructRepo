#include <stdio.h>
#include <stdlib.h>

#define JOSE_NUMBER 8

typedef int datatype;

typedef struct node_st
{
    int data;
    struct node_st *next;
}listnode;

listnode *joseph_create(datatype *datalist, int num)
{
    listnode *node = NULL, *pre = NULL, *me = NULL;
    int i = 0;
    
    for(i = 0; i < num; i++)
    {
        node = malloc(sizeof(*node));
        // if malloc failed in the intial process,
        // free the memory allocted.
        if(node == NULL) 
        {
            int j = 0;
            for(j = 0; j < i;j++)
            {
                node = me->next;
                free(me);
                me = node;
            }
            return NULL;
        }
        if(i == 0)
        {
            me = node;
            pre = node;
        }

        node->data = datalist[i];
        node->next = me;
        pre->next = node;

        pre = node;        
    }
    return me;
}

void joseph_destroy(listnode *me)
{
    listnode *node = me, *next = me;
    while(node != NULL)
    {
        next = node->next;
        free(node);
        node = next;
    }
    return ;
}


void joseph_display(listnode *me)
{
    listnode *node = me;
    if (me==NULL)
    {
        printf("list is empty!\n");
        return ;
    }

    do
    {
        /* code */
        printf("%d \n", node->data);
        node = node->next;
    
    } while (node != me);

    printf("\n");
    return ;
}

// 如果只数1，下面这个方法不能正确处理
// void joseph_kill(listnode **me, int n)
// {
//     listnode *cur = *me;
//     int i = 0;
//     if(me == NULL)
//         return ;
//     while(cur->next != cur)
//     {
//         for(i = 0; i< n-2; i++)
//             cur = cur->next;
//         printf("kill %d \n",cur->next->data);   
//         cur->next = cur->next->next;
//         cur = cur->next;
//     }
//     *me = cur;
//     return ;
// }

void joseph_kill(listnode **me, int n)
{
    listnode *cur = *me, *pre, *prebak;
    int i = 0;
    if(*me == NULL)
        return ;
    pre = malloc(sizeof(*pre));
    if(pre == NULL)
        return ;
    pre->data = 0;
    pre->next = NULL;
    prebak = pre;
    while(cur->next != cur)
    {
        i = 0;
        
        while(i < n-1)
        {
            pre = cur;
            cur = cur->next;
            i++;
        }
        pre->next = cur->next;
        printf("kill %d \n",cur->data);
        free(cur);
        cur = pre->next;
        //printf("cur: %d \n",cur->data);
        //printf("pre->next %d \n",pre->next->data);
    }
    free(prebak);
    *me = cur;
    return ;
}



// 无头单项循环链表 解决joseph问题

int main()
{
    listnode *list = NULL;
    datatype datals[JOSE_NUMBER] = {1,2,3,4,5,6,7,8};
    list = joseph_create(datals, JOSE_NUMBER);
    int n = 2;
    if(list == NULL)
        exit(1);

    
    joseph_display(list);
    
    joseph_kill(&list,n);
    
    joseph_display(list);
    //joseph_destroy(list);


    exit(0);
}