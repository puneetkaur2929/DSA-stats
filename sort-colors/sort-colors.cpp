class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0;
        int mid=0;
        int high=nums.size()-1;
        while( mid<=high){
            if(nums[low]==1 && nums[mid]==0){
                int temp=nums[mid];
                nums[mid]=nums[low];
                nums[low]=temp;
                low++;
                mid++;
            }
            else if(nums[mid]==1){
                mid++;
                
            }
            else if(nums[mid]==2 ){
                int temp=nums[mid];
                nums[mid]=nums[high];
                nums[high]=temp;
                high--;
            }
            else if(nums[low]==0 && nums[mid]==0){
                low++;
                mid++;
            }
        }
        
    }
};