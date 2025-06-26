#include<iostream>
using namespace std;
#include<vector>
void sort(int*v,int size){
    if(size==1){
        return;
    }
    for(int i=0;i<size-1;i++){
        if(v[i]>v[i+1]){
            swap(v[i],v[i+1]);
        }
    }
    sort(v,size-1);
}

int main(){
    int nums[7]={3,5,4,6,7,2,7};
    int size=7;
    cout<<"HI";
    sort(nums,size);
    for(int i=0;i<size;i++){
        cout<<nums[i]<<" "; 
    }

}