//the API of Stack implementated in Array
#ifndef _Stack_H

struct StackRecord;
typedef int ElementType;
typedef struct StackRecord *Stack;
int IsEmpty(Stack S);
int IsFull(Stack S);
Stack CreateStack(int MaxElements);
ElementType Pop(Stack S);
ElementType Top(Stack S);
void Push(ElementType X,Stack S);

#endif /* _Stack_H */

#include "arraystack.c"
