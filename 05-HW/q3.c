#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int rc = fork();
    
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child (new process)
        printf("hello.\n");
    } else {
        // parent goes down this path (original process)
        for (size_t i = 0; i < 100000; i++)
        {
            ;
        }
        printf("goodbye.\n");
    }
    return 0;
}
