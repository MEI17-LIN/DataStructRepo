#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sqstack.h"

static int compute(sqstack *snum, int op)
{
    datatype n1, n2, n;
    
    if(st_pop(snum, &n2) != 0 || st_pop(snum, &n1) != 0)
        return -1;

    switch(op)
    {
        case '+':
            n = n1 + n2;
            break;

        case '-':
            n = n1 - n2;
            break;

        case '*':
            n = n1 * n2;
            break;

        case '/': // int的直接除法，这算一个陷阱吧
            n = n1 / n2;
            break;

        default:
            return -2;
    }
    st_push(snum, &n);   
    return 0;
}



static int deal_bracket(sqstack *snum, sqstack *sop)
{
    datatype old_op;
    st_top(sop, &old_op);
    while(old_op != '(')
    {
        st_pop(sop, &old_op);
        if(compute(snum, old_op) !=0)
            return -2;
        st_top(sop, &old_op);
    }
    return st_pop(sop, &old_op);
}

static int get_pri(int op)
{
    // printf("get_pri:%d\n", op);
    switch(op)
    {
        case '(':
            return 0;
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            printf("wrong get_pri \n");
            exit(1);
    }
}

static int deal_op(sqstack *snum, sqstack *sop, int op)
{
    datatype old_op;
    // printf("deal_op:%c\n", op);
    // printf("deal_op:st_isempty(sop): %d\n", st_isempty(sop));
    if(op == '(' || st_isempty(sop) == 0)
    {
        // printf("push directly\n");
        return st_push(sop, &op);
    }
    
    st_top(sop, &old_op);
    // printf("deal_op:old_op:st_isempty(sop): %d\n", old_op);
    while (get_pri(op) <= get_pri(old_op))
    {
        /* code */
        st_pop(sop, &old_op);
        compute(snum, old_op);
        if(st_isempty(sop) == 0)
            break;
        st_top(sop, &old_op);
        
    }
    // printf("deal_op:st_push:%c\n",op);
    return st_push(sop, &op);
}



int main()
{
    char str[] = "(11+3)*2-5";
    int i = 0;
    int value = 0, flag = 0;
    int old_op;
    sqstack *st_num = NULL, *st_op = NULL;
    
    // create num stack and operate stack
    st_num = st_create();
    if(st_num == NULL)
        exit(1);
    st_op = st_create();
    if(st_op == NULL)
        exit(1);

    // travel str
    while(str[i] != '\0')
    {
        if(str[i] >= '0' && str[i] <= '9') // if str[i] is a number
        {
            value = value*10 + (str[i]-'0');
            flag = 1;
        }
        else // if str[i] is an operator
        {
            // printf("\n");
            // printf("i:%d str[i]:%c\n", i, str[i]);
            // printf("st_num:\n");
            // st_travel(st_num);

            // printf("st_op:\n");
            // st_travel(st_op);
            
            if(flag)
            {
                st_push(st_num, &value); 
                // printf("i:%d value:%d\n", i, value);
                flag = 0;
                value = 0;
            }

            if (str[i] == ')')
            {
                if(deal_bracket(st_num, st_op) != 0)
                {
                    // printf("deal_bracket() failed\n");
                    exit(1);
                }
            }
            //else if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
            else
            {
                deal_op(st_num, st_op, str[i]);
                
            }
        }
        i++;
    } 



    if(flag)
        st_push(st_num, &value);

    printf("FINAL\n");
    printf("st_num:\n");
    st_travel(st_num);

    printf("st_op:\n");
    st_travel(st_op);

    while(st_isempty(st_op) !=0)
    {
        st_pop(st_op, &old_op);
        compute(st_num, old_op);
    }

    st_pop(st_num, &value);

    printf("res:%d\n", value);
    st_destroy(st_num);
    st_destroy(st_op);

    exit(0);
}