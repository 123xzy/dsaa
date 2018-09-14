//The API of stack

#ifndef _Stack_H

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;
typedef int ElementType;

int IsEmpty(Stack S);
Stack CreateStack(void);
void Push(ElementType X,Stack S);
ElementType Top(Stack S);
ElementType Pop(Stack S);

#endif /* _Stack_H */

#include "stack.c"
