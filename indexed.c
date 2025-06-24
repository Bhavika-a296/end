#include <stdio.h>

int main() {
    int n, index[10], size[10], blocks[10][20], i, j;
    printf("Enter no. of files: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter starting block of file%d: ", i + 1);
        scanf("%d", &index[i]);
        printf("Enter blocks occupied by file%d: ", i + 1);
        scanf("%d", &size[i]);
        printf("enter blocks of file%d: ", i + 1);
        for (j = 0; j < size[i]; j++)
            scanf("%d", &blocks[i][j]);
    }

    printf("\nFile   index   length\n");
    for (i = 0; i < n; i++)
        printf("%-6d %-7d %d\n", i + 1, index[i], size[i]);
    return 0;
}
