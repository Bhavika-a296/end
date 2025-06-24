#include <stdio.h>

int main() {
    int b, p;
    printf("Enter number of blocks: ");
    scanf("%d", &b);
    int bs[b], bu[b]; 
    printf("Enter block sizes:\n");
    for (int i = 0; i < b; i++) {
        scanf("%d", &bs[i]);
        bu[i] = 0;
    }

    printf("Enter number of processes: ");
    scanf("%d", &p);
    int ps[p], alloc[p], frag[p]; 

    printf("Enter process sizes:\n");
    for (int i = 0; i < p; i++) {
        scanf("%d", &ps[i]);
        alloc[i] = -1;
    }

  
    for (int i = 0; i < p; i++) {
        int worst = -1;
        for (int j = 0; j < b; j++) {
            if (!bu[j] && bs[j] >= ps[i]) {
                if (worst == -1 || bs[j] > bs[worst])
                    worst = j;
            }
        }
        if (worst != -1) {
            alloc[i] = worst;
            frag[i] = bs[worst] - ps[i];
            bu[worst] = 1;
        }
    }

    printf("\nProcess\tSize\tBlock\tFragment\n");
    for (int i = 0; i < p; i++) {
        printf("P%d\t%d\t", i, ps[i]);
        if (alloc[i] != -1)
            printf("%d\t%d\n", alloc[i], frag[i]);
        else
            printf("NA\tNA\n");
    }

    return 0;
}
