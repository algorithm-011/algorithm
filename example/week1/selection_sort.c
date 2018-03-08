#include <stdio.h>

void print(int arr[], int n);
void swap(int *x, int *y);
void selection_sort(int arr[], int n);

void print(int arr[], int n)
{
    int i;
    for(i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selection_sort(int arr[], int n)
{
    int i, j;
    for(i=0; i<n-1; i++)
   {
        int idx = i;
        for(j=i+1; j<n; j++)
            if(arr[j] < arr[idx])
                idx = j;
        swap(&arr[idx], &arr[i]);
        // printf(arr, n);
    }
}


int main(void)
{
    // Arrays
    int first[] = {50, 9, 2, 48, 90};
    int second[] = {10, 32, 24, 3, 29};

    // Array size
    int n1 = sizeof(first) / sizeof(first[0]);
    int n2 = sizeof(second) / sizeof(second[0]);

    printf("===Before\n");
    print(first, n1);
    print(second, n2);

    // Sorting
    selection_sort(first, n1);
    selection_sort(second, n2);

    // Result
    printf("===After\n");
    print(first, n1);
    print(second, n2);
    
    return 0;
}
