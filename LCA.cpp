#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node*left;
    node*right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

node* insert(node*root,int x){
    if(root==NULL){
        root=new node(x);
        return root;
    }    
    if(root->data>x){
        root->left=insert(root->left,x);
    }
    else{
        root->right=insert(root->right,x);
    }
    return root;
}

void CreateBST(node* &root){
    int x;
    cin>>x;
    while(x!=-1){
        root=insert(root,x);
        cin>>x;
    }
}
node* LCA(node*root,int a ,int b){
    if(root==NULL){
        return NULL;
    }
    if(a>root->data && b>root->data){
        return LCA(root->right,a,b);
    }
    else if(a<root->data &&b<root->data){
        return LCA(root->left,a,b);
    }
    else if((a<root->data && b>root->data)||(a>root->data && b<root->data)){
        return root;
    }
    return root;
}
void inorder(node*root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    node*root=NULL;
    CreateBST(root);
    inorder(root);
    node*ans=LCA(root,60,70);
    cout<<endl<<ans->data;

}