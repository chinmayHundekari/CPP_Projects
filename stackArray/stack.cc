#include <iostream>
#include "stack.hpp"

Stack::Stack()
{
    stackSize = 0;
}
int Stack::size()
{
    return stackSize;
}
int Stack::isEmpty()
{
    return (stackSize == 0);
}

int Stack::top()
{
    if (isEmpty())
        throw e_stack_empty();
    else
        return stack[stackSize-1];
}

void Stack::push(int e)
{
    if (stackSize < STACK_SIZE)
        stack[stackSize++] = e;
    else
        throw e_stack_full();
}

int Stack::pop()
{
    if (isEmpty())
        throw e_stack_empty();
    else
        return stack[--stackSize];
}
