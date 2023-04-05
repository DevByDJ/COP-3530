#include "List.h"

#ifndef STACKQUEUELAB_QUEUE_H
#define STACKQUEUELAB_QUEUE_H

class Queue: public List {
    public:
        void enqueue(int value);

        int dequeue();

        int peek();
};

#endif // STACKQUEUELAB_QUEUE_H