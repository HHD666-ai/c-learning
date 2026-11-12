#pragma once
typedef char BTDataType;
typedef struct BinaryTreeNode{
    BTDataType data;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
}BTNode;
BTNode*BuyBTNode(int val);
/* Returns NULL on allocation failure after freeing all partial nodes. */
BTNode* CreateTree(void);
void Preorder(BTNode* root);

// 中序遍历
void Inorder(BTNode* root);

// 后序遍历
void Postorder(BTNode* root);
void DestroyTree(BTNode* root);
int TreeLevelKSize(BTNode* root, int k);
/* Returns 1 for complete, 0 for incomplete, -1 on allocation failure. */
int TreeComplete(BTNode* root);
