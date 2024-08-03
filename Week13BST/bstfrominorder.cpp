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

Node* InorderFromBST(int* inorder, int start, int end){
    //base case
    if(start > end) return NULL;
    
    //as we have to create a balanced BST, we will chose the middle element as root
    int mid = start + (end - start) / 2;
    int element = inorder[mid];

    //create the root node
    Node* root = new Node(element);

    //create the left and right subtree using recursion
    root->left = InorderFromBST(inorder, start, mid - 1);
    root->right = InorderFromBST(inorder, mid + 1, end);

    return root;
}

int main()
{
    int inorder[] = {10, 20, 30, 40, 50, 60, 70};
    int size = 7;
    Node* root = InorderFromBST(inorder, 0, size - 1);
    LevelWiseOrderTraversal(root);
    return 0;
}