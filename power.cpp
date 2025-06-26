#include<iostream>
using namespace std;

int solve(int a ,int b){
    if(b==1){
        return a;
    }
    if(b%2==0){
        return solve(a,b/2)*solve(a,b/2);
    }
    else{
        return a*(solve(a,b/2)*solve(a,b/2));
    }
}



int main(){
    int a=2;
    int b=11;
    int ans=solve(a,b);
    cout<<ans;
}