class Solution {
public:
    int addDigits(int num) {
       long long nn=0;
        while(num>9){
           while(num!=0){
            long long rem=num%10;
                nn+=rem;
               num=num/10;
           } 
            num=nn;
            nn=0;
        }
        return num;
    }
};