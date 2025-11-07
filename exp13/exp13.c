#include <stdio.h>
#include <stdbool.h>

int main() {
    int n, m;

    
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resources: ");
    scanf("%d", &m);

    int max_need[n][m], allocation[n][m], need[n][m];
    int available[m];
    bool finish[n];
    int safe_sequence[n];
    int count = 0;

   
    printf("\nEnter Max Need Matrix (%d x %d):\n", n, m);
    for (int i = 0; i < n; i++) {
        printf("P%d: ", i);
        for (int j = 0; j < m; j++) {
            scanf("%d", &max_need[i][j]);
        }
    }

    
    printf("\nEnter Allocation Matrix (%d x %d):\n", n, m);
    for (int i = 0; i < n; i++) {
        printf("P%d: ", i);
        for (int j = 0; j < m; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    
    printf("\nEnter Available Resources (%d values): ", m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &available[i]);
    }

    
    for (int i = 0; i < n; i++)
        finish[i] = false;


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            need[i][j] = max_need[i][j] - allocation[i][j];
        }
    }

    
    printf("\nNeed Matrix:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d: ", i);
        for (int j = 0; j < m; j++) {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

   
    while (count < n) {
        bool allocated = false;
        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                bool can_allocate = true;
                for (int j = 0; j < m; j++) {
                    if (need[i][j] > available[j]) {
                        can_allocate = false;
                        break;
                    }
                }
                if (can_allocate) {
                    for (int j = 0; j < m; j++) {
                        available[j] += allocation[i][j];
                    }
                    finish[i] = true;
                    safe_sequence[count++] = i;
                    allocated = true;

                    printf("Process P%d executed, Available: ", i);
                    for (int k = 0; k < m; k++) {
                        printf("%d ", available[k]);
                    }
                    printf("\n");
                }
            }
        }

        if (!allocated) {
            printf("\nSystem is in Deadlock!\n");
            break;
        }
    }

    
    if (count == n) {
        printf("\nSAFE Sequence: ");
        for (int i = 0; i < n; i++) {
            printf("P%d ", safe_sequence[i]);
        }
        printf("\n");
    }

    return 0;
}
