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
    cin>>x;
    if(x==-1){
        return NULL;
    }
    node* root=new node(x);
    root->left=buildtree();
    root->right=buildtree();
    return root;
}
void preorder(node*root){
    if(root==NULL){
        return;
    }
    cout<<root->data;
    preorder(root->left);
    preorder(root->right);
}
int height(node*root){
    if(root==NULL){
        return 0;
    }
    int leftHeight=height(root->left);
    int rightHeight=height(root->right);
    int ans=max(leftHeight,rightHeight)+1;
    return ans;

}


int main(){
    node*root=buildtree();

}