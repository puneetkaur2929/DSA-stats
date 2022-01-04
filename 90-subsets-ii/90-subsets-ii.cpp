class Solution {
public:
    void subset(vector<int>&nums,int index,vector<int>&ds,vector<vector<int>>&ans){
        ans.push_back(ds);
        for(int i=index;i<nums.size();i++){
            if(i!=index && nums[i]==nums[i-1]){
                continue;
            }
            ds.push_back(nums[i]);
            subset(nums,i+1,ds,ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>ds;
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        subset(nums,0,ds,ans);
        return ans;
    }
};