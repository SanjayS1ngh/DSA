#include<iostream>
using namespace std;
#include<string>

string rev(string s,int i,int j){
    if(i>j){
        return s;
    }
    swap(s[i],s[j]);
    return rev(s,i+1,j-1);

}

string reverse(string s){
    int e=s.length()-1;
    return rev(s,0,e);
}

int main(){
    string s="abcd";
    string ans=reverse(s);
    cout<<ans;
}