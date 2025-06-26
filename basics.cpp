#include <iostream>
using namespace std;

void destination(int src,int dest){
    if(src==dest){
        cout<<"you have reached"<<endl;
        return;
    }
    cout<<"you are now at src "<<src<<endl;
    destination(src+1,dest);
    cout<<"you have retured at src "<<src<<endl;

}


int main(){
    destination(1,10);
}