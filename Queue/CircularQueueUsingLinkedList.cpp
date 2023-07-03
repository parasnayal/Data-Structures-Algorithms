// Implement queue using linked list
#include <iostream>
#include <limits>
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

class queue
{
private:
    Node *front, *rear;

public:
    queue()
    {
        this->front = NULL;
        this->rear = NULL;
    }
    void enqueue(int data);
    void dequeue();
    int Front();
    void display();
};

void queue ::enqueue(int data)
{
    Node *newNode;
    newNode = new Node(data);
    if (front == NULL)
    {
        front = rear = newNode;
        return;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
    rear->next = front;
}

void queue ::dequeue()
{

    if (front == NULL)
    {
        cout << "Queue is empty " << endl;
        return;
    }
    else
    {

        Node *temp = front;
        cout << "Deleted element is => " << front->data << endl;
        if (front == rear)
        {
            front = rear = NULL;
        }
        else
        {
            front = front->next;
            rear->next = front;
        }

        delete temp;
    }
}

int queue ::Front()
{
    if (front == NULL)
    {
        cout << "Queue is empty " << endl;
        return -1;
    }

    return front->data;
}

void queue ::display()
{
    // cout << front << endl;
    if (front == NULL)
    {
        cout << "Queue is empty" << endl;
        return;
    }
    Node *temp = front;
    while (temp->next != front)
    {
        cout << temp->data << "\t";
        temp = temp->next;
    }
    cout << temp->data;
    cout << endl;
}

int main(void)
{
    queue q;
    q.enqueue(42);
    q.enqueue(66);
    q.enqueue(35);
    q.display();
    // Delete all of them
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.display();
    // Insert 10
    q.enqueue(10);
    q.display();
    // Try deleting an element in an empty circular queue.
    q.dequeue();
    return 0;
}