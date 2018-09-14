#include "list.h"
#include "stdlib.h"

int main()
{
    List list;
    Position p;

    list = malloc( sizeof( struct Node ) );

    Insert( 8,list,list );
    p = list->Next;
    Insert( 5,list,p );

    
    printf("%d\n",Retrieve(p));
    printf("%d\n",Retrieve(p->Next));

    exit(1);
}

