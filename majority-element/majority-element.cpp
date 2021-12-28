class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>m;
        int ans=INT_MIN;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        for(auto it:m){
            if(it.second>(nums.size()/2) && ans<it.first){
                ans=it.first;
            }
        }
        return ans;
    }
};