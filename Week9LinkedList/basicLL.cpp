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


//printing linked list
void printLL(Node* head)
{
    Node* temp = head;
    while(temp->next != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << temp->data;
    cout << endl;
}

//printing length of linkedlist
int lengthLL(Node* head)
{
    Node* temp = head;
    int length = 0;

    while(temp != NULL)
    {
        length++;
        temp = temp->next;
    }

    return length;
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

void insertAtTail(Node* &head, int value)
{
    Node* newnode = new Node(value);
    //if LL is empty
    if(head == NULL)
    {
        head = newnode;
        return;
    }
    //else
    Node* temp = head;

    //iterate till we get the last node
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
}

void insertAtPosition(Node* &head, int value, int position)
{
    //if there is an invalid position entered
    if(position < 1)
    {
        cout << "Please enter a valid position" << endl;
        return;
    }

    //if the position entered is more than the length of the linked list
    int length = lengthLL(head);
    if(position > length+1)
    {
        cout << "Position cannot be more than the length of linked list" << endl;
        return;
    }
    Node *newnode = new Node(value);

    //if we have to insert at the first position
    if(position == 1)
    {
        insertAtHead(head, value);
        return;
    }
    
    //if position is last position
    if(position == length+1)       //*****ERROR CHANCES*****
    {
        insertAtTail(head, value);
        return;
    }
    // //if LL is empty
    // if(head == NULL)
    // {
    //     if(position != 1)
    //     {
    //         cout << "Linked List is empty" << endl;
    //         return;
    //     }
    //     else
    //     {
    //         head = newnode;
    //         return;
    //     }
    // }
    //else
    int pos = 1;
    Node* temp = head;
    while(pos != position - 1)
    {
        temp = temp->next;
        pos++;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

int main()
{
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30); 
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);
    //here only the nodes are created at different memory locations

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    //now all nodes are connected and linked list is created

    Node* head = first;
    //head pointer points to the first node

    //printing the above made linkedlist
    printLL(head);

    //printing length of the linked list
    cout << "Length of linked list : " << lengthLL(head) << endl;

    //inserting data at the beginning of linked list
    insertAtHead(head, 25);
    printLL(head);

    insertAtHead(head, 4);
    printLL(head);

    //inserting data at the end of the linkedlist
    insertAtTail(head, 65);
    printLL(head);

    insertAtTail(head, 78);
    printLL(head);

    //inserting data at a particular position
    insertAtPosition(head, 45, 3);
    printLL(head);
    return 0;
}