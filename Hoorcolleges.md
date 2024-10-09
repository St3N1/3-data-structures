# Hoorcolleges
## List-based collections

ADT = Abstract Data Type

### The array list ADT
- vector or array list ADT extends the notion of array by storing a sequence of object
- an element can be accessed, inserted or removed by specifying its index
- an exception is thrown when index is incorrect
- main methods
	+ at(int i)
	+ set(int i, object o)
	+ insert(int i, object o)
	+ erase(int i)
- additional methods
	+ size()
	+ empty()
	
### Applications of array lists
- direct applications
	+ sorted collection of objects
- indirect applications
	+ auxiliary data structure for algorithms
	+ component of other data structures
	
### Array-based implementation
- array A of size N
- A variable n jeeps track of the size of the array list
- operation at(i) is implementen in O(1) time by returning A[i]
- operation set(i,o) is implementen in O(1) time by performing A[i]=0

### insertion
- in operation insert(i,o), we need to make room for the new element by shifting forward the n-i elements A[i], ..., A[i-1]
- in worst case (i=0), this takes O(n) time

### element removal
- in operation erase(i), we need to fill the hole left by the removed element by shifting backwards the n-i-1 elements A[i+1], ..., A[n-1]
- in the worst case (i=0), this takes O(n) time

### performance
- in the array based implementation of an array list:
	+ the space used by the data structure is O(n)
	+ size, empty, at and set run in O(1) time
	+ insert and erase run in O(n) time in worst case
- if we use the array in a circular fashion, operations insert(0,x) and erase(0,x) run in O(1) time
- in an insert operation, when the array is full, instead of throwing an exception, we can replace the array with a larger one

### growable array-based array list
- in an insert(o) operation, we always insert at the end
- when the array is full, we replace the array with a larger one
- how large should the new array be?
	+ incremental strategy: increase the size by a constant c
	+ doubling strategy: double the size
	
### comparison of the strategies
- we compare the incremental strategy and the doubling strategy by analyzing the total time T(n) needed to perform a series of n insert(o) operations
- we assume that we start with an empty stack represented by an array of size 1
- we call amortized time of an insert operation the average time taken by an insert over the series of operations

### incremental strategy analysis
- we replace the array k=n/c times for n >= 1
- the total time T(n) of a series of n insert operations is proportional to n+ck(k+1)/2
- since c is a constant, T(n) is O(n+k^2), i.e., O(n^2)
- the amortized time of an insert operation is O(n)

### doubling strategy analysis
- we replace the array k=log2*n times
- the total time T(n) of a series of n insert operations is proportional to n+2^(k+1)-1=3n-1
- T(n) is O(n)
- the amortized time of an insert operation is O(1)

## Linked lists

### Position ADT
- the position ADT models the notion of place within a data structure where a single object is stored
- it gives a unified view of diverse ways of storing data, such as:
	+ a cell of an array
	+ a node of a linked list
- just one method:
	+ object p.element(): returns the element at position
	+ in C++ it is convenient to implement this as *p
	
### Node list ADT
- the node list ADT models a serquence of positions storing arbitrary objects
- it establishes a before/after relation between positions
- generic methods;
	+ size()
	+ empty()
- iterators:
	+ begin()
	+ end()
- update methods
	+ insertFront(e)
	+ insertBack(e)
	+ removeFront()
	+ removeBack()
- iterator-based update:
	+ insert(p,e)
	+ remove(p)
	
### Singly linked list
- a singly linked list is a concrete data structure consisting of a sequence of nodes
- each node stores
	+ element
	+ link to the next node
	
### inserting at the head
1. allocate a new node
2. insert new element
3. have new node point to old head
4. update head to point to new node

### inserting at the tail
1. allocate a new node
2. insert new element
3. have new node point to null
4. have old last node point to new node
5. update tail to point to new node

### removing at the tail
- removing at the tail of a singly linked is not efficient
- there is constant-time way to update the tail to point to the previous node
- *you have to travers the hole linked list to find end/tail*

### insertion and removal in general
- do the steps:
  + traverse the Linked List
  + fix the links
  + for removal: Free the memory (for C / C++)

### costs of singly linked list
- traversal O(n)
- insertion O(n)
- deletion O(n)

### doubly linked list
- a doubly linked list provides a natural implementation of the Node List ADT
- nodes implement position and store:
	+ element
	+ link to previous node
	+ link to next node
- special trailer and header nodes
- ability to do a reverse lookup

