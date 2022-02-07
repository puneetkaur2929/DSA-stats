class Solution {
public:
    char findTheDifference(string s, string t) {
        
        int ans=0;
        for(auto i:t){
           ans+=(i);
        }
        for(auto j:s){
           
            ans-=(j);
        }
        return ans;
    }
};