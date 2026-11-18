#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
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
}

static int ReadInt(int *value)
{
    char token[64];
    char *end;
    int length;
    if (scanf("%63s%n", token, &length) != 1 || length == 63)
        return 0;

    errno = 0;
    long number = strtol(token, &end, 10);
    if (end == token || *end != '\0' || errno == ERANGE ||
        number < INT_MIN || number > INT_MAX)
        return 0;

    *value = (int)number;
    return 1;
}

int main(void)
{
    int n;
    int a[1000];
    printf("请输入元素个数：");
    if (!ReadInt(&n) || n < 0 || n > (int)(sizeof(a) / sizeof(a[0])))
    {
        fprintf(stderr, "元素个数必须是 0 到 1000 之间的整数。\n");
        return 1;
    }

    printf("请输入数组元素：");
    for (int i = 0; i < n; i++)
    {
        if (!ReadInt(&a[i]))
        {
            fprintf(stderr, "第 %d 个元素不是有效的 int 整数。\n", i + 1);
            return 1;
        }
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
