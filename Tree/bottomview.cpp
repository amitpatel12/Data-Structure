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

vector<int> bottomView(Node *root)
    {
        //Your code here
        map<int,int> mp;
        int line = 0; //(number line (-n,+n))
        // solve(root,mp,line);
        vector<int> ans;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            pair<Node*, int> temp = q.front();
            q.pop();
            Node* curr = temp.first;
            int line = temp.second;
           
            mp[line] = curr -> data;
            
            if(curr -> left){
                q.push({curr -> left,line - 1});
            }
            if(curr -> right){
                q.push({curr -> right,line + 1});
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

    vector<int> ans = bottomView(root);
    

    cout<<"--------------------------------bottom View of Tree--------------------------------"<<endl;

    for(auto x : ans){
        cout<<x<<" ";
    }

    
    return 0;
}