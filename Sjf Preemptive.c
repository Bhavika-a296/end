#include <stdio.h>
#include <limits.h>

int main() {
    int n, at[50], bt[50], rt[50], ct[50], tat[50], wt[50];
    int gantt[100], ganttSize = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter Arrival & Burst Time for P%d: ", i + 1);
        scanf("%d%d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }

    int time = 0, done = 0;
    float totalTAT = 0, totalWT = 0;

    while (done < n) {
        int idx = -1, min = INT_MAX;

        for (int i = 0; i < n; i++)
            if (at[i] <= time && rt[i] > 0 && rt[i] < min)
                min = rt[i], idx = i;

        if (idx != -1) {
            rt[idx]--;
            gantt[ganttSize++] = idx;
            time++;
            if (rt[idx] == 0) {
                ct[idx] = time;
                tat[idx] = ct[idx] - at[idx];
                wt[idx] = tat[idx] - bt[idx];
                totalTAT += tat[idx];
                totalWT += wt[idx];
                done++;
            }
        } else {
            gantt[ganttSize++] = -1; // CPU Idle
            time++;
        }
    }

    // Output
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);

    printf("\nAverage TAT = %.2f", totalTAT / n);
    printf("\nAverage WT  = %.2f\n", totalWT / n);

    // Gantt Chart
    printf("\nGantt Chart:\n");
    printf("-------------------------------------------------\n|");
    for (int i = 0; i < ganttSize; i++) {
        if (gantt[i] == -1)
            printf(" IDLE |");
        else
            printf(" P%d  |", gantt[i] + 1);
    }
    printf("\n-------------------------------------------------\n0");

    for (int i = 1, t = 1; i <= ganttSize; i++) {
        if (i < ganttSize && gantt[i] != gantt[i - 1])
            printf("%5d", t);
        else if (i == ganttSize)
            printf("%5d", t);
        t++;
    }

    printf("\n");
    return 0;
}
