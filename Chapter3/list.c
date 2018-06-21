#include "stdio.h"

struct Node
{
    ElementType Element;
    Position Next;
};

/* make empty list */

List MakeEmpty( List L )
{
    Position P;

    P = L->Next;
    while( P != NULL )
    {
        P->Element = 0;
        P = P->Next;
    }

    return L;
}   

/* return true if L is empty */

int IsEmpty( List L )
{
    return L->Next == NULL;
}

/* return if P is the last position in list L */
/* Parameter L is unused in this implementation */

int IsLast( Position P,List L )
{
    return P->Next == NULL;
}

/* return position of X in L;NULL if not found */

Position Find( ElementType X,List L )
{
    Position P;
    
    P = L->Next;
    while( P != NULL && P->Element != X ) 
        P = P->Next;
    
    return P;
}   

/* If X is not found,then Next field of returned */
/* Position is NULL */
/* Assumes a header */

Position FindPrevious( ElementType X,List L )
{
    Position P = L;

    while( P->Next != NULL && P->Next->Element != X )
        P = P->Next;
    
    return P;
}   

/* delete first occurence of X from a list */
/* assume use of a header node */

void Delete( ElementType X,List L )
{
    Position P,TmpCell;

    P = FindPrevious( X,L );
    
    if( P != NULL )             /* I think here is a bug */
    {
        TmpCell = P->Next;
        P->Next = TmpCell->Next;
        free( TmpCell );
    }
}

/* Insert( after legal position P ) */
/* Header implementation assumed */
/* Parameter L is unused in this implementation */

void Insert( ElementType X,List L,Position P )
{
    Position TmpCell;

    TmpCell = malloc( sizeof( struct Node ) );
    if( TmpCell == NULL )
        printf( "out of space" );

    TmpCell->Element = X;
    TmpCell->Next = P->Next;
    P->Next = TmpCell;
}   

/* delete a list */

void DeleteList( List L )
{
    Position P,Tmp;

    P = L->Next;
    L->Next = NULL;  /* Header assumed */
    while( P != NULL )
    {
       Tmp = P->Next;
       free(P);
       P = Tmp;
    }
}    

/* return head of a list */

Position Header( List L )
{
    return ( Position )L;   
}    

/* return first node of a list */

Position First( List L )
{
    return L->Next;
}    

/* return advance node of p */
//Position Advance( Position P )

/* return value of P */
ElementType Retrieve( Position P )
{
    return P->Element;
}

