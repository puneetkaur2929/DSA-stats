class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
         vector<vector<int>> ans;
        int n=nums.size();
        int pos=1;
        while(n!=1){
            pos*=n;
            n=n-1;
        }
        while(pos!=0){
            next_permutation(nums.begin(),nums.end());
            ans.push_back(nums);
            pos--;
        }
        return ans;
        
    }
};