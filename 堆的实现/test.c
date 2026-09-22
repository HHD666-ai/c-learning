#include <stdio.h>
#include "Heap.h"

int main()
{
    Heap hp;
    HeapInit(&hp);

    HeapPush(&hp, 5);
    HeapPush(&hp, 3);
    HeapPush(&hp, 8);
    HeapPush(&hp, 1);
    HeapPush(&hp, 6);

    printf("堆顶：%d\n", HeapTop(&hp));
    printf("大小：%d\n", HeapSize(&hp));

    while (!HeapEmpty(&hp))
    {
        printf("%d ", HeapTop(&hp));
        HeapPop(&hp);
    }

    printf("\n");

    HeapDestroy(&hp);

    return 0;
}