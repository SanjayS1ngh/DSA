#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class graph{
    public:
    unordered_map<int,vector<int>>adj;

     void addElement(int u,int v,bool direction){//if d==1 means directed
        
        adj[u].push_back(v);
        if(direction==0){
            adj[v].push_back(u);
        }
    }

    void display(){
         for(auto i:adj){
            cout<<"node "<<i.first<<"-->";
            for(auto j:i.second){
                cout<<j;
            }
         }
    }
};




int main(){
    int n;
    cout<<"enter the no of nodes";
    cin>>n;
    cout<<"enter the no of edges";
    int m;
    cin>>m;
    graph g;
    for(int i=-0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g.addElement(u,v,0);
    } 
    g.display();
}