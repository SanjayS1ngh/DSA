#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
    node(int x){
         this->data=x;
        this->next=NULL;
    }
};
void insertathead(node* &head,int data){
    node* newnode=new node(data);
    newnode->next=head;
    head=newnode;
}
void insertatend(node* &head,int data){
    node* newnode=new node(data);
    if(!head||head->next==NULL){
        head=newnode;
        return;
    }
    node *lastnode=head;
    while(lastnode->next){
        lastnode=lastnode->next;
    }
    lastnode->next=newnode;
}
node* findmiddle(node* head){
    node*slow=head;
    node*fast=head->next;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
void insertatmiddle(node* &head,int data){
    node* newnode=new node(data);
    if(!head){
        head=newnode;
        return;
    }
    node*middle=findmiddle(head);
    node*temp=middle->next;
    middle->next=newnode;
    newnode->next=temp;
}
void display(node* head){
    while(head){
        cout<<head->data<<"-->";
        head=head->next;
    }
}

int main(){
    node *head(NULL);
    int choice ,data;
    cout<<"choice 1 : insert at head"<<endl;
    cout<<"choice 2 : insert at end"<<endl;
    cout<<"choice 3: insert at middle"<<endl;
    cout<<"choice 4: display"<<endl;
    cout<<"choice 5: exit"<<endl;
    while(true){
        cout<<"enter your choice:"<<endl;
        cin>>choice;
        switch (choice){
        case 1:
        cout<<"enter the data: ";
        cin>>data;
        insertathead(head,data);
        break;
        case 2:
        cout<<"enter the data: ";
        cin>>data;
        insertatend(head,data);
        break;
        case 3:
        cout<<"enter the data: ";
        cin>>data;
        insertatmiddle(head,data);
        break;
        case 4:
        display (head);
        break;
        case 5:
            return 0;
        default:
            cout<<"invalid choice";
    };
    }
    
}