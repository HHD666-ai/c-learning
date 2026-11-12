#include<stdio.h>
void AdjustDown(int *a,int n,int root){
    if(n<=1||root<0||root>=n){
        return;
    }
    int parent=root;
    /* Only non-leaf nodes have children; this also prevents index overflow. */
    while(parent<n/2){
        int child=parent*2+1;
        if(child+1<n&&a[child+1]>a[child]){
            child++;
        }
        if(a[child]>a[parent]){
            int tmp=a[parent];
            a[parent]=a[child];
            a[child]=tmp;
            parent=child;
        }else{
            break;
        }
    }
}
void HeapSort(int *a,int n){
    if(n<=1){
        return;
    }
    int i=n/2-1;
    for(;i>=0;i--){
         AdjustDown(a, n, i);
    }
    for(int end=n-1;end>0;end--){
        int tmp=a[0];
        a[0]=a[end];
        a[end]=tmp;
        AdjustDown(a, end, 0);
    }
}int main(void)
{
    int a[] = {4, 7, 2, 9, 5, 1, 6, 3};
    int n = sizeof(a) / sizeof(a[0]);

    HeapSort(a, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n");

    return 0;
}
