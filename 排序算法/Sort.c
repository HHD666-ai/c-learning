#include "Sort.h"

void InsertSort(int* a, int n)
{
    if (n <= 1)
        return;
    for (int i = 0; i < n - 1; ++i)
    {
        int end = i;
        int tmp = a[end + 1];
        while (end >= 0 && tmp < a[end])
        {
            a[end + 1] = a[end];
            --end;
        }
        a[end + 1] = tmp;
    }
}

void ShellSort(int* a, int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        /* i++ visits all groups; i < n-gap keeps i+gap in bounds. */
        for (int i = 0; i < n - gap; ++i)
        {
            int end = i;
            int tmp = a[end + gap];
            while (end >= 0 && tmp < a[end])
            {
                a[end + gap] = a[end];
                end -= gap;
            }
            a[end + gap] = tmp;
        }
    }
}

void SelectSort(int* a, int n)
{
    if (n <= 1)
        return;

    for (int i = 0; i < n - 1; ++i)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (a[j] < a[minIndex])
                minIndex = j;
        }
        if (minIndex != i)
        {
            int tmp = a[i];
            a[i] = a[minIndex];
            a[minIndex] = tmp;
        }
    }
}

/* Max-heap adjustment; both subtrees must already be heaps. */
static void AdjustDown(int* a, int n, int root)
{
    if (n <= 1 || root < 0 || root >= n)
        return;

    int parent = root;
    /* Calculate child indices only when parent is not a leaf. */
    while (parent < n / 2)
    {
        int child = parent * 2 + 1;
        if (child + 1 < n && a[child + 1] > a[child])
            ++child;
        if (a[child] > a[parent])
        {
            int tmp = a[parent];
            a[parent] = a[child];
            a[child] = tmp;
            parent = child;
        }
        else
            break;
    }
}

void HeapSort(int* a, int n)
{
    if (n <= 1)
        return;

    for (int i = n / 2 - 1; i >= 0; i--)
        AdjustDown(a, n, i);

    for (int end = n - 1; end > 0; --end)
    {
        int tmp = a[0];
        a[0] = a[end];
        a[end] = tmp;
        /* end is the remaining heap size; a[end] is already sorted. */
        AdjustDown(a, end, 0);
    }
}

static void SortSwap(int* x, int* y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void QuickSort(int* a, int left, int right)
{
    while (left < right)
    {
        int key = left;
        int L = left;
        int R = right;
        while (L < R)
        {
            /* With the left pivot, R must move first. */
            while (L < R && a[R] >= a[key])
                --R;
            while (L < R && a[L] <= a[key])
                ++L;
            if (L < R)
                SortSwap(&a[L], &a[R]);
        }
        SortSwap(&a[key], &a[L]);

        /* Recurse only into the smaller side to bound stack depth. */
        if (L - left < right - L)
        {
            if (left < L)
                QuickSort(a, left, L - 1);
            if (L == right)
                break;
            left = L + 1;
        }
        else
        {
            if (L < right)
                QuickSort(a, L + 1, right);
            if (L == left)
                break;
            right = L - 1;
        }
    }
}
