class Solution {
public:
    bool isvalid(unordered_map<char,int>&ms,unordered_map<char,int>&mp){
        unordered_map<char,int>::iterator s;
        
        // unordered_map<char,int>::iterator p;
        s=ms.begin();
        // p=mp.begin();
        while(s!=ms.end()){
            if(ms[s->first]!=mp[s->first]){
                return false;
            }
            s++;
            // p++;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int i=0;
        int j=0;
        unordered_map<char,int>mp;
         unordered_map<char,int>ms;
        for(char c:p){
            mp[c]++;
        }
       vector<int>ans;
        while(j<s.length()){
            if(mp.find(s[j])!=mp.end()){
                ms[s[j]]++;
                if(j-i+1==p.length()){
                    if(isvalid(ms,mp)){
                         ans.push_back(i);
                        ms[s[i]]--;
                        if(ms[s[i]]==0){
                            ms.erase(s[i]);
                        }
                        i++;
                        j++;
                    }
                    else{
                        ms[s[i]]--;
                        if(ms[s[i]]==0){
                            ms.erase(s[i]);
                        }
                        i++;
                        j++;
                    }
                   
                    
                }
                else{
                   j++; 
                }
                
               
            }
            else{
                ms.clear();
                j++;
                i=j;
            }
            
            
        }
        return ans;
    }
};