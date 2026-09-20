#include<stdio.h>
#include<stdlib.h>
#include"Stack.h"
void StackInit(Stack*ps){
    ps->_a=NULL;
    ps->_top=0;
    ps->_capacity=0;
}
void StackPush(Stack* ps, STDataType data)
{if(ps->_capacity==ps->_top){
    int newCapacity=ps->_capacity==0?4:ps->_capacity*2;
    STDataType *tmp=(STDataType*)realloc(ps->_a,sizeof(STDataType)*newCapacity);
if(tmp==NULL){
    perror("realloc fail");
    return ;
}ps->_a=tmp;
ps->_capacity=newCapacity;
}
 ps->_a[ps->_top] = data;
    ps->_top++;
}void StackPop(Stack* ps)
{
    if (ps->_top == 0)
    {
        return;
    }

    ps->_top--;
}
STDataType StackTop(Stack* ps)
{
    return ps->_a[ps->_top - 1];
}
int StackSize(Stack* ps)
{
    return ps->_top;
}
int StackEmpty(Stack* ps)
{
    return ps->_top == 0;
}
void StackDestroy(Stack* ps)
{
    free(ps->_a);

    ps->_a = NULL;
    ps->_top = 0;
    ps->_capacity = 0;
}
