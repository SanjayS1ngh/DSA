// User function Template for C++

#include<algorithm>
using namespace std;
#include<vector>
class Solution {
  public:
    void unionSet(int u,int v,vector<int>&parent,vector<int>&rank){
        int parentOfU=findParent(parent,u);
        int parentOfV=findParent(parent,v);
        if(rank[parentOfU]<rank[parentOfV]){
            parent[parentOfU]=parent[v];
        }
        else if(rank[parentOfU]>rank[parentOfV]){
            parent[parentOfV]=parent[u];
        }
        else{
            parent[parentOfU]=parent[v];
            rank[v]++;
        }
        
    }
    int findParent(vector<int>&parent,int node){
        if(parent[node]==node){
            return node;
        }
        return parent[node]=findParent(parent,parent[node]);
    }
    static bool cmp(vector<int>&a,vector<int>&b){
        return a[2]<b[2];
    }
    int kruskalsMST(int V, vector<vector<int>> &edges){
        vector<int>parent(V);
        for(int i=0;i<V;i++){
            parent[i]=i;
        }
        vector<int>rank(V,0);
        sort(edges.begin(),edges.end(),cmp);
        int ans=0;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int parentOfU=findParent(parent,u);
            int parentOfV=findParent(parent,v);
            if(parentOfU!=parentOfV){
                ans+=edges[i][2];
                unionSet(u,v,parent,rank);
            }
        }   
        return ans;
    }
};