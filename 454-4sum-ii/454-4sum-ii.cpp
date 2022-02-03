class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int>m;
        for(int i:nums1){
            for(int j:nums2){
                m[i+j]++;
            }
        }
        int count=0;
        for(int k:nums3){
            for(int l:nums4){
                count+=(m[-(k+l)]);
            }
        }
        return count;
    }
};