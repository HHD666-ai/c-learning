
#include <stdio.h>

// 打印数组
void PrintArray(const int* a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// 冒泡排序（升序）
void BubbleSort(int* a, int n)
{
    if (a == NULL || n <= 1)
        return;

    for (int i = 0; i < n - 1; i++)
    {
        int flag = 0;

        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;

                flag = 1;
            }
        }

        // 本趟没有交换，说明数组已经有序
        if (flag == 0)
            break;
    }
}

int main()
{
    int a[] = {5, 2, 4, 1, 8, 3};

    int n = sizeof(a) / sizeof(a[0]);

    printf("排序前：");
    PrintArray(a, n);

    BubbleSort(a, n);

    printf("排序后：");
    PrintArray(a, n);

    return 0;
}
