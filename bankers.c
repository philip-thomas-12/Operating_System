#include <stdio.h>

#define  P 5 
#define R 3 


void calculateNeed( int need[P][R],int max[P][R], int alloc[P][R]) {
    
    for (int i = 0; i < P; i++)
        for (int j = 0; j < R; j++)
            need[i][j] = max[i][j] - alloc[i][j]; // Need = Max - Allocated
}

int isSafe(int alloc[P][R], int max[P][R], int avail[R]) {
    int need[P][R], safeSequence[P], finished[P] = {0};
    int work[R];

    calculateNeed(need, max, alloc);

    // Copy available resources
    for (int i = 0; i < R; i++)
        work[i] = avail[i];

    int count = 0;
    while (count < P) {
        int found = 0;
        for (int i = 0; i < P; i++) {
            if (!finished[i]) {
                int j;
                for (j = 0; j < R; j++)
                    if (need[i][j] > work[j])
                        break;

                if (j == R) { // If all needs of process are met
                    for (int k = 0; k < R; k++)
                        work[k] += alloc[i][k]; // Release resources

                    safeSequence[count] = i;
                    count++;
                    finished[i] = 1;
                    found = 1;
                }
            }
        }
        if (!found) { // No process can execute, unsafe state
            printf("System is in an unsafe state!\n");
            return 0;
        }
    }

    printf("System is in a safe state. Safe sequence: ");
    for (int i = 0; i < P; i++)
        printf("%d ", safeSequence[i]);
    printf("\n");
    return 1;
}

int main() {
    int alloc[P][R] = {{0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2}};
    int max[P][R] = {{7, 5, 3}, {3, 2, 2}, {9, 0, 2}, {2, 2, 2}, {4, 3, 3}};
    int avail[R] = {3, 3, 2};

    isSafe(alloc, max, avail);
    return 0;
}
