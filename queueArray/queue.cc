#include <iostream>
#include "queue.hpp"

Queue::Queue()
{
    qBot = 0;
    qTop = 0;
}
int Queue::size()
{
    if (qBot >= qTop)
        return (qBot - qTop);
    else
        return (QUEUE_SIZE - qBot + qTop);
}
int Queue::isEmpty()
{
    return (qBot == qTop);
}

int Queue::top()
{
    if (isEmpty())
        throw e_queue_empty();
    else
        return queue[qTop];
}

void Queue::enqueue(int e)
{
    if (size() < QUEUE_SIZE - 1)
        queue[qBot++] = e;
    else
        throw e_queue_full();
}

int Queue::dequeue()
{
    if (isEmpty())
        throw e_queue_empty();
    else
        return queue[qTop++];
}
