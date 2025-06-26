#include <iostream>
using namespace std;
#include<vector>
#include <climits>
class node{
    public:
    int data;
    node*left;
    node*right;
    node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};

node* insertinBST(node*root,int d){
    if(root==NULL){
        root=new node(d);
        return root;
    }
    if(d<root->data){
        root->left=insertinBST(root->left,d);
    }
    else{
        root->right=insertinBST(root->right,d);
    }   
    return root;
}

void createBST(node*&root){
    int n;
    cin>>n;
    while(n!=-1){
        root=insertinBST(root,n);
        cin>>n;
    }
}

void inorder(node* root,vector<int>&v){
    if(root==NULL){
        return ;
    }
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}

node*BALANCE(int s,int e,vector <int>v){

    if(s>e){
        return NULL;
    }
    int mid=(s+e)/2;
    node*temp=new node(v[mid]);
    temp->left=BALANCE(s,mid-1,v);
    temp->right=BALANCE(mid+1,e,v);
    return temp;
}

node*balanceBST(node*root){
    vector<int>ans;
    inorder(root,ans);
    int s=0;
    int e=ans.size()-1;
    return BALANCE(s,e,ans);
}

int main(){
    node*root=NULL;
    createBST(root);
}