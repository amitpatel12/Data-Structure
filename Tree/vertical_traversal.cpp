#include<iostream>
#include<vector>
#include<queue>
#include<map>
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


vector<int> verticalOrder(Node *root)
    {
        //Your code here
        map<int,map<int,vector<int>>> mp;
        queue<pair<Node*,pair<int,int>>> q;
        vector<int> ans;
        if(root == NULL)
            return ans;
        q.push({root,{0,0}});
        
        while(!q.empty()){
           pair<Node*,pair<int,int>> temp = q.front();
            q.pop();
            Node* curr = temp.first;
            int lvl = temp.second.first;
            int hd = temp.second.second; // Horizontal distance
            mp[hd][lvl].push_back(curr -> data);
            
            if(curr -> left){
                q.push({curr ->left,{lvl+1,hd-1}});
            }
            if(curr -> right){
                q.push({curr ->right,{lvl+1,hd+1}});
            }
            
        }
        
        for(auto x : mp){
            for(auto y : x.second){
                for(auto i : y.second){
                    ans.push_back(i);
                }
            }
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

    vector<int> ans = verticalOrder(root);
    

    cout<<"--------------------------------Boundary Traversal--------------------------------"<<endl;

    for(auto x : ans){
        cout<<x<<" ";
    }

    //ans = 4 2 1 5 6 3  

    
    return 0;
}