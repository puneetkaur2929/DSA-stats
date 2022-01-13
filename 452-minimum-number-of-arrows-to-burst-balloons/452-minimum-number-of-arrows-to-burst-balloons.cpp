  bool compare(vector<int>&a,vector<int>&b){
     
           return a[1]<b[1];
    }
class Solution {
public:
   
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size()==0)return 0;
        if(points.size()==1)return 1;
        sort(points.begin(),points.end(),compare);
        int arr=1;
         int lastp=points[0][1];
        for(int i=1;i<points.size();i++){
            if( points[i][0]>lastp){
                arr++;
                lastp=points[i][1];
            }
        }
        return arr;
    }
};