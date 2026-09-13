#pragma once
typedef int SLDataType;
typedef struct SListNode{
    SLDataType data;
    struct SListNode* next;
}SLTNode;

void SLTPrint(SLTNode* phead);
void SLTPushBack(SLTNode** pphead,SLDataType x);
