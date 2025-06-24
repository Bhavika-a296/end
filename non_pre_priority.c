#include <stdio.h>
#include <limits.h>

#define MAX 100

void calculateAverageTimes(int n, int turnaround[], int waiting[]) {
    float totalTAT = 0, totalWT = 0;
    for (int i = 0; i < n; i++) {
        totalTAT += turnaround[i];
        totalWT += waiting[i];
    }
    printf("\n🔸 Average Turnaround Time: %.2f", totalTAT / n);
    printf("\n🔸 Average Waiting Time   : %.2f\n", totalWT / n);
}

void PriorityScheduling(int n, int arrival[], int burst[], int priority[], int isPreemptive) {
    if (isPreemptive) {
        printf("❌ This function handles only **Priority Scheduling (Non-Preemptive)**.\n");
        return;
    }

    int completion[MAX], turnaround[MAX], waiting[MAX], isDone[MAX] = {0};
    int currentTime = 0, completed = 0;
    int gantt[MAX * 10], gantt_len = 0;

    while (completed < n) {
        int idx = -1;
        int highestPriority = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (!isDone[i] && arrival[i] <= currentTime) {
                if (priority[i] < highestPriority || 
                    (priority[i] == highestPriority && arrival[i] < arrival[idx])) {
                    highestPriority = priority[i];
                    idx = i;
                }
            }
        }

        if (idx == -1) {
            gantt[gantt_len++] = -1; // CPU idle
            currentTime++;
            continue;
        }

        for (int t = 0; t < burst[idx]; t++)
            gantt[gantt_len++] = idx;

        completion[idx] = currentTime + burst[idx];
        currentTime = completion[idx];
        turnaround[idx] = completion[idx] - arrival[idx];
        waiting[idx] = turnaround[idx] - burst[idx];
        isDone[idx] = 1;
        completed++;
    }

    // Output Table
    printf("\n🔹 Priority Scheduling (Non-Preemptive) Result:\n");
    printf("PID\tArrival\tBurst\tPriority\tCompletion\tTurnaround\tWaiting\n");
    for (int i = 0; i < n; i++) {
        printf("P%-2d\t%-7d%-7d%-9d\t%-11d%-11d%-7d\n", i + 1, arrival[i], burst[i], priority[i], completion[i], turnaround[i], waiting[i]);
    }

    calculateAverageTimes(n, turnaround, waiting);

    // Gantt Chart
    printf("\n🔸 Gantt Chart:\n ");
    for (int i = 0; i < gantt_len; i++) {
        if (gantt[i] == -1)
            printf("IDLE ");
        else
            printf("P%-3d", gantt[i] + 1);
    }
    printf("\n");

    for (int i = 0; i <= gantt_len; i++)
        printf("%-5d", i);
    printf("\n");
}

int main() {
    int n;
    int arrival[MAX], burst[MAX], priority[MAX];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter Arrival Time, Burst Time and Priority for Process %d: ", i + 1);
        scanf("%d %d %d", &arrival[i], &burst[i], &priority[i]);
    }

    PriorityScheduling(n, arrival, burst, priority, 0);  // Non-preemptive

    return 0;
}
