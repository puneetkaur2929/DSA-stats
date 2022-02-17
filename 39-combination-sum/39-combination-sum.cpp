class Solution {
public:
    void solve(int i,int sum,vector<int>&arr,vector<int>inter,vector<vector<int>>&ans){
        if(i==arr.size()){
             
            return;
        }
        if(sum==0){
                ans.push_back(inter);
            return;
            
        }
       
        
             if(sum>=arr[i]){
            inter.push_back(arr[i]);
            solve(i,sum-arr[i],arr,inter,ans);
                 inter.pop_back();
        }
        
        solve(i+1,sum,arr,inter,ans);
        
       return;
    }
        
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>inter;
        solve(0,target,candidates,inter,ans);
        return ans;
    }
};