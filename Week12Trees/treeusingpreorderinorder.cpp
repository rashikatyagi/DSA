#include<iostream>
#include<queue>
#include<map>
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

int positionInInorder(int* inorder, int element, int size){
    for(int i = 0 ; i < size ; i++){
        if(inorder[i] == element) return i;
    }
    return -1;
}

Node* CreateUsingPreorderInorder(int* preorder, int &preIndex, int* inorder, int start, int end, int size, map<int, int> &mp){
    //base condition
    if(preIndex >= size || start > end) return NULL;
    int element = preorder[preIndex++];

    //create the root node
    Node* root = new Node(element);

    // get the position of root element in the inorder array to get the left and right subtree
    //int position = positionInInorder(inorder, element, size);

    //using map
    int position = mp[element];

    // make the left and right subtree
    root->left = CreateUsingPreorderInorder(preorder, preIndex, inorder, start, position - 1, size, mp);
    root->right = CreateUsingPreorderInorder(preorder, preIndex, inorder, position + 1, end, size, mp);
    return root;
}

int main()
{
    int inorder[] = {10, 8, 6, 2, 4, 12};
    int preorder[] = {2, 8, 10, 6, 4, 12};
    int size = 6;
    int preIndex = 0;
    int startInorder = 0;
    int endInorder = 5;

    //create a mapping between index and elements of inorder array
    map<int, int> mp;
    for(int i = 0 ; i < size ; i++){
        mp[inorder[i]] = i;
    }

    Node* root = CreateUsingPreorderInorder(preorder, preIndex, inorder, startInorder, endInorder, size, mp);
    LevelWiseOrderTraversal(root);
    return 0;
}