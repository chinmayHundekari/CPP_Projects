#ifndef QUEUE_H_
#define QUEUE_H_
#include <exception>
using namespace std;
#define QUEUE_SIZE 1000

class Queue {
protected:
    int queue[QUEUE_SIZE];
    int qTop;
    int qBot;
public:
    int size();
    int isEmpty();
    int top();
    void enqueue(int e);
    int dequeue();
    Queue();
};
class e_queue_full: public exception
{
  virtual const char* what() const throw()
  {
    return "Queue is full, Maximum size is 1000";
  }
};
class e_queue_empty: public exception
{
  virtual const char* what() const throw()
  {
    return "Queue is empty";
  }
};
#endif
