#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
    int filedesc = open("q2.txt", O_WRONLY | O_APPEND | O_CREAT, S_IWUSR|S_IRUSR);
    if(filedesc < 0) {
        // openning failed; exit
        fprintf(stderr, "open failed\n");
        exit(1);
    }
    int rc = fork();
    
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child (new process)
        printf("Hi! I am child (pid: %d) and filedesc is %d.\n", (int) getpid(), filedesc);
        if (write(filedesc, "Hi from child\n", 14) != 14) {
            // writing failed; exit
            fprintf(stderr, "write failed (child).\n");
            exit(1);
        }
        if(close(filedesc) < 0){
            // closing failed; exit
            fprintf(stderr, "close failed\n");
            exit(1);
        }
    } else {
        // parent goes down this path (original process)
        printf("Hi! I am parent of %d (pid:%d) and filedesc is %d.\n", rc, (int) getpid(), filedesc);
        if (write(filedesc, "Hi from parent\n", 15) != 15) {
            // writing failed; exit
            fprintf(stderr, "write failed (parent).\n");
            exit(1);
        }
        if(close(filedesc) < 0){
            // closing failed; exit
            fprintf(stderr, "close failed\n");
            exit(1);
        }
    }
    return 0;
}
