#include<iostream>
#include<queue>
#include<vector>
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

void LeftView(Node* root, int level, vector<int>&leftView){
    //base case
    if(root == NULL) return;
    if(leftView.size() == level){
        leftView.push_back(root->data);
    }
    LeftView(root->left, level + 1, leftView);
    LeftView(root->right, level + 1, leftView);
}
void RightView(Node* root, int level, vector<int>&rightView){
    //base case
    if(root == NULL) return;
    if(rightView.size() == level){
        rightView.push_back(root->data);
    }
    LeftView(root->right, level + 1, rightView);
    LeftView(root->left, level + 1, rightView);
}

int main()
{
    Node* root = createTree();
    LevelWiseOrderTraversal(root);
    vector<int> leftView;
    LeftView(root, 0, leftView);
    cout << "Left view : ";
    for(int i = 0 ; i < leftView.size() ; i++){
        cout << leftView[i] << " ";
    }
    cout << endl;
    vector<int> rightView;
    cout << "Right view : ";
    RightView(root, 0, rightView);
    for(int i = 0 ; i < rightView.size() ; i++){
        cout << rightView[i] << " ";
    }
    cout << endl;
    return 0;
}