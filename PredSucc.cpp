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

node* insertinBST(node* root,int d){
    if (root==NULL){
        root=new node(d);
        return root;
    }
    if(root->data>d){
        root->left=insertinBST(root->left,d);
    }
    if(root->data<d){
        root->right=insertinBST(root->right,d);
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

void CreateBST(node*&root){
    int n;
    cin>>n;
    while(n!=-1){
        root=insertinBST(root,n);
        cin>>n;
    }
}

pair<int ,int> PredSuc(node*root,int val){
    node*temp=root;
    int pre=-1;
    int suc=-1;
    while(temp!=NULL){
        if(temp->data==val){
            node*lefttt=temp->left;
            node*righttt=temp->right;
            while(lefttt!=NULL){
                pre=lefttt->data;
                lefttt=lefttt->right;
            }
            while(righttt!=NULL){
                suc=righttt->data;
                righttt=righttt->left;
            }
            break;
        }
        else if(temp->data>val){
            suc=temp->data;
            temp=temp->left;
        }
        else{
            pre=temp->data;
            temp=temp->right;
        }
    }
    return{pre,suc};

}

int main(){
    node*root=NULL;
    cout<<"Enter the nos for BST"<<endl;
    CreateBST(root);
    inorder(root);
    pair <int ,int>ans=PredSuc(root,5);
    cout<<ans.first<<" "<<ans.second; 
}