class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // int rarr[matrix.size()];
        // int carr[matrix[0].size()];
        vector<int>rarr(matrix.size(),-1);
        vector<int>carr(matrix[0].size(),-1);
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    rarr[i]=0;
                    carr[j]=0;
                }
            }
        }
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(rarr[i]==0 || carr[j]==0){
                    matrix[i][j]=0;
                }
            }
        }
    }
};