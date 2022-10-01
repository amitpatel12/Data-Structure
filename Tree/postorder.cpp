#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }

};

void postrecursive(Node* root){
    if(root == NULL)
        return;
    postrecursive(root->left);
    postrecursive(root->right);
    cout << root->data << " ";
}

void postorder(Node* root){
    stack<Node*>s1,s2;
    s1.push(root);
    while(!s1.empty()){
        Node* curr = s1.top();
        s1.pop();
        s2.push(curr);
        if(curr->left)
            s1.push(curr->left);
        if(curr->right) 
            s1.push(curr->right);
    }

    while(!s2.empty()){
        Node* curr = s2.top();
        s2.pop();
        cout << curr->data << " ";
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

    cout<<"--------------using single stack----------------"<<endl;
    postorder(root);
    cout<<endl;
    cout<<"--------------using Recursion----------------"<<endl;
    postrecursive(root);
    cout<<endl;
    // cout<<"--------------using two stack----------------"<<endl;
    // preorderTraversal(root);

    return 0;
}