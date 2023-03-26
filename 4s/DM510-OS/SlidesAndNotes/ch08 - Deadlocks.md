# System model
- Consists of resources (R1, R2 ... Rm), CPU cycles, memory spaces, I/O devices
- Each process Ri has Wi instances 
- Each process utilizes a resource as follows:
  - Request
  - Use
  - Release

# Mutex / Semaphore
- Can only be grabbed by one processes at a time 
- Mutex not preemptible if held by a process even when sleeping
- A mutex should only be grabbed if you grab everything at once
- Semaphores can be grabbed by multiple processes at a time

# Deadlock Characterization
- Mutual exclusion: only one process at a time can use a resource
- Hold and wait: a process holding at least one resource is waiting to acquire additional resources held by other processes
- No pre-emption: a resource can be released only voluntarily by the process holding it, after that process has completed its task
- Circular wait: there exists a set {P0, P1, …, Pn} of waiting processes such that P0 is waiting for a resource that is held by P1, P1 is waiting for a resource that is held by P2, …, Pn–1 is waiting for a resource that is held by Pn, and Pn is waiting for a resource that is held by P0.
- NOTE: You can forget about hold and wait since circular wait implies hold and wait

# Deadlock example
![[Pasted image 20230321122836.png]]

# Resources-Allocation Graph
- A set of vertices V and a set of edges E.
  - V is partitioned into two types:
    - P = {P1, P2, …, Pn}, the set consisting of all the processes in the system
    - R = {R1, R2, …, Rm}, the set consisting of all resource types in the system
- request edge – directed edge Pi -> Rj
- ! assignment edge – directed edge Rj -> Pi

![[Pasted image 20230321123633.png]]

![[Pasted image 20230321123717.png]]
-The is a cycle from R2 through T2 to R1 to T2 to R3 to T3 and then R2 again

![[Pasted image 20230321123726.png]]
- There is a cycle but of T2 releases its hold on R1 T1 can get R1 and release R2 then T3 can get R2
![[Pasted image 20230321131334.png]]
Dotted lines = claim edge indicates that a process wants that resource, converted to request edge when process requests the resource, converted to assignment edge when the resource is allocated to the process, when resource is released by a process, assignment edge reconverts to a claim edge





# Basic facts about deadlocks
### General
- If graph contains no cycles => no deadlock
- If graph contains a cycle => if only one instance per resource type, then deadlock
- If graph contains a cycle => if several instances per resource type, possibility of deadlock
### Regarding states
- If a system is in safe state Þ no deadlocks
- If a system is in unsafe state Þ possibility of deadlock
- Avoidance Þ ensure that a system will never enter an unsafe state.

# Deadlock handling
- Ensure that the system never enters a state where all deadlock characteristics occur
- The system should be able to recover if it enters a deadlock state
- Or you can ignore the problem and pretend that the deadlock never happened

## Deadlock prevention 
### Mutual Exclusion
- Not required for sharable resources (e.g., read-only files); must hold for non-sharable resources
### Hold and Wait
- Must guarantee that whenever a process requests a resource, it does not hold any other resources:
  - Require process to request and be allocated all its resources before it begins execution, or allow process to request resources only when the process has none allocated to it.
  - Low resource utilization; starvation possible
### No pre-emption:
- If a process that is holding some resources requests another resource that cannot be immediately allocated to it, then all resources currently being held are released
- Pre-empted resources are added to the list of resources for which the process is waiting
- Process will be restarted only when it can regain its old resources, as well as the new ones that it is requesting
### Circular Wait
- Impose a total ordering of all resource types, and require that each process requests resources in an increasing order of enumeration
### Method for preventing deadlocks
- Invalidate circular wait condition (most common)
- Assign each resource (i.e. mutex locks) a unique number
- Require resources must be acquired in order 

## Deadlock avoidance
- Requires that the system has some additional a priori information available
  - Simplest and most useful model requires that each process declare the maximum number of resources of each type that it may need
  - The deadlock-avoidance algorithm dynamically examines the resource-allocation state to ensure that there can never be a circular-wait condition
  - Resource-allocation state is defined by the number of available and allocated resources, and the maximum demands of the processes

# Safe state
- A state where the system can allocate resources to each process (up to its maximum requirement) in some order and there is no chance of deadlock occurring. ![[Pasted image 20230321130827.png]]

# Avoidance Algs.
- Single instance of a resource type
  - Use a resource-allocation graph
- Multiple instances of a resource type
  - Use the Banker’s Algorithm

# Banker's Alg.
- Multiple instances of resources
- Each process must a priori claim maximum use
- When a process requests a resource it may have to wait
- When a process gets all its resources it must return them in a finite amount of time
## Data structure
- Let n = number of processes, and m = number of resources types.
  - Available: Vector of length m. If available $[j]$ = k, there are k instances of resource type Rj available
  - Max: n x m matrix. If Max $[i,j]$ = k, then process Pi may request at most k instances of resource type Rj
  - Allocation: n x m matrix. If Allocation$[i,j]$ = k then Pi is currently allocated k instances of Rj
  - Need: n x m matrix. If Need$[i,j]$ = k, then Pi may need k more instances of Rj to complete its task $Need [i,j] = Max[i,j] – Allocation [i,j]$

# Safety algorithm 
![[Pasted image 20230321133459.png]]

# Resource request algorithm
![[Pasted image 20230321133514.png]]

# Deadlock Detection
- Allow system to enter deadlock state
- Detection algorithm to detect the deadlock
- Recovery scheme that lets the process recover from a deadlocked state

# Resource allocation graph and wait for graph
### Single instance of each resource type
![[Pasted image 20230321134433.png]]

![[Pasted image 20230321134401.png]]

### Several instances of a resource type
- Available: A vector of length m indicates the number of available resources of each type
- Allocation: An n x m matrix defines the number of resources of each type currently allocated to each process
- Request: An n x m matrix indicates the current request of each process. If Request $[i][j]$ = k, then process Pi is requesting k more instances of resource type Rj

# Detection Alg.
![[Pasted image 20230321134602.png]]
![[Pasted image 20230321134608.png]]
Algorithm requires an order of $O(m * n^2)$ operations to detect whether the system is in deadlocked state

### Usage 
- When and how often to invoke depends on:
  - How often ad deadlock is likely to occur
  - How many processes will need to be rolled back -> One process for each disjoint cycle

![[Note for usage]]

# Recovery from deadlocks
- Abort all deadlocked processes 
- Abort one process at a time until the deadlock 
- In which order should a process  e aborted
  - Priority
  - Computation time - How long to completion
  - Resources the process has used
  - How many process will need to be terminated
  - Interactive or batch
- Selecting a victim -> Minimize cost
- Rollback -> Return to some sage state - restart process for that state
- Starvation -> Same process may always be picked as victim, include number of rollback in cost factor