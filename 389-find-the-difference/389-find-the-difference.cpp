class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int>m;
        for(auto i:s){
            m[i]++;
        }
        for(auto i:t){
            if(m.count(i)!=0){
                m[i]--;
                if(m[i]==0){
                    m.erase(i);
                }
            }
            else{
                return i;
            }
        }
        return t[0];
    }
};