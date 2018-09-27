/*
 * The API of B_Tree 
 * the structural properties of b-tree of order M
 * 1.all leaves are at the same depth
 * 2.all nodes hava between M/2 and M children
*/

#ifndef B_Tree_H

struct B_Node;
typedef struct B_Node *PtrBNode;
typedef PtrBNode BTree;
typedef PtrBNode BNode;
typedef int ElementType;

BTree Create_B_Tree();
BNode Search(ElementType X);
void Insert(BTree T,ElementType X);
BTree Split();

#endif /* B_Tree_H */

#include "B_Tree.c"
