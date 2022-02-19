class Solution {
public:
       bool helper(int i,vector<int>&col,vector<vector<int>>adj){
        queue<pair<int,int>>q;
        q.push({i,-1});
           col[i]=0;
        
        while(!q.empty()){
            int fn=q.front().first;
            int par=q.front().second;
            q.pop();
            for(int it:adj[fn]){
                if(col[it]==-1){
                    q.push({it,fn});
               
                    col[it]= (col[fn]==0) ?1 :0;
                }
                else{
                  
                    if(col[fn]==col[it]){
                        return false;
                    }
                
                    
                }
               
                
            }
        }
        return true;;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>col(graph.size(),-1);
        for(int i=0;i<graph.size();i++){
            if(col[i]==-1){
                if(helper(i,col,graph)==false){return false;}
            }
        }
        return true;
    }
};