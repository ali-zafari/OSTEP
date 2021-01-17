# Chapter 5 - Process API
## Simulation
4. **Orphaned processes** (processes that their parents are exited) in Unix will be adopted by the special ```init``` process.
    - ```Zombie``` vs ```Orphaned```:

        ```Zombie```: A process which has finished the execution but still has entry in the process table to report to its parent process is known as a zombie process. **A child process always first becomes a zombie before being removed from the process table.** The parent process reads the exit status of the child process which reaps off the child process entry from the process table.

        ```Orphaned```: A process whose parent process no more exists i.e. either finished or terminated without waiting for its child process to terminate is called an orphan process. **The orphan process is soon adopted by init process, once its parent process dies.**

6. In cases which the number of actions is equal to the number of process forked, I can tell what set of actions made the process tree, otherwise I can't tell.
---
## Code

### [Q1](q1.c)
Child process (which is forked by the parent) has its own separate copy of the parent variables.

### [Q2](q2.c)
Child prcess has the same file descriptor and they both can write on the file simultaneously with no problem.

### [Q3](q3.c)
By doing some more tasks int the parent process, we could make the os to switch to the child process.
