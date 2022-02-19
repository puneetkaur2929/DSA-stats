// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
bool helper(int i,vector<int>&col,vector<int>adj[]){
        if(col[i]==-1){
            col[i]=0;
        }
            for(int it:adj[i]){
                if(col[it]==-1){
                   col[it]= col[i]==0 ?1:0;
                   if(!helper(it,col,adj)){
                       return false;
                   }
                }
                else{
                    if(col[i]==col[it]){
                        return false;
                    }
                    
            }
            }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	     vector<int>col(V,-1);
        for(int i=0;i<V;i++){
            if(col[i]==-1){
               
                if(helper(i,col,adj)==false){return false;}
            }
        }
        return true;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends