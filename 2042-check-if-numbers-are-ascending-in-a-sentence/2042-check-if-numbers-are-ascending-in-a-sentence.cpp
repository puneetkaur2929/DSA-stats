class Solution {
public:
    bool areNumbersAscending(string s) {
        int res=0;
        int prev=0;
        vector<int>ans;
        for(int i=0;i<s.length();i++){
            
            if(s[i]>='0'&& s[i]<='9'){
                res=res*10+s[i]-'0';
            }
            else if(res!=0){
                if(prev>=res){
                    return false;
                }
              
                    prev=res;
                   
                    res=0;
                
            }
        }
       
        return res==0 || prev<res;
    }
};