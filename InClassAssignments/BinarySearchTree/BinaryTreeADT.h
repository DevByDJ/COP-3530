// File : BinaryTreeADT.h
// Class: COP 3530 Data Structures and Algo
// Dev  : Danny Joseph
// Desc : Implemented a Binary Tree
// --------------------------------------------------------

#ifndef BINARYSEARCHTREE_BINARYTREEADT_H
#define BINARYSEARCHTREE_BINARYTREEADT_H

#include<list>


class BinaryTreeADT {
private:
    struct BinaryNode {
        int data;
        BinaryNode *left;
        BinaryNode *right;
    };

    

public:

    BinaryNode * root;

    BinaryTreeADT();

    bool isEmpty();

    BinaryNode* insert(BinaryNode * root, int value); 

    bool search(BinaryNode * root, int value);

    void preOrderTraversal(BinaryNode * root, std::list<int> &values);

};


#endif //LINKEDLIST_LIST_H