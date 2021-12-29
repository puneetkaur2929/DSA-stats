class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int st=0;
        int pos=0;
        unordered_set<char>m;
        for(int i=0;i<s.length();i++){
            if(m.find(s[i])!=m.end()){
                while(st<i && m.find(s[i])!=m.end() ){
                    m.erase(s[st]);
                    st++;
                }
            }
            m.insert(s[i]);
            pos=max(pos,i-st+1);
        }
        return pos;
    }
};