// Implement queue using an array
// enqueue => O(1)
// dequeue => O(1)
// Front => O(1)
// display => O(n)
// Space complexity => O(n)
#include <iostream>
using namespace std;
class queue
{
private:
    int data, rear, front, *arr, capacity;

public:
    queue(int capacity)
    {
        this->capacity = capacity;
        this->arr = new int[capacity];
        rear = front = -1;
    }
    void enqueue(int data);
    void dequeue();
    int Front();
    int size();
    void display();
};
void queue ::enqueue(int data)
{
    if (rear >= capacity - 1)
    {
        cout << "Queue is full" << endl;
        return;
    }
    else if (front == -1)
    {
        front++;
    }
    rear++;
    arr[rear] = data;
}

void queue ::dequeue()
{
    if (front == -1)
    {
        cout << "Queue is empty" << endl;
        return;
    }
    else
    {
        int element = arr[front];
        cout << "Deleted element is => " << element<<endl;
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front++;
        }
    }
}

int queue ::Front()
{
    if (front == -1)
    {
        cout << "Queue is empty" << endl;
        return -1;
    }
    int element = arr[front];
    return element;
}

int queue ::size()
{
    return rear + 1;
}

void queue ::display()
{
    for (int i = front; i <= rear; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}
int main(void)
{
    queue q(5);
    q.enqueue(10);
    q.enqueue(15);
    q.enqueue(20);
    q.enqueue(25);
    q.enqueue(30);
    cout << "Elements of the Queue are => " << endl;
    q.display();
    cout << q.Front() << endl;
    q.dequeue();
    cout << "Elements of the Queue after removing element => " << endl;
    q.display();
    cout << q.Front() << endl;
    q.enqueue(35);
    q.enqueue(40);
    return 0;
}