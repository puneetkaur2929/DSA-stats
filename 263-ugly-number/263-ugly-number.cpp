class Solution {
public:
    bool isUgly(int n) {
       if(n==0){
           return false;
       }
        while(n!=0){
            if(n==1){
            return true;
        } 
      
           n=n%2==0 ? n/2 :(n%3==0 ? n/3 : (n%5==0  ? n/5 : -1));
            if(n==-1){
                return false;
            }
            
        }
        return true;
    }
};