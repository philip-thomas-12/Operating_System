#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// MFT (Fixed Partition)
void mft(int memory_size, int partition_size, int processes[], int n) {
    int partitions = memory_size / partition_size;
    int allocated[MAX] = {0};

    printf("\nMFT (Fixed Partition):\n");
    for (int i = 0; i < n; i++) {
        if (processes[i] <= partition_size && allocated[i] == 0) {
            printf("Process %d of size %d allocated in partition %d\n", i + 1, processes[i], i % partitions + 1);
        } else {
            printf("Process %d of size %d could not be allocated\n", i + 1, processes[i]);
        }
    }
}

// MVT (Variable Partition)
void mvt(int memory_size, int processes[], int n) {
    int memory = memory_size;

    printf("\nMVT (Variable Partition):\n");
    for (int i = 0; i < n; i++) {
        if (processes[i] <= memory) {
            printf("Process %d of size %d allocated\n", i + 1, processes[i]);
            memory -= processes[i];
        } else {
            printf("Process %d of size %d could not be allocated\n", i + 1, processes[i]);
        }
    }
}

int main() {
    int memory_size, partition_size, n;
    printf("Enter total memory size: ");
    scanf("%d", &memory_size);

    printf("Enter partition size for MFT: ");
    scanf("%d", &partition_size);

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int processes[MAX];
    printf("Enter process sizes:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &processes[i]);
    }

    mft(memory_size, partition_size, processes, n);
    mvt(memory_size, processes, n);

    return 0;
}
