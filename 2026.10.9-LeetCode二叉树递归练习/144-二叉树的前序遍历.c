#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int count(struct TreeNode* root){
    if(root==NULL){
        return 0;
    }return count(root->left)+count(root->right)+1;
}
void preorder(struct TreeNode*root,int *ret,int*index){
if(root==NULL)return ;
ret[*index]=root->val;
(*index)++;
preorder(root->left,ret,index);
preorder(root->right,ret,index);
}
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize=0;
    int n=count(root);
    if(n==0)return NULL;
    int *ret=(int*)malloc(sizeof(int) * n);
       if (ret == NULL)
    {
        return NULL;
    }preorder(root, ret, returnSize);

    return ret;

}
