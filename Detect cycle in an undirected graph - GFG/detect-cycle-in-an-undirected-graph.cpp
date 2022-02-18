// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
   bool helper(int i,vector<int>&vis,vector<int>adj[]){
        queue<pair<int,int>>q;
        q.push({i,-1});
        vis[i]=1;
        while(!q.empty()){
            int fn=q.front().first;
            int par=q.front().second;
            q.pop();
            for(int it:adj[fn]){
                if(vis[it]!=1){
                    q.push({it,fn});
                vis[it]=1;
                }
                else{
                   if(par!=it){
                    return true;
                }  
                }
               
                
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        
        vector<int>vis(V,0);
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                if(helper(i,vis,adj)==true){return true;}
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends