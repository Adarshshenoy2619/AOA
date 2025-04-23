#include <stdio.h>
#include <string.h>

struct Job {
    char id;
    int deadline;
    int profit;
};

void jobSequencing(struct Job jobs[], int n) {
    int result[n];
    bool slot[n];
    for (int i = 0; i < n; i++) {
        slot[i] = false;
    }

    for (int i = 0; i < n; i++) {
        for (int j = (jobs[i].deadline - 1); j >= 0; j--) {
            if (slot[j] == false) {
                result[j] = i;
                slot[j] = true;
                break;
            }
        }
    }

    printf("Job sequence to maximize profit:\n");
    for (int i = 0; i < n; i++) {
        if (slot[i]) {
            printf("%c ", jobs[result[i]].id);
        }
    }
}

int main() {
    int n;

    printf("Enter number of jobs: ");
    scanf("%d", &n);

    struct Job jobs[n];
    
    printf("Enter job details (id, deadline, profit):\n");
    for (int i = 0; i < n; i++) {
        printf("Job %d:\n", i+1);
        scanf(" %c %d %d", &jobs[i].id, &jobs[i].deadline, &jobs[i].profit);
    }

    jobSequencing(jobs, n);
    
    return 0;
}
