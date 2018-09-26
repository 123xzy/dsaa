//the implematation of binary search tree

#include "stdio.h"

struct TreeNode
{
    ElementType X;
    SearchTree Left;
    SearchTree Right;
};

/* why to free(T)? */
SearchTree MakeEmpty(SearchTree T)
{
    if(T == NULL)
        return NULL;
    else{
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
        free(T);
    }
}

Position Find(SearchTree T,ElementType X)
{
    if(T == NULL)
        return NULL;
    else if(T->Element > X)
        return Find(T->Right,X);
    else if(T->Element < X)
        return Find(T->Left,X);
    else return T;
}

/* recursive implementation of FindMin */
Position FindMin(SearchTree T)
{
    if(T == NULL)
        return NULL;
    else if(T->Left == NULL)
        return T;
    else return FindMin(T->Left);
}

/* nonrecursive implementation of FindMax */
Position FindMax(SearchTree T)
{
    if(T != NULL)
        while(T->Right != NULL)
            T = T->Right;
    return T;
}

SearchTree Insert(ElementType X,SearchTree T)
{
    if(T == NULL)
    {
        T = malloc(sizeof(struct TreeNode));
        if(T == NULL)
            printf("Out of space");
        else{
            T->Element = X;
            T->Left = T->Right = NULL;
        }
    }
    else if(T->Element < X)
        T->Right = Insert(X,T->Right);
    else if(T->Element > X)
        T->Left = Insert(X,T->Left);

    return T;
}

SearchTree Delete(SearchTree T,ElementType X)
{
    Position TmpCell;

    if(T == NULL)
        printf("element does not exist");
    else if(T->Element < X) /* Go Right */
        T->Right = Delete(T->Right,X);
    else if(T->Element > X) /* Go left */
        T->Left = Delete(T->Left,X);
    else if(T->Element == X)
    {
        TmpCell = T;

        /* if T has one child or zero child */
        if(T->Left == NULL)
            T = T->Right;
        else if(T->Right == NULL)
            T = T->Left;
        free(TmpCell);
    
        /* Two children */
        TmpCell = FindMin(T->Right);
        T->Element = TmpCell->Element;
        T->Right = Delete(T->Right,T->Element);
    }
    return T;
}

void PrintTree(SearchTree T)
{   
    if(T != NULL)
    {   
        PrintTree(T->Left);
        printf("%d",T->Element);
        PrintTree(T->Right);
    }
}
