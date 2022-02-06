class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        int j=0;
        int n=nums.size();
        while(j<n){
            if(nums[i]==nums[j]){
                if(j-i+1 >2){
                    for(int x=j;x<n-1;x++){
                        nums[x]=nums[x+1];
                    }
                    n=n-1;
                }
                else{
                   j++; 
                }
                
            }
            else {
                i=j;
                j++;
                
            }
        }
        return n;
    }
};