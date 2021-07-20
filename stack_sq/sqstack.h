#ifndef  SQSTACK_H__
#define  SQSTACK_H__

#define MAXSIZE 5
typedef int datatype;

typedef struct 
{
    datatype data[MAXSIZE]; //存储空间
    int top; //栈顶
}sqstack;


sqstack *st_create(void);
void st_destroy(sqstack *);

int st_isempty(sqstack *);

int st_push(sqstack *, datatype *);
int st_pop(sqstack *, datatype *); 

int st_top(sqstack *, datatype *); // check the top of the stack

void st_travel(sqstack*);


#endif // ! SQSTACK_H__
