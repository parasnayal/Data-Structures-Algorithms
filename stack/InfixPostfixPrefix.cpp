// Infix => Infix is the way to write a expression In which operator is written between the operand.It can easily understand by the human.
// Example => a+b

// Prefix => Is the way to write a expression in which operator is written before operand .It is also known as polish notation.
// Example => +ab

// Postfix => Is the way to write a expression in which operator is written after the operand .It is also known as Reverse polish notation.
// Example => ab+

// Infix to postfix conversion

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
    bool isOperator(char ch);
    int precedence(char ch);
    string infixToPostfix(string infix);
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

bool stack ::isOperator(char ch)
{
    if (ch == '+' || ch == '*' || ch == '-' || ch == '/' || ch == '^' || ch == '%' || ch == '(' || ch == ')')
    {
        return true;
    }
    else
    {
        return false;
    }
}

int stack ::precedence(char ch)
{
    if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else if (ch == '*' || ch == '/')
    {
        return 2;
    }
    else if (ch == '^')
    {
        return 3;
    }
    else
    {
        return 0;
    }
}

string stack ::infixToPostfix(string infix)
{
    string postfix = "";
    for (int i = 0; i < infix.length(); i++)
    {
        char ch = infix.at(i);
        if (!isOperator(ch))
        {
            postfix += ch;
        }
        else
        {
            if (isEmpty())
            {
                push(ch);
            }

            else if (ch == '(')
            {
                push(ch);
            }
            else if (ch == ')')
            {
                while (!isEmpty() && peek() != '(')
                {
                    postfix += peek();
                    pop();
                }
                pop();
            }
            else if (precedence(ch) > precedence(peek()))
            {
                push(ch);
            }
            else if (precedence(ch) <= precedence(peek()))
            {
                while (!isEmpty() && precedence(ch) <= precedence(peek()))
                {
                    postfix += peek();
                    pop();
                }
                push(ch);
            }
        }
    }
    while (!isEmpty())
    {
        postfix += peek();
        pop();
    }
    return postfix;
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
    // string infix = "a+b*(c^d-e)^(f+g*h)-i";
    string infix = "K+L-M*N+(O^P)*W/U/V*T+Q";
    cout << s.infixToPostfix(infix) << endl;
    return 0;
}
