#include <iostream>
using namespace std;
#include<stack>
struct node{
    int data;
    node*next;
    node(int x){
        data=x;
        next=NULL;
    }
};
void insertathead(node*&head,int data){
    node*newnode=new node(data);
    newnode->next=head;
    head=newnode;
}
bool ispalindrome(node*head){
    stack<int>s;
    node*curr=head;
    while(curr!=NULL){
        s.push(curr->data);
        curr=curr->next;
    }
    curr=head;
    while(curr!=NULL&&curr->data==s.top()){
        s.pop();
        curr=curr->next;
    }
    return curr==NULL;
}
int main(){
    node*head(NULL);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        insertathead(head,x);
    }
    bool ans=ispalindrome(head);
    cout<<ans;
}
