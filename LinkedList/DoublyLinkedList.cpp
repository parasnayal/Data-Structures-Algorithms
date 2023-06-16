// Creation of the doubly linked list
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
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
};
void list ::create_list()
{
    int data, choice = 1;
    Node *temp, *newNode;
    while (choice)
    {
        cout << "Enter the element" << endl;
        cin >> data;
        newNode = new Node(data);
        if (head == NULL)
        {
            head = tail = temp = newNode;
        }
        else
        {
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
            tail = temp;
        }
        cout << "Do you want to continue ( 0 , 1 ) ? " << endl;
        cin >> choice;
    }
}

void list ::insert_at_beg()
{
    int data, choice = 1;
    Node *temp = head, *newNode;
    while (choice)
    {
        cout << "Enter the element at the beginning of the doubly linked list" << endl;
        cin >> data;
        newNode = new Node(data);
        newNode->next = temp;
        temp->prev = newNode;
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
        cout << "Enter the element at the end of the doubly linked list" << endl;
        cin >> data;
        newNode = new Node(data);
        temp->next = newNode;
        newNode->prev = temp;
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
    else
    {

        while (i < index - 1)
        {
            temp = temp->next;
            i++;
        }
        cout << "Enter the element " << endl;
        cin >> data;
        newNode = new Node(data);
        newNode->prev = temp;
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void list ::delete_at_beg()
{
    Node *temp = head;
    head = temp->next;
    head->prev = NULL;
    delete temp;
}

void list ::delete_at_end()
{
    Node *temp = tail;
    tail->prev->next = NULL;
    tail = temp->prev;
    delete temp;
}

void list ::delete_at_index(int index)
{
    int i = 0;
    Node *temp = head;
    while (i < index)
    {
        temp = temp->next;
        i++;
    }
    temp->prev->next = temp->next;
    delete temp;
}

void list ::reverse()
{
    Node *temp = head, *nextNode = head->next, *prevNode = NULL;
    tail = head;
    while (nextNode != NULL)
    {

        temp->next = prevNode;
        temp->prev = nextNode;
        prevNode = temp;
        temp = nextNode;
        nextNode = nextNode->next;
    }
    temp->next = prevNode;
    temp->prev = nextNode;
    head = temp;
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
    cout << "Elements of the doubly linked list are => " << endl;
    l1.display();

    // l1.insert_at_beg();
    // cout << "Elements of the doubly linked list after inserting element at the beginning => " << endl;
    // l1.display();

    // l1.insert_at_end();
    // cout << "Elements of the doubly linked list after inserting element at the end => " << endl;
    // l1.display();

    // int index = 3;
    // l1.insert_at_index(index);
    // cout << "Elements of the doubly linked list after inserting element at index " << index << " are => " << endl;
    // l1.display();

    // l1.delete_at_beg();
    // cout << "Elements of the doubly linked list after deleting element from the beginning => " << endl;
    // l1.display();

    // l1.delete_at_end();
    // cout << "Elements of the doubly linked list after deleting element from the end => " << endl;
    // l1.display();

    // int index = 3;
    // l1.delete_at_index(index);
    // cout << "Elements of the doubly linked list after deleting element from the end => " << endl;
    // l1.display();

    l1.reverse();
    cout << "Elements of the linked list after reversing => " << endl;
    l1.display();
    return 0;
}
