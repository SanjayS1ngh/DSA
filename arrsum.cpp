#include<iostream>
using namespace std;

int sum(int arr[],int size){
    if(size==0){
        return 0;
    }
    if(size==1){
        return arr[0];
    }
    
    return arr[0]+sum(arr+1,size-1);
}

int main(){
 int arr[5]={1,2,1,2,1};
 int ans =sum(arr,5);
 cout<<ans<<endl;
}