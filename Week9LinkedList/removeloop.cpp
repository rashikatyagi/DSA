/*This code can be more optimized and here it is not mandatory to use two functions*/

#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node()
        {
            this->next = NULL;
        }
        Node(int data)
        {
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

bool checkLoop(Node* head)
{
    if(head == NULL || head->next == NULL)
    {
        //list is empty or list have single element
        return false;
    }

    //creating the fast and slow pointers
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL)
    {
        fast = fast->next;
        if(fast != NULL)
        {
            fast = fast->next;    //fast has moved two steps now we can move slow
            slow = slow->next;
        }
        if(fast == slow)        
            return true;
    }
    
    return false;
}

void removeLoop(Node* &head)
{
    Node* fast = head;
    Node* slow = head;

    while(fast != NULL)
    {
        fast = fast->next;
        if(fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }

        if(fast == slow)
        {
            slow = head;
            break;
        }
    }

    while(slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    //till here we got the starting point of the loop
    Node* temp = fast;
    while(temp->next != fast)
    {
        temp = temp->next;
    }
    
    temp->next = NULL;   //removing the loop
}

int main()
{
    //creating the head
    Node* head = new Node;

    //creating the nodes
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30); 
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);
    Node* sixth = new Node(60);
    Node* seventh = new Node(70);
    Node* eighth = new Node(80); 
    Node* ninth = new Node(90);
    Node* tenth = new Node(100);
    
    //joining the linked list to form a loop
    head = first;
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eighth;
    eighth->next = ninth;
    ninth->next = tenth;
    //tenth->next = third;    //here the loop is created

    if(checkLoop(head) == true)
    {
        cout << "Loop was present" << endl;
        removeLoop(head);
        printLL(head);
    }
    else
    {
        cout << "Loop is not present" << endl;
        printLL(head);
    }
    return 0;
}