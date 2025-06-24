#include<stdio.h>
#include<stdlib.h>

void FCF(int n, int at[], int bt[]){
    int i, wt[n], tat[n], ct[n];
    int total_wt=0, total_tat=0;
    ct[0]=at[0]+bt[0];
    for( i=1; i<n; i++){
        ct[i]= (at[i]>ct[i-1])? at[i]+bt[i]:ct[i-1]+bt[i];
    }
    for( i=0; i<n; i++){
        wt[i]= ct[i]-at[i]-bt[i];
        tat[i]=ct[i]-at[i];
        total_wt+=wt[i];
        total_tat+=tat[i];
    }
    printf("CPU Scheduling: FCFs\n");
    printf("Process\tAT\tBT\tCT\tWT\tTAT\n");
    for (i=0; i<n; i++){
        printf("\n\tp%d\t%d\t%d\t%d\t%d\t%d\t", i, at[i], bt[i], ct[i], wt[i], tat[i]);
    }
    printf("\nAverage Waiting time: %2f\n", (float)total_wt/n);
    printf("\nAverage Turn Arround time: %2f\n", (float)total_tat/n);

printf("\nGantt Chart:");
printf("\n0");
for (int i=0; i<n; i++){
    printf("-----");
}
printf("\n");
for (int i=0; i<n; i++){
printf("|p%d", i);
    
}
printf("|\n");
for (int i=0; i<n; i++){
printf("%d\t", ct[i]);
}
printf("\n");
}
int main(){
    int n;
    printf("Enter the number of process:\n");
    scanf("%d", &n);
    int at[n], bt[n], ct[n];
    for (int i=0; i<n; i++){
        printf("Enter AT for p%d:",i);
        scanf("%d", &at[i]);
         printf("Enter BT for p%d:",i);
        scanf("%d", &bt[i]);
}
FCF(n, at, bt);
}
