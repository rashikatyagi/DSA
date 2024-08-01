#include <iostream>
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
    //condition for empty linked list
    if(head == NULL)
    {
        cout << "Empty Linked List" << endl;
        return;
    }

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

void deleteAtHead(Node* &head, Node* &tail)
{
    if(head == NULL)
    {
        cout << "Cannot delete as the linkedlist is empty" << endl;
        return;
    }

    if(head == tail)
    {
        tail = NULL;
    }
    
    Node* temp = head;
    head = temp->next;
    
    //first node is seperated from the linked list
    temp->next = NULL;

    //this delete keyword is used to deallocate the memory
    delete temp;
}

void deleteAtTail(Node* &head, Node* &tail)
{
    if(head == NULL)
    {
        cout << "Cannot delete as the linked list is empty" << endl;
        return;
    }

    Node* prev = head;
    while(prev->next->next != NULL)
    {
        prev = prev->next;
    }
    //now prev is on second last node

    prev->next = NULL;
    delete tail;
    tail = prev;
}

void deleteAtPosition(Node* &head, Node* &tail, int position)
{
    if(position < 1 || position > lengthLL(head))
    {
        cout << "Enter a valid position" << endl;
        return;
    }

    //case when head and tail lies on the same node i.e the single node condition
    //this case will be considered when we are considering the tail in every step
    if(head == tail)
    {
        Node* temp = head;
        delete temp;
        //linked list is empty now
        head = NULL;
        tail = NULL;
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

    //else part
    Node* prev = NULL;
    Node* curr = head;
    while(position != 1)
    {
        position--;
        prev = curr;
        curr = curr->next;
    }
    prev->next = curr->next;
    
    //now this curr node is out of the linked list
    curr->next = NULL;
    delete curr;
}

int main()
{
    Node* first = new Node(10);
    // Node* second = new Node(20);
    // Node* third = new Node(30); 
    // Node* fourth = new Node(40);
    // Node* fifth = new Node(50);
    //here only the nodes are created at different memory locations

    // first->next = second;
    // second->next = third;
    // third->next = fourth;
    // fourth->next = fifth;
    //now all nodes are connected and linked list is created

    Node* head = first;
    Node* tail = first;
    //head pointer points to the first node

    //printing the above made linkedlist
    printLL(head);

    //deleting the first node
    // deleteAtHead(head, tail);
    // printLL(head);

    // //deleting the last node
    // deleteAtTail(head, tail);
    // printLL(head);

    //deleting the second node
    deleteAtPosition(head, tail, 1);
    printLL(head);

    // deleteAtPosition(head, tail, 2);
    // printLL(head);

    // deleteAtPosition(head, tail, 1);
    // printLL(head);
    return 0;
}