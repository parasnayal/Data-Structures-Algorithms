// Creation of the singly linked list
// Insertion at beg => O(1)
// Insertion at index => O(n)
// Insertion at end => O(n) and if we maintain a tail pointer then it would be optimize to O(1)
// delete at beg => O(1)
// delete at index => O(n)
// delete at end => O(n) and if we maintain a tail pointer then it would be optimize to O(1)
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

class list
{
private:
    Node *head, *tail;

public:
    list()
    {
        this->head = NULL;
        this->tail = NULL;
    }

    void create_list();
    void insert_at_beg();
    void insert_at_end();
    void insert_at_index(int index);
    void delete_at_beg();
    void delete_at_end();
    void delete_at_index(int index);
    void reverse();
    void display();
    int getLength()
    {
        int length = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            temp = temp->next;
            length++;
        }
        return length;
    }
};

void list ::create_list()
{
    int data, choice = 1;
    Node *newNode, *temp;
    while (choice)
    {
        cout << "Enter the element" << endl;
        cin >> data;
        newNode = new Node(data);
        if (head == NULL)
        {
            temp = head = tail = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
            tail = temp;
        }
        cout << "Do you want to continue (0 , 1 ) ? " << endl;
        cin >> choice;
    }
}

void list ::insert_at_beg()
{
    int data, choice = 1;
    Node *temp = head, *newNode;
    while (choice)
    {
        cout << "Enter the element at the beginning of the linked list " << endl;
        cin >> data;
        newNode = new Node(data);
        newNode->next = temp;
        temp = newNode;
        cout << "Do you want to continue ( 0 , 1 ) ? " << endl;
        cin >> choice;
    }
    head = temp;
}

void list ::insert_at_end()
{
    int data, choice = 1;
    Node *temp = tail, *newNode;
    while (choice)
    {
        cout << "Enter the element at the end of the linked list " << endl;
        cin >> data;
        newNode = new Node(data);
        temp->next = newNode;
        temp = newNode;
        cout << "Do you want to continue ( 0 , 1 ) ? " << endl;
        cin >> choice;
    }
    tail = temp;
}

void list ::insert_at_index(int index)
{
    int data, i = 0;
    Node *temp = head, *newNode;
    if (index == 0)
    {
        insert_at_beg();
    }
    else if (index == getLength())
    {
        insert_at_end();
    }
    else
    {
        while (i < index - 1)
        {
            temp = temp->next;
            i++;
        }
        cout << "Enter the data at the index " << index << endl;
        cin >> data;
        newNode = new Node(data);
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void list ::delete_at_beg()
{
    Node *temp = head;
    head = temp->next;
    delete temp;
}

void list ::delete_at_end()
{
    Node *temp = tail, *prevNode = head;
    while (prevNode->next != tail)
    {
        prevNode = prevNode->next;
    }
    prevNode->next = NULL;
    tail = prevNode;
    delete temp;
}

void list ::delete_at_index(int index)
{
    int i = 0;
    Node *nextNode = head->next, *curNode = head;
    while (i < index - 1)
    {
        curNode = curNode->next;
        nextNode = nextNode->next;
        i++;
    }
    curNode->next = nextNode->next;
    delete nextNode;
}

void list ::reverse()
{
    Node *curNode = head, *nextNode = head->next, *prevNode = NULL;
    tail = head;
    while (nextNode != NULL)
    {
        curNode->next = prevNode;
        prevNode = curNode;
        curNode = nextNode;
        nextNode = nextNode->next;
    }
    curNode->next = prevNode;
    head = curNode;
}
void list ::display()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "\t";
        temp = temp->next;
    }
    cout << endl;
}
int main(void)
{
    list l1;
    l1.create_list();
    cout << "Elements of the singly linked list are => " << endl;
    l1.display();

    // l1.insert_at_beg();
    // cout << "Elements of the singly linked list after inserting element at the beginning => " << endl;
    // l1.display();

    // l1.insert_at_end();
    // cout << "Elements of the singly linked list after inserting element at the end => " << endl;
    // l1.display();

    // int index = 3;
    // l1.insert_at_index(index);
    // cout << "Elements of the singly linked list after inserting element at the index " << index << " are => " << endl;
    // l1.display();

    // cout << "Length of the linked list is => " << l1.getLength() << endl;

    // l1.delete_at_beg();
    // cout << "Elements of the singly linked list after deleting the element from the beginning => " << endl;
    // l1.display();

    // l1.delete_at_end();
    // cout << "Elements of the singly linked list after deleting the element from the end => " << endl;
    // l1.display();

    // index = 2;
    // l1.delete_at_index(index);
    // cout << "Elements of the singly linked list after deleting the element from the index " << index << " are => " << endl;
    // l1.display();

    l1.reverse();
    cout << "Elements of the linked list after reversing => " << endl;
    l1.display();

    cout << "Length of the linked list is => " << l1.getLength() << endl;

    return 0;
}