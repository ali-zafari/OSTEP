## Q1: python3 process-run.py -l 5:100,5:100 -cp
100%, because all that processes execute is doing sth on cpu

## Q2: python3 process-run.py -l 4:100,1:0. -cp
transferring control of IO to a process needs a cpu execution and stopping the IO also needs one. so there need to be (4+2) cpu operations and 4 IO operations

## Q3: python3 process-run.py -l 1:0.,4:100 -cp
cpu utilization change from 60% to 100% as the IO operation process starts first

## Q4: python3 process-run.py -l 1:0.,4:100 -cp -S SWITCH_ON_END
cpu utilization falls to 55% as it waits for the IO operation to be finished

## Q5: python3 process-run.py -l 1:0.,4:100 -cp -S SWITCH_ON_IO
100% cpu utilization, all good

## Q6: python3 process-run.py -l 3:0,5:100,5:100,5:100 -S SWITCH_ON_IO -I IO_RUN_LATER -c -p
not good utilization because we were able to do cpu operations simulatneously with subsequent IO operations

## Q7: python3 process-run.py -l 3:0,5:100,5:100,5:100 -S SWITCH_ON_IO -I IO_RUN_LATER -c -p
there is more contex switching here but better utilization at all, when a process completes an IO it is better to switch back to it since there may occur another IO in it

## Q8-1: python3 process-run.py -s 1 -l 3:50,3:50 -S SWITCH_ON_IO -I IO_RUN_LATER -c -p
## Q8-2: python3 process-run.py -s 2 -l 3:50,3:50 -S SWITCH_ON_IO -I IO_RUN_LATER -c -p
## Q8-3: python3 process-run.py -s 3 -l 3:50,3:50 -S SWITCH_ON_IO -I IO_RUN_LATER -c -p
when there are overlapping IO operations there seems no difference between IO_RUN_LATER and IO_RUN_IMMEDAITE



