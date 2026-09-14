#pragma once
typedef int SLDataType;
typedef struct SListNode{
    SLDataType data;
    struct SListNode* next;
}SLTNode;

void SLTPrint(SLTNode* phead);
void SLTPushBack(SLTNode** pphead,SLDataType x);
void SLTPushFront(SLTNode**pphead,SLDataType x);
void SLTPopFront(SLTNode**pphead);
void SLTPopBack(SLTNode**pphead);
SLTNode* SLTFind(SLTNode*phead,SLDataType x);
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLDataType x);
void SLTErase(SLTNode** pphead, SLTNode* pos);
void SLTInsertAfter(SLTNode* pos, SLDataType x);
void SLTEraseAfter(SLTNode* pos);
void SLTDestroy(SLTNode** pphead);
