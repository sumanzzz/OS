#include <stdio.h>

int main() {
    int blockCount, processCount;
    int blockSize[10], processSize[10], allocation[10];
    int i, j;

    printf("Enter number of memory blocks: ");
    scanf("%d", &blockCount);

    printf("Enter size of each block:\n");
    for (i = 0; i < blockCount; i++) {
        printf("Block %d size: ", i + 1);
        scanf("%d", &blockSize[i]);
    }

    printf("Enter number of processes: ");
    scanf("%d", &processCount);

    printf("Enter size of each process:\n");
    for (i = 0; i < processCount; i++) {
        printf("Process %d size: ", i + 1);
        scanf("%d", &processSize[i]);
    }

    for (i = 0; i < processCount; i++)
        allocation[i] = -1;  // Initialize as unallocated

    // First Fit Algorithm
    for (i = 0; i < processCount; i++) {
        for (j = 0; j < blockCount; j++) {
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i]; // reduce block size
                break;
            }
        }
    }

    printf("\nProcess\tSize\tBlock Allocated\n");
    for (i = 0; i < processCount; i++) {
        if (allocation[i] != -1)
            printf("P%d\t%d\tB%d\n", i + 1, processSize[i], allocation[i] + 1);
        else
            printf("P%d\t%d\tNot Allocat#include <stdio.h>

int main() {
    int blockCount, processCount;
    int blockSize[10], processSize[10], allocation[10];
    int i, j;

    printf("Enter number of memory blocks: ");
    scanf("%d", &blockCount);

    printf("Enter size of each block:\n");
    for (i = 0; i < blockCount; i++) {
        printf("Block %d size: ", i + 1);
        scanf("%d", &blockSize[i]);
    }

    printf("Enter number of processes: ");
    scanf("%d", &processCount);

    printf("Enter size of each process:\n");
    for (i = 0; i < processCount; i++) {
        printf("Process %d size: ", i + 1);
        scanf("%d", &processSize[i]);
    }

    for (i = 0; i < processCount; i++)
        allocation[i] = -1;  // Initialize as unallocated

    // First Fit Algorithm
    for (i = 0; i < processCount; i++) {
        for (j = 0#include <stdio.h>

int main() {
    int blockCount, processCount;
    int blockSize[10], processSize[10], allocation[10];
    int i, j;

    printf("Enter number of memory blocks: ");
    scanf("%d", &blockCount);

    printf("Enter size of each block:\n");
    for (i = 0; i < blockCount; i++) {
        printf("Block %d size: ", i + 1);
        scanf("%d", &blockSize[i]);
    }

    printf("Enter number of processes: ");
    scanf("%d", &processCount);

    printf("Enter size of each process:\n");
    for (i = 0; i < processCount; i++) {
        printf("Process %d size: ", i + 1);
        scanf("%d", &processSize[i]);
    }

    for (i = 0; i < processCount; i++)
        allocation[i] = -1;  // Initialize as unallocated

    // First Fit Algorithm
    for (i = 0; i < processCount; i++) {
        for (j = 0; j < blockCount; j++) {
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i]; // reduce block size
                break;
            }
        }
    }

    printf("\nProcess\tSize\tBlock Allocated\n");
    for (i = 0; i < processCount; i++) {
        if (allocation[i] != -1)
            printf("P%d\t%d\tB%d\n", i + 1, processSize[i], allocation[i] + 1);
        else
            printf("P%d\t%d\tNot Allocat#include <stdio.h>

int main() {
    int blockCount, processCount;
    int blockSize[10], processSize[10], allocation[10];
    int i, j;

    printf("Enter number of memory blocks: ");
    scanf("%d", &blockCount);

    printf("Enter size of each block:\n");
    for (i = 0; i < blockCount; i++) {
        printf("Block %d size: ", i + 1);
        scanf("%d", &blockSize[i]);
    }

    printf("Enter number of processes: ");
    scanf("%d", &processCount);

    printf("Enter size of each process:\n");
    for (i = 0; i < processCount; i++) {
        printf("Process %d size: ", i + 1);
        scanf("%d", &processSize[i]);
    }

    for (i = 0; i ; j < blockCount; j++) {
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i]; // reduce block size
                break;
            }
        }
    }

    printf("\nProcess\tSize\tBlock Alloed\n", i + 1, processSize[i]);
    }

    // Calculate total free space left (external fragmentation)
    int externalFrag = 0;
    for (i = 0; i < blockCount; i++)
        externalFrag += blockSize[i];

    printf("\nTotal External Fragmentation = %d\n", externalFrag);

    return 0;
}