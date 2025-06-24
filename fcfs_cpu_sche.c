#include <stdio.h>

int main() {
    int n, i;
    int at[10], bt[10], ct[10], tat[10], wt[10];
    float total_tat = 0, total_wt = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter Arrival and Burst Time:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d - Arrival: ", i + 1);
        scanf("%d", &at[i]);
        printf("Process %d - Burst: ", i + 1);
        scanf("%d", &bt[i]);
    } // Completion Time
    ct[0] = (at[0] > 0) ? at[0] + bt[0] : bt[0];
    for (i = 1; i < n; i++) {
        if (ct[i - 1] < at[i])
            ct[i] = at[i] + bt[i];
        else
            ct[i] = ct[i - 1] + bt[i];
    }// Turnaround & Waiting Time
    for (i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        total_tat += tat[i];
        total_wt += wt[i];
    }// Gantt Chart
    printf("\nGantt Chart:\n");
    for (i = 0; i < n; i++) printf("-------");
    printf("\n|");
    for (i = 0; i < n; i++) printf(" P%d |", i + 1);
    printf("\n");
    for (i = 0; i < n; i++) printf("-------");
    printf("\n0");
    for (i = 0; i < n; i++) printf("     %d", ct[i]);
// Output Table
    printf("\n\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    printf("\nAverage TAT = %.2f", total_tat / n);
    printf("\nAverage WT  = %.2f\n", total_wt / n);
    return 0;
}
