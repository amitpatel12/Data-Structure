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

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* curr = q.front();
        q.pop();
        cout<<curr->data<<" ";
        if(curr->left){
            q.push(curr->left);
        }
        if(curr -> right){
            q.push(curr->right);
        }
    }
}

void levelOrderTraversalLine(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* curr = q.front();
        q.pop();
        if(curr == NULL){
            cout<<endl;
            if(q.size()>1){
                q.push(NULL);
            }
        }
        else{
            cout<<curr->data<<" ";
            if(curr->left){
                q.push(curr->left);
            }
            if(curr-> right){
                q.push(curr->right);
            }
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

    cout<<"----------------------------Level Order Traversal-----------------------------"<<endl;
    levelOrderTraversal(root);
    cout<<endl;
    cout<<"------------Level Order Traversal each level into different Line--------------"<<endl;
    levelOrderTraversalLine(root);
    return 0;
}