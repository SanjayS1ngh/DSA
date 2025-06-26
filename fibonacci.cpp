#include<iostream>
using namespace std;

int fib(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    return fib(n-1)+fib(n-2);

}

int main(){
    int ans1=fib(5);
    int ans2=fib(6);
    cout<<ans1<<" "<<ans2;
}