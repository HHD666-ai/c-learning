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


}