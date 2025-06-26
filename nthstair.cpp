#include<iostream>
using namespace std;
int countDistWayToClimb(int NStairs){
    if(NStairs<0){
        return 0;
    }
    if(NStairs==0){
        return 1;
    }
    return countDistWayToClimb(NStairs-1)+countDistWayToClimb(NStairs-2);
     
}
int main(){
    int ans=countDistWayToClimb(5);
    cout<<ans;

}