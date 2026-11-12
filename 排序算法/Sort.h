#ifndef SORT_H
#define SORT_H

/* Ascending order; n <= 1 requires no access to a. */
void InsertSort(int* a, int n);
void ShellSort(int* a, int n);
void SelectSort(int* a, int n);
void HeapSort(int* a, int n);
/* Inclusive interval [left, right]; left >= right is empty or singleton. */
void QuickSort(int* a, int left, int right);

#endif
