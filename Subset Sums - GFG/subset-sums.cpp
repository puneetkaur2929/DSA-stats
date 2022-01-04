// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
int sum(vector<int>arr,int n,int ansum,vector<int>&ans){
    if(n<0){
        ans.push_back(ansum);
        return 0;
    }
    sum(arr,n-1,ansum+arr[n],ans);
    sum(arr,n-1,ansum,ans);
    return 0;
    
}
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int>ans;
        sum(arr,N-1,0,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends