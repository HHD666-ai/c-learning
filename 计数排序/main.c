#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// 只支持非负整数。遇到负数或内存申请失败时，原数组保持不变。
void CountSort(int *a, int n)
{
    if (a == NULL || n <= 1)
        return;

    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0)
            return;
        if (a[i] > max)
            max = a[i];
    }
    if ((uintmax_t)max >= SIZE_MAX / sizeof(int))
        return;

    size_t range = (size_t)max + 1;
    int *count = calloc(range, sizeof(*count));
    if (count == NULL)
        return;

    for (int i = 0; i < n; i++)
        count[a[i]]++;

    int index = 0;
    for (size_t value = 0; value < range; value++)
    {
        while (count[value] > 0)
        {
            a[index++] = (int)value;
            count[value]--;
        }
    }
    free(count);
}

int main(void)
{
    int a[] = {3, 3, 5, 2, 5, 5};

    int n = sizeof(a) / sizeof(a[0]);

    CountSort(a, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n");

    return 0;
}
