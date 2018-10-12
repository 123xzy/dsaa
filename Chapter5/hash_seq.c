#include "stdio.h"

struct ListNode
{
	ElementType Element;
	Position Next;
};

typedef Position List;

struct HashTbl
{
	int TableSize;
	List *TheLists;
};

HashTable InitializeTable(int TableSize)
{
	HashTable H;
	int i;

	if(TableSize < MinTableSize)
	{
		printf("Table size too small");
		return NULL;
	}
	
	/* allocate table */
	H = malloc(sizeof(struct HashTbl));
	if(H == NULL)
		exit("Out of space");
	
	H->TableSize = NextPrime(TableSize);

	/* allocate array of lists */ 
	H->TheLists = malloc(sizeof(struct(List)*H->TableSize));
	if(H->TheLists == NULL)
		exit("Out of space");
	
	/* allocate list headers */
	for(i = 0;i < H->TableSize;i++)
	{
		/* its inefficiency is that the malloc is 
 		* performed H->TableSize times.We can replace 
 		* it with one call to malloc before loop occues. */
		H->TheLists[i] = malloc(sizeof(struct ListNode));
		if(H->TheLists[i] == NULL)
			exit("Out of space");
		else
			H->TheLists[i]->Next = NULL;	
	}	
	
	return H;
}

Position Find(ElementType Key,HashTable H)
{	
	Position P;
	List L;
	
	L = H->TheLists[Hash(Key,H->TableSize)];
	P = L->Next;
	while(P != NULL && P->Element != Key)
		/* If ElementType is a string,comparision and assignments
		 * can be done with strcmp and strcpy.respectively*/	
		P = P->Next;
	return P;
}

void Insert(ElementType Key,HashTable H)
{
	/* This implematation is bad,cause it computes the hash
 	* function twice.The first is Find().the second is Hash().
 	* So if the hash routines account for a significant portion
 	* of the program running time,we should rewrite it.*/
	Position Pos,NewCell;
	List L;
	
	Pos = Find(Key,H);
	/* If item is already present,we do nothing.*/
	if(Pos == NULL)
	{
		NewCell = malloc(sizeof(struct ListNode));
		if(NewCell == NULL)
			exit("Out of space");
		else
		{
			L = H->TheList[Hash(Key,H->TableSize)];
			NewCell->Next = L->Next;
			NewCell->Element = Key;
			L->Next = NewCell;
		}
	}
}








