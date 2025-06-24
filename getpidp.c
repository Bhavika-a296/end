#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
    pid_t pid;
    printf("Process ID before fork():%d\n", getpid());
    pid = fork();
    if (pid==0){
        printf("Process ID after fork(): Child Process:%d\n", getpid());
    }else{
                printf("Process ID after fork(): Parent Process:%d\n", getpid());

    }
    return 0;
}
