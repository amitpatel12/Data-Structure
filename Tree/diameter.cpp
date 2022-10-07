#include<iostream>
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


int findDiameter(Node* root, int &diameter){
    if(root == NULL){
        return 0;
    }
    int left = findDiameter(root->left,diameter);
    int right = findDiameter(root->right,diameter);

    diameter = max(diameter,left + right +1);
    return max(left,right)+1;
}


int main(){
 Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = NULL;

    cout<<"----------------------------Diameter of the Tree-----------------------------"<<endl;
    int diameter = 0;
    findDiameter(root,diameter);
    cout<<diameter<<endl;
    
    return 0;
}