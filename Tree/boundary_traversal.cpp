#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        this->data = val;
        left = NULL;
        right = NULL;
    }
};

void lefttraverse(Node* root,vector<int>&ans){
    if(root == NULL || (root->left == NULL && root->right == NULL)){
        return;
    }
    ans.push_back(root->data);
    if(root->left){
        lefttraverse(root->left,ans);
    }
    else{
        lefttraverse(root->right,ans);
    }
}

void leaftraverse(Node* root,vector<int>&ans){
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        ans.push_back(root->data);
    }
    
    leaftraverse(root->left,ans);
    leaftraverse(root->right,ans);
    
}

void righttraverse(Node* root,vector<int>&ans){
    if(root == NULL || (root->left == NULL && root->right == NULL)){
        return;
    }
    ans.push_back(root->data);
    if(root->right){
        righttraverse(root->right,ans);
    }
    else{
        righttraverse(root->left,ans);
    }
}

int main(){
 Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = NULL;

    vector<int> ans;
    ans.push_back(root->data);
    //left traverse the tree
    lefttraverse(root->left, ans);

    // leaf traverse the tree
    leaftraverse(root->left, ans);
    leaftraverse(root->right, ans);

    //right traverse the tree
    righttraverse(root->right, ans);

    cout<<"--------------------------------Boundary Traversal--------------------------------"<<endl;

    for(auto x : ans){
        cout<<x<<" ";
    }

    
    return 0;
}