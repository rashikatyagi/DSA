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

bool searchInBST(Node* root, int target){
    if(root == NULL) return false;
    if(root->data == target) return true;
    bool ans1, ans2;
    if(root->data < target) ans1 = searchInBST(root->right, target);
    else ans2 = searchInBST(root->left, target);
    return ans1 || ans2;
}

int main()
{
    Node* root = NULL;
    createBST(root);
    int target;
    bool present = searchInBST(root, target);
    if(present == 1) cout << "Element is present" << endl;
    else cout << "Element is not present" << endl;
    return 0;
}