#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void fifo(int ref[], int n, int f) {
    int frame[10], front = 0;
    int hit = 0, miss = 0;

    for (int i = 0; i < f; i++) frame[i] = -1;

    printf("\nPage\tFrames\t\tStatus\n");
    for (int i = 0; i < n; i++) {
        int page = ref[i];
        int found = 0;

        for (int j = 0; j < f; j++) {
            if (frame[j] == page) {
                found = 1;
                break;
            }
        }

        if (!found) {
            frame[front] = page;
            front = (front + 1) % f;
            miss++;
        } else {
            hit++;
        }

        printf("%d\t", page);
        for (int j = 0; j < f; j++) {
            if (frame[j] != -1)
                printf("%d ", frame[j]);
            else
                printf("- ");
        }
        printf("\t%s\n", found ? "Hit" : "Miss");
    }

    printf("\nTotal Hits: %d", hit);
    printf("\nTotal Misses: %d", miss);
    printf("\nHit Ratio: %.2f%%", (hit * 100.0) / n);
    printf("\nMiss Ratio: %.2f%%\n", (miss * 100.0) / n);
}

int main() {
    int ref[MAX], count = 0, f;
    char input[500];

    printf("Enter reference string :");
    fgets(input, sizeof(input), stdin);

    char *tok = strtok(input, " ");
    while (tok != NULL && count < MAX) {
        ref[count++] = atoi(tok);
        tok = strtok(NULL, " ");
    }

    printf("Enter number of frames: ");
    scanf("%d", &f);

    fifo(ref, count, f);
    return 0;
}
