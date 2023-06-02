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
    void display();
};
void list ::create_list()
{
    int choice = 1, data;
    Node *temp;
    while (choice)
    {
        cout << "Enter the data in the linked list " << endl;
        cin >> data;
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
        cout << "Do you want to continue (0,1) ? " << endl;
        cin >> choice;
    }
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

    cout << "Elment of the linked list are " << endl;
    l1.display();
    return 0;
}