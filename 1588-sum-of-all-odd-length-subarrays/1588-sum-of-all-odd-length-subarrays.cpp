class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int ans=0;
        for(int i=0;i<arr.size();i++){
            int sum=0;
            for(int j=i;j<arr.size();j++){
                if((j-i+1)%2 !=0){
                    sum+=arr[j];
                   
                   ans+=sum;
                    
                }
                else{
                    sum+=arr[j];
                }
            }
            
        }
        return ans;
    }
};