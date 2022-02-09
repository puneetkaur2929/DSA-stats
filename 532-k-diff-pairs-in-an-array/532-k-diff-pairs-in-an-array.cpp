class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        for(int i:nums){
            m[i]++;
        }
        int count=0;
        for(auto i:m){
            if(k==0){
                if(i.second>1){
                    count++;
                }
            }
          else if(m.find(i.first-k)!=m.end()){
               count++;
           }
        }
        return count;
    }
};