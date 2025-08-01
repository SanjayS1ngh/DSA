#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<unordered_map>
class Solution {
public:

    void dfs(int node,vector<int>&parent,int &timer,vector<int>&disc,vector<int>&low,vector<vector<int>>&result,unordered_map<int,vector<int>>&adj,vector<bool>&visited){
        visited[node]=true;
        disc[node]=low[node]=timer++;
        for(auto nbr: adj[node]){
            if(nbr==parent[node]){
                continue;
            }
            if(!visited[nbr]){
                parent[nbr]=node;
                dfs(nbr,parent,timer,disc,low,result,adj,visited);
                low[node]=min(low[node],low[nbr]);
                if(low[nbr]>disc[node]){
                    vector<int>ans;
                    ans.push_back(node);
                    ans.push_back(nbr);
                    result.push_back(ans);
                }
            }
            else{
                low[node]=min(low[node],disc[nbr]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int>disc(n,-1);
        vector<bool>visited(n,false);
        vector<int>low(n,-1);
        vector<int>parent(n,-1);
        vector<vector<int>>result;
        int timer=0;
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,parent,timer,disc,low,result,adj,visited);
            }
        }
        return result;
        
    }
};