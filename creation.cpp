#include<iostream>
using namespace std;
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
void inorder(node*root){
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
            pre->right=curr;
            curr=curr->left;
        }
        else{
            pre->right=NULL;
            cout<<curr->data<<" ";
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
node* insertinBST(node* root,int d){
    if(root==NULL){
        root=new node(d);
        return root;
    }
    if(d>root->data){
        root->right=insertinBST(root->right,d);
    }
    else{
        root->left=insertinBST(root->left,d);
    }
    return root;
}

void takeinput(node*& root){
    int x;
    cin>>x;
    while(x!=-1){
        root=insertinBST(root,x);
        cin>>x;
    }
}
int main(){
    node* root=NULL;
    cout<<"enter no you want to insert in BST";
    takeinput(root);
    inorder(root);
    cout<<endl;
    preorder(root);
}