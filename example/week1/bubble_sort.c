#include <stdio.h>

void swap(int *x, int *y);
void print(int arr[], int n);
void bubble_sort(int arr[], int n);

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

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
    for(i=0; i<n; i++)
    {
        for(j=0; j<n-1-i; j++)
            if(arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
        // print(arr, n);
    }
}

int main(void)
{
    // Arrays
    int first[] = {30, 234, 1, 4, 320};
    int second[] = {49, 2, 1, 3, 20};

    // Array size
    int n1 = sizeof(first) / sizeof(first[0]);
    int n2 = sizeof(second) / sizeof(second[0]);

    printf("===Before\n");
    print(first, n1);
    print(second, n2);

    // Sorting
    bubble_sort(first, n1);
    bubble_sort(second, n2);

    printf("===After\n");
    print(first, n1);
    print(second, n2);

    return 0;
}
