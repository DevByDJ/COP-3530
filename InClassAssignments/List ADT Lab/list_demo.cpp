// File : list_demo.cpp
// Class: COP 3530 Digital Sys & Architecture
// Dev  : <<Your Name Here>>
// Desc : Implement a Linked List ADT by randomly calling
//        list operations with random values
// --------------------------------------------------------
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "List.h"
#include "List.cpp"


// --------------------------------------------------------
// Types
// --------------------------------------------------------

// simulated menu choice operations on the list
enum ListOp {
    LIST_APPEND,
    LIST_INSERT,
    LIST_SEARCH,
    LIST_UPDATE,
    LIST_DELETE
};


// --------------------------------------------------------
// Function Declarations (proto-types)
// --------------------------------------------------------
void appendList(List* list);
void insertList(List* list);
void searchList(List* list);
void updateList(List* list);
void deleteList(List* list);
void printList(List* list);


// --------------------------------------------------------
// Function Definitions
// --------------------------------------------------------
int main() {

    List list; // the one and only List

    char again; // user choice to continue
    do {

        srand(time(NULL));  // refresh random numbers

        // random list operations
        int op = rand() % 5 ;
        switch(op) {
            case LIST_APPEND:
                appendList(&list);
                break;
            case LIST_INSERT:
                insertList(&list);
                break;
            case LIST_SEARCH:
                searchList(&list);
                break;
            case LIST_UPDATE:
                updateList(&list);
                break;
            case LIST_DELETE:
                deleteList(&list);
        }

        // print the current list
        printList(&list);

        // prompt user to continue
        std::cout << "\nAgain (N/n)? ";
        std::cin.get(again);
        std::cout << std::endl;

    } while(again != 'N' && again != 'n');

    return 0; // return success to OS
} // main


/**
 * Append a random number to the end of the list
 * @param list -- pointer to a list ADT
 */
void appendList(List* list) {

    srand(time(NULL)); // refresh random numbers

    int value = rand() % 10; // calc random number value
    list->insert(value);      // test 1-parameter insert w/ default position

    std::cout << "Appended " << value << " at " << list->getSize() - 1 << std::endl;
}


/**
 * Insert a random number at a random position
 * @param list -- pointer to a list ADT
 */
void insertList(List* list) {

    srand(time(NULL)); // refresh random numbers

    int value = rand() % 10;       // calc random number value
    int position = list->getSize(); // init to size in case list is empty

    if(list->isEmpty()) {
        list->insert(value); // test 1-parameter insert w/ default position
    }
    else {
        position = rand() % list->getSize(); // calc random position (0 <-> (size - 1))
        list->insert(value, position); // test 2-parameter insert
    }

    std::cout << "Inserted " << value << " at " << position << std::endl;
} // insertList

void searchList(List* list) {

    srand(time(NULL)); // refresh random numbers

    // Generate a random number between 0 and 9
    int value = rand() % 10; 
    
    // Get the size of the list
    int size = list->getSize();
    
    // Used to store the result of the search
    int result = 0;
    
    // Check if an element exists in the list
    if(size)
    {
        result = list->search(value, size);
    }
    
    // Output the result of the search
    if(result > 0)
    {
        std::cout << "We are searching for " << value << " and the result is: " << result << std::endl;
    }
    else
    {
        std::cout << "No result was found for " << value << std::endl;
    }
    
}


/**
 * Update a random list position with a new random number
 * @param list -- pointer to a list ADT
 */
void updateList(List* list) {
    if (list->isEmpty()) {
        std::cout << "Update failed: list empty!" << std::endl;
    }
    else {
        // calc random number value and list position
        int value = rand() % 100;
        int position = rand() % list->getSize();

        list->modify(value, position); // test modify method

        std::cout << "Updated " << value << " at " << position << std::endl;
    }
} // updateList


/**
 * Delete 1 value at a random position in the list
 * @param list -- pointer to a list ADT
 */
void deleteList(List* list) {
    if (list->isEmpty()) {
        std::cout << "Delete failed: list empty!" << std::endl;
    }
    else {
        int position = rand() % list->getSize(); // calc random position

        int value = list->remove(position); // test remove method

        std::cout << "Deleted " << value << " from " << position << std::endl;
    }
} // deleteList


/**
 * Print the current list to the console
 * @param list -- pointer to a list ADT
 */
void printList(List* list) {
    int size =list->getSize();

    if (size) {
        std::cout << "List = {";
        for (int i = 0; i < size; i++) {
            std::cout << list->read(i);
            if (i < size - 1)
                std::cout << ",";
        }
        std::cout << "}" << std::endl;
    }
    else {
        std::cout << "List is empty!" << std::endl;
    }
} // printList