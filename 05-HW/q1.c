#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int x = 99;
    printf("Hi! I am (pid: %d) and x is: %d.\n", (int) getpid(), x);
    int rc = fork();
    
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child (new process)
        printf("Hi! I am child (pid: %d) and x is %d.\n", (int) getpid(), x);
        x = 100;
        printf("I am child again (pid:%d) and have changed x to %d.\n", (int) getpid(), x);
    } else {
        // parent goes down this path (original process)
        printf("Hi! I am parent of %d (pid:%d) and x is %d.\n",
	       rc, (int) getpid(), x);
        x = 101;
        printf("I am parent again (pid:%d) and have changed x to %d.\n", (int) getpid(), x);

    }
    return 0;
}