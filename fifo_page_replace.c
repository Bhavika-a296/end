#include <stdio.h>

int main() {
    int ref[100], frame[10], n, f, i, j, front = 0, hit = 0, miss = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter reference string:\n");
    for (i = 0; i < n; i++) scanf("%d", &ref[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);
    for (i = 0; i < f; i++) frame[i] = -1;

    printf("\nPage\tFrames\t\tStatus\n");
    for (i = 0; i < n; i++) {
        int found = 0;
        for (j = 0; j < f; j++)
            if (frame[j] == ref[i]) found = 1;

        if (!found) {
            frame[front] = ref[i];
            front = (front + 1) % f;
            miss++;
        } else hit++;

        printf("%d\t", ref[i]);
        for (j = 0; j < f; j++)
            frame[j] == -1 ? printf("- ") : printf("%d ", frame[j]);
        printf("\t%s\n", found ? "Hit" : "Miss");
    }

    printf("\nTotal Hits: %d\nTotal Misses: %d\n", hit, miss);
    printf("Hit Ratio: %.2f%%\nMiss Ratio: %.2f%%\n", hit * 100.0 / n, miss * 100.0 / n);

    return 0;
}
