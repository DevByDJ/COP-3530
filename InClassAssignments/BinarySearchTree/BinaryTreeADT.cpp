// File : BinaryTreeADT.cpp
// Class: COP 3530 Data Structures and Algo
// Dev  : Danny Joseph
// Desc : Implemented a Binary Tree
// --------------------------------------------------------
#include "BinaryTreeADT.h"

BinaryTreeADT::BinaryTreeADT()
{
    root = nullptr;
}
bool BinaryTreeADT::isEmpty()
{
    return !root;
}
BinaryTreeADT::BinaryNode* BinaryTreeADT::insert(BinaryNode * root, int value)
{
    // Base Case: to exit to finish out the task
    if(!root)
        return new BinaryNode {value, nullptr, nullptr};
    else if(value <= root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);
    
    return root;

}

bool BinaryTreeADT::search(BinaryNode *root, int value)
{
    if(!root)
        return false;
    else if (value == root->data)
        return true;
    else if (value <= root->data)
        return search(root->left, value);
    else
        return search(root->right, value);    
}

void BinaryTreeADT::preOrderTraversal(BinaryNode *root, std::list<int> &values)
{
    if(!root)
        return;
    else
    {
        values.push_back(root->data);
        if(root->left)
            preOrderTraversal(root->left, values);
        if(root->right)
            preOrderTraversal(root->right, values);
    }
}
