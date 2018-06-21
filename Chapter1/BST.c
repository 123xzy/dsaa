#include<stdio.h>
#include<BST.h>

typedef ElementType int;

struct TreeNode
{
    ElementType Element;
    SearchTree Left;
    SearchTree Right;
}

/* make a empty tree */
SearchTree MakeEmtpy(   SearchTree T    )
{
    if(T != NULL)
    {
        MakeEmpty( T->Right );
        MakeEmpty( T->Left  );
        free(T);
    }
    return NULL;
}

/* find X in tree */
Position Find(ElementType X,SearchTree T)
{
    if(T == NULL)
        return NULL;
    if(X < T->Element)
        Find(X,T->Left);
    else
    if(X > T->Element)
        Find(X,T->Right);
    else 
        return T;
}


