#include "LinkedList.h"

Node *SLL_CreateNode(ElementType NewData)
{
  Node *NewNode = (Node *)malloc(sizeof(Node));

  NewNode->Data = NewData;
  NewNode->NextNode = NULL;

  return NewNode;
}

void SLL_DestroyNode(Node *Node)
{
  free(Node);
}

// *Head로 선언하면 arg의 주소값만 복사하기 때문에 arg의 포인터를 제어하지 못함
void SLL_AppendNode(Node **Head, Node *NewNode)
{
  if (*Head == NULL)
  {
    *Head = NewNode;
  }
  else
  {
    Node *Tail = *Head;
    while (Tail->NextNode != NULL)
    {
      Tail = Tail->NextNode;
    }
    Tail->NextNode = NewNode;
  }
}

Node *SLL_GetNodeAt(Node *Head, int Location)
{
  Node *Current = Head;

  while (Current != NULL && (--Location) >= 0)
  {
    Current = Current->NextNode;
  }

  return Current;
}

void SLL_RemoveNode(Node **Head, Node *Remove)
{
  if (*Head == Remove)
  {
    *Head = Remove->NextNode;
  }
  else
  {
    Node *Current = *Head;
    while (Current != NULL && Current->NextNode != Remove)
    {
      Current = Current->NextNode;
    }
    if (Current != NULL)
      Current->NextNode = Remove->NextNode;
  }
}

void SLL_InsertAfter(Node *Current, Node *NewNode)
{
  NewNode->NextNode = Current->NextNode;
  Current->NextNode = NewNode;
}

int SLL_GetNodeCount(Node *Head)
{
  int Count = 0;
  Node *Current = Head;

  while (Current != NULL)
  {
    Current = Current->NextNode;
    Count++;
  }

  return Count;
}

void SLL_InsertNewHead(Node **Head, Node *NewHead)
{
  if (Head == NULL)
  {
    *Head = NewHead;
  }
  else
  {
    NewHead->NextNode = *Head;
    *Head = NewHead;
  }
}

void SLL_InsertBefore(Node **Head, Node *Current, Node *NewHead)
{
  if (*Head == NULL)
  {
    return;
  }
  else
  {
    Node *Before = *Head;
    while (Before->NextNode != Current)
    {
      Before = Before->NextNode;
    }
    if (Before != NULL)
    {
      SLL_InsertAfter(Before, NewHead);
    }
  }
}

void SLL_DestroyAllNodes(Node **List)
{
  int i = 0;
  int Count = 0;
  Node *Current = NULL;

  Count = SLL_GetNodeCount(*List);
  for (i = 0; i < Count; i++)
  {
    Current = SLL_GetNodeAt(*List, 0);
    if (Current != NULL)
    {
      SLL_RemoveNode(&*List, Current);
      SLL_DestroyNode(Current);
    }
  }
}

int _main(int argc, char const *argv[])
{
  printf("sizeof(Node) = %lu\n", sizeof(Node));     // Node 자료형 크기
  printf("sizeof(Node *) = %lu\n", sizeof(Node *)); // Node를 참조하는 Pointer 크기

  Node *List = NULL;
  Node *MyNode = NULL;
  SLL_AppendNode(&List, SLL_CreateNode(117));
  SLL_AppendNode(&List, SLL_CreateNode(119));
  SLL_AppendNode(&List, SLL_CreateNode(212));

  MyNode = SLL_GetNodeAt(List, 1);
  printf("%d should be 119\n", MyNode->Data);

  SLL_RemoveNode(&List, MyNode);
  SLL_DestroyNode(MyNode);

  return 0;
}
