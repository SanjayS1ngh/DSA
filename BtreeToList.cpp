#include<iostream>
#include<vector>
using namespace std;
class node{
    public:
    int data;
    node*left;
    node*right;
    node(int x){
        data=x;
        left=NULL;
        right=NULL;
    }
};

node*buildtree(){
    
    int x;
    cout<<"enter node: ";
    cin>>x;
    if(x==-1){
        return NULL;
    }
    node*newnode=new node(x);
    newnode->left=buildtree();
    newnode->right=buildtree();
}
void preorder(node*root,vector<int>&v){
    if(root==NULL){
        return;
    }
    v.push_back(root->data);
    preorder(root->left,v);
    preorder(root->right,v);
}
void BtreeToList(node*&root){
    vector<int>v;
    preorder(root,v);
    int n=v.size();
    node*newnode=new node(v[0]);
    node*curr=newnode;
    for(int i=1;i<n;i++){
        node*temp=new node(v[i]);
        curr->left=NULL;
        curr->right=temp;
        curr=temp;
    }
    curr->left=NULL;
    curr->right=NULL;

}
int main(){
    node*root=buildtree();
    

}