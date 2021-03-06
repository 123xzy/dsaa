//The API of DoubleList

#ifndef _Doublelist_H

struct Node;
typedef int ElementType;
typedef struct Node *PtrNode;
typedef PtrNode List;
typedef PtrNode Position;

List MakeEmpty( List L );
int IsEmpty( List L );
int IsLast( Position P,List L );
Position Find( ElementType X,List L );
void Delete( ElementType X,List L );
Position FindPrevious( ElementType X,List L);
void Insert( ElementType X,Position P);
void DeleteList( List L );
Position Header( List L );
Position First( List L );
Position Advance( Position P );
ElementType Retrieve( Position P );

#endif      /* _Doublelist_H */

#include "doublelist.c"
