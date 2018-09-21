//The implementation of Avl tree

struct AvlNode
{
    ElmentType Element;
    AvlTree Right;
    AvlTree Left;
    int Height;
};

/* Function to compute height of an avl tree */
static int Height(Position P)
{
    if(P == NULL)
        return -1;
    else return P->Height;
}

/* insertion into an avl tree */
AvlTree Insert(ElementType X,AvlTree T)
{
    if(T == NULL)
    {
        /* create and return a new tree */
        T = malloc(sizeof(struct AvlNode));
        if(T == NULL)
            print("out of space");
        else
        {
            T->Element = X;
            T->Height = 0;
            T->Left = T->Right = NULL;
        }
    }
    else
    {
        if(X < T->Element)
        {
            T->Left = Insert(X,T->Left);
            if((Height(T->Left)-Height(T->Right)) == 2)
                if(X < T->Left->Element)
                    T = SingleRotateWithLeft(T);
                else
                    T = DoubleRotateWithLeft(T);
        
        }
        else if(X > T->Element)
        {
            T->Right = Insert(X,T->Right);
            if((Height(T->Left)-Height(T->Right)) == 2)
                if(X > T->Right->Element)
                    T = SingleRotateWithRight(T);
                else
                    T = DoubleRotateWithLeft(T);
        }

        //X == T->Element means X is in the tree 
        //already,so we will do nothing
    }

    T->Height = Max(Height(T->Left),Height(T->Right)) + 1;
}

/* This function can be caller only if K2 has a left child
 * Perform a rotate between a node and its left child
 * update heights,then return new root
 */
static Position SingleRotateWithLeft(Position K2)
{
   Position K1;

   K1 = K2->Left;
   K2->Left = K1->Right;
   K1->Left = K2;

   K2->Height = Max(Height(K2->Left),Height(K2->Right)) + 1;

   K1->Height = Max(Height(K1->Left),Height(K1->Right)) + 1;

   return K1;       // return new root
}

static Position SingleRotateWithRight(Position K1)
{
   Position K2;

   K2 = K1->Right;
   K1->Right = K2->Left;
   K2->Right = K1;

   K2->Height = Max(Height(K2->Left),Height(K2->Right)) + 1;

   K1->Height = Max(Height(K1->Left),Height(K1->Right)) + 1;

   return K2;       // return new root
    
}

/* This function can be called only if K3 has a left
 * child and k3's left child has a right child
 * Do the left-right double rotation
 * update heights, and return new root 
 */
static Position DoubleRotateWithLeft(Position K3)
{
    /* Rotate between K1 and K2 */
    K3->Left = SingleRotateWithRight(K3->Left);

    /* Rotate between K3 and K2 */
    return SingleRotateWithLeft(K3);
}

static Position DoublePotateWithRight(Position K3)
{
    /* Rotate between K1 and K2 */
    K3->Right = SingleRotateWithLeft(K3->Right);

    /* Rotate between K3 and K2 */
    return SingleRotateWithRight(K3);
}

