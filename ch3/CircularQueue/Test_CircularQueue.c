#include "CircularQueue.h"

int main(int argc, char const *argv[])
{
  int i;
  CircularQueue *Queue;

  CQ_CreateQueue(&Queue, 10);

  CQ_Enqueue(Queue, 1);
  CQ_Enqueue(Queue, 2);
  CQ_Enqueue(Queue, 3);
  CQ_Enqueue(Queue, 4);

  for (i = 0; i < 3; i++)
  {
    printf("Dequeue: %d, ", CQ_Dequeue(Queue));
    printf("Front:%d, Rear:%d\n", Queue->Front, Queue->Rear);
  }

  i = 100;
  while (CQ_IsFull(Queue) == 0)
  {
    CQ_Enqueue(Queue, i++);
  }

  printf("\nCapacity: %d, Size: %d\n", Queue->Capacity, CQ_GetSize(Queue));

  while (CQ_IsEmpty(Queue) == 0)
  {
    printf("Dequeue: %d, ", CQ_Dequeue(Queue));
    printf("Front:%d, Rear:%d\n", Queue->Front, Queue->Rear);
  }
  printf("Is Empty: %d, Is Full: %d\n", CQ_IsEmpty(Queue), CQ_IsFull(Queue));

  while (CQ_IsFull(Queue) == 0)
  {
    CQ_Enqueue(Queue, i++);
  }
  CQ_Enqueue(Queue, i++);
  printf("\nFront:%d, Rear:%d\n", Queue->Front, Queue->Rear);
  printf("Is Empty: %d, Is Full: %d\n", CQ_IsEmpty(Queue), CQ_IsFull(Queue));
  // 현재 구현에서 큐가 데이터로 포화지만 전단, 후단 위치가 같으면 공백 상태로 판정

  CQ_DestroyQueue(Queue);
  return 0;
}
