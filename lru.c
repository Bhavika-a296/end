#include <stdio.h>

int main() {
    int n, f, i, j, ref[50], frame[5], recent[5], time = 0, hit = 0;

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
        for (j = 0; j < f; j++) {
            if (frame[j] == ref[i]) {
                found = 1;
                recent[j] = ++time;
                break;
            }
        }

        if (!found) {
            int pos = 0;
            for (j = 0; j < f; j++) {
                if (frame[j] == -1) { pos = j; break; }
                if (recent[j] < recent[pos]) pos = j;
            }
            frame[pos] = ref[i];
            recent[pos] = ++time;
        } else hit++;

        printf("%d\t", ref[i]);
        for (j = 0; j < f; j++)
            frame[j] == -1 ? printf("- ") : printf("%d ", frame[j]);
        printf("\t%s\n", found ? "Hit" : "Miss");
    }

    printf("\nTotal Hits: %d\nTotal Misses: %d\n", hit, n - hit);
    return 0;
}
