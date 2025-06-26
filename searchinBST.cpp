#include <iostream>
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

node* insert(node*root,int x){
    if(root==NULL){
        root=new node(x);
        return root;
    }
    if(x>root->data){
        root->right=insert(root->right,x);
    }
    else{
        root->left=insert(root->left,x);
    }
    return root;

}
void createBST(node* &root){
    int x;
    cin>>x;
    while(x!=-1){
        root=insert(root,x);
        cin>>x;
    }
}
void inorder(node*root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
bool searchinBST(node*root,int d){
    node*temp=root;
    while(temp!=NULL){
        if(temp->data==d){
        return true;
        }
        if(d>temp->data){
            temp=temp->right;
        }
        else{
            temp=temp->left;
        }
    }
    return false;
}
int main(){
    node* root=NULL;
    createBST(root);
    inorder(root);
    cout<<endl;
    bool ans=searchinBST(root,7);
    cout<<ans;
}