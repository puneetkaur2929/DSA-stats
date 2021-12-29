class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>s;
        int len=1;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        for(auto it = s.begin(); it != s.end(); it++){
            int first=*it;
            if(s.find(first+1)!=s.end()){
                len++;  
            }
            else{ 
                ans=max(ans,len);
                len=1;
            }
            // cout<<"first "<< first<<" len "<<len<<" ans " <<ans<<"," ;
        }
        
       
        return ans;
    }
};