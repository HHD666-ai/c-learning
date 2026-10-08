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
    int a[] = { 5, 3, 8, 1, 6 };

    int n = sizeof(a) / sizeof(a[0]);

    HeapSort(a, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}
