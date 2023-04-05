#include "Stack.h"

void Stack::push(int value)
{
    insert(value, LIST_HEAD);
}

int Stack::pop()
{
    return remove(LIST_HEAD);
}

int Stack::peek()
{
    return read(LIST_HEAD);
}
