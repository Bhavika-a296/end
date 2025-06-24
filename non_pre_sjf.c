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

void SJF(int n, int arrival[], int burst[], int isPreemptive) {
    if (isPreemptive) {
        printf("This function handles only **SJF Non-Preemptive**.\n");
        return;
    }

    int pid[MAX], completion[MAX], turnaround[MAX], waiting[MAX], isDone[MAX] = {0};
    int currentTime = 0, completed = 0;

    // Assign process IDs
    for (int i = 0; i < n; i++)
        pid[i] = i;

    while (completed < n) {
        int idx = -1, minBurst = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (!isDone[i] && arrival[i] <= currentTime) {
                if (burst[i] < minBurst || (burst[i] == minBurst && arrival[i] < arrival[idx])) {
                    minBurst = burst[i];
                    idx = i;
                }
            }
        }

        if (idx == -1) {
            currentTime++;  // CPU is idle
            continue;
        }

        completion[idx] = currentTime + burst[idx];
        currentTime = completion[idx];
        turnaround[idx] = completion[idx] - arrival[idx];
        waiting[idx] = turnaround[idx] - burst[idx];
        isDone[idx] = 1;
        completed++;
    }

    // Output Table
    printf("\n SJF Non-Preemptive Scheduling Result:\n");
    printf("PID\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");
    for (int i = 0; i < n; i++) {
        printf("P%-2d\t%-7d%-7d%-11d%-11d%-7d\n", pid[i] + 1, arrival[i], burst[i], completion[i], turnaround[i], waiting[i]);
    }

    calculateAverageTimes(n, turnaround, waiting);
}

int main() {
    int n, arrival[MAX], burst[MAX];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter Arrival Time and Burst Time for Process %d: ", i + 1);
        scanf("%d %d", &arrival[i], &burst[i]);
    }

    SJF(n, arrival, burst, 0);  // Call for non-preemptive version

    return 0;
}
