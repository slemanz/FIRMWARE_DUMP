# 13. Task Schedular

## Implementing a scheduler 

- Let's implement a scheduler which schedules multiple user tasks in a round-robin fashion by carrying out the context switch operation 
- Round robin scheduling method is, time slices are assigned to each task in equal portions and in circular order

## What is a task? 

- A task is nothing but a piece of code, or you can call it a ('C') function, which does a specific job when it is allowed to run on the CPU. 
- A task has its own stack to create its local variables when it runs on the CPU. Also when scheduler decides to remove a task from CPU, scheduler first saves the context(state) of the task in task's private stack 
-  So, in summary, a piece code or a function is called a task when it is schedulable and never loses its 'state' unless it is deleted permanently.

## What is scheduling? 

- Scheduling is an algorithm which takes the decision of pre-empting a running task from the CPU and takes the decision about which task should run on the CPU next 
- The decision could be based on many factors such as system load, the priority of tasks, shared resource access, or a simple round-robin method

## What is context switching? 

- Context switching is the procedure of switching out of the currently running task from the CPU after saving the task's execution context or state and switching in the next task's to run on the CPU by retrieving the past execution context or state of the task.

## Task's stack area init and storing of dummy SF 

- Each task can consume a maximum of 1KB of memory as a private stack 
- This stack is used to hold tasks local variables and context(SF1+SF2) 
- When a Task is getting scheduled for the very first time, it doesn't have any context. So, the programmer should store dummy SF1 and SF2 in Task's stack area as a part of "task initialization" sequence before launching the scheduler.

Here the project: [Schedualar](../task/)