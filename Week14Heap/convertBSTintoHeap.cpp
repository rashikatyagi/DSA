// There is a given complete binary tree which is also a BST. Convert it to a max heap
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

void createPostorderMappingusingInorder(Node* &root, vector<int> &inorder, int &index){
    if(root == NULL) return;
    createPostorderMappingusingInorder(root->left, inorder, index);
    createPostorderMappingusingInorder(root->right, inorder, index);
    root->data = inorder[index++];
}

void createInorder(Node* root, vector<int> &inorder){
    if(root == NULL) return;
    createInorder(root->left, inorder);
    inorder.push_back(root->data);
    createInorder(root->right, inorder);
}

void createHeapFromBST(Node* root){
    vector<int> inorder;
    createInorder(root, inorder); 
    int index = 0;
    createPostorderMappingusingInorder(root, inorder, index);
}

int main()
{
    Node* root = NULL;
    cout << "BST :" << endl;
    createBST(root);
    LevelWiseOrderTraversal(root);
    cout << "Max heap from BST :" << endl;
    createHeapFromBST(root);
    LevelWiseOrderTraversal(root);
    return 0;
}