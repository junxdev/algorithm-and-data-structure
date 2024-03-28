#include "DoublyLinkedList.h"

int main(int argc, char const *argv[])
{
  int i = 0;
  int Count = 0;
  Node *List = NULL;
  Node *Current = NULL;
  Node *NewNode = NULL;

  for (i = 0; i < 5; i++)
  {
    NewNode = DLL_CreateNode(i);
    DLL_AppendNode(&List, NewNode);
  }

  Count = DLL_GetNodeCount(List);
  for (i = 0; i < Count; i++)
  {
    Current = DLL_GetNodeAt(List, i);
    printf("List[%d] : %d\n", i, Current->Data);
  }

  printf("\nInserting 3000 After [2]...\n\n");
  Current = DLL_GetNodeAt(List, 2);
  NewNode = DLL_CreateNode(3000);
  DLL_InsertAfter(Current, NewNode);

  Count = DLL_GetNodeCount(List);
  for (i = 0; i < Count; i++)
  {
    Current = DLL_GetNodeAt(List, i);
    printf("List[%d] : %d\n", i, Current->Data);
  }

  PrintReverse(List);

  Count = DLL_GetNodeCount(List);
  printf("\nDestroying List(%d)...\n", Count);
  for (i = 0; i < Count; i++)
  {
    Current = DLL_GetNodeAt(List, 0);
    if (Current != NULL)
    {
      DLL_RemoveNode(&List, Current);
      DLL_DestroyNode(Current);
    }
  }

  Count = DLL_GetNodeCount(List);
  printf("\nAfter Destroying List, The Count is %d\n", Count);

  return 0;
}
