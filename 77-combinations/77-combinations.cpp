class Solution {
public:
    void solve(int i,int n, int k,vector<int>&inter,vector<vector<int>>&ans){
       
        if(inter.size()==k){
            ans.push_back(inter);
            return;
        }
         if(i==n+1){
            return;
        }
        inter.push_back(i);
        solve(i+1,n,k,inter,ans);
        inter.pop_back();
        solve(i+1,n,k,inter,ans);
        return;
    }
    vector<vector<int>> combine(int n, int k) {
         vector<vector<int>> ans;
        vector<int>inter;
        solve(1,n,k,inter,ans);
        return ans;
    }
};