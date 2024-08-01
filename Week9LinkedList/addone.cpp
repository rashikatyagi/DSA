#include<iostream>
#include <vector>
using namespace std;

class Node
{
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
    //if empty
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

void reverse(Node* &head)
{
    if(head == NULL || head->next == NULL)
    {
        //single or no element case
        return;
    }
    Node* curr = head;
    Node* prev = NULL;
    Node* temp = NULL;
    while(curr != NULL)
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    head = prev;
}

void addOne(Node* &head){
    if(head == NULL) return;
    reverse(head);
    Node* temp = head;
    int carry = 1;
    while(temp != NULL){
        int sum = temp->data + carry;
        temp->data = sum % 10;
        carry = sum / 10;
        if(temp->next == NULL && carry){
            Node* newnode = new Node(carry);
            temp->next = newnode;
            reverse(head);
            return;
        }
        temp = temp->next;
    }
    reverse(head);
}

// void addOne(Node* &head)
// {
//     // no element case
//     if (head == NULL)
//     {
//         return;
//     }

//     reverse(head);
//     Node* temp = head;
//     int carry = (temp->data + 1) / 10;
//     temp->data = (temp->data + 1) % 10;

//     while (carry != 0 && temp->next != NULL)
//     {
//         temp = temp->next;
//         temp->data += carry;
//         carry = temp->data / 10;
//         temp->data %= 10;
//     }

//     if (carry != 0)
//     {
//         Node* newnode = new Node(carry);
//         temp->next = newnode;
//     }

//     reverse(head);
// }


// void addOne(Node* &head)
// {
//     //no element case
//     if(head == NULL)
//     {
//         return;
//     }

//     reverse(head);
//     Node* temp = head;
//     int carry = (temp->data+1)/10;

//     if(carry == 0)
//     {
//         temp->data += 1;
//         reverse(head);
//         return;
//     }
//     else
//     {
//         while(carry != 0 && temp->next != NULL)
//         {
//             temp->data = (temp->data+1) % 10;
//             temp = temp->next;
//             temp->data += carry;
//             carry = temp->data / 10;
//         }
//         if(temp->next == NULL && carry != 0)
//         {
//             temp->data = temp->data % 10;
//             Node* newnode = new Node(carry);
//             temp->next = newnode;
//         }
//         reverse(head);
//     }
// }

int main()
{
    //creating the head
    Node* head = new Node;

    //creating the nodes
    Node* first = new Node(9);
    // Node* second = new Node(9);
    // Node* third = new Node(8); 
    // Node* fourth = new Node(40);
    // Node* fifth = new Node(50);
    // Node* sixth = new Node(60);
    // Node* seventh = new Node(70);
    // Node* eighth = new Node(80); 
    // Node* ninth = new Node(90);
    // Node* tenth = new Node(100);
    
    //joining the linked list to form a loop
    head = first;
    // first->next = second;
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

    addOne(head);
    cout << "Linked List after : " << endl;
    printLL(head);
    
    return 0;
}