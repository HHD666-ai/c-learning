#include<stdio.h>
#include<stdlib.h>
#include"list.h"
LTNode *LTInit(void){
    LTNode*phead=(LTNode*)malloc(sizeof(LTNode));
    if(phead==NULL){
        printf("malloc fail");
        return NULL;
    }
    phead->next=phead;
    phead->prev=phead;
    return phead;
}
bool LTEmpty(LTNode* phead){
    return phead->next==phead;
}void LTPrint(LTNode* phead){
    LTNode *cur=phead->next;
    while(cur!=phead){
        printf("%d",cur->data);
    cur=cur->next;

    }
    printf("\n");

}
void LTPushBack(LTNode* phead, LTDataType x){
    LTNode*newnode=(LTNode*)malloc(sizeof(LTNode));
     if (newnode == NULL)
    {
        perror("malloc fail");
        return;
    }newnode->data=x;
LTNode*tail=phead->prev;
tail->next=newnode;
newnode->prev=tail;
newnode->next=phead;
phead->prev=newnode;

}void LTPushFront(LTNode* phead, LTDataType x){
    LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
    if (newnode == NULL)
    {
        perror("malloc fail");
        return;
    }

    newnode->data = x;
    LTNode*first=phead->next;
    phead->next=newnode;
    newnode->prev=phead;
    newnode->next=first;
    first->prev=newnode;
}
void LTPopBack(LTNode* phead){
    if(LTEmpty(phead)){
        return ;
    }

LTNode*tail=phead->prev;
LTNode*prev=tail->prev;
prev->next=phead;
phead->prev=prev;
    free(tail);

}
void LTPopFront(LTNode* phead)
{
    if (LTEmpty(phead))
    {
        return;
    }
      LTNode* first = phead->next;
    LTNode* second = first->next;

    phead->next = second;
    second->prev = phead;

    free(first);

}LTNode* LTFind(LTNode* phead, LTDataType x)
{
    LTNode* cur = phead->next;

    while (cur != phead)
    {
        if (cur->data == x)
        {
            return cur;
        }

        cur = cur->next;
    }

    return NULL;
}void LTInsert(LTNode* pos, LTDataType x){
       LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
    if (newnode == NULL)
    {
        perror("malloc fail");
        return;
    }

    newnode->data = x;
    LTNode*prev=pos->prev;
    prev->next=newnode;
    newnode->prev=prev;
    newnode->next=pos;
    pos->prev=newnode;
}void LTErase(LTNode* pos)
{
    LTNode* prev = pos->prev;
    LTNode* next = pos->next;

    prev->next = next;
    next->prev = prev;

    free(pos);
}void LTDestroy(LTNode* phead){
    LTNode*cur=phead->next;
    while(cur!=phead){
        LTNode*next=cur->next;
        free(cur);
        cur=next;
    }
    free(phead);
}
