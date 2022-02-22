class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans=0;
        for(int i=0;i<columnTitle.length();i++){
            ans=ans*26+(columnTitle[i]-64);
        }
        return ans;
    }
};