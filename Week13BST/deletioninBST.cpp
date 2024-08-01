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

Node* maxValue(Node* root){
    if(root == NULL) return NULL;
    if(root->right == NULL) return root;
    Node* max_value = maxValue(root->right);
    return max_value;
}

Node* deleteNodeInBST(Node* root, int target){
    //base case
    if(root == NULL) return NULL;

    //search for the target element
    if(root->data == target){
        //deletion of node
        
        //CASE 1 LEAF NODE
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        } 
        //CASE 2 SINGLE NODE
        if(root->left == NULL){
            Node* rightSubtree = root->right;
            delete root;
            return rightSubtree;
        }
        if(root->right == NULL){
            Node* leftSubtree = root->left;
            delete root;
            return leftSubtree;
        }
        //CASE 3 BOTH SIDE NODES
        else{
            Node* max_node = maxValue(root->left);
            root->data = max_node->data;
            root->left = deleteNodeInBST(root->left, max_node->data);
            return root;
        }
    }
    else if(root->data < target){
        root->right = deleteNodeInBST(root->right , target);
    }
    else{
        root->left = deleteNodeInBST(root->left, target);
    }
    return root;
}

int main()
{
    Node* root = NULL;
    createBST(root);
    cout << "Before deletion :" << endl;
    LevelWiseOrderTraversal(root);
    int target;
    cout << "Enter which node you want to delete (-1 for termination) : ";
    cin >> target;
    while(target != -1){
        root = deleteNodeInBST(root, target);
        LevelWiseOrderTraversal(root);
        cout << "Enter which node you want to delete (-1 for termination) : ";
        cin >> target;
    }
    return 0;
}