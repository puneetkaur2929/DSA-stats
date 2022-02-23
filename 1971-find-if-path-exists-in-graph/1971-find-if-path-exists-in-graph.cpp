class Solution {
public:
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>v(n);
        if(n==1){
            return true;
        }
        for(int i=0;i<edges.size();i++){
            v[edges[i][0]].push_back(edges[i][1]);
            v[edges[i][1]].push_back(edges[i][0]);
        }
      
       queue<int>q;
      
        q.push(source);
       vector<int>vis(n,0);
        vis[source]=1;
        while(!q.empty()){
            int fn=q.front();
            q.pop();
            if(fn==destination){
                    return true;
                }
            for(int i:v[fn]){
                
                
                if(vis[i]==0){
                    q.push(i);
                    vis[i]=1;
                }
                
            }
            
        }
        return false;
    }
};