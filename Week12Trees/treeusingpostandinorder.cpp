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

Node* createTreeUsingPostorderInorder(int* postorder, int &postIndex, int* inorder, int start, int end, int size, map<int, int> &mp){
    //base case
    if(postIndex < 0 || start > end) return NULL;

    //get the element
    int element = postorder[postIndex--];

    //make a root of the element
    Node* root = new Node(element);

    //get position of element in the inorder
    int position = mp[element];

    //make the left and right subtrees
    root->right = createTreeUsingPostorderInorder(postorder, postIndex, inorder, position + 1, end, size, mp);
    root->left = createTreeUsingPostorderInorder(postorder, postIndex, inorder, start, position - 1, size, mp);
    return root;
}

int main()
{
    int inorder[] = {8, 14, 6, 2, 10, 4};
    int postorder[] = {8, 6, 14, 4, 10, 2};
    int size = 6;
    int postIndex = size - 1;
    int startInorder = 0;
    int endInorder = size - 1;

    map<int, int> mp;
    for(int i = 0 ; i < size ; i++){
        mp[inorder[i]] = i;
    }

    Node* root = createTreeUsingPostorderInorder(postorder, postIndex, inorder, startInorder, endInorder, size, mp);
    LevelWiseOrderTraversal(root);
    return 0;
}