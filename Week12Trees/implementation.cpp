#include<iostream>
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

void preorder(Node* &root){
    //base case
    if(root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* &root){
    //base case
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* &root){
    //base case
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

Node* createTree(){
    cout << "Enter the value of node : ";
    int value;
    cin >> value;

    //base case
    if(value == -1){
        return NULL;
    }

    //create a new node
    Node* newnode = new Node(value);

    //Left Subtree 
    cout << "Left of " << newnode->data << " :";
    newnode->left = createTree();
    //Right Subtree 
    cout << "Right of " << newnode->data << " :";
    newnode->right = createTree();

    return newnode; 
}

int main()
{
    Node* root = createTree();
    cout << root->data << endl;
    return 0;
}