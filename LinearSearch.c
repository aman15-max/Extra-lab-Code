//Linear search

#include <stdio.h>

int main() {
    int arr[5] = {5, 2, 8, 1, 3}, n = 5, key, i, found = 0;

    printf("Enter element to search: ");
    scanf("%d", &key);

    for(i = 0; i < n; i++) {
        if(arr[i] == key) {
            printf("Found at position %d\n", i+1);
            found = 1;
            break;
        }
    }

    if(!found) printf("Not found\n");
    return 0;
}