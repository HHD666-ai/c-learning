#pragma once
typedef int HPDataType;
typedef struct Heap{
    HPDataType *_a;
    int _size;
    int _capacity;
}Heap;
void HeapInit(Heap* hp);
void HeapDestroy(Heap* hp);

void HeapPush(Heap* hp, HPDataType x);
void HeapPop(Heap* hp);

HPDataType HeapTop(Heap* hp);

int HeapSize(Heap* hp);
int HeapEmpty(Heap* hp);