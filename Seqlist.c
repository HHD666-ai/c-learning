#include "Seqlist.h"
#include<string.h>
void SLInit(SL* ps){
    assert(ps);
    ps->a =(SLDataType*)malloc(sizeof(SLDataType)* INIT_CAPACITY);
    if(ps->a==NULL){
        perror("malloc fail");
        exit(1);
    }
    ps->size=0;
    ps->capacity=INIT_CAPACITY;
}
void SLPushBack(SL* ps,SLDataType x){
    assert(ps);
    SLCheckCapacity(ps);  
    ps->a[ps->size++] = x; 
    // ps->size++;         
   }

void SLPrintf(SL* ps){
    assert(ps);
    for(int i=0;i<ps->size;i++){
        printf("姓名：%s\n", ps->a[i].name);
        printf("性别：%s\n", ps->a[i].sex);
        printf("年龄：%d\n", ps->a[i].age);
        printf("电话：%s\n", ps->a[i].tel);
        printf("地址：%s\n", ps->a[i].addr);
        printf("-------------\n");
}
    }
    
void SLCheckCapacity(SL* ps){
assert(ps);
if(ps->size==ps->capacity){
    int newCapacity=ps->capacity*2;
    SLDataType*tmp =realloc(ps->a,sizeof(SLDataType)*newCapacity);
    if(tmp==NULL){
        perror("realloc fail");
        exit(1);
    }
    ps->a=tmp;
    ps->capacity=newCapacity;
}

}
void SLPopBack(SL*ps){
    assert(ps);
if(ps->size==0){
    return;
}
ps->size--;

}
void SLPushFront(SL*ps,SLDataType x){
    assert(ps);
    SLCheckCapacity(ps);
    for(int i=ps->size;i>0;i--){
        ps->a[i]=ps->a[i-1];
    }
    ps->a[0]=x;
    ps->size++;
}
void SLPopFront(SL*ps){
    assert(ps);
    if(ps->size==0){
        return ;

    }for( int i=1;i<ps->size;i++){
        ps->a[i-1]=ps->a[i];
    }
    ps->size--;
}void SLInsert(SL*ps,int pos,SLDataType x){
    assert(ps);
    assert(pos>=0&&pos<=ps->size);
    SLCheckCapacity(ps);
    for(int i=ps->size;i>pos;i--){
        ps->a[i]=ps->a[i-1];

    }
    ps->a[pos]=x;
    ps->size++;
}
void SLErase(SL*ps,int pos){
    assert(ps);
    assert(pos>=0&&pos<ps->size);
    for(int i=pos+1;i<ps->size;i++){
        ps->a[i-1]=ps->a[i];
    }
    ps->size--;
}int SLFind(SL* ps,const char* name){
    assert(ps);
    assert(name);
    for(int i=0;i<ps->size;i++){
        if(strcmp(ps->a[i].name,name)==0){
            return i;
        }
    }return -1;
}
void SLModify(SL*ps,int pos,SLDataType x){
    assert(ps);
    assert(pos>=0&&pos<ps->size);
    ps->a[pos]=x;
}

