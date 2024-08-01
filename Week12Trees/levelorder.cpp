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

void LevelOrder(Node* &root){
    // this is done using the queue datastructure

    //base case
    if(root == NULL) return;
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        cout << temp->data << " ";
        if(temp->left != NULL) q.push(temp->left);
        if(temp->right != NULL) q.push(temp->right);
    }
    cout << endl;
}

void LevelWiseOrderTraversal(Node* &root){
    //base case
    if(root == NULL) return;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout << endl;
            if(!q.empty()) q.push(NULL);
        }
        else{
            cout << temp->data << " ";
            if(temp->left != NULL) q.push(temp->left);
            if(temp->right != NULL) q.push(temp->right);
        }
    }
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
    LevelWiseOrderTraversal(root);
    return 0;
}