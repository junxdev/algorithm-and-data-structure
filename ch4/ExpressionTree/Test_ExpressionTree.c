#include "ExpressionTree.h"

int main(int argc, char const *argv[])
{
  ETNode *Root = NULL;

  char PostfixExpression[20] = "71*52-/";
  ET_BuildExpressionTree(PostfixExpression, &Root);

  printf("Preorder ...\n");
  ET_PreorderPrintTree(Root);
  printf("\n\n");

  printf("Inorder ...\n");
  ET_InorderPrintTree(Root);
  printf("\n\n");

  printf("Postorder ...\n");
  ET_PostorderPrintTree(Root);
  printf("\n");

  printf("Evaluation Result : %f \n", ET_Evaluate(Root));

  ET_DestroyTree(Root);

  return 0;
}
