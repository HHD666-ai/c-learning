#include<stdio.h>
void ShellSort(int *a,int n){
    int gap=n/2;
    while(gap>0){
        for(int i=gap;i<n;i++){
            int tmp=a[i];
            int j=i-gap;
            while(j>=0&&a[j]>tmp){
                a[j+gap]=a[j];
                j-=gap;
            }
            a[j+gap]=tmp;
        }
        gap/=2;
    }
}int main()
{
    int a[] = {8, 9, 1, 7, 3, 2, 5, 4};
    int n = sizeof(a) / sizeof(a[0]);

    ShellSort(a, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n");

    return 0;
}