class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k%2 ==0 || k %5==0){
            return -1;
        }
        if(1%k==0){
            return 1;
        }
        int rem=1%k;
       
        unordered_set<int>s;
        while(rem!=0 && s.find(rem)==s.end()){
            s.insert(rem);
            rem=(rem*10+1)%k;
            
           
        }
        if(rem==0){
            return s.size()+1;
        }
        
        return -1;
        
    }
};