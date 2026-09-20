#include<stdio.h>
#include<stdlib.h>
#include"Queue.h"
void QueueInit(Queue*q){
    q->_front=NULL;
    q->_rear=NULL;
}void QueuePush(Queue* q, QDataType data){
    QNode *newnode=(QNode*)malloc(sizeof(QNode));
     if (newnode == NULL)
    {
        perror("malloc fail");
        return;
    }
    newnode->_data=data;
    newnode->_next=NULL;
    if(q->_rear==NULL){
         q->_front=newnode;
    q->_rear=newnode;
    }else{
        q->_rear->_next=newnode;
        q->_rear=newnode;
    }
}void QueuePop(Queue* q){
    if(q->_front==NULL){
        return ;
    }
    QNode*next=q->_front->_next;
    free(q->_front);
    q->_front=next;
    if(q->_front==NULL){
        q->_rear=NULL;
    }
}QDataType QueueFront(Queue* q)
{
    return q->_front->_data;
}QDataType QueueBack(Queue* q)
{
    return q->_rear->_data;
}int QueueEmpty(Queue* q)
{
    return q->_front == NULL;
}int QueueSize(Queue* q){
    int size=0;
    QNode*cur=q->_front;
    while(cur!=NULL){
        size++;
        cur=cur->_next;
    }
    return size;
}void QueueDestroy(Queue* q)
{
    QNode* cur = q->_front;

    while (cur != NULL)
    {
        QNode* next = cur->_next;
        free(cur);
        cur = next;
    }

    q->_front = NULL;
    q->_rear = NULL;
}
