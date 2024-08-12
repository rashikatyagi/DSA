#include<iostream>
#include <queue>
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

pair<int, bool> checkIfCompleteBinaryTreeIsHeap(Node* root){
    // base case - 1 null nodes
    if(root == NULL){
        return make_pair(INT_MIN, true);
    } 
    // base case - 2 leaf nodes
    if(root->left == NULL && root->right == NULL){
        return make_pair(root->data, true);
    }
    auto left = checkIfCompleteBinaryTreeIsHeap(root->left);
    auto right = checkIfCompleteBinaryTreeIsHeap(root->right);

    if(root->data > left.first && root->data > right.first && left.second && right.second)
    {
        return make_pair(root->data, true);
    }
    else{
        return make_pair(max(left.first, right.first), false);
    }
}

int main()
{
    Node* root = createTree();
    auto it = checkIfCompleteBinaryTreeIsHeap(root);
    cout << it.second << endl;
    return 0;
}