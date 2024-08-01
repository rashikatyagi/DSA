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

void printLeftPartA(Node* root){
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL) return;

    cout << root->data << " ";

    if(root->left != NULL) printLeftPartA(root->left);
    else printLeftPartA(root->right);
}

void printLeafPartB(Node* root){
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL){
        cout << root->data << " ";
        return;
    }
    printLeafPartB(root->left);
    printLeafPartB(root->right);
}

void printRightPartC(Node* root){
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL) return;
    if(root->right != NULL) printLeftPartA(root->right);
    else printLeftPartA(root->left);

    cout << root->data << " ";
}

void BoundaryTraversal(Node* root){
    cout << "Boundary Traversal : ";
    cout << root->data << " ";
    printLeftPartA(root->left);
    printLeafPartB(root->left);
    printLeafPartB(root->right);
    printRightPartC(root->right);
}

int main()
{
    Node* root = createTree();
    BoundaryTraversal(root);
    return 0;
}