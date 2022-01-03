class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        int j=1;
        if(nums.size()==0){
            return 0;
        }
        while(j<nums.size()){
            if(nums[i]!=nums[j]){
                i+=1;
                nums[i]=nums[j];
            }
            else {
                j++;
            }
        }
        return i+1;
    }
};