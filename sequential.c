#include <stdio.h>

int main() {
    int n, start[10], len[10], file, i;
    printf("Enter no.of files: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter no. of blocks occupied by file%d ", i + 1);
        scanf("%d", &len[i]);
        printf("Enter the starting block of file%d ", i + 1);
        scanf("%d", &start[i]);
    }

    printf("\nFilename   Start block   length\n");
    for (i = 0; i < n; i++)
        printf("%-10d %-13d %d\n", i + 1, start[i], len[i]);

    printf("\nEnter file name: ");
    scanf("%d", &file);
    printf("File name is:%d length is:%d blocks occupied ", file, len[file - 1]);
    for (i = 0; i < len[file - 1]; i++)
        printf("%d ", start[file - 1] + i);
    printf("\n");
    return 0;
}
