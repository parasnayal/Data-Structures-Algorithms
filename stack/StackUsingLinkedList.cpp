// Stack using an linked list
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class stack
{
private:
    Node *top;

public:
    stack()
    {
        this->top = NULL;
    }
    void push(int data);
    int pop();
    int peek();
    bool isEmpty();
    void display();
};

void stack ::push(int data)
{
    Node *newNode = new Node(data);
    if (top == NULL)
    {
        top = newNode;
    }
    else
    {
        newNode->next = top;
        top = newNode;
    }
}
int stack ::pop()
{
    Node *temp = top;
    if (top == NULL)
    {
        cout << "Stack is underflowed" << endl;
        return -1;
    }
    else
    {
        int element = temp->data;
        top = temp->next;
        delete temp;
        return element;
    }
}
int stack ::peek()
{

    if (top == NULL)
    {
        cout << "Stack is empty" << endl;
        return -1;
    }
    else
    {
        int element = top->data;
        return element;
    }
}
bool stack ::isEmpty()
{
    return top == NULL ? true : false;
}

void stack ::display()
{
    Node *temp = top;
    while (temp != NULL)
    {
        cout << temp->data << "\t";
        temp = temp->next;
    }
    cout << endl;
}
int main(void)
{
    stack s;

    // Push the elements of stack
    s.push(11);
    s.push(22);
    s.push(33);
    s.push(44);

    // Display stack elements
    s.display();

    // Print top element of stack
    cout << "\nTop element is " << s.peek() << endl;

    // Delete top elements of stack
    cout << "Deleted element is " << s.pop() << endl;
    cout << "Deleted element is " << s.pop() << endl;

    // Display stack elements
    s.display();

    // Print top element of stack
    cout << "\nTop element is " << s.peek() << endl;
    return 0;
}