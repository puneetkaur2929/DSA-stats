class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        cout<<sum<<endl;
        
        int news=0;
        for(int i=0;i<nums.size();i++){
            if(news==(sum-nums[i])){
                return i;
            }
            else{
                news+=nums[i];
                sum-=nums[i];
            }
        }
        return -1;
        
    }
};