class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int maxdist=0;
        int last;
        int i=0;
        while(seats[i]==0){
            i++;
        }
        last=i;
        maxdist=i;
        
       for(; i<seats.size();i++){
           if(seats[i]==1){
               maxdist=max(maxdist,(i-last)/2);
               last=i;
           }
       }
        maxdist=max(maxdist,i-last-1);
        return maxdist;
    }
};