#include <stdio.h>

int main() {
    int arr[5] = {1, 2, 3, 5, 8}, n = 5, key, low=0, high=n-1, mid;

    printf("Enter element to search: ");
    scanf("%d", &key);

    while(low <= high) {
        mid = (low + high) / 2;
        if(arr[mid] == key) {
            printf("Found at position %d\n", mid+1);
            return 0;
        }
        else if(arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    printf("Not found\n");
    return 0;
}