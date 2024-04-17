#include <stdio.h>

void BubbleSort(int DataSet[], int Length)
{
  int i = 0, j = 0, temp = 0, sorted = 1;

  for (i = 0; i < Length - 1; i++)
  {
    sorted = 1;

    for (j = 0; j < Length - (i + 1); j++)
    {
      if (DataSet[j] > DataSet[j + 1])
      {
        temp = DataSet[j + 1];
        DataSet[j + 1] = DataSet[j];
        DataSet[j] = temp;
        sorted = 0;
      }
    }

    if (sorted)
      break;
  }
}

int main(int argc, char const *argv[])
{
  int DataSet[] = {2, 1, 3, 4, 5, 6};
  int Length = sizeof DataSet / sizeof DataSet[0];
  int i = 0;

  BubbleSort(DataSet, Length);

  for (i = 0; i < Length; i++)
  {
    printf("%d ", DataSet[i]);
  }

  printf("\n");

  return 0;
}
