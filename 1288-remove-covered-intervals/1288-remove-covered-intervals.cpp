
    
class Solution {
public:
     static bool greaterin(vector<int> &a,vector<int> &b){
        if(a[0]==b[0]){
            if(a[1]>b[1]){
                return true;
            }
        }
        else if(a[0]<b[0]){
            return true;
        }
        return false;
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),greaterin);
        int count=0;
        int cmp=intervals[0][1];
        int ans=intervals.size();
        for(int i=1;i<intervals.size();i++){
            if(cmp>=intervals[i][1]){
               
                ans--;
            }
            else{
                cmp=intervals[i][1];
            }
        }
        return ans;
    }
};