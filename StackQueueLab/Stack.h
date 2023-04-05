#include "List.h"

#ifndef STACKQUEUELAB_STACK_H
#define STACKQUEUELAB_STACK_H

class Stack: public List {
    public:
        void push(int value);

        int pop();

        int peek();

};

#endif // STACKQUEUELAB_STACK_H