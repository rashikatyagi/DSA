#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    
    Node(){
        this->left = NULL;
        this->right = NULL;
    }
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertIntoBST(Node* root, int data){
    if(root == NULL){
        root = new Node(data);
        return root;
    }
    //if elements already present in the BST
    if(data < root->data){
        root->left = insertIntoBST(root->left, data);
    }
    else{
        root->right = insertIntoBST(root->right, data);
    }
    return root;
}

void createBST(Node* &root){
    int value;
    cout << "Enter data : ";
    cin >> value;
    while(value != -1){
        root = insertIntoBST(root, value);
        cout << "Enter data : ";
        cin >> value;
    }
}

void LevelWiseOrderTraversal(Node* root){
    queue<Node* > q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp == NULL){
            cout << endl;
            if(!q.empty()) q.push(NULL);  //level completed
        }
        else{
            cout << temp->data << " ";
            if(temp->left != NULL) q.push(temp->left);
            if(temp->right != NULL) q.push(temp->right);
        }
    }
}

void convertBSTintoDoublyLinkedListLCR(Node* root, Node* &head){
    if(root == NULL) return;

    // RCL
    convertBSTintoDoublyLinkedListLCR(root->left, head);

    root->left = head;
    if(head) head->right = root;
    head = root;

    convertBSTintoDoublyLinkedListLCR(root->right, head);
}

void convertBSTintoDoublyLinkedListRCL(Node* root, Node* &head){
    if(root == NULL) return;

    // RCL
    convertBSTintoDoublyLinkedListRCL(root->right, head);

    root->right = head;
    if(head) head->left = root;
    head = root;

    convertBSTintoDoublyLinkedListRCL(root->left, head);
}

void printLinkedList(Node* head){
    Node* temp = head;
    while(temp){
        cout << temp->data << " -> ";
        temp = temp->right;
    }
}

void reversePrintLinkedList(Node* head){
    Node* temp = head;
    while(temp){
        cout << temp->data << " -> ";
        temp = temp->left;
    }
}


int main()
{
    Node* root = NULL;
    createBST(root);
    cout << "BST :-" << endl;
    LevelWiseOrderTraversal(root);

    Node* head = NULL;
    // convertBSTintoDoublyLinkedListRCL(root, head);
    convertBSTintoDoublyLinkedListLCR(root, head);
    cout << "Doubly Linked List formed : ";
    // printLinkedList(head);
    reversePrintLinkedList(head);
    return 0;
}