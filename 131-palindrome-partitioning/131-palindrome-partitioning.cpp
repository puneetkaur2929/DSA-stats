class Solution {
public:
    bool ispal(string s,int start,int end){
        while(start<end){
            if(s[start]!=s[end]){
                return false;
            }
            else{
                start++;
                end--;
            }
        }
        return true;
    }
    void part(int index,string &s,vector<string>&in,vector<vector<string>>&ans){
        if(index==s.size()){
            ans.push_back(in);
            return ;
        }
        for(int i=index;i<s.size();++i){
            if(ispal(s,index,i)){
                in.push_back(s.substr(index,i - index+1));
                part(i+1,s,in,ans);
                in.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>in;
        vector<vector<string>>ans;
        part(0,s,in,ans);
        return ans;
    }
};