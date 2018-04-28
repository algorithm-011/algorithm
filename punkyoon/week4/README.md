# Linear Search

## 내용

앞에서부터 순차적으로 찾는 알고리즘. O(n) 시간이 걸린다.

## 구현

```c
#include <stdio.h>

int linear_search(int arr[], int n, int key);

int linear_search(int arr[], int n, int key)
{
    int i;
    for(i=0; i<n; i++)
        if(arr[i] == key)
            return 1;
    return -1;
}

int main(void)
{
    int arr[] = {3, 25, 1, 68, 2, 40, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("10: %d\n", linear_search(arr, size, 10));
    printf("40: %d\n", linear_search(arr, size, 40));

    return 0;
}
```

# Binary Search

## 내용

검색 범위를 좁혀가는 방식을 사용한다. 자료들은 모두 정렬되어있는 상태여야 한다.

O(log n)의 시간이 걸린다.

## 구현

```c
#include <stdio.h>

int binary_search(int arr[], int n, int key);

int binary_search(int arr[], int n, int key)
{
    int high = n - 1, low = 0, mid;

    while(low <= high)
    {
        mid = (low + high) / 2;

        if(arr[mid] == key)
            return 1;
        else if(arr[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;
}

int main(void)
{
    int arr[] = {1, 4, 5, 12, 14, 30, 40, 50, 100};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("10: %d\n", binary_search(arr, size, 10));
    printf("40: %d\n", binary_search(arr, size, 40));

    return 0;
}
```

# Parametric Search
