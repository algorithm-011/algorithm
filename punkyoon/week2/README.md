# Selection Sort

## 참고 자료

https://www.geeksforgeeks.org/selection-sort/

## 내용

주어진 리스트에서 최솟값을 찾고, 맨 앞에 위치한 값과 교체하여 정렬을 진행하는 알고리즘.

n개의 데이터를 정렬하는 데 O(n^2) 시간이 걸린다.

## 구현

```c
#include <stdio.h>

void print(int arr[], int n);
void selection_sort(int arr[], int n);

void print(int arr[], int n)
{
    int i;
    for(i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void selection_sort(int arr[], int n)
{
    int i, j;
    for(i=0; i<n; i++)
    {
        int temp, min = i;

        for(j=i; j<n; j++)
            if(arr[i] > arr[j])
                min = j;

        if(min != i)
        {
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

int main(void)
{
    int arr[] = {14, 2, 6, 43, 29, 1};
    int size = sizeof(arr) / sizeof(int);

    printf("===== Before\n");
    print(arr, size);

    selection_sort(arr, size);

    printf("===== After\n");
    print(arr, size);

    return 0;
}
```

# Bubble Sort

## 참고 자료

https://www.geeksforgeeks.org/bubble-sort/

## 내용

![bubble sort](https://upload.wikimedia.org/wikipedia/commons/c/c8/Bubble-sort-example-300px.gif)

인접한 원소끼리 비교하며 정렬하는 알고리즘.

n개의 데이터를 정렬하는 데 O(n^2) 시간이 걸린다.

## 구현

```c
#include <stdio.h>

void print(int arr[], int n);
void bubble_sort(int arr[], int n);

void print(int arr[], int n)
{
    int i;
    for(i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void bubble_sort(int arr[], int n)
{
    int i, j;

    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
            if(arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
    }
}

int main(void)
{
    int arr[] = {32, 3, 2, 9, 10, 21};
    int size = sizeof(arr) / sizeof(int);

    printf("===== Before\n");
    print(arr, size);

    bubble_sort(arr, size);

    printf("===== After\n");
    print(arr, size);

    return 0;
}
```

# Insertion Sort

## 참고 자료

https://en.wikipedia.org/wiki/Insertion_sort

## 내용

![insertion sort](https://upload.wikimedia.org/wikipedia/commons/0/0f/Insertion-sort-example-300px.gif)

모든 요소를 앞에서부터 차례대로 이미 정렬된 부분과 비교하고, 자신의 위치를 찾아 삽입하며 정렬하는 알고리즘.

n개의 데이터를 정렬하는 데 O(n^2) 시간이 걸린다.

## 구현

```c
#include <stdio.h>

void print(int arr[], int n);
void insertion_sort(int arr[], int n);

void print(int arr[], int n)
{
    int i;
    for(i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void insertion_sort(int arr[], int n)
{
    int i, j;

    for(i=1; i<n; i++)
    {
        int temp = arr[j=i];

        while(--j >= 0 && temp < arr[j])
        {
            arr[j+1] = arr[j];
            arr[j] = temp;
        }
    }
}

int main(void)
{
    int arr[] = {123, 3, 20, 39, 1, 4};
    int size = sizeof(arr) / sizeof(int);

    printf("===== Before\n");
    print(arr, size);

    insertion_sort(arr, size);

    printf("===== After\n");
    print(arr, size);

    return 0;
}
```

# Heap Sort

## 참고 자료

https://en.wikipedia.org/wiki/Heapsort

## 내용

Max heap 혹은 Min heap을 구성하여 정렬하는 알고리즘. heap을 구성하고 파괴하면서 정렬을 진행한다.

O(n log n) 시간이 걸린다.

## 구현

```c
#include <stdio.h>
#include <stdlib.h>

int *heap = NULL;
int n = 0;

void push(int data);
int pop(void);

void upheap(int idx);
void downheap();

void heap_sort(int arr[], int size);
void print(int arr[], int size);

void push(int data)
{
    heap[n] = data;
    upheap(n++);
}

int pop(void)
{
    int temp = heap[0];
    heap[0] = heap[--n];
    downheap();

    return temp;
}

void upheap(int idx)
{
    int val = heap[idx];
    while(idx > 0 && heap[((idx+1)/2)-1] < val)
    {
        heap[idx] = heap[((idx+1)/2)-1];
        idx = ((idx+1)/2) - 1;
    }
    heap[idx] = val;
}

void downheap(void)
{
    int val = heap[0];
    int i = 0;
    while(i <= n/2)
    {
        int j = ((i+1)*2) - 1;
        if(j+1 <= n && heap[j] < heap[j+1])
            j++;
        if(val >= heap[j])
            break;
        heap[i] = heap[j];
        i = j;
    }

    heap[i] = val;
}

void heap_sort(int arr[], int size)
{
    int i;
    for(i=0; i<size; i++)
    {
        arr[i] = pop();
        printf("%d: %d\n", i+1, arr[i]);
    }
}

void print(int arr[], int size)
{
    int i;
    for(i=0; i<size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(void)
{
    int arr[] = {15, 2, 8, 11, 9, 7};
    int i, size = sizeof(arr) / sizeof(int);

    heap = malloc(sizeof(int) * size + 1);

    for(i=0; i<size; i++)
        push(arr[i]);

    printf("===== Before\n");
    print(arr, size);

    heap_sort(arr, size);

    printf("===== After\n");
    print(arr, size);

    free(heap);
    return 0;
}
```
