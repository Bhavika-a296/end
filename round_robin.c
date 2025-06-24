#include <stdio.h>
#include <limits.h>

#define MAX 100

void calculateAverageTimes(int n, int turnaround[], int waiting[]) {
    float totalTAT = 0, totalWT = 0;
    for (int i = 0; i < n; i++) {
        totalTAT += turnaround[i];
        totalWT += waiting[i];
    }
    printf("\n Average Turnaround Time: %.2f", totalTAT / n);
    printf("\n Average Waiting Time   : %.2f\n", totalWT / n);
}

void RoundRobin(int n, int arrival[], int burst[], int quantum) {
    int remaining[MAX], completion[MAX], turnaround[MAX], waiting[MAX];
    int time = 0, done = 0;
    int visited[MAX] = {0};
    int queue[MAX * 2], front = 0, rear = 0;
    int gantt[MAX * 20], gantt_time[MAX * 20], gantt_len = 0;

    for (int i = 0; i < n; i++)
        remaining[i] = burst[i];

    // Add initial processes to queue
    for (int i = 0; i < n; i++) {
        if (arrival[i] <= time && !visited[i]) {
            queue[rear++] = i;
            visited[i] = 1;
        }
    }

    while (done < n) {
        if (front == rear) {
            time++;  // Advance time, no execution logged
            for (int i = 0; i < n; i++) {
                if (arrival[i] <= time && !visited[i]) {
                    queue[rear++] = i;
                    visited[i] = 1;
                }
            }
            continue;
        }

        int idx = queue[front++];
        int execTime = (remaining[idx] > quantum) ? quantum : remaining[idx];

        // Gantt Chart logs (only actual execution)
        gantt[gantt_len] = idx;
        gantt_time[gantt_len] = time;
        gantt_len++;

        time += execTime;
        remaining[idx] -= execTime;

        // Check for new arrivals during execution
        for (int i = 0; i < n; i++) {
            if (arrival[i] > time - execTime && arrival[i] <= time && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }

        if (remaining[idx] > 0)
            queue[rear++] = idx;
        else {
            completion[idx] = time;
            done++;
        }
    }

    // Calculate turnaround and waiting times
    for (int i = 0; i < n; i++) {
        turnaround[i] = completion[i] - arrival[i];
        waiting[i] = turnaround[i] - burst[i];
    }

    // Output Table
    printf("\n🔹 Round Robin Scheduling Result (Quantum = %d):\n", quantum);
    printf("PID\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");
    for (int i = 0; i < n; i++) {
        printf("P%-2d\t%-7d%-7d%-11d%-11d%-7d\n", i + 1, arrival[i], burst[i], completion[i], turnaround[i], waiting[i]);
    }

    calculateAverageTimes(n, turnaround, waiting);

    // Gantt Chart Output
    printf("\n Gantt Chart :\n ");
    for (int i = 0; i < gantt_len; i++) {
        printf("P%-3d", gantt[i] + 1);
    }
    printf("\n");

    for (int i = 0; i < gantt_len; i++) {
        printf("%-4d", gantt_time[i]);
    }
    printf("%-4d\n", time);  // Final time marker
}

int main() {
    int n, quantum;
    int arrival[MAX], burst[MAX];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter Arrival Time and Burst Time for Process %d: ", i + 1);
        scanf("%d %d", &arrival[i], &burst[i]);
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &quantum);

    RoundRobin(n, arrival, burst, quantum);
    return 0;
}
