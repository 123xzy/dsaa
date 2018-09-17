// Ex_3.2:print the elements in L that are in positions specified by P
// use case:L(9,7,3,4,5,8) P(1,3,5,7,9)
// output:9 3 5

#include "list.h"

/* running time:O(Max(L,P)) */
void PrintLots(List L,List P)
{   
    Position Lpos,Ppos;

    Lpos = First(L);
    Ppos = First(P);
    
    int counter = 1;

    //printf("%d\n",Lpos->Element);
    
    while(Lpos != NULL && Ppos != NULL)
    {
        if(counter++ == Ppos->Element)
        {
            printf("%d\n",Lpos->Element);
            Ppos = Ppos->Next;
        }
        Lpos = Lpos->Next;
    }
}

int main()
{
    List L,P;

    L = malloc( sizeof( struct Node ) );
    P = malloc( sizeof( struct Node ) );

    Insert(8,L,L);
    Insert(5,L,L);
    Insert(4,L,L);
    Insert(3,L,L);
    Insert(7,L,L);
    Insert(9,L,L);

    Insert(9,P,P);
    Insert(7,P,P);
    Insert(5,P,P);
    Insert(3,P,P);
    Insert(1,P,P);
    
    PrintLots(L,P);

    return 0;
}
