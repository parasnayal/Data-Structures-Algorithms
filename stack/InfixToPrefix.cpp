// Time Complexity: O(n)
// Auxiliary Space: O(n) because we are keeping a stack.

// First, reverse the infix expression given in the problem.
// Scan the expression from left to right.
// Whenever the operands arrive, print them.
// If the operator arrives and the stack is found to be empty, then simply push the operator into the stack.
// If the incoming operator has higher precedence than the TOP of the stack, push the incoming operator into the stack.
// If the incoming operator has the same precedence with a TOP of the stack, push the incoming operator into the stack.
// If the incoming operator has lower precedence than the TOP of the stack, pop, and print the top of the stack. Test the incoming operator against the top of the stack again and pop the operator from the stack till it finds the operator of a lower precedence or same precedence.
// If the incoming operator has the same precedence with the top of the stack and the incoming operator is ^, then pop the top of the stack till the condition is true. If the condition is not true, push the ^ operator.
// When we reach the end of the expression, pop, and print all the operators from the top of the stack.
// If the operator is ')', then push it into the stack.
// If the operator is '(', then pop all the operators from the stack till it finds ) opening bracket in the stack.
// If the top of the stack is ')', push the operator on the stack.
// At the end, reverse the output.

#include <iostream>
#include <string>
using namespace std;
string reverse(string &name);
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
    string infixToPrefix(string infix);
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

string stack ::infixToPrefix(string infix)
{
    string prefix = "";
    for (int i = 0; i < infix.length(); i++)
    {
        char ch = infix.at(i);
        if (!isOperator(ch))
        {
            prefix += ch;
        }
        else if (ch == '(')
        {
            push(ch);
        }
        else if (ch == ')')
        {
            while (!isEmpty() && peek() != '(')
            {
                prefix += peek();
                pop();
            }
            pop();
        }
        else
        {
            if (ch == '^')
            {
                while (precedence(ch) == precedence(peek()))
                {
                    prefix += peek();
                    pop();
                }
            }
            else
            {
                while (precedence(ch) < precedence(peek()))
                {
                    prefix += peek();
                    pop();
                }
            }
            push(ch);
        }
    }
    while (!isEmpty())
    {
        prefix += peek();
        pop();
    }

    reverse(prefix);
    return prefix;
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
    // string infix = "K+L-M*N+(O^P)*W/U/V*T+Q";
    string infix = ("x+y*z/w+u");
    reverse(infix);
    cout << "Prefix expression => " << s.infixToPrefix(infix) << endl;
    return 0;
}

string reverse(string &name)
{
    int n = name.length();
    for (int i = 0; i <= n / 2; i++)
    {
        swap(name[i], name[n - i - 1]);
    }

    for (int i = 0; i <= n; i++)
    {
        if (name[i] == ')')
        {
            name[i] = '(';
        }
        else if (name[i] == '(')
        {
            name[i] = ')';
        }
    }
    return name;
}