#include <stdio.h>

struct Item {
    int value, weight;
};

void sortItems(struct Item items[], int n) {
    int i, j;
    struct Item temp;
    for (i = 0; i < n-1; i++) {
        for (j = i+1; j < n; j++) {
            float r1 = (float)items[i].value / items[i].weight;
            float r2 = (float)items[j].value / items[j].weight;
            if (r1 < r2) {
                temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
}

float fractionalKnapsack(int W, struct Item items[], int n) {
    sortItems(items, n);
    int i;
    float totalValue = 0.0;
    for (i = 0; i < n; i++) {
        if (W >= items[i].weight) {
            W -= items[i].weight;
            totalValue += items[i].value;
        } else {
            totalValue += ((float)items[i].value / items[i].weight) * W;
            break;
        }
    }
    return totalValue;
}

int main() {
    int n, W, i;
    struct Item items[100];
    scanf("%d %d", &n, &W); 
    for (i = 0; i < n; i++) {
        scanf("%d %d", &items[i].value, &items[i].weight);
    }
    float maxValue = fractionalKnapsack(W, items, n);
    printf("%.2f", maxValue);
    return 0;
}
