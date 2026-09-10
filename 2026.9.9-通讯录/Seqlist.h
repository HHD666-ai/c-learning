#pragma once
#include "contact.h"
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define INIT_CAPACITY 4
typedef PeoInfo SLDataType;

typedef struct SeqList{
    SLDataType* a;
    int size;
    int capacity;

}SL;

void SLInit(SL* ps);
void SLPushBack(SL* ps,SLDataType x);
void SLPrintf(SL* ps);
void SLCheckCapacity(SL* ps);
void SLPopBack(SL*ps);
void SLPushFront(SL*ps,SLDataType x);
void SLPopFront(SL*ps);
void SLInsert(SL*ps,int pos,SLDataType x);
void SLErase(SL*ps,int pos);
int  SLFind(SL* ps,const char* name);
void SLModify(SL*ps,int pos,SLDataType x);
