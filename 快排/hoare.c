#include<stdio.h>
int PartSort(int *a,int left,int right){
    int key=a[left];
    int i=left;
    int j=right;
    while(i<j){
        while(j>i&&a[j]>=key){
            j--;
        }
        while(j>i&&a[i]<=key){
            i++;
        }
        if(i<j){
            int tmp=a[i];
            a[i]=a[j];
            a[j]=tmp;
        }
    }int tmp = a[left];
a[left] = a[i];
a[i] = tmp;

return i;

}void QuickSort(int *a,int left,int right){
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