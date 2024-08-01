#include<iostream>
#include<queue>
#include<vector>
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

void TopView(Node* root){
    map<int, int> temp;
    queue< pair<Node*, int> > q;
    q.push(make_pair(root, 0));
    while(!q.empty()){
        //extracting the node and horizontal distance
        Node* node = q.front().first;
        int hd = q.front().second;

        q.pop();
        //check whether there is a mapping for hd already or not
        if(temp.find(hd) == temp.end())  //mapping not found
        {
            temp[hd] = node->data;
        }
        //push the left and right node along with there assumptional levels
        if(node->left != NULL) q.push(make_pair(node->left, hd - 1));
        if(node->right != NULL) q.push(make_pair(node->right, hd + 1));
    }

    for(auto i : temp){
        cout << i.second << " ";
    }
    cout << endl;
}

void BottomView(Node* root){
    map<int, int> temp;
    queue< pair<Node*, int> > q;
    q.push(make_pair(root, 0));
    while(!q.empty()){
        //extracting the node and horizontal distance
        Node* node = q.front().first;
        int hd = q.front().second;

        q.pop();
        //check whether there is a mapping for hd already or not
        
        //ONLY THE CONDITION IS REMOVED
        temp[hd] = node->data;
        
        //push the left and right node along with there assumptional levels
        if(node->left != NULL) q.push(make_pair(node->left, hd - 1));
        if(node->right != NULL) q.push(make_pair(node->right, hd + 1));
    }

    for(auto i : temp){
        cout << i.second << " ";
    }
    cout << endl;
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
    cout << "Top view : ";
    TopView(root);
    cout << "Bottom view : " ;
    BottomView(root);
    return 0;
}