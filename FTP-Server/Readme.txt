
Objective:	To simulate getblk algorithm mechanism.
----------

Analysis:
---------



Technology Used:
----------------
Implemented using C procedural programming language.

Assumption:
-----------
1. Processes are executing in Multiprogramming environment.
2. Socket Programming is being used here to create multiprpgramming environment.
3. All Processes are scheduled using First-Come-First-Serve(FCFS) scheduling algorithm.
4. At a time, signal is given to only one process(Processes which are in Indefinite sleep executing their System 	Call).

Output:
------

To compile this repository:
--------------------------

Compile kernel Program :	cc kernel.c -o kernel
Compile Process Program:	cc process.c -o process
Compile Dependencies   :	cc dependency.c -o dependency

To execute:					./kernel
-----------




Conclusion:
----------
