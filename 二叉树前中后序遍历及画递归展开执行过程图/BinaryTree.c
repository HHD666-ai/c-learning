#include "BinaryTree.h"
#include "Queue.h"
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

    /* Nodes are not linked yet, so partial allocation can be freed directly. */
    if (nodea == NULL || nodeb == NULL || nodec == NULL
        || noded == NULL || nodee == NULL || nodef == NULL)
    {
        free(nodea);
        free(nodeb);
        free(nodec);
        free(noded);
        free(nodee);
        free(nodef);
        return NULL;
    }

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

int TreeLevelKSize(BTNode* root, int k)
{
    if (root == NULL || k < 1)
        return 0;
    if (k == 1)
        return 1;
    return TreeLevelKSize(root->left, k - 1)
         + TreeLevelKSize(root->right, k - 1);
}

int TreeComplete(BTNode* root)
{
    Queue q;
    QueueInit(&q);
    int result = 1;
    if (!QueuePush(&q, root))
    {
        result = -1;
        goto cleanup;
    }
    while (!QueueEmpty(&q))
    {
        BTNode* node = QueueFront(&q);
        QueuePop(&q);
        if (node == NULL)
            break;
        /* NULL children must also enter the queue. */
        if (!QueuePush(&q, node->left) || !QueuePush(&q, node->right))
        {
            result = -1;
            goto cleanup;
        }
    }
    while (!QueueEmpty(&q))
    {
        if (QueueFront(&q) != NULL)
        {
            result = 0;
            break;
        }
        QueuePop(&q);
    }
cleanup:
    QueueDestroy(&q);
    return result;
}
