class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
         stack<int>l;
    stack<int> r;
    vector<int> vl;
    vector<int > vr;
    l.push(0);
    vl.push_back(-1);
        int n=heights.size();
    for(int i=1;i<n;i++){
        if(l.size()>0 && heights[i]>heights[l.top()]){
            vl.push_back(l.top());
        }
        else if (l.size()>0 && heights[i]<=heights[l.top()]){
            while(l.size()>0 && heights[i]<=heights[l.top()]){
                l.pop();
            }
            if(l.size()==0){
                vl.push_back(-1);
            }
            else{
                vl.push_back(l.top());
            }
        }
        l.push(i);
    }
    
    r.push(n-1);
    vr.push_back(n);
    for(int j=n-2;j>=0;j--){
        if(r.size()>0 && heights[j]>heights[r.top()]){
            vr.push_back(r.top());
        }
        else if(r.size()>0 && heights[j]<=heights[r.top()]){
            while(r.size()>0 && heights[j]<=heights[r.top()]){
                r.pop();
            }
            if(r.size()==0){
                vr.push_back(n);
            }
            else{
                vr.push_back(r.top());
            }
        }
        r.push(j);
    }
    reverse(vr.begin(),vr.end());
    
    for(int g=0;g<n;g++){
        vl[g]=vr[g]-vl[g]-1;
    }
    for(int h=0;h<n;h++){
        heights[h]=heights[h]*vl[h];
    }
    return *max_element (heights.begin(), heights.end());
    }
};