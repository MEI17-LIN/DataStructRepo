#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sqstack.h"



int main()
{
    char str[] = "(11+3)*2-5";
    int i = 0, value = 0;
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
        }
        else // if str[i] is an operator
        {
            if(str[i] == '(')
                st_push(st_op, &str[i]);
            else if (str[i] == ')')
            {

            }
            else if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
            {

            }
            value = 0;             
        }


 

        i++;
    } 

    st_destroy(st_num);
    st_destroy(st_op);

    exit(0);
}