#include <iostream>
#include <list>

#include "BSTree.h"


enum BSTTraverse {
    BSTInOrder,
    BSTPreOrder,
    BSTPostOrder,
    BSTBreadth
    };

void printTree(BSTree<char> &tree, BSTTraverse order = BSTInOrder);

int main() {

    BSTree <char> tree; // generics (data type choice)

    int arrLen = 11;
    char arr[] = {'F', 'D', 'E' ,'J','G','B', 'K', 'A', 'I', 'C', 'H'};

    for(int i = 0; i < arrLen; i++) {
        tree.insert( arr[i]);
    }

    printTree(tree);
    printTree(tree, BSTPreOrder);
    printTree(tree, BSTPostOrder);
    printTree(tree, BSTBreadth);

    tree.empty();

    return 0;
}
void printTree(BSTree<char> &tree, BSTTraverse order){
    std::list<char> keys;

    switch(order){
        case BSTInOrder:
            std::printf("In order: ");
            tree.getInOrder(keys);
            break;
        case BSTPreOrder:
            std::printf("Pre-order: ");
            tree.getPreOrder(keys);
            break;
        case BSTPostOrder:
            std::printf("Post-order: ");
            tree.getPostOrder(keys);
            break;
        case BSTBreadth:
            std::printf("Breadth: ");
            tree.getBreadthFirst(keys);

    }// order

    bool first = true;
    for(auto& elem : keys){
        if(!first)
            std::printf(", ");
        std::cout<< elem ;
        first = false;
    }

    std::cout << std::endl;

}// printTree