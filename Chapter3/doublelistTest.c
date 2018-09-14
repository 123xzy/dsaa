//test of doubly linked list

#include "doublelist.h"
#include "stdlib.h"
	
int main()
{
    List dlist;
    Position p;

    dlist = malloc( sizeof( struct Node ) );
    dlist->Element = 6;
    dlist->Next = NULL;
    dlist->Prev = NULL;

    Insert(2,dlist);
    p = dlist->Next;
    Insert(5,p);
    Delete(5,dlist);   
    
    printf("%d\n",dlist->Next->Element);
//    printf("%d\n",Retrieve(p->Next));

    exit(1);
}

