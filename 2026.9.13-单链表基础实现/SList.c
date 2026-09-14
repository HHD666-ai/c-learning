#include <stdio.h>
#include <stdlib.h>
#include "SList.h"

void SLTPrint(SLTNode*phead){
    SLTNode* cur=phead;
    while(cur != NULL){
        printf("%d->",cur->data);
        cur=cur->next;
    }
    printf("NULL\n");
}
void SLTPushBack(SLTNode **pphead,SLDataType x){
    if(pphead==NULL){ return; }
 
    SLTNode* newnode=(SLTNode*)malloc(sizeof(SLTNode));
    if(newnode==NULL){
        perror("malloc fail");
        return ;
    }
    newnode->data=x;
    newnode->next=NULL;
 if(*pphead==NULL){
    *pphead=newnode;
 }
 else{
    SLTNode* tail=*pphead;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    tail->next=newnode;
 }


}void SLTPushFront(SLTNode**pphead,SLDataType x){
    if(pphead==NULL){ return; }
    SLTNode*newnode=(SLTNode*)malloc(sizeof(SLTNode));
    if(newnode==NULL){
        perror("malloc fail");
        return ;
    }newnode->data=x;
    newnode->next=*pphead;
    *pphead=newnode;
}
void SLTPopFront(SLTNode**pphead){
    if(pphead==NULL || *pphead==NULL){
        return ;
    }
    SLTNode* next=(*pphead)->next;
    free(*pphead);
    *pphead=next;
}
void SLTPopBack(SLTNode**pphead){
    if(pphead==NULL || *pphead==NULL){
        return ;

    }if((*pphead)->next==NULL){
        free(*pphead);
        *pphead=NULL;
        return ;
    }
    SLTNode*prev=NULL;
    SLTNode*tail=*pphead;
    while(tail->next!=NULL){
        prev=tail;
        tail=tail->next;
    }free(tail);
    prev->next=NULL;
}
SLTNode* SLTFind(SLTNode*phead,SLDataType x){
SLTNode*cur=phead;
while(cur!=NULL){
    if(cur->data==x){
        return cur;
    }cur=cur->next;
}
return NULL;
}
void SLTInsert(SLTNode**pphead,SLTNode* pos,SLDataType x){
    if(pphead==NULL || pos==NULL){ return; }
    if(pos==*pphead){
        SLTPushFront(pphead, x);
        return ;

    }
    SLTNode*prev=*pphead;
    while(prev!=NULL && prev->next!=pos){
        prev=prev->next;
    }
    if(prev==NULL){ return; }
    SLTNode* newnode=(SLTNode*)malloc(sizeof(SLTNode));
    if(newnode==NULL){
        perror("malloc fail");
        return ;
    }
newnode->data=x;
newnode->next=pos;
prev->next=newnode;

}
void SLTErase(SLTNode** pphead, SLTNode* pos){
    if(pphead==NULL || pos==NULL){ return; }
    if (pos == *pphead)
    {
        SLTPopFront(pphead);
        return;
    }
    SLTNode* prev = *pphead;

    while (prev != NULL && prev->next != pos)
    {
        prev = prev->next;
    }

    if(prev==NULL){ return; }
    prev->next = pos->next;

    free(pos);
}void SLTInsertAfter(SLTNode* pos, SLDataType x){
    if(pos==NULL){ return; }
    SLTNode*newnode=(SLTNode*)malloc(sizeof(SLTNode));
     if(newnode==NULL){
        perror("malloc fail");
        return ;
    }newnode->data=x;
    newnode->next=pos->next;
    pos->next=newnode;

}
void SLTEraseAfter(SLTNode* pos){
    if (pos == NULL || pos->next == NULL)
    {
        return;
    }
    SLTNode*del=pos->next;
    pos->next=del->next;
    free(del);
}void SLTDestroy(SLTNode** pphead)
{
    if(pphead==NULL){ return; }
    SLTNode* cur = *pphead;

    while (cur != NULL)
    {
        SLTNode* next = cur->next;

        free(cur);

        cur = next;
    }

    *pphead = NULL;
}

