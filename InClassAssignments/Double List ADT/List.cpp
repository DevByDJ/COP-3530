// File : List.h
// Class: COP 3530 DATA STRUCTS
// Dev  : Danny Joseph
// Desc : Double-Linked List ADT implementation
// --------------------------------------------------------
#include "List.h"



/**
 * Default constructor - initialize empty list
 */
List::List()
    : head {nullptr, nullptr}, tail {nullptr, nullptr} size{0} {

} // default constructor


/**
 * Destructor - clean up nodes
 */
List::~List() {
    // if list is not empty
    if (head) {
        // repeat until head moved past end of list
        while (head->next) {
            Node* temp = head;  // hold reference to current head Node
            head = head->next;  // move head pointer to next node in list
            delete temp;        // delete old head Node
        }

    } // is list empty
} // destructor


/**
 * Accessor for the list size property
 * @return int size (empty = 0)
 */
int List::getSize() {
    return size;
} // getSize


/**
 * Signifies if the list is empty or not
 * @return bool True if empty (size==0)
 */
bool List::isEmpty() {
    return size == 0;
} // isEmpty


/**
 * Add a new value into the list at the head, a
 * specified position, or at the tail if position
 * is -1 or invalid position
 * @param value - int value to store
 * @param position - position in list to store value (default -1)
 */
void List::insert(int value, int position) {
    Node* temp = new Node{value, nullptr, nullptr};
    tail = traverse(size);

    // if (position < LIST_HEAD || position >= size)
    //     position = size;

    // determine where in list to insert
    if( size == 0 || position < 0) {
        temp->next = head;  // new node points to head
        head = temp;        // move head pointer to new node
    } else {  // middle or tail of list

        // traverse list to node - 1
        Node* pNode = traverse(position - 1);

        // insert node between current and next node
        temp->next = pNode->next; // new node points to next node
        pNode->next = temp;       // current node points to new node

    } // where in list

    // increment size of the list
    size++;

} // insert


/**
 * Remove a value from the list at a specified position and
 * return it to the caller
 * @param position - position in the list or tail if -1
 *                   or invalid position
 * @return - value removed from the list
 */
int List::remove(int position) {
    int value = -1;
    tail = traverse(size);

    if(isEmpty())
        return value;

    Node* temp;
    if(position == LIST_HEAD || size == 1)
    {
        temp = head;

        head = temp->next;

    } else if(position == size || position == LIST_TAIL){

        temp = tail;

    } else { 
        if(position > LIST_HEAD && position < LIST_TAIL) 
            position = size - 1;

        Node* pNode = traverse(position - 1);
        temp = pNode->next;
        pNode->next = pNode->next->next;
    }

    value = temp->value;
    delete temp;

    size--;

    return value;
} // remove


/**
 * Return a value from the list at a specified position without
 * removing it
 * @param position - position in the list
 * @return - value found at position (-1 if not found or invalid position)
 */
int List::read(int position) {
    int value = -1;

    if (size > 0) {
        Node* pNode = traverse(position);
        value = pNode->value;
    }

    return value;
} // read


/**
 * Modify a value at a specified position in the list
 * @param value - new value
 * @param position - position in the list
 */
void List::modify(int value, int position) {

    if (size > 0) {
        Node* pNode = traverse(position);
        pNode->value = value;
    }

} // modify

// search through the linked list for a specified value
int List::search(int valueToSearch, int sizeOfTheList) 
{
    // initialize the pointer to the head of the list
    Node* pNode = head;

    // counter for list traversal
    int counter = 0;

    // return -1 is sizeOfTheList is 0
    if(sizeOfTheList == 0)
    {
        return -1;
    }

    // iterate until the listed is fully traversed, 
    // or pNode->next is equal to nullptr
    while(counter < sizeOfTheList && pNode->next)
    {
        // check if the current node's value is what we are searching
        if(pNode->value == valueToSearch)
        {
            // return the current counter index if the value has been found     
            return counter;
        }
        else
        {
            // set the pointer to the next node 
            pNode = pNode->next;
            
            // increment the counter
            counter++;
        }
    }

    // return -1 if no value has been found until the list was completely traversed 
    return -1;

}


// Private methods
// --------------------------------------------------------

/**
 * Iterate node pointer to specified position in the list
 * @param position - 0 to size-1
 * @return pointer to Node at List[position] (or null if empty)
 */
List::Node* List::traverse(int position) {
    Node* pNode = head; // start at head of list (null if empty)
    
    // traversing backwards if a negative position is given
    if(position < 0)
    {
        int counter = 0; // zero indexed list
                     // (don't move if position == 0)
        while(counter > position  && pNode->previous) {
            pNode->next = pNode;
            pNode = pNode->previous;
            counter--;
    // traversing backwards if a positive position is given
    } else {

        int counter = 0; // zero indexed list
                     // (don't move if position == 0)
        while(counter < position  && pNode->next) {
            pNode->previous = pNode;
            pNode = pNode->next;
            counter++;

        }

    } // traversal

    }


    return pNode;
}