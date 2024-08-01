#include<iostream>
#include <vector>
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

void printLL(Node* head)
{
    if(head == NULL)
    {
        cout << "Linked List is empty" << endl;
        return;
    }
    Node* temp = head;
    while(temp->next != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << temp->data << endl;
}

int lengthLL(Node* head)
{
    if(head == NULL)
        return 0;
    else if(head->next == NULL)
        return 1;
    
    Node* temp = head;
    int length = 0;
    while(temp != NULL)
    {
        length++;
        temp = temp->next;
    }
    return length;
}

Node* reverseK_Group(Node* &head, int k)
{
    if(k < lengthLL(head))
    {
    //base cases
    if(head == NULL || head->next == NULL)
    {
        //single or no element case
        return head;
    }
    int ktemp = 1;
    Node* curr = head;
    Node* prev = NULL;
    Node* nextNode;
    while(ktemp <= k)
    {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
        ktemp++;
    }

    //Recursion
    Node* ans = NULL;
    if(curr != NULL)
        ans = reverseK_Group(curr, k);
    
    //joining the reversed linked lists
    head->next = ans;
    return prev;
    }
    return head;
}

int main()
{
    //creating the head
    Node* head = new Node;

    //creating the nodes
    Node* first = new Node(10);
    Node* second = new Node(20);
    // Node* third = new Node(30); 
    // Node* fourth = new Node(40);
    // Node* fifth = new Node(50);
    // Node* sixth = new Node(60);
    // Node* seventh = new Node(70);
    // Node* eighth = new Node(80); 
    // Node* ninth = new Node(90);
    // Node* tenth = new Node(100);
    
    //joining the linked list to form a loop
    head = first;
    first->next = second;
    // second->next = third;
    // third->next = fourth;
    // fourth->next = fifth;
    // fifth->next = sixth;
    // sixth->next = seventh;
    // seventh->next = eighth;
    // eighth->next = ninth;
    // ninth->next = tenth;

    cout << "Linked List before : " << endl;
    printLL(head);

    int k = 5;
    cout << "After reversal : " << endl;
    head = reverseK_Group(head, k);
    printLL(head);
    
    return 0;
}