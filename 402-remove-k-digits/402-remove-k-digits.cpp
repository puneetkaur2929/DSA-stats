class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.length()<=k){
            return "0";
        }
        stack<char>s;
        s.push(num[0]);
        int i=1;
        for(i=1;i<num.length();i++){
           
            if(num[i]<s.top()){
              while(k>0 && !s.empty() && num[i]<s.top()){
                  k--;
                    s.pop();
                    
              }
                   
                }
            s.push(num[i]);
                
            }
           while(k!=0){
               s.pop();
               k--;
           }
        
        
        string ans;
       
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        while(ans.back()=='0'){
            ans.pop_back();
        }
        reverse(ans.begin(),ans.end());
        
        return ans.empty() ? "0":ans;
    }
};