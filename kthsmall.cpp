#include <iostream>
using namespace std;
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
int ksmall(node*root,int &i,int k){
    if(root==NULL){
        return -1;
    }
    int left=ksmall(root->left,i,k);
    if(left!=-1){
        return left;
    }
    i++;
    if(i==k){
        return root->data;
    }
    return ksmall(root->right,i,k);
    
}
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

void inorder(node* root){
    if(root==NULL){
        return ;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
node* findmin(node*root){
    node*temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}

node*deletion(node*root,int val){
    if(root==NULL){
        return root;
    }
    if(root->data<val){
        root->right=deletion(root->right,val);
        return root;
    }
    if(root->data>val){
        root->left=deletion(root->left,val);
        return root;
    }
    if(root->data==val){

        //no child
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        if(root->left!=NULL&&root->right==NULL){
            node*temp;
            temp=root->left;
            delete root;
            return temp;    
        }
        if(root->right!=NULL&&root->left==NULL){
            node*temp;
            temp=root->right;
            delete root;
            return temp; 
        }
        if(root->left!=NULL && root->right!=NULL){
            int min=findmin(root->right)->data;
            root->data=min;
            root->right=deletion(root->right,min);
            return root;

        }
    }
}

int main(){
    node* root=NULL;
    cout<<"enter no you want to insert in BST"<<endl;
    createBST(root);
    inorder(root);
    cout<<endl;
    root=deletion(root,4);
    cout<<endl;
    inorder(root);
    int i=0;
    int ans=ksmall(root,i,4);
    cout<<endl<<ans;
}