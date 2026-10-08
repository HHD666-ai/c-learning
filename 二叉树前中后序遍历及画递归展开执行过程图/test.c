#include <stdio.h>
#include "BinaryTree.h"

int main()
{
    BTNode* root = CreateTree();

    printf("Preorder: ");
    Preorder(root);
    printf("\n");

    printf("Inorder: ");
    Inorder(root);
    printf("\n");

    printf("Postorder: ");
    Postorder(root);
    printf("\n");

    DestroyTree(root);

    return 0;
}
