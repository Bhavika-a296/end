#include <stdio.h>

int main() {
    int n, start[10], size[10], blocks[10][20], i, j;
    char name[10];

    printf("Enter no. of files: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter file name: ");
        scanf(" %c", &name[i]);
        printf("Enter starting block: ");
        scanf("%d", &start[i]);
        printf("Enter no.of blocks: ");
        scanf("%d", &size[i]);
        for (j = 0; j < size[i]; j++)
            scanf("%d", &blocks[i][j]);
    }

    printf("\nFile   start   size   block\n");
    for (i = 0; i < n; i++) {
        printf("%c      %-7d %-6d", name[i], start[i], size[i]);
        for (j = 0; j < size[i]; j++) {
            printf("%d", blocks[i][j]);
            if (j != size[i] - 1) printf("--->");
        }
        printf("\n");
    }
    return 0;
}
