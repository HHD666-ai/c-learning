#include <stdbool.h>
#include <stdlib.h>

typedef struct QNode{
    int data;
    struct QNode*next;
}QNode;
typedef struct Queue{
    QNode*front;
    QNode*rear;
    int size;
}Queue;

typedef struct {
    Queue q1;
    Queue q2;
} MyStack;

void QueueInit(Queue* q)
{
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}

void QueuePush(Queue* q, int x)
{
    QNode* newnode = (QNode*)malloc(sizeof(QNode));

    newnode->data = x;
    newnode->next = NULL;

    if (q->rear == NULL)
    {
        q->front = newnode;
        q->rear = newnode;
    }
    else
    {
        q->rear->next = newnode;
        q->rear = newnode;
    }

    q->size++;
}

int QueueFront(Queue* q)
{
    return q->front->data;
}

void QueuePop(Queue* q){
    QNode* next = q->front->next;
    free(q->front);
    q->front=next;
    if (q->front == NULL)
    {
        q->rear = NULL;
    }
    q->size--;
}

void QueueDestroy(Queue* q)
{
    QNode* cur = q->front;

    while (cur != NULL)
    {
        QNode* next = cur->next;
        free(cur);
        cur = next;
    }

    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}

MyStack* myStackCreate() {
    MyStack* obj=(MyStack*)malloc(sizeof(MyStack));

    if (obj == NULL)
    {
        return NULL;
    }

    QueueInit(&obj->q1);
    QueueInit(&obj->q2);

    return obj;
}

void myStackPush(MyStack* obj, int x) {
    if (obj->q1.size > 0)
    {
        QueuePush(&obj->q1, x);
    }
    else if (obj->q2.size > 0)
    {
        QueuePush(&obj->q2, x);
    }
    else
    {
        QueuePush(&obj->q1, x);
    }
}

int myStackPop(MyStack* obj) {
    Queue *emptyQ;
    Queue *noemptyQ;
    if(obj->q1.size>0){
        noemptyQ = &obj->q1;
        emptyQ = &obj->q2;
    }else{
        noemptyQ = &obj->q2;
        emptyQ = &obj->q1;
    }
    while(noemptyQ->size>1){
        int x=QueueFront(noemptyQ);
        QueuePop(noemptyQ);
        QueuePush(emptyQ,x);
    }
    int ret = QueueFront(noemptyQ);
    QueuePop(noemptyQ);
    return ret;
}

int myStackTop(MyStack* obj) {
    Queue *emptyQ;
    Queue *noemptyQ;
    if(obj->q1.size>0){
        noemptyQ = &obj->q1;
        emptyQ = &obj->q2;
    }else{
        noemptyQ = &obj->q2;
        emptyQ = &obj->q1;
    }
    while(noemptyQ->size>1){
        int x=QueueFront(noemptyQ);
        QueuePop(noemptyQ);
        QueuePush(emptyQ,x);
    }
    int ret = QueueFront(noemptyQ);
    QueuePop(noemptyQ);
    QueuePush(emptyQ,ret);
    return ret;
}

bool myStackEmpty(MyStack* obj) {
    return obj->q1.size == 0 && obj->q2.size == 0;
}

void myStackFree(MyStack* obj) {
    QueueDestroy(&obj->q1);
    QueueDestroy(&obj->q2);
    free(obj);
}
