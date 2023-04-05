// File : stack_queue.cpp
// Class: COP 3530 Data Structs
// Dev  : Danny Joseph
// Desc : Demo program for Stacks, Queues, and Lists
// --------------------------------------------------------
#include <iostream>

#include "Stack.h"
#include "Queue.h"

enum MenuChoice {
    m_Exit,
    m_GetValue,
    m_AddStack,
    m_RemoveStack,
    m_CopyStack,
    m_AddQueue,
    m_RemoveQueue,
    m_CopyQueue
};

MenuChoice getMenuChoice();
int getValue();

void printList(List & list);

void addValueStack(Stack & stack, int value);
int delValueStack(Stack & stack);
int getValueStack(Stack & stack);

void addValueQueue(Queue & queue, int value);
int delValueQueue(Queue & queue);
int getValueQueue(Queue & queue);


int main() {

    Stack stack;
    Queue queue;

    int value = 0;  // will be used between the menu items

    MenuChoice menuItem;
    do {
        
        menuItem = getMenuChoice();
        
        switch(menuItem) {

            case m_GetValue:
                value = getValue();
                break;
            
            case m_AddStack:
                addValueStack(stack, value);
                break;

            case m_RemoveStack:
                value = delValueStack(stack);
                break;

            case m_CopyStack:
                value = getValueStack(stack);
                break;

            case m_AddQueue:
                addValueQueue(queue, value);
                break;

            case m_RemoveQueue:
                value = delValueQueue(queue);
                break;

            case m_CopyQueue:
                value = getValueQueue(queue);
                break;

            default:
                printf("\nGoodbye!\n");
        } // menu

        std::printf("\nStack:\n");
        printList(stack);

        std::printf("\nQueue:\n");
        printList(queue);

    } while(menuItem != m_Exit);

    return 0;
}


/**
 * Print the menu and get user input
 * @return user menu choice
 */
MenuChoice getMenuChoice() {
    int choice;

    do { // print menu and ask for choice
         // until a valid choice is entered
        std::printf("\n\nMenu:\n");
        std::printf("\t%d...New Value\n", m_GetValue);
        std::printf("\t%d...Add to Stack\n", m_AddStack);
        std::printf("\t%d...Remove from Stack\n", m_RemoveStack);
        std::printf("\t%d...Copy from Stack\n", m_CopyStack);
        std::printf("\t%d...Add to Queue\n", m_AddQueue);
        std::printf("\t%d...Remove from Queue\n", m_RemoveQueue);
        std::printf("\t%d...Copy from Queue\n", m_CopyQueue);
        std::printf("\t%d...Exit\n", m_Exit);
        std::printf("\t> ");
        std::cin >> choice;

    } while (!(choice >= m_Exit && choice <= m_CopyQueue));

    return static_cast<MenuChoice>(choice); // case int choice to enum
} // getMenuChoice


/**
 * Get a new integer value from user
 * @return user entered value
 */
int getValue() {
    int value;
    std::printf("\nEnter an integer value: ");
    std::cin >> value;
    return value;
}

void printList(List & list) {
    for (int ndx = 0; ndx < list.getSize(); ndx++){
        std::cout << list.read(ndx) << std::endl;
    }
}


/**
 * add a value to the stack
 * @param stack - the stack
 * @param value - value to push
 */
void addValueStack(Stack & stack, int value) {
    stack.push(value);
} // addValueStack


/**
 * remove a value from the stack
 * @param stack - the stack
 * @return value removed from stack
 */
int delValueStack(Stack & stack) {
    return stack.pop();
} // delValueStack

/**
 * read value on the stack
 * @param stack - the stack
 * @return value read from stack
 */
int getValueStack(Stack & stack) {
    return stack.peek();
}

/**
 * add a value to the queue
 * @param queue - the queue
 * @param value - value to enqueue
 */
void addValueQueue(Queue & queue, int value) {
    queue.enqueue(value);
} // addValueQueue


/**
 * remove a value from the queue
 * @param queue - the queue
 * @return value removed from Queue
 */
int delValueQueue(Queue & queue) {
    return queue.dequeue();
} // delValueQueue

/**
 * read value in the queue
 * @param queue - the queue
 * @return value read from Queue
 */
int getValueQueue(Queue & queue) {
    return queue.peek();
}