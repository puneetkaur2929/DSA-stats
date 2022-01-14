class Solution {
public:
    string sortSentence(string s) {
        int f=0;
        int l=0;
        vector<string>v(9," ");
        map<int,string>m;
        while(l<s.length() && f<s.length()){
            if(s[l]>='1'&& s[l]<='9'){
                m[s[l]-'0']=s.substr(f,l-f);
                
                f=l+2;
                
            }
            l++;
        }
        string ans;
         map<int,string>::iterator itr;
        itr=m.begin();
        while(itr!=m.end()){
                ans=ans+itr->second;
            
            itr++;
            if(itr!=m.end()){
                ans+=' ';
            }
            
           
        }
        return ans;
    }
};