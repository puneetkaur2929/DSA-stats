class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int me=0;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(count==0){
                me=nums[i];
                count=1;
            }
            else {
                if(me==nums[i]){
                    count++;
                }
                else{
                    count--;
                }
            }
        }
        return me;
    }
};