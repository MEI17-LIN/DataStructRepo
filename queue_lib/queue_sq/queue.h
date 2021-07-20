#ifndef QUEUE_H__
#define QUEUE_H__

#define MAXSIZE 5

typedef int datatype;


typedef struct
{
    datatype data[MAXSIZE];
    int head, tail;
}queue;

queue * queue_create(void);
void queue_destroy(queue *);

int queue_isempty(queue *);
void queue_clear(queue *);

int queue_enqueue(queue *, datatype *);
int queue_dequeue(queue *, datatype *);

void queue_travel(queue *);


#endif // _
