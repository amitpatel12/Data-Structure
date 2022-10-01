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

//using recursion
void preorderrecursive(Node *root){
    if(root == NULL)
        return;
    cout<<root->data<<" ";
    preorderrecursive(root->left);
    preorderrecursive(root->right);
}
//using single stack
void preorder(Node* root){
    stack<Node*>s;
    s.push(root);

    while(!s.empty()){
        Node* curr = s.top();
        s.pop();
        cout<<curr->data<<" ";
        if(curr->right != NULL){
            s.push(curr->right);
        }
        if(curr->left!= NULL){
            s.push(curr->left);
        }

    }
}

//using two stack
void preorderTraversal(Node *root){
    stack<Node*> s1;
    stack<Node*> s2;
    s1.push(root);

    while(!s1.empty() || !s2.empty()){
        while(!s1.empty()){
            Node* curr = s1.top();
            s1.pop();
            s2.push(curr);
    }
    Node *curr = s2.top();
    s2.pop();
    cout<<curr->data<<" ";
    if(curr->left){
        s1.push(curr->left);
    }
    if(curr-> right){
        s1.push(curr->right);
    }

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
    preorder(root);
    cout<<endl;
    cout<<"--------------using Recursion----------------"<<endl;
    preorderrecursive(root);
    cout<<endl;
    cout<<"--------------using two stack----------------"<<endl;
    preorderTraversal(root);

    return 0;
}