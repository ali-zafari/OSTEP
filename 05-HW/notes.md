Unix uses two system calls to create a process: fork() and exec() 
also wait() is used when a process decides to wait for its child.


fork always duplicates from its calling process.
exec can call other processes different from its calling process. but the strange point about exec is that it will never returns anything. it just replaces the calling process with the process passed to it by its arguments.

pipe() implements an in-kernel pip (i.e. queue)
