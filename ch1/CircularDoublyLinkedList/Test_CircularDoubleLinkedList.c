#include "CircularDoublyLinkedList.h"

int main(int argc, char const *argv[])
{
  int i = 0;
  int Count = 0;
  Node *List = NULL;
  Node *Current = NULL;
  Node *NewNode = NULL;

  for (i = 0; i < 5; i++)
  {
    NewNode = CDLL_CreateNode(i);
    CDLL_AppendNode(&List, NewNode);
  }

  Count = CDLL_GetNodeCount(List);
  for (i = 0; i < Count; i++)
  {
    Current = CDLL_GetNodeAt(List, i);
    printf("List[%d] : %d\n", i, Current->Data);
  }

  printf("\nInserting 3000 After [2]...\n\n");
  Current = CDLL_GetNodeAt(List, 2);
  NewNode = CDLL_CreateNode(3000);
  CDLL_InsertAfter(Current, NewNode);

  printf("\nRemoving Node at 2...\n");
  Current = CDLL_GetNodeAt(List, 2);
  CDLL_RemoveNode(&List, Current);
  CDLL_DestroyNode(Current);

  Count = CDLL_GetNodeCount(List);
  for (i = 0; i < Count * 2; i++)
  {
    if (i == 0)
      Current = List;
    else
      Current = Current->NextNode;

    printf("List[%d] : %d\n", i, Current->Data);
  }

  printf("\nDestroying List(%d)...\n", Count);
  Count = CDLL_GetNodeCount(List);
  for (i = 0; i < Count; i++)
  {
    Current = CDLL_GetNodeAt(List, 0);
    if (Current != NULL)
    {
      CDLL_RemoveNode(&List, Current);
      CDLL_DestroyNode(Current);
    }
  }

  Count = CDLL_GetNodeCount(List);
  printf("\nAfter Destroying List, The Count is %d\n", Count);

  return 0;
}
