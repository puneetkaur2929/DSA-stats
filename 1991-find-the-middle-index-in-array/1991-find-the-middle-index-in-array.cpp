class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        if(nums.size()==1){
            return 0;
        }
        int sum=0;
        for(int i:nums){
            sum+=i;
        }
        int i=0;
        int j=0;
        // sum-=nums[0];
        int nn=0;
        while(j<nums.size()){
            
            sum-=nums[j++];
            if(nn==sum){
                return i;
            }
            nn+=nums[i++];
           
        }
        return -1;
    }
};