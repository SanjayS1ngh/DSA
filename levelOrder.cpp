#include<iostream>
#include<queue>
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
    cout<<"enter element"<<endl;
    cin>>x;
    if(x==-1){
        return NULL;
    }
    node* newnode= new node(x);
    newnode->left=buildtree();
    newnode->right=buildtree();
}

void preorder(node*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
    return;
}

void levelOrder(node*root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node*temp=q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left!=NULL){

                q.push(temp->left);
            }
            if(temp->right!=NULL){

                q.push(temp->right);
            }
        }
    }

}
node*buildFromLevelOrder(){
    int n;
    cout<<"Enter root node";
    cin>>n;
    queue<node*>q;
    node* root=new node(n);
    q.push(root);
    while(!q.empty()){
        node*temp=q.front();
        q.pop();
        cout<<"enter left child of "<<temp->data<<endl;
        int leftchild;
        cin>>leftchild;
        if(leftchild!=-1){
            temp->left=new node(leftchild);
        }
        int rightchild;
        cin>>rightchild;
        if(rightchild!=-1){
            temp->right=new node(rightchild);
        }
    }
    return root;


}




int main(){
    node*root=buildtree();
    preorder(root);
    cout<<endl;
    levelOrder(root);
}