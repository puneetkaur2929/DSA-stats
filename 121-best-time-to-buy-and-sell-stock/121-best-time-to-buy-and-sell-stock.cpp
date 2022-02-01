class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=INT_MAX;
        int pro=0;
        for(int i=0;i<prices.size();i++){
            buy=min(buy,prices[i]);
            pro=max(pro,(prices[i]-buy));
        }
        return pro;
    }
};