Clone List with Random Pointer


You are given a linked list L1 of length n. Each node contains an additional random pointer which could point to any of the nodes in the list, or null.

You need to create a deep copy of this list with n newly created nodes. This will create a new linked list L2. All nodes of L2 will have the same value as the corresponding node in L1. The next and random pointers will point to nodes in L2 rather than L1.

Return the head of L2.

Testing
Input Format
The first line contains ‘T’ denoting the number of test cases.

For each test case, the input consists of three lines:

An integer ‘n’ denoting the length of the linked list.
n space-separated integers denoting the value at each node.
n space-separated integers denoting the index (0 to n-1) of the node to which the random pointer points. -1 if it points to null.
Output Format
For each test case, the output will consist of n lines.

ith line will consists of two space-separated integers x and y for the node at index i.
x = value of the node.
y = index of the node to which the random pointer points.

Sample Input
2
3
1 2 3
2 1 -1
2
5 6
1 0
Expected Output
1 3
2 2
3 -1
5 6
6 5