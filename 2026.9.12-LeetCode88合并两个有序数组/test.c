#include <stdio.h>
#include <string.h>

void merge(int* nums1, int nums1Size, int m,
           int* nums2, int nums2Size, int n);

static int same_array(const int* a, const int* b, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
        {
            return 0;
        }
    }
    return 1;
}

static void print_array(const int* a, int n)
{
    printf("[");
    for (int i = 0; i < n; i++)
    {
        if (i > 0) printf(",");
        printf("%d", a[i]);
    }
    printf("]");
}

static void run_case(const char* name,
                     int* nums1, int nums1Size, int m,
                     int* nums2, int nums2Size, int n,
                     const int* expected)
{
    merge(nums1, nums1Size, m, nums2, nums2Size, n);

    printf("%s: ", name);
    print_array(nums1, nums1Size);

    if (same_array(nums1, expected, nums1Size))
    {
        printf("  PASS\n");
    }
    else
    {
        printf("  FAIL, expected ");
        print_array(expected, nums1Size);
        printf("\n");
    }
}

int main(void)
{
    {
        int nums1[] = {1,2,3,0,0,0};
        int nums2[] = {2,5,6};
        int expected[] = {1,2,2,3,5,6};
        run_case("case1", nums1, 6, 3, nums2, 3, 3, expected);
    }

    {
        int nums1[] = {1};
        int nums2[] = {0};
        int expected[] = {1};
        run_case("case2", nums1, 1, 1, nums2, 0, 0, expected);
    }

    {
        int nums1[] = {0};
        int nums2[] = {1};
        int expected[] = {1};
        run_case("case3", nums1, 1, 0, nums2, 1, 1, expected);
    }

    {
        int nums1[] = {4,5,6,0,0,0};
        int nums2[] = {1,2,3};
        int expected[] = {1,2,3,4,5,6};
        run_case("case4", nums1, 6, 3, nums2, 3, 3, expected);
    }

    {
        int nums1[] = {1,2,3,0,0,0};
        int nums2[] = {4,5,6};
        int expected[] = {1,2,3,4,5,6};
        run_case("case5", nums1, 6, 3, nums2, 3, 3, expected);
    }

    return 0;
}
