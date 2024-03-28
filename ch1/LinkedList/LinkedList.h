#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode
{
  ElementType Data;
  struct tagNode *NextNode;
} Node;

Node *SLL_CreateNode(ElementType NewData);
void SLL_DestroyNode(Node *Node);
void SLL_AppendNode(Node **Head, Node *NewNode);
Node *SLL_GetNodeAt(Node *Head, int Location);
void SLL_RemoveNode(Node **Head, Node *Remove);
void SLL_InsertAfter(Node *Current, Node *NewNode);
int SLL_GetNodeCount(Node *Head);
void SLL_InsertNewHead(Node **Head, Node *NewHead);
void SLL_InsertBefore(Node **Head, Node *Current, Node *NewHead);
void SLL_DestroyAllNodes(Node **List);

#endif