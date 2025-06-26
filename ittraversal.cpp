#include<iostream>
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
void inorder(node*root){
    node*curr=root;
    while(curr){
        if(curr->left==NULL){
        cout<<curr->data;
        curr=curr->right;
    }
    else{
        node*pre=curr->left;
        while(pre->right&&pre->right!=curr){
            pre=pre->right;
        }
        if(pre->right==NULL){
            pre->right=curr;
            curr=curr->left;
        }
        else{
            pre->right=NULL;
            cout<<curr->data;
            curr=curr->right;
        }
    }    
    }
}
void preorder(node*root){
    node*curr=root;
    while(curr){
        if(curr->left==NULL){
        cout<<curr->data<<" ";
        curr=curr->right;
    }
    else{
        node*pre=curr->left;
        while(pre->right&&pre->right!=curr){
            pre=pre->right;
        }
        if(pre->right==NULL){
            cout<<curr->data<<" ";
            pre->right=curr;
            curr=curr->left;
        }
        else{
            pre->right=NULL;
            curr=curr->right;
        }
    }    
    }
}
int main(){
    node*root=buildtree();
    inorder(root);
    cout<<endl;
    preorder(root);
}