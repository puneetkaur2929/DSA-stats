class Solution {
public:

    vector<vector<int>>ans;
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()==1){
            return intervals;
        }
        sort(intervals.begin(),intervals.end());
        ans.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            vector<int>& last=ans.back();
            if(last[1]>=intervals[i][0]){
               last[1]=max(last[1],intervals[i][1]); 
            }
            else{
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};