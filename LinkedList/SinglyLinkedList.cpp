// Creation of the singly linked list
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
    Node *head;

public:
    list()
    {
        this->head = NULL;
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
        cout << "Enter the elements of the linked list " << endl;
        cin >> data;
        newNode = new Node(data);
        if (head == NULL)
        {
            head = temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
        cout << "Do you want to continue (0 , 1 ) ? " << endl;
        cin >> choice;
    }
}
void list ::insert_at_beg()
{
    int choice = 1, data;
    Node *newNode, *temp = head;
    while (choice)
    {
        cout << "Enter the element at the beginning of the linked list => " << endl;
        cin >> data;
        newNode = new Node(data);
        newNode->next = temp;
        temp = newNode;
        cout << "Do you want to continue (0 , 1 ) ? " << endl;
        cin >> choice;
    }
    head = temp;
}
void list ::insert_at_end()
{
    
}
void list ::insert_at_index()
{
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
    cout << "Elements of the linked list are => " << endl;
    l1.display();
    l1.insert_at_beg();
    cout << "Elements of the linked list after inserting the element at the beginning of the linked list are => " << endl;
    l1.display();
    return 0;
}