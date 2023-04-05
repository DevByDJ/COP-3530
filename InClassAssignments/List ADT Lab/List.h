// File : List.h
// Class: COP 3530 Digital Sys & Architecture
// Dev  : Danny Joseph
// Desc : Linked List ADT interface
// --------------------------------------------------------

#ifndef LINKEDLIST_LIST_H
#define LINKEDLIST_LIST_H

// constants
// --------------------------------------------------------
const int LIST_HEAD = 0;    // list position of head node
const int LIST_TAIL = -1;   // specify current tail position

class List {
private:

    // internal storage structure for a Node
    struct Node {
        int value;
        Node* next;
    };

    Node* head; // hold reference to head of the list (Node[0])
    int size;   // current size of the list (empty==0)

public:

    List();

    ~List();

    int getSize();
    bool isEmpty();

    void insert(int value, int position=LIST_TAIL);

    int remove(int position=LIST_TAIL);

    int read(int position);

    void modify(int value, int position);

    int search(int valueToSearch, int sizeOfTheList);

private:

    Node* traverse(int position);
};

#endif //LINKEDLIST_LIST_H