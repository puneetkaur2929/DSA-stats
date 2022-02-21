class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>indeg(numCourses,0);
        int count=0;
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indeg[prerequisites[i][0]]++;
        }
        queue<int>q;
        for(int i=0;i<indeg.size();i++){
            if(indeg[i]==0){
                q.push(i);
                numCourses--;
            }
        }
        while(!q.empty()){
            int fn=q.front();
            q.pop();
            for(auto it:adj[fn]){
                indeg[it]--;
                if(indeg[it]==0){
                    q.push(it);
                    numCourses--;
                }
            }
        }
        return((numCourses==0) ? true :false);
    }
};