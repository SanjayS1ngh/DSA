#include<iostream>
using namespace std;
#include<vector>
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

node*insert(node*root,int x){
    if(root==NULL){
        root=new node(x);
        return root;
    }
    else if(x>root->data){
        root->right=insert(root->right,x);
    }
    else{
        root->left=insert(root->left,x);
    }
    return root;
}

void CreateBST(node*&root){
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
void invector(node*root,vector<int>&v){
    vector<int>ans;
    if(root==NULL){
        return;
    }
    invector(root->left,v);
    v.push_back(root->data);
    invector(root->right,v);   
}
bool sum(node*root,int t){
    vector<int>ans;
    invector(root,ans);
    int i=0;
    int j=ans.size()-1;
    while(i<j){
        if(ans[i]+ans[j]==t){
            return true;
        }
        else if(ans[i]+ans[j]>t){
            j--;
        }
        else{
            i++;
        }
    }
    return false;
}

int main(){
    node*root=NULL;
    CreateBST(root);
    inorder(root);
    cout<<endl;
    bool ans=sum(root,10);
    cout<<ans;

    
}