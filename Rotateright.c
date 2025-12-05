#include <stdio.h>


void rotateRight(int arr[], int n, int k) {
    int temp[n];


    k = k % n;

    
    for (int i = 0; i < k; i++) {
        temp[i] = arr[n - k + i];
    }

    
    for (int i = 0; i < n - k; i++) {
        temp[k + i] = arr[i];
    }

    
    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
}

int main() {
    int n, k;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements of array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter number of positions to rotate (k): ");
    scanf("%d", &k);

    rotateRight(arr, n, k);

    printf("Array after rotation: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}