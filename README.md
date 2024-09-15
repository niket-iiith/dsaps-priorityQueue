# PRIORITY QUEUE

## Problem Statement: 
### Implement priority queue What is a priority queue?
● A priority queue is a data structure that maintains a collection of
elements, each associated with a priority or value. Elements are stored in a way that allows the retrieval of the element with the highest (or lowest) priority quickly.

● Unlike deques or lists, a priority queue doesn't maintain the elements in
any specific order based on their values, except for ensuring that the highest (or lowest) priority element is readily accessible.

## Operations : 
The C++ standard specifies that a legal (i.e., standard-conforming) implementation of priority queue must satisfy the following performance requirements.
1. priority_queue() - initialize an empty priority queue. Time complexity: O(1)
2. int size() - returns the current size of the priority queue. Time complexity:
O(1)
3. void push(int el) - insert an element el in the priority queue. Time
complexity: O(log(size()))
4. int top() - returns the top (highest or lowest priority) element in the priority
queue. Time complexity: O(1)
5. void pop() - remove the top element of the priority queue. Time
complexity: O(log(size()))
6. bool empty() - returns true if the priority queue is empty else returns false.
Time complexity: O(1)