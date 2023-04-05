// File: BSTree.h
//
// Created by andyh on 3/31/2023.
// Binary Search Tree Abstract Data Type

#include <list>
#include<queue>

#ifndef BINARYTREE2_BSTREE_H
#define BINARYTREE2_BSTREE_H

template <typename K>
class BSTree {


private:
    struct BSTNode {
        K key;
        BSTNode* left;
        BSTNode* right;

        BSTNode(K key){
          this->key = key;
          left = nullptr;
          right = nullptr;

        }

        bool isleaf() {return !left && !right; }
    };

    BSTNode* root;

public:

    /**
     * default constructor - setup empty tree
     */
    BSTree( ){root = nullptr; };

    /**
     *  clean up nodes
     */
    ~BSTree() { makeEmpty(root);}

    /**
     *
     * @return true if tree is empty
     */
    bool isEmpty(){ return !root; }

    void empty() {
        makeEmpty(root);
        root = nullptr;
    };

    /**
     *  Insert a value in order in the tree
     * @param key - value to insert
     */
    void insert ( K key ){
        root  = insertHelper(key, root);
    } // insert

    /**
     * get list of keys in order
     * @param keys
    */
    void getInOrder(std::list<char> & keys){
        inOrder(root, keys);
    }


    /**
     * get list of keys in pre-order
     * @param keys
     */
    void getPreOrder(std::list<char> & keys){
        preOrder(root, keys);
    }

    /**
     * get list of keys in order
     * @param keys
    */
    void getPostOrder(std::list<char> & keys){
        postOrder(root, keys);
    }

    void getBreadthFirst(std::list<char> & keys){
        breadthFirst(root, keys);
    }



private:


    /**
     * populate a list of the keys in order
     * Left, Root (Data), Right
     * @param root - current subtree root
     * @param keys - OUT - list of keys
     */
    void inOrder(BSTNode * root, std::list<char> & keys){

        if (!root) // went past null left/right
            return;

        // traverse down the left side of the tree until you can't anymore    
        inOrder(root->left, keys);
        // capture the keys as you go
        keys.push_back(root->key);
        // traverse down the right side until all right nodes are covered.
        inOrder(root->right, keys);

    } // inOrder


    /**
     * populate a list of the keys in pre-order
     * Root (Data), Left, Right
     * @param root - current subtree root
     * @param keys - OUT - list of keys
     */
    void preOrder(BSTNode* root, std::list<char> & keys){

        if (!root) // went past null left/right
            return;
        // capture this node's key
        keys.push_back(root->key);
        // walk its left branch
        preOrder(root->left, keys);
        // walk its right branch
        preOrder(root->right, keys);

    }// preOrder


    /**
     * populate a list of the keys in post-order
     * Left, Right, Root(Data)
     * @param root - current subtree root
     * @param keys - OUT - list of keys
     */
    void postOrder(BSTNode* root, std::list<char> & keys){

        if (!root) // went past null left/right
            return;

        // traverse down the left side of the tree until you can't anymore    
        postOrder(root->left, keys);

        // traverse down the right side until all right nodes are covered.
        postOrder(root->right, keys);

        // capture the keys as you go
        keys.push_back(root->key);
        

    } // postOrder

    std::list<char> breadthFirst(BSTNode * root, std::list<char> & keys){

        if (!root) // went past null left/right
            return keys;

        // Create a queue that holds Binary Node Pointers
        std::queue<BSTNode*> currentQueue;

        // Start the queue with the root node
        currentQueue.push(root);

        // While the queue has nodes...
        while(!currentQueue.empty())
        {

           // Set the node in the front of the queue as the new root
           root = currentQueue.front();

           // Add this key value to the list of 'chars' that we will return
           keys.push_back(root->key);

           // If that root had a left child add it to the queue
           if(root->left){
                currentQueue.push(root->left);
           }

           // If that root had a right child add it to the queue
           if(root->right){
                currentQueue.push(root->right);
           }

           // Drop the node at the front of the list..
           currentQueue.pop();

        }

        // Return the list of keys collected.
        return keys;


    } // breadthFirst


    /**
     * Insert a key value in a subtree
     * @param key  - value to insert
     * @param root - of the subtree
     * @return root of subtree where value inserted or new node
     */

    BSTNode* insertHelper( K key, BSTNode* root) {
        // if empty then create new node here
        if (!root)
            return new BSTNode(key);

        // if key value less than current then nav left
        if( key <= root->key)
            root->left = insertHelper(key, root->left);

        // key is greater than current root than nav right
        else
            root->right = insertHelper(key, root->right);

        // current node bubles up (to left pointer)
        return  root;


    } // insertHelper

    void makeEmpty(BSTNode* root){

        if(root){
        makeEmpty(root->left);
        makeEmpty(root->right);
        delete root;
        }
        root = nullptr;
    } // makeEmpty

}; // BSTNode



#endif //BINARYTREE2_BSTREE_H
