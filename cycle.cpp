#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;
    node(int x){
        data=x;
        next=NULL;
    }
};
void insertathead(node* &head,int data){
    node* newnode=new node(data);
    newnode->next=head;
    head=newnode;
}
void createcycle(node*head){
    node*temp=head;
    while(head->next!=NULL){
        head=head->next;
    }
    head->next=temp;
}
bool cycle(node* head){
    node*slow=head;
    node*fast=head;
    while(fast->next!=NULL&&fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            return true;
        }
    }
    return false;
}
int main(){
    int n;
    cin>>n;
    node* head(NULL);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        insertathead(head,x);
    }
    bool ans;
    ans=cycle(head);
    cout<<ans;
    createcycle(head);
    ans=cycle (head);
    cout<<ans;
}