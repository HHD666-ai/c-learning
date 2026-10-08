#pragma once
typedef char BTDataType;
typedef struct BinaryTreeNode{
    BTDataType data;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
}BTNode;
BTNode*BuyBTNode(int val);
BTNode* CreateTree(void);
void Preorder(BTNode* root);

// 中序遍历
void Inorder(BTNode* root);

// 后序遍历
void Postorder(BTNode* root);
void DestroyTree(BTNode* root);
