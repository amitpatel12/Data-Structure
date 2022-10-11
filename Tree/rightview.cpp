#include<iostream>
#include<vector>
#include<map>
#include<queue>
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

vector<int> rightView(Node *root)
{
   // Your code here
   vector<int> ans;
   if(root == NULL)
    return ans;
    
    map<int,int> mp;
    queue<pair<Node*,int>>q;
    q.push({root,0});
    
    while(!q.empty()){
        pair<Node*,int> temp = q.front();
        q.pop();
        Node* curr = temp.first;
        int lvl = temp.second;
        
        // upadate until last
        mp[lvl] = curr -> data;
        
        
        if(curr -> left){
            q.push({curr -> left,lvl +1});
        }
        if(curr -> right){
            q.push({curr -> right,lvl +1});
        }
    }
    
    for(auto x : mp){
        ans.push_back(x.second);
    }
    return ans;
  
}

int main(){
 Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = NULL;

    vector<int> ans = rightView(root);
    

    cout<<"--------------------------------Right View of Tree--------------------------------"<<endl;

    for(auto x : ans){
        cout<<x<<" ";
    }

    
    return 0;
}