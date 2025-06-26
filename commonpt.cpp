#include <iostream>
using namespace std;
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
bool commonpt(node*head1,node*head2){
    node*ptr1=head1;
    node*ptr2=head2;
    while(ptr1!=ptr2){
        ptr1=ptr1?ptr1=ptr1->next:ptr1=head2;
        ptr2=ptr2?ptr2=ptr2->next:ptr2=head1;
    }
    return ptr1;
}
int main(){
    node*head1(NULL);
    insertathead(head1,10);
    insertathead(head1,20);
    insertathead(head1,30);
    insertathead(head1,40);
    insertathead(head1,50);
    insertathead(head1,60);

    node*head2(NULL);
    insertathead(head2,70);
    insertathead(head2,80);
    bool ans=commonpt(head1,head2);
    cout<<ans;
    node *temp=head1;
    while(temp->data!=40){
        temp=temp->next;
    }
    head2->next=temp;
    ans=commonpt(head1,head2);
    cout<<ans;
}