//th:e implementation of doubly linked list
//delete & insert:O(1)
  
#include "stdio.h"

struct Node
{
    ElementType Element;
    Position Next;
    Position Prev;
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


/* delete first occurence of X from a list */
/* assume use of a header node */

void Delete( ElementType X,List L )
{
    Position P;

    P = Find(X,L);
    
    if( IsLast(P,L) )            
    {
     	P->Prev->Next = NULL;
	    free(P);
    }
    else{
        P->Prev->Next = P->Next;
        P->Next->Prev = P->Prev;
        free(P);
    }
}

/* Insert after legal position P*/

void Insert( ElementType X,Position P)
{
    Position TmpNode;

    TmpNode = malloc( sizeof( struct Node ) );
    if(TmpNode == NULL)
        printf("Out of space");

    TmpNode->Element = X;

    if(P->Next == NULL){
        TmpNode->Prev = P;
        P->Next = TmpNode;
        TmpNode->Next = NULL;
    }
    else{      
        TmpNode->Next = P->Next;
        P->Next->Prev = TmpNode;
        TmpNode->Prev = P;
        P->Next = TmpNode;
    }
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

