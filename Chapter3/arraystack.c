//implementation of stack in array

#include "stdio.h"

#define EmptyTOS (-1)

struct StackRecord
{
    int Capacity;
    int TopOfStack;
    ElementType *Array;
};

Stack CreateStack(int MaxElements)
{
    Stack S;

    S = malloc(sizeof(struct StackRecord));

    if(S == NULL)
        printf("Out of space");

    S->Array = malloc(sizeof(ElementType) * MaxElements);
    
    if(S->Array == NULL)
        printf("Out of space");

    S->Capacity = MaxElements;

    return S;
}

int IsEmpty(Stack S)
{
    return S->TopOfStack == EmptyTOS;
}
    
int IsFull(Stack S)
{
    return S->TopOfStack == S->Capacity;
}

void Push(ElementType X,Stack S)
{
    if(IsFull(S))
        printf("Full Stack");
    else
        S->Array[++S->TopOfStack] = X;
}

ElementType Top(Stack S)
{
    if(!IsEmpty(S))
        return S->Array[S->TopOfStack];
    else
        printf("Empty Stack");
    return 0;   /* return value to avoid warning */
}

ElementType Pop(Stack S)
{
    if(!IsEmpty(S))
        return S->Array[S->TopOfStack--];
    else
        printf("Empty Stack");
    return 0;
}
    



    



    
