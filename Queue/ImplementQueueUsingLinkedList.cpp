// Implement queue using linked list
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
        front = front->next;
        if (front == NULL)
        {
            rear = NULL;
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
    Node *temp = front;
    while (temp != rear)
    {
        cout << temp->data << "\t";
        temp = temp->next;
    }
    cout << endl;
}

int main(void)
{
    queue q;
    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);
    q.enqueue(20);
    q.enqueue(25);
    q.enqueue(30);
    cout << "Elements of the queue are => " << endl;
    q.display();
    cout << "Top element is => " << q.Front() << endl;
    q.dequeue();
    cout << "Top element is => " << q.Front() << endl;
    cout << "Elements of the queue are => " << endl;
    q.display();
    return 0;
}