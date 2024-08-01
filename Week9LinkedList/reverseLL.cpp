#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;

        //default constructor
        Node(){
            cout << "Default constructor called" << endl;
            this->next = NULL;
        }

        //parameterized constructor
        Node(int data){
            cout << "Parameterized constructor called" << endl;
            this->data = data;
            this->next = NULL;
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


void insertAtHead(Node* &head, int value)
{
    Node *newnode = new Node(value);
    //case when linked list is empty
    if(head == NULL)
    {
        head = newnode;
        return;
    }

    //if linked list is not empty
    newnode->next = head;
    head = newnode;
    return;
}

void reverseLL_iterative(Node* &head)
{
    //handling the empty linked list case
    if(head == NULL)
    {
        cout << "Linked List is empty" << endl;
        return;
    }
    //single element case
    if(head->next == NULL)
    {
        return;
    }
    //else
    Node *prev = NULL;
    Node* curr = head;
    while(curr != NULL)
    {
        Node* temp = curr->next;
        curr->next = prev;
        prev = curr; 
        curr = temp;
    }
    head = prev;
}

void reverseLL_recursive(Node* &head, Node* curr, Node* prev)
{
    //base case
    if(curr == NULL)
    {
        head = prev;
        return;
    }

    //processing part
    Node* temp = curr->next;
    curr->next = prev;

    //recursive part
    reverseLL_recursive(head, temp, curr);
}

int main()
{
    Node* head = NULL;
    insertAtHead(head, 40);
    insertAtHead(head, 10);
    insertAtHead(head, 20);
    insertAtHead(head, 30);
    insertAtHead(head, 50);
    cout << "Initial Linked list : ";
    printLL(head);

    // reverseLL_iterative(head);
    reverseLL_recursive(head, head, NULL);
    cout << "Linked list after reversing : ";
    printLL(head);
    return 0;
}