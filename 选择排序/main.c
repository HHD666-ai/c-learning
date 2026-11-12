#include<stdio.h>
void SelectSort(int *a,int n){
    if(n<=1){
        return;
    }
    for(int i=0;i<n-1;i++){
        int minIndex=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[minIndex]){
                minIndex=j;
            }
        }
        if(minIndex!=i){
            int tmp=a[i];
            a[i]=a[minIndex];
            a[minIndex]=tmp;
        }
    }
}
int main(void)
{
    int a[] = {6, 3, 8, 2, 7, 1, 5, 4};
    int n = sizeof(a) / sizeof(a[0]);

    SelectSort(a, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n");
    return 0;
}
