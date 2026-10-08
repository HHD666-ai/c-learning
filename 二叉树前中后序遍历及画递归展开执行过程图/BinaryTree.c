#include "BinaryTree.h"
#include <stdio.h>
#include <stdlib.h>
BTNode*BuyBTNode(int val){
    BTNode*newnode=(BTNode*)malloc(sizeof(BTNode));
    if(newnode==NULL){
        perror("malloc fail");
        return NULL;
    }
    newnode->data=val;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}BTNode* CreateTree(void)
{
    BTNode* nodea = BuyBTNode('a');
    BTNode* nodeb = BuyBTNode('b');
    BTNode* nodec = BuyBTNode('c');
    BTNode* noded = BuyBTNode('d');
    BTNode* nodee = BuyBTNode('e');
    BTNode* nodef = BuyBTNode('f');

    nodea->left = nodeb;
    nodea->right = nodec;

    nodeb->left = noded;
    nodeb->right = nodee;

    nodec->right = nodef;

    return nodea;
}void Preorder(BTNode* root)
{
    if (root == NULL)
    {
        return;
    }

    printf("%c ", root->data);

    Preorder(root->left);
    Preorder(root->right);
}void Inorder(BTNode* root)
{
    if (root == NULL)
    {
        return;
    }

    Inorder(root->left);

    printf("%c ", root->data);

    Inorder(root->right);
}void Postorder(BTNode* root)
{
    if (root == NULL)
    {
        return;
    }

    Postorder(root->left);
    Postorder(root->right);

    printf("%c ", root->data);
}void DestroyTree(BTNode* root)
{
    if (root == NULL)
    {
        return;
    }

    DestroyTree(root->left);
    DestroyTree(root->right);

    free(root);
}
