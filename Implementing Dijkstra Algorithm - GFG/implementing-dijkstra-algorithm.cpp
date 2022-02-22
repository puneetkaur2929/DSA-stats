// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

#define pp pair<int,int>
class Solution


{
    
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
            priority_queue<pp,vector<pp>,greater<pp>> p;
            vector<int>ans(V,INT_MAX);
            p.push({0,S});
            ans[S]=0;
            while(!p.empty()){
                int dist=p.top().first;
                int tn=p.top().second;
                p.pop();
                for(auto itr:adj[tn]){
                    int newdist=dist+ itr[1];
                    if(ans[itr[0]]>newdist){
                        ans[itr[0]]=newdist;
                        
                         p.push({newdist,itr[0]});
                    }
                   
                }
            }
            return ans;
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends