#ifndef _Queue_H

struct QueueRecord;

typedef struct QueueRecord *Queue;
typedef int ElementType;

int IsEmpty(Queue Q);
int IsFull(Queue Q);
Queue CreateQueue(int MaxElements);
void Enqueue(ElementType X,Queue Q);
ElementType Front(Queue Q);
void Dequeue(Queue Q);

#endif /* _Queue_H */

#include "queue.c"