### performance
- in the implementation of the list ADT by means of a doubly linked list
	+ the space used by a list with n elements is O(n)
	+ the space used by each position of the list is O(1)
	+ insertion and deletion operations of the List ADT run in O(1) time
		* traversal still runs in O(n) time
	+ operation element() of the Position ADT runs in O(1) time
	
## Stacks

### stack ADT
- the stack ADT stores arbitrary objects
- insertions and deletions follow the last-in first-out scheme
- think of a spring-loaded plate dispenser
- main stack operations
	+ push(object): inserts an element
	+ object pop(): removes the last inserted element
- auxiliary stack operations:
	+ object top(): returns last inserted element without removing it
	+ integer size(): returns the number of elements stored
	+ boolean empty(): indicates whether no elements are stored
	
### stack interface in C++
- C++ interface corresponding to our stack ADT
- uses an exception class StackEmpty
- different from the built-in C++ STL class stack

### exceptions
... (known)

### application of stacks
- direct applications
	+ page-visited history in a web browser
	+ undo sequence in a text editor
	+ chain of method calls in the C++ run-time system
- indirect applications
	+ auxiliary data structure for algorithms
	+ component of other data structures
	
### array-based stacks
- a simple way of implementing the stack ADT uses an array
- we add elements from left to right
- a variable keeps track of the index of the top element
- the array storing the stack elements may become full
- a push operation will then throw a StackFull exception
	+ limitation of the array-based implementation
	+ not intrinsic to the stack ADT
	
### perfomance and limitations
- performance
	+ let n be the number of elements in the stack
	+ the space used is O(n)
	+ each operation runs in time O(1)
- limitations
	+ the maximum size of the stack must be defined a priori and cannot be changed -> in case of array-based implementation
	+ trying to push a new element into a full stack causes an implementationspecific exception
	
## Queues

### queue ADT
- the Queue ADT stores arbitrary objects
- insertions and deletions follow the first-in first-out scheme
- insertions are at the rear of the queue and removals are at the front of the queue
- main queue operations:
	+ enqueue(object): inserts an element at the end of the queue
	+ dequeue(): removes the element at the front of the queue
- auxiliary queue operations:
	+ object front(): returns the element at the front without removing it
	+ integer size(): returns the number of elements stored
	+ boolean empty(): indicates whether no elements are stored
- exceptions
	+ attempting the execution of dequeue or front on an empty queue throws an QueueEmpty
	
### array-based queues
- use an array of size N in a circular fashion
- three variables keep track of the front and rear
	+ f -> index of the front element
	+ r -> index immediately past the rear element
	+ n -> number of items in the queue
	
### queue operations
- use n to determine size and emptiness
- operation enqueue throws an exception if the array is full
- this exception is implementationdependent
- operation dequeue throws an exception if the queue is empty
- this exception is specified in the queue ADT

### application: round robin schedulers
- we can implement a round robin scheduler using a queue Q by repeatedly performing the following steps
1. e = Q.front(); Q.dequeue()
2. Service element e
3. Q.enqueue(e)

## Containers and Iterators

- an iterator abstracts the process of scanning through a collection of elements
- a container is an abstract data structure that supports element access through iterators
  + begin(): returns an iterator to the first element
  + end(): return an iterator to an imaginary position just after the last element
- an iterator behaves like a pointer to an element
  + *p: returns the element referenced by this iterator
  + ++p: advances to the next element
- extends the concept of position by adding a traversal capability

### containers
- data structures that support iterators are called containers
- examples include Stack, Queue, Vector, List
- Various notions of iterator:
  + (standard) iterator: allows read-write access to elements
  + const iterator: provides read-only access to elements
  + bidirectional iterator: supports both ++p and --p
  + random-access iterator: supports both p+i and p-i

---
### Iterating through a Container
### Implementing Iterators
### STL Iterators in C++
---
### sequence ADT
- the Sequence ADT is the union of the Array List and Node List ADTs
- elements accessed by
  + Index, or
  + position
- generic methods:
  + size(), empty()
- array List-based methods:
  + at(i), set(i, o), insert(i, o), erase(i)
- list-based methods:
  + begin(), end()
  + insertFront(o), insertBack(o)
  + eraseFront(), eraseBack()
  + insert(p, o), erase(p)
- Bridge methods:
  + atIndex(i), indexOf(p)

---
### Application of Sequences
### Linked-list Implementation
---

### array-based Implementation
- we use a circular array storing positions
- a position object stores:
  + element
  + index
- indices f and l keep track of first and last positions
