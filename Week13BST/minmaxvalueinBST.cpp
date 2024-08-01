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

int minValue(Node* root){
    if(root == NULL){
        cout << "No element present" << endl;
        return -1;
    }
    if(root->left == NULL) return root->data;
    int ans = minValue(root->left);
    return ans;
}

int maxValue(Node* root){
    if(root == NULL){
        cout << "No element present" << endl;
        return -1;
    }
    if(root->right == NULL) return root->data;
    int ans = maxValue(root->right);
    return ans;
}

int main()
{
    Node* root = NULL;
    createBST(root);
    LevelWiseOrderTraversal(root);
    int max_value = maxValue(root);
    int min_value = minValue(root);
    cout << "Maximum is : " << max_value << endl;
    cout << "Minimum is : " << min_value << endl;
    return 0;
}