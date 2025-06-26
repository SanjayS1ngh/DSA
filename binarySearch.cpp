#include <iostream>
using namespace std;

bool search(int arr[],int s,int e,int key){
    if(s>e){
        return false;
    }
    int mid=(s+e)/2;
    if(arr[mid]==key){
        return true;
    }
    else if(arr[mid]>key){
        return search(arr,s,mid-1,key);
    }
    else{
        return search(arr,mid+1,e,key);
    }
}

int main(){
    int arr[8]={1,2,3,4,5,6,7,8};
    int key=9;
    bool ans=search(arr,0,7 ,key);
    cout<<ans;

}