// Circular linked list
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
    void insert_at_index();
    void display();
};
void list ::create_list()
{
    int choice = 1, data;
    Node *temp, *newNode;
    while (choice)
    {
        cout << "Enter the element" << endl;
        cin >> data;
        newNode = new Node(data);
        if (head == NULL)
        {
            head = temp = tail = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
            tail = temp;
        }
        cout << "Do you want to continue ( 0 , 1 ) ? " << endl;
        cin >> choice;
    }
    tail->next = head;
}


void list ::display()
{
    Node *temp = head;
    while (temp->next != head)
    {
        cout << temp->data << "\t";
        temp = temp->next;
    }
    cout << temp->data;
    cout << endl;
}
int main(void)
{
    list l1;
    l1.create_list();
    cout << "Elements of the circular linked list are => " << endl;
    l1.display();
    return 0;
}