#include<stdio.h>
#include<stdlib.h>
typedef struct Poly{
    int coef;
    int exp;
}Poly;
int main(){
    int n,m,t;
    scanf("%d%d%d",&n,&m,&t);
    Poly* p1 = (Poly*)malloc(sizeof(Poly) * n);
Poly* p2 = (Poly*)malloc(sizeof(Poly) * m);
for (int i = 0; i < n; i++)
{
    scanf("%d%d", &p1[i].coef, &p1[i].exp);
}

for (int i = 0; i < m; i++)
{
    scanf("%d%d", &p2[i].coef, &p2[i].exp);
}int i = 0;
int j = 0;
int k = 0;
Poly* ret = (Poly*)malloc(sizeof(Poly) * (n + m));
while (i < n && j < m)
{
   if (p1[i].exp < p2[j].exp)
{
    if (p1[i].coef != 0)
    {
        ret[k] = p1[i];
        k++;
    }
    i++;
}
   else if (p1[i].exp > p2[j].exp)
{
    int sign = (t == 0) ? 1 : -1;

    int coef = p2[j].coef * sign;

    if (coef != 0)
    {
        ret[k] = p2[j];
        ret[k].coef = coef;
        k++;
    }

    j++;
}
    else
    {int sign = (t == 0) ? 1 : -1;
           int coef = p1[i].coef + sign * p2[j].coef;
  if (coef != 0)
    {
        ret[k].coef = coef;
        ret[k].exp = p1[i].exp;
        k++;
    }

    i++;
    j++;
    }
}while (i < n)
{
    if (p1[i].coef != 0)
    {
        ret[k] = p1[i];
        k++;
    }

    i++;
}while (j < m)
{
    int sign = (t == 0) ? 1 : -1;

    int coef = p2[j].coef * sign;

    if (coef != 0)
    {
        ret[k] = p2[j];
        ret[k].coef = coef;
        k++;
    }

    j++;
}
if (k == 0)
{
    printf("0");
}

for (int p = 0; p < k; p++)
{
    int c = ret[p].coef;
    int e = ret[p].exp;

    // 不是第一项，并且系数为正，要补 +
    if (p > 0 && c > 0)
    {
        printf("+");
    }

    // 处理负号
    if (c < 0)
    {
        printf("-");
        c = -c;
    }

    // 指数为0，就是常数
    if (e == 0)
    {
        printf("%d", c);
    }
    else
    {
        // x前面的系数不是1才输出
        if (c != 1)
        {
            printf("%d", c);
        }

        if (e == 1)
        {
            printf("x");
        }
        else
        {
            printf("x^%d", e);
        }
    }
}

printf("\n");
}
