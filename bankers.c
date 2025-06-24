#include <stdio.h>
#include <stdbool.h>

int main() {
    int n, m;

    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resource types: ");
    scanf("%d", &m);

    int allocation[n][m], max[n][m], need[n][m], total[m], available[m];
    bool finish[n];
    int safeSeq[n];

    // Input Allocation matrix
    printf("\nEnter Allocation Matrix:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d: ", i);
        for (int j = 0; j < m; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    // Input Max matrix
    printf("\nEnter Max Matrix:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d: ", i);
        for (int j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    // Input Total resources
    printf("\nEnter Total Resources:\n");
    for (int j = 0; j < m; j++) {
        scanf("%d", &total[j]);
    }

    // Calculate Available = Total - Sum of Allocation
    for (int j = 0; j < m; j++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += allocation[i][j];
        }
        available[j] = total[j] - sum;
    }

    // Calculate Need = Max - Allocation
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
        finish[i] = false;
    }

    // Display Matrices
    printf("\n%-10s", "Process");
    for (int j = 0; j < m; j++) printf("A%-3d", j);
    printf("    ");
    for (int j = 0; j < m; j++) printf("M%-3d", j);
    printf("    ");
    for (int j = 0; j < m; j++) printf("N%-3d", j);
    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("P%-9d", i);
        for (int j = 0; j < m; j++) printf("%-4d", allocation[i][j]);
        printf("    ");
        for (int j = 0; j < m; j++) printf("%-4d", max[i][j]);
        printf("    ");
        for (int j = 0; j < m; j++) printf("%-4d", need[i][j]);
        printf("\n");
    }

    // Print Initial Available
    printf("\nInitial Available Resources:\n");
    for (int j = 0; j < m; j++) {
        printf("R%d ", j);
    }
    printf("\n");
    for (int j = 0; j < m; j++) {
        printf("%-3d", available[j]);
    }
    printf("\n");

    // Find Safe Sequence
    int count = 0;
    printf("\nProcess Execution Order and Available Resources:\n");
    while (count < n) {
        bool found = false;

        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                bool canRun = true;
                for (int j = 0; j < m; j++) {
                    if (need[i][j] > available[j]) {
                        canRun = false;
                        break;
                    }
                }

                if (canRun) {
                    for (int j = 0; j < m; j++) {
                        available[j] += allocation[i][j];
                    }

                    printf("P%-2d executed\tAvailable: ", i);
                    for (int j = 0; j < m; j++) {
                        printf("%-3d", available[j]);
                    }
                    printf("\n");

                    safeSeq[count++] = i;
                    finish[i] = true;
                    found = true;
                }
            }
        }

        if (!found) {
            printf("\nSystem is in an UNSAFE state. No safe sequence.\n");
            return 1;
        }
    }

    // Print Safe Sequence
    printf("\nSafe Sequence: ");
    for (int i = 0; i < n; i++) {
        printf("P%d", safeSeq[i]);
        if (i != n - 1) printf(" -> ");
    }
    printf("\n");

    return 0;
}
