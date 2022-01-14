class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        bool neg=false;
        int len=s.length();
        while(s[i]==' ' && i<len){
            i++;
        }
        if(s[i]=='-' && i<len){
            neg=true;
            i++;
        }
        else if(s[i]=='+' && i<len){
            i++;
        }
        while(s[i]=='0'){
            i++;
        }
       int res=0;
         while(i<s.length()&&(s[i]>='0'&&s[i]<='9'))
        {
             int digit=s[i]-'0';
             if(res>INT_MAX/10 || (res==INT_MAX/10 && digit>7)){
                 return neg?INT_MIN:INT_MAX;
             }
                      
            res=res*10+digit;
            
            i++;
        }
        return neg==true?-res:res;
    }
};