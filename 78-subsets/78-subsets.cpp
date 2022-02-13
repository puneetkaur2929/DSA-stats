class Solution {
public:
     void solve(vector<int>i,vector<int>o,vector<vector<int>>&ans){
        if(i.size()==0){
            ans.push_back(o);
            return ;
        }
        vector<int>o1;
        vector<int>o2;
        o1=o;
        o2=o;
        o2.push_back(i[0]);
        i.erase(i.begin());
        solve(i,o1,ans);
        solve(i,o2,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>o;
        vector<vector<int>>ans;
        solve(nums,o,ans);
        return ans;
    }
};