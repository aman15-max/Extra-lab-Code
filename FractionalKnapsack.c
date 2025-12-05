#include <stdio.h>


struct Item {
    int weight;
    int value;
};


void swap(struct Item *a, struct Item *b) {
    struct Item temp = *a;
    *a = *b;
    *b = temp;
}


void sortItems(struct Item arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            double r1 = (double)arr[j].value / arr[j].weight;
            double r2 = (double)arr[j + 1].value / arr[j + 1].weight;
            if (r1 < r2) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}


double fractionalKnapsack(int W, struct Item arr[], int n) {
    sortItems(arr, n);

    printf("\nItems sorted by value/weight ratio:\n");
    printf("Item\tWeight\tValue\tValue/Weight\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%.2f\n", i + 1, arr[i].weight, arr[i].value, (double)arr[i].value / arr[i].weight);
    }

    double totalValue = 0.0;
    int curWeight = 0;

    printf("\nItems taken into knapsack:\n");
    printf("WeightTaken\tValueAdded\n");

    for (int i = 0; i < n; i++) {
        if (curWeight + arr[i].weight <= W) {
            
            curWeight += arr[i].weight;
            totalValue += arr[i].value;
            printf("%d\t\t%d\n", arr[i].weight, arr[i].value);
        } else {
            
            int remain = W - curWeight;
            totalValue += arr[i].value * ((double)remain / arr[i].weight);
            printf("%d (fraction)\t%.2f\n", remain, arr[i].value * ((double)remain / arr[i].weight));
            break; 
        }
    }

    return totalValue;
}