// Implement stack using an array
// push => O(1)
// pop => O(1)
// isEmpty => O(1)
// size => O(1)
#include <iostream>
#define CAPACITY 10
using namespace std;
class stack
{
private:
    int top, arr[CAPACITY];

public:
    stack()
    {
        this->top = -1;
    }
    bool push(int data);
    int pop();
    int peek();
    int size();
    bool isEmpty();
};

bool stack::push(int data)
{
    if (top >= (CAPACITY - 1))
    {
        cout << "Stack is overflowed" << endl;
        return false;
    }
    else
    {
        int element = arr[top];
        top++;
        arr[top] = data;
        return true;
    }
}

int stack ::peek()
{
    if (isEmpty())
    {
        cout << "Stack is Empty" << endl;
        return -1;
    }
    else
    {
        return arr[top];
    }
}
int stack ::pop()
{
    if (isEmpty())
    {
        cout << "Stack is underflowed" << endl;
        return -1;
    }
    else
    {
        int element = arr[top];
        top--;
        return element;
    }
}
int stack::size()
{
    return top + 1;
}

bool stack ::isEmpty()
{
    return top < 0;
}

int main(void)
{

    stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.pop() << " Popped from stack\n";

    // print top element of stack after popping
    cout << "Top element is : " << s.peek() << endl;

    // print all elements in stack :
    cout << "Elements present in stack : ";
    while (!s.isEmpty())
    {
        // print top element in stack
        cout << s.peek() << " ";
        // remove top element in stack
        s.pop();
    }
    return 0;
}