#pragma once
#include<stdbool.h>
typedef int LTDataType;
typedef struct ListNode{
    LTDataType data;
    struct ListNode*prev;
    struct ListNode*next;
}LTNode;
LTNode* LTInit(void);
void LTDestroy(LTNode* phead);
void LTPrint(LTNode* phead);
bool LTEmpty(LTNode* phead);

void LTPushBack(LTNode* phead, LTDataType x);
void LTPopBack(LTNode* phead);

void LTPushFront(LTNode* phead, LTDataType x);
void LTPopFront(LTNode* phead);

void LTInsert(LTNode* pos, LTDataType x);
void LTErase(LTNode* pos);

LTNode* LTFind(LTNode* phead, LTDataType x);
