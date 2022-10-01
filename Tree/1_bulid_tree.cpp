#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        this->data = d;
        this-> left = NULL;
        this->right = NULL;
    }
};

node* buildTree(node* root){
    cout<<"Enter the data "<<endl;
    int data;
    cin>>data;
    root = new node(data);
    if(data == -1){
        return NULL;
    }
    cout<<"enter left node data "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"enter right node data "<<data<<endl;
    root->right = buildTree(root->right);
    return root;
}

void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        node* curr = q.front();
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
void levelOrderTraversalLine(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* curr = q.front();
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

void preorderTraversal(node *root){
    stack<node*> s1;
    stack<node*> s2;
    s1.push(root);

    while(!s1.empty() || !s2.empty()){
        while(!s1.empty()){
            node* curr = s1.top();
            s1.pop();
            s2.push(curr);
    }
    node *curr = s2.top();
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

void inorderTraversal(node* root){
    stack<node*> s;
    node* curr = root;

    while(!s.empty() || curr != NULL){
        if(curr!= NULL){
            s.push(curr);
            curr = curr->left;
        }
        else{
            curr = s.top();
            s.pop();
            cout<<curr->data<<" ";
            curr = curr->right;
        }
    }
}
int main(){
    node* root = NULL;
    root = buildTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 

    //Level order Traversal
    cout<<"Level Order Traversal"<<endl;
    levelOrderTraversal(root);
    cout<<endl;
    levelOrderTraversalLine(root);
    cout<<"Preorder Traversal"<<endl;
    preorderTraversal(root);
    cout<<"Preorder Traversal"<<endl;
    inorderTraversal(root);
    cout<<endl;
    return 0;
}