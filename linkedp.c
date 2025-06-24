#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50
typedef struct{
    char name[20];
    int size;
    int blocks[MAX];
    int start;
}filerecord;

void Linked(){
    int n,i,j;
    filerecord files[MAX];
    printf("Enter the the number of files:\n");
    scanf("%d",&n);
    for (i=0; i<n; i++){
        printf("Enter the file names:\n");
        scanf("%s", &files[i].name);
        printf("Enter the number of blocks occupied:\n");
        scanf("%d", &files[i].size);
        printf("Enter the Starting block:\n");
        scanf("%d", &files[i].start);
        for(j=0;j<files[i].size;j++)
        {
        printf("Enter blocks:\n ");
        scanf("%d", &files[i].blocks[j]);
        }
    }
    
    printf("\n%-15s %-15s %-15s %-20s\n", "File Name", "File Size", "Starting bolck", "Block Occupied");
    for(i=0;i<n;i++)
    {
        printf("%-15s %-15d %-15d", files[i].name, files[i].size, files[i].start);
        for(j=0; j<files[i].size; j++){
            printf("%d\t",files[i].blocks[j]);
            if(j<files[i].size-1){
                printf("-->");
            }
        }
        printf("\n");
    }

} 

    int main()
    {
        Linked();
        return 0;
    }
