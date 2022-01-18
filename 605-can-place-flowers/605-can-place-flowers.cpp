class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        if(flowerbed.size()==1){
           return flowerbed[0]==0  || n==0 ? true : false;
        }
        if(flowerbed.size()>1 && flowerbed[0]==0 && flowerbed[1]!=1){
            flowerbed[0]=1;
            n-=1;
        }
        int i=1;
        while(i<=flowerbed.size()-2 && n>0){
            if(flowerbed[i]==0){
                if(flowerbed[i-1]==1){
                    i++;
                } 
        
                else{
                    if(flowerbed[i+1]==1){
                        i++;
                    }
                    else{
                        flowerbed[i]=1;
                        i++;
                        n-=1;
                    }
                }
            }
            else{
                i++;
            }
        }
        if(flowerbed.size()>1 && flowerbed[flowerbed.size()-1]==0 && flowerbed[flowerbed.size()-2]==0 ){
            n-=1;
        }
        return n<=0 ? true : false;
    }
};