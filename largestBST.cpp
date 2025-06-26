#include<iostream>
using namespace std;
#include<climits>
class info{
    public:
    int size;
    int max;
    int min;
    bool isBST;
};




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

node* buildtree(){
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
info solve(node*root,int&ans){
    if(root==NULL){
        return {0,INT_MAX,INT_MIN,true};
    }
    info left=solve(root->left,ans);
    info right=solve(root->right,ans);
    info currentnode;
    currentnode.size=left.size+right.size+1;
    currentnode.max=max(right.max,root->data);
    currentnode.min=min(left.min,root->data);

    if(left.isBST && right.isBST &&(root->data>left.max&&root->data<right.min)){
        currentnode.isBST=true;
    }
    else{
        currentnode.isBST=false;
    }
    if(currentnode.isBST){
        ans=max(ans,currentnode.size);
    }
    return currentnode;

}
int largestBST(node*root){
    int maxsize=0;
    info temp=solve(root,maxsize);
    return maxsize;
}
int main(){
    node*root=buildtree();
    int ans=largestBST(root);
    cout<<endl<<ans;
}