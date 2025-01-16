# 13. Task Schedular

## Implementing a scheduler 

- Let's implement a scheduler which schedules multiple user tasks in a round-robin fashion by carrying out the context switch operation 
- Round robin scheduling method is, time slices are assigned to each task in equal portions and in circular order

## What is a task? 
- A task is nothing but a piece of code, or you can call it a ('C') function, which does a specific job when it is allowed to run on the CPU. 
- A task has its own stack to create its local variables when it runs on the CPU. Also when scheduler decides to remove a task from CPU, scheduler first saves the context(state) of the task in task's private stack 
-  So, in summary, a piece code or a function is called a task when it is schedulable and never loses its 'state' unless it is deleted permanently.