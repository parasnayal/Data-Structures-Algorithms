// Implement Queue using stack

// ********** 1st way **********

// Time Complexity:
// Push operation: O(N).
// In the worst case we have empty whole of stack 1 into stack 2.
// Pop operation: O(1).
// Same as pop operation in stack.
// Auxiliary Space: O(N).
// Use of stack for storing values.

// #include <iostream>
// #include <stack>
// using namespace std;
// class queue
// {
// public:
//     stack<int> s1, s2;
//     queue(){};
//     void enqueue(int data);
//     int dequeue();
//     int front();
// };

// void queue ::enqueue(int data)
// {
//     if (s1.empty())
//     {
//         s1.push(data);
//     }
//     else
//     {
//         while (!s1.empty())
//         {
//             s2.push(s1.top());
//             s1.pop();
//         }
//         s1.push(data);
//         while (!s2.empty())
//         {
//             s1.push(s2.top());
//             s2.pop();
//         }
//     }
// }

// int queue ::dequeue()
// {
//     if (s1.empty())
//     {
//         cout << "Queue is empty " << endl;
//         return -1;
//     }
//     else
//     {
//         int element = s1.top();
//         s1.pop();
//         return element;
//     }
// }

// int queue ::front()
// {
//     if (s1.empty())
//     {
//         cout << "Queue is empty " << endl;
//         return -1;
//     }
//     else
//     {
//         int element = s1.top();
//         return element;
//     }
// }

// int main(void)
// {
//     queue q;
//     q.enqueue(1);
//     q.enqueue(2);
//     q.enqueue(3);

//     cout << q.dequeue() << '\n';
//     cout << q.dequeue() << '\n';
//     cout << q.dequeue() << '\n';
//     return 0;
// }

// ********** 2nd way *************

// Time Complexity:
// Push operation: O(1).
// Same as pop operation in stack.
// Pop operation: O(N) in general and O(1) amortized time complexity.
// In the worst case we have to empty the whole of stack 1 into stack 2 so its O(N). Amortized time is the way to express the time complexity when an algorithm has the very bad time complexity only once in a while besides the time complexity that happens most of time. So its O(1) amortized time complexity, since we have to empty whole of stack 1 only when stack 2 is empty, rest of the times the pop operation takes O(1) time.
// Auxiliary Space: O(N).
// Use of stack for storing values.

#include <iostream>
#include <stack>
using namespace std;
class queue
{
public:
    stack<int> s1, s2;
    queue(){};
    void enqueue(int data);
    int dequeue();
    int front();
};

void queue ::enqueue(int data)
{
    s1.push(data);
}

int queue ::dequeue()
{
    if (s1.empty() && s2.empty())
    {
        cout << "Queue is empty " << endl;
        return -1;
    }
    else
    {
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int element = s2.top();
        s2.pop();
        return element;
    }
}

int queue ::front()
{
    if (s1.empty() && s2.empty())
    {
        cout << "Queue is empty " << endl;
        return -1;
    }
    else
    {
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int element = s2.top();
        return element;
    }
}

int main(void)
{
    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << q.dequeue() << '\n';
    cout << q.dequeue() << '\n';
    cout << q.dequeue() << '\n';
    return 0;
}