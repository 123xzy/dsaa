// queue-array implementation

#include "stdio.h"

struct QueueRecord
{
    int Capacity;
    int Front;
    int Rear;
    int Size;
    ElementType *Array;
};

int IsEmpty(Queue Q)
{
    return Q->Size == 0;
}

int IsFull(Queue Q)
{
    return Q->Size == Q->Capacity;
}

Queue CreateQueue(int MaxElements)
{
    Queue Q;

    Q = malloc(sizeof(struct QueueRecord));
    if(Q == NULL)
        printf("Out of space");

    Q->Array = malloc(sizeof(ElementType) * MaxElements);

    if(Q->Array == NULL)
        printf("Out Of Space");

    Q->Capacity = MaxElements;
    Q->Size = 0;
    Q->Front = 0;
    Q->Rear = MaxElements;

    return Q;
}

void Enqueue(ElementType X,Queue Q)
{
    if(IsFull(Q))
        printf("Full Queue");
    else{
        Q->Size++;
        Q->Rear = (++Q->Rear)%Q->Capacity;
        Q->Array[Q->Rear] = X;
    }
}

ElementType Front(Queue Q)
{
    return Q->Array[Q->Front];
}

void Dequeue(Queue Q)
{
    Q->Front = (++Q->Front)%Q->Capacity;
}


    
