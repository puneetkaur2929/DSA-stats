class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0){
            return 1;
        }
          int bit=floor(log2(n));
        int xorn=pow(2,bit+1)-1;
        return n^xorn;
        
    }
};