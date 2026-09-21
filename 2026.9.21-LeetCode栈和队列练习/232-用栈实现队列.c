#include <stdbool.h>
#include <stdlib.h>

typedef struct StackNode{
    int data;
    struct StackNode*next;
}StackNode;
typedef struct Stack
{
    StackNode* top;
    int size;
} Stack;

typedef struct {
    Stack inStack;
    Stack outStack;
} MyQueue;

void stackinit(Stack *st){
    st->top=NULL;
    st->size=0;
}

void stackpush(Stack *st,int x){
    StackNode* newnode=(StackNode*)malloc(sizeof(StackNode));
    newnode->data=x;
    newnode->next=st->top;
    st->top=newnode;
    st->size++;
}

void stackpop(Stack *st){
    if(st->top==NULL){
        return;
    }
    StackNode *next=st->top->next;
    free(st->top);
    st->top=next;
    st->size--;
}

int stacktop(Stack* st)
{
    return st->top->data;
}

bool stackempty(Stack* st)
{
    return st->top == NULL;
}

void stackdestroy(Stack*st){
    StackNode *cur=st->top;
    while(cur!=NULL){
        StackNode*next=cur->next;
        free(cur);
        cur=next;
    }
    st->top=NULL;
    st->size=0;
}

MyQueue* myQueueCreate() {
    MyQueue*obj=(MyQueue*)malloc(sizeof(MyQueue));
    if(obj==NULL){
        return NULL;
    }
    stackinit(&obj->inStack);
    stackinit(&obj->outStack);
    return obj;
}

void myQueuePush(MyQueue* obj, int x) {
    stackpush(&obj->inStack, x);
}

int myQueuePop(MyQueue* obj) {
    if(stackempty(&obj->outStack)){
        while(!stackempty(&obj->inStack)){
            int x=stacktop(&obj->inStack);
            stackpop(&obj->inStack);
            stackpush(&obj->outStack,x);
        }
    }
    int ret=stacktop(&obj->outStack);
    stackpop(&obj->outStack);
    return ret;
}

int myQueuePeek(MyQueue* obj) {
    if(stackempty(&obj->outStack)){
        while(!stackempty(&obj->inStack)){
            int x=stacktop(&obj->inStack);
            stackpop(&obj->inStack);
            stackpush(&obj->outStack,x);
        }
    }
    int ret=stacktop(&obj->outStack);
    return ret;
}

bool myQueueEmpty(MyQueue* obj) {
    return stackempty(&obj->outStack)&&stackempty(&obj->inStack);
}

void myQueueFree(MyQueue* obj) {
    stackdestroy(&obj->inStack);
    stackdestroy(&obj->outStack);
    free(obj);
}
