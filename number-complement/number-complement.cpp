class Solution {
public:
    int findComplement(int num) {
      int bit=floor(log2(num));
        int xorn=pow(2,bit+1)-1;
        return num^xorn;
        
    }
};