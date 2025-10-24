#include <stdio.h>
#include <stdbool.h>

#define MAX 10

int allocation[MAX][MAX], request[MAX][MAX], available[MAX];
bool visited[MAX];
int numProcesses, numResources;


void detectDeadlock() {
    bool finished[MAX];
    for (int i = 0; i < numProcesses; i++)
        finished[i] = false;  // Initially, no process has finished

    int work[MAX];
    for (int i = 0; i < numResources; i++)
        work[i] = available[i];  // Copy of available resources

    int count = 0;

    while (count < numProcesses) {
        bool found = false;

        for (int p = 0; p < numProcesses; p++) {
            if (!finished[p]) {
                bool canFinish = true;

                // Check if all requested resources of P[p] can be satisfied
                for (int r = 0; r < numResources; r++) {
                    if (request[p][r] > work[r]) {
                        canFinish = false;
                        break;
                    }
                }

                // If process p can finish, simulate its completion
                if (canFinish) {
                    for (int r = 0; r < numResources; r++)
                        work[r] += allocation[p][r];  // Release its resources

                    finished[p] = true;
                    found = true;
                    count++;
                }
            }
        }

        // If no process could proceed in this pass, break (possible deadlock)
        if (!found)
            break;
    }

    // Display results
    bool deadlockFound = false;
    printf("\nDeadlocked Processes: ");
    for (int i = 0; i < numProcesses; i++) {
        if (!finished[i]) {
            printf("P%d ", i);
            deadlockFound = true;
        }
    }

    if (!deadlockFound)
        printf("None");
    printf("\n");
}

int main() {
    printf("Enter number of processes: ");
    scanf("%d", &numProcesses);

    printf("Enter number of resources: ");
    scanf("%d", &numResources);

    printf("Enter Allocation Matrix (%d x %d):\n", numProcesses, numResources);
    for (int i = 0; i < numProcesses; i++)
        for (int j = 0; j < numResources; j++)
            scanf("%d", &allocation[i][j]);

    printf("Enter Request Matrix (%d x %d):\n", numProcesses, numResources);
    for (int i = 0; i < numProcesses; i++)
        for (int j = 0; j < numResources; j++)
            scanf("%d", &request[i][j]);

    printf("Enter Available Resources (%d):\n", numResources);
    for (int i = 0; i < numResources; i++)
        scanf("%d", &available[i]);

    detectDeadlock();

    return 0;
}