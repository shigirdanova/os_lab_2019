#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t child_pid;
    // Сreating a child process
    child_pid = fork();
    if (child_pid > 0) {
     printf("It's a parent process\n");
     printf("Pause\n");  
    sleep(10);
    } else {
        printf("It's the child process. STOP!\n"); 
        exit(0);
    }
 sleep(10);   
 return 0;
}
