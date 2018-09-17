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
