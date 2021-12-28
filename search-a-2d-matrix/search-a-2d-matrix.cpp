class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int col=matrix[0].size()-1;
        for(int i=0;i<matrix.size();i++){
            if(matrix[i][col]>=target){
                int start=0;
                int end=col;
                while(start<=end){
                    int mid=start+(end-start)/2;
                    if(matrix[i][mid]==target){
                        return true;
                    }
                    else if(matrix[i][mid]<target){
                        start=mid+1;
                    }
                    else{
                        end=mid-1;
                    }
                }
            }
        }
        return false;
    }
};