#include "arraystack.h"

int main()
{
    Stack S;

    S = CreateStack(10);/* fixed capacity stack */
    //S = CreateStack(); 

    //printf("%d\n",IsEmpty(S));
    Push(5,S);
    int x = Pop(S);
    printf("%d\n",x);
    Push(7,S);
    printf("%d\n",Top(S));
    Pop(S);
    printf("%d\n",IsEmpty(S));

    exit(1);
}
