#include "LinkedList.h"

int main(int argc, char const *argv[])
{
  int i = 0;
  int Count = 0;
  Node *List = NULL;
  Node *Current = NULL;
  Node *NewNode = NULL;

  for (i = 0; i < 5; i++)
  {
    NewNode = SLL_CreateNode(i);
    SLL_AppendNode(&List, NewNode);
  }

  NewNode = SLL_CreateNode(-1);
  SLL_InsertNewHead(&List, NewNode);

  NewNode = SLL_CreateNode(-2);
  SLL_InsertNewHead(&List, NewNode);

  Count = SLL_GetNodeCount(List);
  for (i = 0; i < Count; i++)
  {
    Current = SLL_GetNodeAt(List, i);
    printf("List[%d] : %d\n", i, Current->Data);
  }

  printf("\nInserting 3000 After [2]...\n\n");
  Current = SLL_GetNodeAt(List, 2);
  NewNode = SLL_CreateNode(3000);
  SLL_InsertAfter(Current, NewNode);

  printf("\nInserting 4000 Before [2]...\n\n");
  NewNode = SLL_CreateNode(4000);
  SLL_InsertBefore(&List, Current, NewNode);

  Count = SLL_GetNodeCount(List);
  for (i = 0; i < Count; i++)
  {
    Current = SLL_GetNodeAt(List, i);
    printf("List[%d] : %d\n", i, Current->Data);
  }

  Count = SLL_GetNodeCount(List);
  printf("\nDestroying List(%d)...\n", Count);
  // for (i = 0; i < Count; i++)
  // {
  //   Current = SLL_GetNodeAt(List, 0);
  //   if (Current != NULL)
  //   {
  //     SLL_RemoveNode(&List, Current);
  //     SLL_DestroyNode(Current);
  //   }
  // }
  SLL_DestroyAllNodes(&List);

  Count = SLL_GetNodeCount(List);
  printf("\nAfter Destroying List, The Count is %d\n", Count);

  return 0;
}
