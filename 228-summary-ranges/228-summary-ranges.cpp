class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
         vector<string>ans;
        if(nums.size()==0){
            return ans;
        }
       
        int s=nums[0];
        int e=nums[0];
       
        for(int i=1;i<nums.size();i++){
            if(e+1==nums[i]){
                e=nums[i];
            }
            else{
                if(s==e ){
                    string in=to_string(s);
                    ans.push_back(in);
                }
                else{
                    string in=to_string(s) +"->" + to_string(e);
                    ans.push_back(in);
                    
                }
                
                s=nums[i];
                e=nums[i];
            }
        }
        if(s==e ){
                    string in=to_string(s);
                    ans.push_back(in);
                }
                else{
                    string in=to_string(s) +"->" + to_string(e);
                    ans.push_back(in);
                    
                }
        
        return ans;
    }
};