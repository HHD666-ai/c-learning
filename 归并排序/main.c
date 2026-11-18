#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
void Merge(int *a,int *tmp,int left,int mid,int right){
    int i=left;
    int j=mid+1;
    int k=left;
    while(i<=mid&&j<=right){
        // 相等时先取左区间，保持相等元素的原始顺序。
        if(a[i]<=a[j]){
            tmp[k++]=a[i++];
        }else{
             tmp[k++]=a[j++];
        }
    }
    while(i<=mid){
      tmp[k++] = a[i++];
    }
    while (j <= right)
    {
        tmp[k++] = a[j++];
    }
     for (int i = left; i <= right; i++)
    {
        a[i] = tmp[i];
    }
}void MergeSortInternal(int *a,int *tmp,int left,int right){
if(left>=right){
    return ;

}
    int mid = left + (right - left) / 2;


    MergeSortInternal(a, tmp, left, mid);


    MergeSortInternal(a, tmp, mid + 1, right);
    Merge(a, tmp, left, mid, right);
}void MergeSort(int* a, int n)
{
    if (a == NULL || n <= 1 || (uintmax_t)n > SIZE_MAX / sizeof(*a))
    {
        return;
    }

    int *tmp = malloc((size_t)n * sizeof(*tmp));

    if (tmp == NULL)
    {
        return;
    }

    MergeSortInternal(a, tmp, 0, n - 1);

    free(tmp);
}int main()
{
    int a[] = {7, 4, 6, 2, 9, 1, 5, 3};

    int n = sizeof(a) / sizeof(a[0]);

    printf("排序前：");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    MergeSort(a, n);

    printf("\n排序后: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n");

    return 0;
}
