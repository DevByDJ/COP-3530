// File : tree_app.cpp
// Class: COP 3530 Digital Sys & Architecture
// Dev  : Danny Joseph
// Desc : Implemented a Binary Tree
// --------------------------------------------------------
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "BinaryTreeADT.h"
#include "BinaryTreeADT.cpp"

int main() {
    BinaryTreeADT tree;
    
    if (tree.isEmpty())
        tree.root = tree.insert(tree.root, 6);

    tree.insert(tree.root, 10);
    tree.insert(tree.root, 7);
    tree.insert(tree.root, 4);
    tree.insert(tree.root, 11);

    if(tree.search(tree.root, 7))
        std::printf("Found %d", 7);
    else
    {
        std::printf("\n");
        std::printf("%d Not Found!\n", 7);
        std::printf("\n");
    }

    std::list<int> preOrder;
    tree.preOrderTraversal(tree.root, preOrder);

    for (std::list<int>::iterator it=preOrder.begin(); it != preOrder.end(); ++it)
        std::printf("%d", *it);
        std::cout<< std::endl;

    return 0;

}

