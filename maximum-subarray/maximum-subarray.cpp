class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==0) return 0;
		int n=nums.size();
		int cur=0;
		int res=INT_MIN;
		for(int i=0;i<n;i++){

			cur+=nums[i];
			if(cur<nums[i]){
				cur=nums[i];
			}
			res=max(cur,res);

		}
		return res;
    }
};