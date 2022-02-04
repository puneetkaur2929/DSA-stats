class KthLargest {
public:
    int ko;
    priority_queue<int,vector<int>,greater<int>>p;
    KthLargest(int k, vector<int>& nums) {
        ko=k;
        for(auto i:nums){
            p.push(i);
            if(p.size()>k){
                p.pop();
                
            }
        }
    
    }
    
    int add(int val) {
        p.push(val);
        if(p.size()>ko){
            p.pop();
        }
        return p.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */