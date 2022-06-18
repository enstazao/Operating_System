/* fork : create a new process */
#include <stdlib.h>   /* needed to define exit() */
#include <unistd.h>   /* needed for fork()       */
#include <sys/wait.h> /* needed for wait()       */
#include <stdio.h>    /* needed for printf()     */
int main(int argc, char **argv) {
    int pid; /* process ID */
    
    pid = fork();
    if (pid == 0) {
        printf("In child\n");
        printf("Child Process PID=> %d\n", getpid());
    }
    else if (pid == -1) {
        printf("Error");
    }
    else {
        printf("In Parent\n");
        printf("Child PID=> %d\n", pid);
        printf("Parent PID=> %d\n", getpid());
    }
    sleep(1);
}