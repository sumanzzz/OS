//Internal Fragmentation
#include <stdio.h>

int main() {
    int n, blockSize[10], processSize[10];
    int i, j, allocation[10];
    int totalWaste = 0;

    printf("Enter number of memory blocks: ");
    scanf("%d", &n);

    printf("Enter size of each block:\n");
    for (i = 0; i < n; i++) {
        printf("Block %d size: ", i + 1);
        scanf("%d", &blockSize[i]);
    }

    printf("Enter size of each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d size: ", i + 1);
        scanf("%d", &processSize[i]);
    }

    printf("\nProcess\tBlock\tInternal Fragmentation\n");

    for (i = 0; i < n; i++) {
        if (processSize[i] <= blockSize[i]) {
            allocation[i] = i; // Assign block i to process i
            int waste = blockSize[i] - processSize[i];
            totalWaste += waste;
            printf("P%d\tB%d\t%d\n", i + 1, i + 1, waste);
        } else {
            allocation[i] = -1;
            printf("P%d\tNot Allocated\t-\n", i + 1);
        }
    }

    printf("\nTotal Internal Fragmentation = %d\n", totalWaste);
    return 0;
}
