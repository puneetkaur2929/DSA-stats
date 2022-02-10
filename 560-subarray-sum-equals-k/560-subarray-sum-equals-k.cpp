class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>s;
        int sum=0;
        int count=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum==k){
                count++;
            }
             if(s.find(sum-k)!=s.end()){
                count+=s[sum-k];
            }
            if(s.find(sum)!=s.end()){
                s[sum]++;
            }
            else{
                s[sum]=1;
            }
                
            
        }
        return count;
    }
};