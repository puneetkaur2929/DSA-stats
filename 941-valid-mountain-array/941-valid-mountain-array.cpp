class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n=arr.size();
        int count=0;
        for(int i=1;i<n-1;){
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){
                count=1;
                int j=i;
                while(j>=1 && arr[j]>arr[j-1]){
                    count++;
                    j--;
                }
                while(i<n-1 && arr[i]>arr[i+1]){
                    count++;
                    i++;
                }
                
            }
           else{
               i++;
           }
        }
        if(count==n){
            return true;
        }
      return false;  
    }
};