class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int mid=(nums.size()-1)/2;
        int i=0;
        int j=nums.size()-1;
        if(nums[0]==nums[mid]){
            return nums[0];
        }
        if(nums[j]==nums[mid]){
            return nums[j];
        }
        while(i<j){
           if(nums[i]==nums[j]){
               return nums[i];
           }
            else{
                i++;
                j--;
            }
        }
        return 0;
    }
};