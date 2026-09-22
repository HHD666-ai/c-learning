#include "Heap.h"
#include<stdio.h>
#include<stdlib.h>
void HeapInit(Heap* hp)
{
    hp->_a = NULL;
    hp->_size = 0;
    hp->_capacity = 0;
}void Swap(HPDataType* px,HPDataType* py){
    HPDataType tmp=*px;
    *px=*py;
    *py=tmp;
}void AdjustUp( HPDataType *_a,int child){
    int parent=(child-1)/2;
    while(child>0){
        if(_a[child]<_a[parent]){
            Swap(&_a[child],&_a[parent]);
            child=parent;
            parent=(child-1)/2;
        }
        else{break;}
    }
}void AdjustDown(HPDataType*a,int size,int parent){
    int child=parent*2+1;
    while(child<size){
        if(child+1<size&&a[child+1]<a[child]){
            child++;
        }if(a[child]<a[parent]){
            Swap(&a[child], &a[parent]);
            parent=child;
            child=parent*2+1;
        }else break;
    }
}

void HeapPush(Heap*hp,HPDataType x){
    if(hp->_size==hp->_capacity){
        int newcapacity=hp->_capacity==0?4:hp->_capacity*2;
        HPDataType*tmp=(HPDataType*)realloc(hp->_a,sizeof(HPDataType)*newcapacity);

        if (tmp == NULL)
        {
            perror("realloc fail");
            return;
        }
        hp->_a=tmp;
        hp->_capacity=newcapacity;
    }
    hp->_a[hp->_size]=x;
    AdjustUp(hp->_a,hp->_size);
    hp->_size++;
}void HeapPop(Heap* hp){
    if(hp->_size==0){
        return ;
    }
    Swap(&hp->_a[0],&hp->_a[hp->_size-1]);
    hp->_size--;
    AdjustDown(hp->_a,hp->_size,0);
}
HPDataType HeapTop(Heap*hp){
    return hp->_a[0];
}int HeapSize(Heap* hp)
{
    return hp->_size;
}int HeapEmpty(Heap* hp)
{
    return hp->_size == 0;
}void HeapDestroy(Heap* hp)
{
    free(hp->_a);

    hp->_a = NULL;
    hp->_size = 0;
    hp->_capacity = 0;
}