// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<int>key(V,10000000);
        vector<bool>mst(V,false);
        vector<int>par(V,-1);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;
        p.push({0,0});
        key[0]=0;
       
        while(!p.empty()){
            int u=p.top().second;
            p.pop();
            mst[u]=true;
            for(auto i:adj[u]){
                if(mst[i[0]]==false && i[1]<key[i[0]]){
                    key[i[0]]=i[1];
                    par[i[0]]=u;
                    p.push({key[i[0]],i[0]});
                }
            }
        }
        int sum=0;
        for(int i=0;i<V;i++){
            sum+=key[i];
        }
        return sum;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends