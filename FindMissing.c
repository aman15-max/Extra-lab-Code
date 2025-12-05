#include <stdio.h>

int findMissing(int arr[], int n) {
    int total = n * (n + 1) / 2;   // Expected sum from 0..n
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    return total - sum;
}

int main() {
    int arr[] = {3, 0, 1};  // Here n = 3, numbers from 0..3, missing 2
    int n = sizeof(arr) / sizeof(arr[0]);

    int missing = findMissing(arr, n);
    printf("Missing number is: %d\n", missing);

    return 0;
}