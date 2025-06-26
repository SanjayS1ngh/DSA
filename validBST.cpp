#include <iostream>
using namespace std;
#include<climits>
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

bool isbinary(node*root,int max,int min){
    if (root==NULL){
        return true;
    }
    if(root->data>min && root->data<max){
        bool left=isbinary(root->left,root->data,min);
        bool right=isbinary(root->right,max,root->data);
        return left && right;
    }
    else{
        return false;
    }



}
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
    // bool ans=searchinBST(root,7);
    // cout<<ans;
    int min=INT_MIN;
    int max=INT_MAX;
    bool anss=isbinary(root,max,min);
    cout<<anss;
}