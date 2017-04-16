#ifndef STACK_H_
#define STACK_H_
#include <exception>
using namespace std;
#define STACK_SIZE 1000

class Stack {
private:
    int stack[STACK_SIZE];
    int stackSize;
public:
    int size();
    int isEmpty();
    int top();
    void push(int e);
    int pop();
    Stack();
};
class e_stack_full: public exception
{
  virtual const char* what() const throw()
  {
    return "Stack is full, Maximum size is 1000";
  }
};
class e_stack_empty: public exception
{
  virtual const char* what() const throw()
  {
    return "Stack is empty";
  }
};
#endif
