#include<stdio.h>
int PartSort(int *a,int left,int right){
    int keyi=right;
    int cur=left;
    int prev=left-1;
    while(cur<keyi){
        if(a[cur]<a[keyi]){
            prev++;
            int tmp=a[cur];
            a[cur]=a[prev];
            a[prev]=tmp;

        }
        cur++;
    }
    prev++;
     int tmp=a[keyi];
            a[keyi]=a[prev];
            a[prev]=tmp;
            return prev;
}void QuickSort(int* a, int left, int right){
    if(left>=right){
        return ;
    }
    int keyi = PartSort(a, left, right);

    QuickSort(a, left, keyi - 1);

    QuickSort(a, keyi + 1, right);
}int main()
{
    int a[] = {5, 3, 8, 2, 4};
    int n = sizeof(a) / sizeof(a[0]);

    QuickSort(a, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n");

    return 0;
}