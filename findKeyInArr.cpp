#include<iostream>
using namespace std;

bool ispresent(int arr[],int size,int key){
    if(size==0){
        return false;
    }
    if(arr[0]==key){
        return true;
    }
    return ispresent(arr+1,size-1,key);
}

int main(){
    int arr[5]={1,2,3,4,5};
    int key=-1;
    int size=5;
    bool ans=ispresent(arr,size,key);
    cout<<ans;
}