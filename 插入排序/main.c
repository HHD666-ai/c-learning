#include<stdio.h>
void InsertSort(int *a,int n){
    int i,j;
    int tmp;
    for(i=1;i<n;i++){
        tmp=a[i];
        j=i-1;
        while(j>=0&&a[j]>tmp){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=tmp;
    }
}int main(){
    int n;
    int a[1000];
     printf("请输入元素个数：");
    scanf("%d", &n);

    printf("请输入数组元素：");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    InsertSort(a, n);

    printf("排序结果：");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n");

    return 0;
}