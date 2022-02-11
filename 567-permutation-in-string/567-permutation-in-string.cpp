class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>m;
        unordered_map<char,int>m1;
        for(int i=0;i<s1.size();i++){
            m[s1[i]]++;
        }
        int i=0;
        int j=0;
        while(j<s2.size()){
            if(m.find(s2[j])!=m.end()){
                m1[s2[j]]++;
                if(j-i+1==s1.size()){
                    unordered_map<char,int>::iterator it;
                    it=m.begin();
                    int count=0;
                    while(it!=m.end()){
                        if(m[it->first]==m1[it->first]){
                             count++;  
                        }
                       
                        it++;
                    }
                    if(count==m.size()){
                        return true;
                    }
                    else{
                        m1[s2[i]]--;
                    if(m1[s2[i]]==0){
                        m1.erase(s2[i]);
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
                m1.clear();
                j++;
                i=j;
            }
        }
        return false;
    }
};