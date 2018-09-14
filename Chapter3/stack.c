//The implementation of stack in linked list

#include "stdio.h"

struct Node
{
    ElementType Element;
    PtrToNode Next;
};

int IsEmpty(Stack S)
{
    return S->Next == NULL;
}

Stack CreateStack(void)
{
    Stack S;

    S = malloc(sizeof(struct Node));
    if(S == NULL)
        printf("Out of Space");
    S->Element = 0;
    S->Next = NULL;
    
    return S;
}

void Push(ElementType X,Stack S)
{
    PtrToNode TmpCell;

    TmpCell = malloc(sizeof(struct Node));

    if(TmpCell == NULL)
        printf("Out of Space");
    else if (IsEmpty(S))
    {
        TmpCell->Next = NULL;
        TmpCell->Element = X;
        S->Next = TmpCell;
    }
    else{
        TmpCell->Element = X;
        TmpCell->Next = S->Next;
        S->Next = TmpCell;
    }

}

ElementType Pop(Stack S)
{
   PtrToNode TmpCell;

   ElementType TmpX;
    
   if(S->Next == NULL)
        printf("Empty Stack");
   else{
        TmpCell = S->Next;
        TmpX = TmpCell->Element;
        S->Next = TmpCell->Next;
    
        free(TmpCell);
   }
   return TmpX;
}

ElementType Top(Stack S)
{
    return S->Next->Element;
}






 
