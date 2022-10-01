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

int level = 0;
vector<vector<int>> ans;

//DFS approach
void reverseLevelOrderTraversal(Node * root,int level){
    if(root == NULL){
        return;
    }
      if(level >= ans.size()){
        ans.push_back({});
    }
    ans[level].push_back(root->data);
    
    reverseLevelOrderTraversal(root->left,level+1);
    reverseLevelOrderTraversal(root->right,level+1);
  
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
    reverseLevelOrderTraversal(root,level);
    reverse(ans.begin(),ans.end());
    for(int i = 0; i<ans.size(); i++) {
        for(int j = 0; j<ans[i].size(); j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    
    return 0;
}