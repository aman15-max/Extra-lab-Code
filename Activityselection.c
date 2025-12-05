#include <stdio.h>
struct Activity {
    int start, finish;
};

void sortByFinish(struct Activity arr[], int n) {
    int i, j;
    struct Activity temp;

    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(arr[j].finish > arr[j+1].finish) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
void activitySelection(struct Activity arr[], int n) {
     sortByFinish(arr, n);
 printf("Selected activities (start, finish):\n");
    
    int i = 0;
    printf("(%d, %d)\n", arr[i].start, arr[i].finish);

    
    for(int j = 1; j < n; j++) {
        if(arr[j].start >= arr[i].finish) {
            printf("(%d, %d)\n", arr[j].start, arr[j].finish);
            i = j;
        }
    }
}

int main() {
    struct Activity arr[] = { {1, 3}, {2, 4}, {0, 6}, {5, 7}, {8, 9}, {5, 9} };
    int n = sizeof(arr) / sizeof(arr[0]);

    activitySelection(arr, n);

    return 0;
}
