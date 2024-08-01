#include <iostream>
using namespace std;

class Node{
    public:
    
    int data;
    Node* prev;
    Node* next;

    //default constructor
    Node(){
        this->next = NULL;
        this->prev = NULL;
    }
    //parameterized constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }

};

void printLL(Node*head)
{
    //if linked list is empty
    if(head == NULL)
    {
        cout << "Linked list is empty" << endl;
        return;
    }

    //else
    Node* temp = head;
    while(temp->next != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << temp->data << endl;
}

int lengthLL(Node* head)
{
    int length = 0;
    if(head == NULL)
    {
        return length;
    }

    Node* temp = head;
    while(temp != NULL)
    {
        length++;
        temp = temp->next;
    }
    return length;
}

void insertAtHead(Node* &head, Node* &tail, int data)
{
    //create a node
    Node* newnode = new Node(data);

    //check whether linked list is empty or not
    if(head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }

    //if not empty
    //no change in tail then
    newnode->next = head;
    head->prev = newnode;
    head = newnode;
}

void insertAtTail(Node* &head, Node* &tail, int data)
{
    //create a node
    Node* newnode = new Node(data);

    //check if linked list is empty
    if(head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }

    //if not empty
    newnode->prev = tail;
    tail->next = newnode;
    tail = newnode;
}

void insertAtPosition(Node* head, Node* tail, int data, int position)
{
    if(position < 1 || position > lengthLL(head)+1)
    {
        cout << "Please enter suitable position" << endl;
        return;
    }
    //if we have to insert at the first position
    if(position == 1)
    {
        insertAtHead(head, tail, data);
        return;
    }
    //if we have to insert after last node
    if(position == lengthLL(head)+1)
    {
        insertAtTail(head, tail, data);
        return;
    }
    //else

    //create a newnode
    Node* newnode = new Node(data);
    Node* temp = head;
    while(position != 1)
    {
        position--;
        temp = temp->next;
    }
    newnode->prev = temp->prev;
    newnode->next = temp;
    temp->prev->next = newnode;
    temp->prev = newnode;
}

void deleteAtHead(Node* &head, Node* &tail)
{
    //linked list is empty
    if(head == NULL)
    {
        cout << "Linked list is already empty" << endl;
        return;
    }
    //single element case
    Node* temp = head;
    if(head == tail)
    {
        delete temp;
        head = NULL;
        tail = NULL;
    }
    //else
    head = temp->next;
    temp->next = NULL;
    delete temp;
}

void deleteAtTail(Node* &head, Node* &tail)
{
    //linked list is empty
    if(head == NULL)
    {
        cout << "Linked list is already empty" << endl;
        return;
    }
    //single element case
    if(head == tail)
    {
        delete tail;
        head = NULL;
        tail = NULL;
    }
    //else
    Node *temp = tail->prev;
    temp->next->prev = NULL;
    temp->next = NULL;
    delete tail;
    tail = temp; 
}

void deleteAtPosition(Node* &head, Node* &tail, int position)
{
    //if the position is out of bounds
    if(position < 1 || position > lengthLL(head))
    {
        cout << "Enter a suitable position" << endl;
        return;
    }
    if(position == 1)
    {
        deleteAtHead(head, tail);
        return;
    }
    if(position == lengthLL(head))
    {
        deleteAtTail(head, tail);
        return;
    }
    //else 
    Node* temp = head;
    while(position != 1)
    {
        position--;
        temp = temp->next;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    //isolated the temp node
    temp->next = temp->prev = NULL;
    delete temp;
}

int main()
{
    Node* head = NULL; 
    Node* tail = NULL;
    
    //initially
    printLL(head);

    insertAtHead(head, tail, 10);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 50);
    insertAtTail(head, tail, 80);
    printLL(head);

    insertAtPosition(head, tail, 15, 2);
    insertAtPosition(head, tail, 478, 4);
    printLL(head);

    deleteAtPosition(head, tail, 3);
    printLL(head);
    return 0;
}