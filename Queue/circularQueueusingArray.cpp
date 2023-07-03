// Implement circular queue using an array
#include <iostream>
using namespace std;
class queue
{
private:
    int data, front, rear, *arr, capacity;

public:
    queue(int capacity)
    {
        this->capacity = capacity;
        arr = new int[capacity];
        front = rear = -1;
    }
    void enqueue(int data);
    void dequeue();
    int Front();
    bool isFull();
    bool isEmpty();
    int size();
    void display();
};

void queue ::enqueue(int data)
{
    if (isFull())
    {
        cout << "Queue is full" << endl;
        return;
    }
    else if (front == -1)
    {
        front = 0;
    }
    rear = rear + 1 % capacity;
    arr[rear] = data;
}

void queue ::dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is empty" << endl;
        return;
    }
    else
    {
        int element = arr[front];
        cout << "Deleted element is => " << element << endl;
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % capacity;
        }
    }
}

int queue ::Front()
{
    if (isEmpty())
    {
        cout << "Queue is empty" << endl;
        return -1;
    }
    else
    {
        return arr[front];
    }
}

bool queue ::isFull()
{
    return (rear + 1) % capacity == front ? true : false;
}

bool queue ::isEmpty()
{

    return front == -1 ? true : false;
}

int queue ::size()
{
    return rear - front + 1;
}

void queue ::display()
{
    int i = front;
    if (front < rear)
    {
        while (i <= rear)
        {
            cout << arr[i] << "\t";
            i++;
        }
    }
    else
    {
        while (i != rear)
        {
            cout << arr[i] << "\t";
            i = (i + 1) % capacity;
        }
        cout << arr[i] << "\t";
    }
    cout << endl;
}

int main(void)
{
    queue q(5);
    q.enqueue(42);
    q.enqueue(66);
    q.enqueue(35);
    q.enqueue(59);
    q.enqueue(17);
    q.display();
    // Delete first 2 elements
    q.dequeue();
    q.dequeue();
    q.display();
    // Insert 10
    q.enqueue(10);
    q.display();
    return 0;
}