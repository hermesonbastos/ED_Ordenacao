#ifndef NODE_H
#define NODE_H
#include <iostream>

struct Node {
    int value;
    Node *next;
    Node *prev;

    Node(const int& val, Node *prevPtr, Node *nextPtr){
        value = val;
        prev = prevPtr;
        next = nextPtr;
    }
};

#endif
