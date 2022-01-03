class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int,int>m1;
        unordered_map<int,int>m2;
         if(trust.size()==0 && n==1){
             return 1;
         }
        if(trust.size()==0 && n>1){
            return -1;
        }
        if(n==trust.size()){
            return -1;
        }
        for(int i=0;i<trust.size();i++){
            m1[trust[i][0]]=trust[i][1];
            m2[trust[i][1]]++;
        }
        int cou=INT_MIN;
        int ans=-1;
        for(auto i:m2){
            if(i.second>cou && i.second==n-1 &&m1.find(i.first)==m1.end()){
                cou=max(cou,i.second);
                ans=i.first;
            }
            else if(cou==i.second){
                cou=INT_MIN;
                ans=-1;
            }
        }
        return ans;
    }
};